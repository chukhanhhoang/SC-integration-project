function [a, b, ig, c, d, jh, Cost, smax, smin] = BJNewtonGaussStep(Y, U, s, q, sMat, qMat, Gc, a0, b0, ig0, c0, d0, jh0, SelA, SelB, OrderI, ...														 OrderC, OrderD, OrderJ, Lambda, Transient, TheNoisePlane, TheModel, LogDet, DC, Nyquist, TraceOn);%%	[a, b, ig, c, d, jh, Cost, smax, smin] = BJNewtonGaussStep(Y, U, s, q, sMat, qMat, Gc, a0, b0, ig0, c0, d0, jh0, SelA, SelB, OrderI, ...%												OrderC, OrderD, OrderJ, Lambda, Transient, TheNoisePlane, TheModel, LogDet, DC, Nyquist, TraceOn)%%	output parameters%		a		=	new estimate coefficients denominator polynomial plant model, dimension 1 x OrderA+1%		b		=	new estimate coefficients numerator polynomial plant model, dimension 1 x OrderB+1%		ig		=	new estimate coefficients initial cond. plant model, dimension 1 x OrderI+1%		c		=	new estimate coefficients numerator polynomial noise model, dimension 1 x OrderC+1%		d		=	new estimate coefficients denominator polynomial noise model, dimension 1 x OrderD+1%		jh		=	new estimate coefficients initial cond. noise model, dimension 1 x OrderJ+1%		Cost	=	value of the cost function in the last iteration step%		smax	=	largest singular value of the Jacobian matrix%		smin	=	smallest singular value of the Jacobian matrix%%	input parameters%		Y				=	DFT spectrum output signal, dimensions: number of frequencies x 1%		U				=	DFT spectrum input signal, dimensions: number of frequencies x 1%		s				=	vector of (zk^-1) or (jwk) values, dimension: number of frequencies x 1%		sMat			=	table of powers of (jwk)^r or (zk^-r)%		qMat			=	table of powers of (zk^-r)%		Gc				=	controller transfer function, zero or empty if unknown or not present%		a0				=	previous estimate coefficients denominator polynomial plant model, dimension 1 x OrderA+1%		b0				=	previous estimate coefficients numerator polynomial plant model, dimension 1 x OrderB+1%		ig0				=	previous estimate coefficients initial cond. plant model Ig, dimensions: OrderI+1 x 1%		c0				=	previous estimate coefficients numerator polynomial noise model, dimension 1 x OrderC+1%		d0				=	previous estimate coefficients denominator polynomial noise model, dimension 1 x OrderD+1%		jh0				=	previous estimate coefficients initial cond. noise model Jh, dimensions: OrderJ+1 x 1%		SelA			=	if 1 then coeff. A-polynomial is unknown; if zero the coeff. is known equal to zero%		SelB			=	if 1 then coeff. B-polynomial is unknown; if zero the coeff. is known equal to zero%		OrderI			=	order initial cond. polynomial plant model%		OrderJ			=	order initial cond. polynomial noise model%		Lambda			=	lambda faktor Levenberg-Marquardt itteration scheme%		Transient		=	if Transient = 1 then initial conditions plant and/or noise model are estimated%		TheNoisePlane	=	'z', 's', 'w' => discrete-time or continous-time noise model%		TheModel		=	'BJ		=>	Box-Jenkins;%							'OE'	=>	output error (plant model only);%							'NO' => autoregressive moving average (noise model only)%		LogDet			=	1 if logdet(NoiseCovarianceMatrix) is present in likelihood; otherwise 0%		DC				=	1 if DC present otherwise 0%		Nyquist			=	1 if Nyquist frequency present otherwise 0%		TraceOn			=	1 the display messages%% Rik Pintelon, 1998% version April, 2004, added: CT and DT noise modeling in limited frequency band% version July, 2004, added: ARMAX%% calculate plant modelA = polyval(fliplr(a0),s);B = polyval(fliplr(b0),s);if Transient == 1	Ig = polyval(fliplr(ig0),s);else	Ig = [];end;% calculate noise modelC = polyval(fliplr(c0),q);D = polyval(fliplr(d0),q);if Transient == 1	Jh = polyval(fliplr(jh0),q);else	Jh = [];end;% calculate parameter variationError = BJError(Y, U, A, B, Ig, C, D, Jh, Gc, Transient, LogDet, DC, Nyquist);Jacob = BJJacob(Y, U, sMat, qMat, Error, A, B, Ig, C, D, Jh, Gc, SelA, SelB, OrderI, ...				OrderC, OrderD, OrderJ, Transient, TheNoisePlane, TheModel, LogDet, DC, Nyquist);% % scaling of the columns of the Jacobian matrix to improve the condition number % TheScale = sum(abs(Jacob.^2), 1).^0.5;% IndexZeroes = find(TheScale == 0);% TheScale(IndexZeroes) = 1;% Jacob = Jacob ./ repmat(TheScale, [size(Jacob, 1), 1]);if ~isempty(Jacob)	[u,ss,v] = svd([real(Jacob);imag(Jacob)], 0);		switch TheModel		case {'BJ','OE','ARMAX'}, mm = 1;		case 'ARMA', mm = 0;	end		switch TheNoisePlane		case {'z',''},			nn = mm;		case {'s','w'},			nn = mm + 2;			if strcmp(TheModel,'ARMAX')				nn = nn-1;			end	end		smax = ss(1,1);	smin = ss(end-nn, end-nn);	diags = diag(ss);	diags = diags(1:end-nn);	DeltaParam = -v*diag([diags./(diags.^2+Lambda);zeros(nn,1)])*(u.'*[real(Error);imag(Error)]);%     % denormalisation parameter variation%     DeltaParam = DeltaParam ./ TheScale.';else	smax = [];	smin = [];	DeltaParam = [];endif strcmp(TheModel,'BJ') | strcmp(TheModel,'OE') | strcmp(TheModel,'ARMAX')		sumA = sum(SelA);	sumB = sum(SelB);	Deltaa = zeros(1,length(SelA));	Deltaa(SelA==1) = DeltaParam(1:sumA).';	Deltab = zeros(1,length(SelB));	Deltab(SelB==1) = DeltaParam(sumA+1:sumA+sumB).';	a = a0 + Deltaa;	b = b0 + Deltab;	upper = sumA+sumB;	if Transient == 1		lower = upper+1;		upper = lower+OrderI;		Deltaig = DeltaParam(lower:upper).';		ig = ig0 + Deltaig;	else		ig = [];	end;	% normalise parameters to satisfy the norm 1 constraint	ScaleParam = norm([a b ig]);	a = a/ScaleParam;	b = b/ScaleParam;	if Transient == 1		ig = ig/ScaleParam;	end;	elseif strcmp(TheModel,'ARMA')		a = a0;	b = b0;	ig = ig0;	endif strcmp(TheModel,'BJ') | strcmp(TheModel,'ARMA') | strcmp(TheModel,'ARMAX')		if strcmp(TheModel,'ARMA')		upper = 0;	end	switch TheNoisePlane		case 'z', nn = 1;		case {'s','w'}, nn = 0;	end	lower = upper+1;	upper = lower+OrderC-nn;	Deltac = [zeros(nn,1) DeltaParam(lower:upper).'];	c = c0 + Deltac;	if strcmp(TheModel,'ARMAX')		d = a;		jh = jh0;	else		lower = upper+1;		upper = lower+OrderD-nn;		Deltad = [zeros(nn,1) DeltaParam(lower:upper).'];		d = d0 + Deltad;		if Transient == 1			lower = upper+1;			upper = lower+OrderJ;			Deltajh = DeltaParam(lower:upper).';			jh = jh0 + Deltajh;		else			jh = [];		end	end	% stabilize C polynomial otherwise:	%	- the cost function without logdet term can be made arbitrarily small	%	- the cost function with logdet term increases exponentially	% imposes also a sum constraint in 's', 'w' planes	c = BJStabilizeRoots(c, TheNoisePlane,TraceOn);	if ~strcmp(TheModel,'ARMAX')		% stabilize D polynomial (otherwise the cost function with logdet term increases exponentially)		[d, sumd] = BJStabilizeRoots(d, TheNoisePlane,TraceOn);		% in 's' and 'w' plane the constraint on the d coefficients influences the noise transient polynomial 		% imposes also a sum constraint in 's', 'w' planes		if Transient & (TheNoisePlane ~= 'z')			jh = jh/sumd;		end	end	elseif strcmp(TheModel,'OE')		c = c0;	d = d0;	jh = jh0;	endCost = BJCost(Y, U, a, b, ig, c, d, jh, s, q, Gc, Transient, LogDet, DC, Nyquist);