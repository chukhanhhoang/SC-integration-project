function [Theta, Cost, smax, smin, wscale] = MIMO_BTLS(data, Sel, Theta0, ModelVar, IterVar);%%       Bootstrapped total least squares estimate plant model parameters from noisy%       input-output data. The following cases can be handled:%%           1. 1 MIMO experiment with random excitations; or the concatenation of several data records %              (see the ArbLocalPolyAnal function).  %           2. 1 MIMO experiment with periodic excitations%              (see the FastLocalPolyAnal function).  %           3. nexp >=1 MIMO experiments with periodic excitations%              (see the RobustLocalPolyAnal function for the case nu = nexp).  %%% [Theta, Cost, smax, smin, wscale] = MIMO_BTLS(data, Sel, Theta0, ModelVar, IterVar);%%					%				Stochastic framework: errors-in-variables%					Y = B/A U0 + Ig/A + NY%                   U = U0 + NU%%				System with nu inputs and ny outputs%					Y:					ny x 1 observed output%					U:					nu x 1 observed input%					NY:					ny x 1 output noise%					NU:					nu x 1 input noise%%				Model class: common denominator model%					G = B/A:			ny x nu plant transfer function%					Tg = Ig/A:			ny x 1 plant transient term%					A:					polynomial of order OrderA%					B:					ny x nu matrix polynomial of order OrderB%					Ig:					ny x 1 vector polynomial of order OrderIg%%				Coefficients polynomials in raising powers of Omega, where%					s-domain			Omega = j*2*pi*freq%					sqrt(s)-domain		Omega = sqrt(j*2*pi*freq)%					z-domain			Omega = exp(-j*2*pi*freq*Ts)%%       Reference:%%                   Pintelon R., P. Guillaume, G. Vandersteen and Y. Rolain (1998). Analyses, development and applications of TLS %                   algorithms in frequency-Domain System Identification, SIAM J. Matrix Anal. Appl., vol. 19, no. 4, pp. 983-1004.%					%%	Output parameters%%		Theta				=	estimated value plant, noise, and initial conditions parameters%								structure with fields 'A', 'B', 'Ig'%									Theta = struct('A',[],'B',[], 'Ig', [])%									Theta.A = 1 x (OrderA+1)%										Theta.A(r) = coefficient a(r-1) of Omega^(r-1) %									Theta.B = ny x nu x (OrderB+1)%										Theta.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%									Theta.Ig = ny x (OrderIg+1)%										Theta.Ig(i,r) = coefficient ig(i,r-1) of Omega^(r-1) %								Note:	all coefficients (except those for which Sel = 0) are free%										during the minimization + in each iteration step the following%										constraints are imposed:%											norm([a, vec(b), vec(ig)] = 1%%		Cost				=	value of the cost function in the last iteration step%%		smax				=	largest singular value of the Jacobian matrix%%		smin				=	smallest singular value of the Jacobian matrix%%		wscale				=	angular frequency scaling%%%	Input parameters%%		data				=	structure containing the non-parametric data required for the identification%									data.Y		=	output DFT spectra of 1 or nu independent MIMO experiments %                                                       1 MIMO experiment:   ny x F %                                                       nexp MIMO experiments: ny x nexp x F with nexp >= 1 %									data.U		=	input DFT spectra of 1 or nu independent MIMO experiments %                                                       1 MIMO experiment:   nu x F %                                                       nexp MIMO experiments: nu x nexp x F with nexp >= 1 %									data.freq	=	vector of frequency values (Hz), size: F x 1 or 1 x F %									data.Ts		=	sampling time (s)%									data.CY		=	(sample) noise covariance matrix of Y %                                                       1 MIMO experiment:   ny x ny x F %                                                       nexp MIMO experiments: ny x ny x nexp x F with nexp >= 1 %                                   data.CU     =   (sample) noise covariance matrix of U  %                                                       1 MIMO experiment:   nu x nu x F %                                                       nexp MIMO experiments: nu x nu x nexp x F with nexp >= 1 %                                   data.CYU    =   (sample) noise covariance matrix of U %                                                       1 MIMO experiment:   ny x nu x F %                                                       nexp MIMO experiments: ny x nu x nexp x F with nexp >= 1 %%		Sel					=	structure with fields 'A', 'B', 'Ig'%									Sel = struct('A',[],'B',[], 'Ig', [])%									Sel.A = 1 x (OrderA+1)%										Sel.A(r) = 1 if coeff. a(r-1) is unknown%										Sel.A(r) = 0 if coeff. a(r-1) = 0%									Sel.B = ny x nu x (OrderB+1)%										Sel.B(i,j,r) = 1 if coeff. b(i,j,r-1) is unknown%										Sel.B(i,j,r) = 0 if coeff. b(i,j,r-1) = 0%									Sel.Ig = ny x (OrderIg+1)%										Sel.Ig(i,r) = 1 if coeff. ig(i,r-1) is unknown%										Sel.Ig(i,r) = 0 if coeff. ig(i,r-1) = 0%%		Theta0				=	starting value plant, and initial conditions parameters%								structure with fields 'A', 'B', 'Ig'%									Theta0 = struct('A',[],'B',[], 'Ig', [])%									Theta0.A = 1 x (OrderA+1)%										Theta0.A(r) = coefficient a(r-1) of Omega^(r-1) %									Theta0.B = ny x nu x (OrderB+1)%										Theta0.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%									Theta0.Ig = ny x (OrderIg+1)%										Theta0.Ig(i,r) = coefficient ig(i,r-1) of Omega^(r-1) %%		ModelVar			=	contains the information about the model to be identified%								structure with fields 'Transient', 'ThePlane', 'TheModel', 'RecipPlant' %									ModelVar = struct('Transient', [], 'PlantPlane', [], 'NoisePlane', [], 'RecipPlant', [])%									ModelVar.Transient		=	1 then the initial conditions of the plant and/or noise are estimated%									ModelVar.PlantPlane		=	plane of the plant model%																	's':	continuous-time;%																	'w':	sqrt(s)-domain%																	'z':	discrete-time;%																	'':		plane not defined%									ModelVar.RecipPlant		=	1 if plant model is reciprocal: G(i,j) = G(j,i)%%		IterVar				=	contains the information about the minimization procedure%								structure with fields 'LM', 'MaxIter', 'TolParam', 'TolCost', 'TraceOn'%									IterVar = struct('LM', [], 'MaxIter', [], 'TolParam', [], 'TolCost', [], 'TraceOn', [])%									IterVar.LM              =	if 1 then the iteration stops if the corresponding ML cost %                                                               function increases   %									IterVar.MaxIter         =	maximum number of itterations of the minimization procedure%									IterVar.TolParam        =	relative precision on parameter estimates%									IterVar.TolCost         =	relative precision on cost function%									IterVar.TraceOn         =	1 then output iterations (optional)%%% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, 30 November 2009% All rights reserved.% Software can be used freely for non-commercial applications only.% Version 24 October 2011%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% initialisation of the variables, and compatibility check of the input arguments %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% model structure variablesModelVar.PlantPlane = lower(ModelVar.PlantPlane);ModelVar.Struct = 'EIV';% add number of inputs and outputs to ModelVarModelVar.ny = size(data.Y,1);ModelVar.nu = size(data.U,1);% 1. imposes the compatibility of the parameter vector Theta0 and%    the free model parameters with the model structure% 2. puts the order of the polynomials in ModelVar[Theta0, Sel, ModelVar] = MIMO_ML_ModelCompatibility(Theta0, Sel, ModelVar);% check if DC and Nyquist belong to the frequency setif data.freq(1) == 0, data.DC = 1; else data.DC = 0; endif data.freq(end) == 1/(2*data.Ts), data.Nyquist = 1; else data.Nyquist = 0; end data.freq = data.freq(:);% determine the number of MIMO experimentsNumberDim = length(size(data.U));           % number of matrix dimensionsif NumberDim == 2    data.NumberExp = 1;                     % number of MIMO experimentselseif NumberDim == 3    data.NumberExp = size(data.U, 2);       % number of MIMO experimentsend % if% jw, sqrt(jw), or exp(-jwTs) values for plant and noise modelx = struct('Plant', []);% matrix of powers of x xMat = struct('Plant', []);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% domain of the plant model %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% the vector s represents z^-1, s, or sqrt(s) of the plant modelswitch ModelVar.PlantPlane	case {'s','w'}		if ModelVar.PlantPlane == 's'			x.Plant = sqrt(-1)*2*pi*data.freq;		elseif ModelVar.PlantPlane == 'w'			x.Plant = (sqrt(-1)*2*pi*data.freq).^(0.5);		end;		wscale = median(abs(x.Plant));		x.Plant = x.Plant/wscale;	case 'z'		x.Plant = exp(-sqrt(-1)*2*pi*data.freq*data.Ts);		wscale = 1;	case ''		x.Plant = ones(size(data.freq));		wscale = 1;	otherwise, disp('Invalid plant plane ...'), returnendnmax = max([ModelVar.na, ModelVar.nb, ModelVar.nig]);xMat.Plant = MIMO_ML_CalcOmegaMat(x.Plant, nmax);% normalize the starting values for s-, and sqrt(s)-domainsTheta0 = MIMO_ML_Normalise(Theta0, wscale, ModelVar);%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% maximum likelihood estimate of the model parameters %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% cost function starting valuesCost = MIMO_ML_Cost(data, Theta0, x, ModelVar);% initialisation itertation parametersMaxRelErr = NaN;RelVarCost = NaN;DeltaCost = NaN;OldTheta = Theta0;OldCost = Cost;OldMaxRelErr = MaxRelErr;OldRelVarCost = RelVarCost;OldDeltaCost = DeltaCost;if IterVar.TraceOn == 1    home    disp(['BTLS iteration # ',int2str(0)]);    fprintf('condition number: NaN \n');	fprintf('maximum relative variation parameters: %e \n',MaxRelErr);	fprintf('cost function (delta cost): %e (%e ) \n',Cost,DeltaCost);end% starting values onlyif IterVar.MaxIter < 1	Theta = OldTheta;endiii = 0;while iii <= IterVar.MaxIter	 iii = iii + 1;     % parametric transfer function estimate    PolyTrans = MIMO_ML_CalcPolyTrans(OldTheta, x);        % weighting linear least squares cost function    data.W = MIMO_Calc_IQML_Weight(data, PolyTrans);        % weighted linear least squares estimate    [Theta, smax, smin, wscale] = MIMO_WGTLS(data, Sel, ModelVar);        % normalise the parameters    Theta = MIMO_ML_Normalise(Theta, wscale, ModelVar); 	Cost = MIMO_ML_Cost(data, Theta, x, ModelVar);		if ~(IterVar.LM && (Cost > OldCost))        				% estimated parameters polynomial A		A = Theta.A(Sel.A == 1);		OldA = OldTheta.A(Sel.A == 1);		MaxRelErr = max([abs((A - OldA)./A)]);				% estimated parameters ny x nu matrix polynomial B		for ii = 1:ModelVar.ny			for jj = 1:ModelVar.nu				B = squeeze(Theta.B(ii, jj, Sel.B(ii,jj,:) == 1)).';				OldB = squeeze(OldTheta.B(ii, jj, Sel.B(ii,jj,:) == 1)).';				MaxRelErr = max([MaxRelErr, abs((B - OldB)./B)]);			end % jj		end % ii				% estimated parameters ny x 1 vector polynomial Ig		for ii = 1:ModelVar.ny			Ig = Theta.Ig(ii, Sel.Ig(ii,:) == 1);			OldIg = OldTheta.Ig(ii, Sel.Ig(ii,:) == 1);			MaxRelErr = max([MaxRelErr, abs((Ig - OldIg)./Ig)]);		end % ii				DeltaCost = Cost - OldCost;			RelVarCost = abs(DeltaCost)/Cost;		OldTheta = Theta;		OldCost = Cost;		OldMaxRelErr = MaxRelErr;		OldRelVarCost = RelVarCost;		OldDeltaCost = DeltaCost;            end         % restore the previous estimates and stop the iteration    if IterVar.LM && (Cost > OldCost)                 Theta = OldTheta;        Cost = OldCost;        MaxRelErr = OldMaxRelErr;        RelVarCost = OldRelVarCost;        DeltaCost = OldDeltaCost;        iii = IterVar.MaxIter + 1;		    end		if (IterVar.TraceOn && (iii ~= IterVar.MaxIter + 1))				home		disp(['BTLS iteration # ',int2str(iii)]);		disp(['condition number:',num2str(smax/smin)]);		disp(['maximum relative variation parameters: ',num2str(MaxRelErr)]);	 	disp(['cost function (delta cost): ',num2str(Cost),' (',num2str(DeltaCost),')']);			end % if trace on		if (MaxRelErr < IterVar.TolParam) | (RelVarCost < IterVar.TolCost)		iii = IterVar.MaxIter + 1;	end % if relative variation parameters or cost function is small enough	end % while main iteration loop%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% denormalize the estimated parameters for s-, and sqrt(s)-domains %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Theta = MIMO_ML_DeNormalise(Theta, wscale, ModelVar);