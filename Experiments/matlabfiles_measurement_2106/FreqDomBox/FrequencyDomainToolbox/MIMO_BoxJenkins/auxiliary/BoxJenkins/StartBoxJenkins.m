function [a, b, ig, varY] = StartBoxJenkins(Y, U, freq, Ts, SelA, SelB, OrderI, ThePlane, Feedback, LevenbergMarquardt,...                                            MaxItterations, TolParam, TolCost, TraceOn)%%%	[a, b, ig, varY] = StartBoxJenkins(Y, U, freq, Ts, SelA, SelB, OrderI, ThePlane, Feedback, LevenbergMarquardt,...%                                      MaxItterations, TolParam, TolCost, TraceOn)%%		Identification of a linear dynamic system in the frequency domain%		for arbitrary excitations using a nonparametric noise model%		and a continous-time, discrete-time, or sqrt(s)-time plant model%%	output parameters%% 		a					=	plant denominator parameters% 		b					=	plant numerator parameters% 		ig					=	plant initial and final conditions parameters% 		varY				=	nonparametric noise model: the complex variance of the % 								output at the frequencies defined in freq%%	input parameters%		Y					=	output Fourier coefficients%		U					=	input Fourier coefficients%		freq				=	frequency vector; for discrete-time normalised on the sampling frequency%		Ts					=	sampling time%		SelA				=	if 1 then coeff. A-polynomial is unknown; if zero the coeff. is known equal to zero%		SelB				=	if 1 then coeff. B-polynomial is unknown; if zero the coeff. is known equal to zero%		OrderI				=	order numerator polynomial 1st transient model%		ThePlane			=	's' => continuous-time; 'z' => discrete-time models; 'w' => sqrt(s)-domain%		Feedback			=	1 the correction for feedback is included%		LevenbergMarquardt	=	if LevenbergMarquardt = 1 then Levenberg-Marquardt minimization scheme is used%		MaxItterations		=	maximum number of itterations of the minimization procedure%		TolParam			=	relative precision on parameter estimates%		TolCost				=	relative precision on cost function%		TraceOn				=	if TracOn == 1 then output itterations%% Johan Schoukens, 6 March 1998 (a rainy afternoon)% Modified by Rik Pintelon, April 1, 2004 (not a joke!)%freq = freq(:);Y = Y(:);U = U(:);if ThePlane == 'z'	q = exp(-sqrt(-1)*freq*2*pi*Ts);elseif ThePlane == 's'	q = sqrt(-1)*freq*2*pi;elseif ThePlane == 'w'	q = sqrt(sqrt(-1)*freq*2*pi);end% na = length(SelA)-1;% nb = length(SelB)-1;OrderA = length(SelA)-1;OrderB = length(SelB)-1;if nargin < 8, Feedback = 0; end  % check for identification under feedback%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% initial estimate of the noise model, no system parameters used %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% first rough initial noise model without using model knowledgevarY = varest(Y,U);% GTLS-estimate without transientTransient = 0;TheWeight = YvesWeight(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, OrderA, OrderB, ThePlane);[agtls, bgtls, tgtls, Costgtls, smax, smin] = WGTLS(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, Transient, ThePlane, TheWeight, 0);% BTLS-estimate without transient[abtls, bbtls, tbtls, Costbtls, smax, smin] = BTLS(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, agtls, bgtls, tgtls,...													1, Transient, ThePlane, MaxItterations, TolParam, TolCost, 0, TraceOn);% ML-estimate without transient[a, b, ig, Tauml, Costml, smax, smin] = ML(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, abtls, bbtls, tbtls, 0,...											Transient, 0, ThePlane, LevenbergMarquardt, MaxItterations, TolParam, TolCost, 0, TraceOn);% [pvectz]=elis(fiddata(Y,U,freq,varY,zeros(size(freq))),'z',nb,na,struct('fs',1)); % initialization without transients% [domain,b,a,delay,fs,Znum,Zdenom,comments,fdate,ig]=imppar(pvectz);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% improved estimate, no transient information used in noise estimate %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% second rough initial noise model without transient knowledgeG = polyval(fliplr(b),q)./polyval(fliplr(a),q);varY = varest(Y,U,G);% ML-estimate with transientTransient = 1;ig = zeros(1,OrderI+1);[a, b, ig, Tauml, Costml, smax, smin] = ML(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, a, b, ig, 0,...											Transient, 0, ThePlane, LevenbergMarquardt, MaxItterations, TolParam, TolCost, 0, TraceOn);% [pvectz]=elis(fiddata(Y,U,freq,varY,zeros(size(freq))),'z',nb,na,struct('fs',1,'transients','on','initmodel',fidmodel('z^-1',b,a,0,1)));% [domain,b,a,delay,fs,Znum,Zdenom,comments,fdate,ig]=imppar(pvectz);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% full estimate, including the transient estimate in noise estimate %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%loop = 1;		% loop: number of updates of the nonparametric noise modelfor k=1:loop	% improved estimate using the robust noise variance estimates	G = polyval(fliplr(b),q)./polyval(fliplr(a),q); 	Ig = polyval(fliplr(ig),q)./polyval(fliplr(a),q); 	varY = varest(Y,U,G,Ig);		% ML-estimate with transient	[a, b, ig, Tauml, Costml, smax, smin] = ML(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, a, b, ig, 0,...												Transient, 0, ThePlane, LevenbergMarquardt, MaxItterations, TolParam, TolCost, 0, TraceOn);% 	[pvectz]=elis(fiddata(Y,U,freq,varY,zeros(size(freq))),'z',nb,na,struct('fs',1,'transients','on','initmodel',fidmodel('z^-1',b,a,0,1)));% 	[domain,b,a,delay,fs,Znum,Zdenom,comments,fdate,ig]=imppar(pvectz);	end%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% refine if feedback present %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if Feedback == 1	% refine the estimates for feedback	for k = 1:loop*2				G = polyval(fliplr(b),q)./polyval(fliplr(a),q); 		Ig = polyval(fliplr(ig),q)./polyval(fliplr(a),q); 		varY = varest(Y,U,G,Ig,'on');						% ML-estimate with transient		[a, b, ig, Tauml, Costml, smax, smin] = ML(Y, U, varY, zeros(size(varY)), zeros(size(varY)), q, SelA, SelB, OrderI, a, b, ig, 0,...													Transient, 0, ThePlane, LevenbergMarquardt, MaxItterations, TolParam, TolCost, 0, TraceOn);		% 		[pvectz]=elis(fiddata(Y,U,freq,varY,zeros(size(freq))),'z',nb,na,struct('fs',1,'transients','on','initmodel',fidmodel('z^-1',b,a,0,1)));% 		[domain,b,a,delay,fs,Znum,Zdenom,comments,fdate,ig]=imppar(pvectz);		endend