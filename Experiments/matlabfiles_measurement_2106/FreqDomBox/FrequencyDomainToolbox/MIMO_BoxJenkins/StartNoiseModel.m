function Theta = StartNoiseModel(data, ThetaPlant, Sel, ModelVar, IterVar, FigNum)%%	function Theta = StartNoiseModel(data, ThetaPlant, Sel, ModelVar, IterVar, FigNum) %%       Generation of staring values for the nosie model parameters H = C/D%       and Th = Ih/A. %       This function uses the siso version of the Box-Jenkins toolbox.%										%       References:%%                   Pintelon R., and J. Schoukens (2006). Box-Jenkins identification revisited - Part I: theory, Automatica, %                   vol. 42, no. 1, pp. 63-75.%%                   Pintelon R., Y. Rolain, and J. Schoukens (2006). Box-Jenkins identification revisited - Part II: applications, %                   Automatica, vol. 42, no. 1, pp. 77-84.%%                   Pintelon, R., J. Schoukens, and P. Guillaume (2007). Box-Jenkins identification revisited - Part III: multivariable %                   systems, Automatica, vol. 43, no. 5, pp. 868-875.%%                   Pintelon, R., and J. Schoukens (2012). System Identification: A Frequency Domain Approach, second edition, %                   IEEE Press-Wiley, Piscataway (USA). %%	Output parameter%%		Theta			    =	estimated value noise, and initial conditions parameters + plant model parameters %								ThetaPlant = struct('A', [], 'B', [], 'Ig', [], 'C',[],'D',[], 'Ih', [])%									Theta.A     =   1 x (OrderA+1)%                                                   	ThetaPlant.A(r) = coefficient a(r-1) of Omega^(r-1) %									Theta.B     =   ny x nu x (OrderB+1)%                                                   	ThetaPlant.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%									Theta.Ig    =   ny x (OrderIg+1) %									Theta.C     =   ny x ny x (OrderC+1)%                                                       Theta.C(i,j,r) = coefficient c(i,j,r-1) of Omega^(r-1) %									Theta.D     =	1 x (OrderD+1)%                                                       Theta.D(r) = coefficient d(r-1) of Omega^(r-1)%									Theta.Ih    =   ny x (OrderIh+1)%                                                       Theta.Ih(i,r) = coefficient ih(i,r-1) of Omega^(r-1)%%%	Input parameters%%		data				=	structure containing the non-parametric data required for the identification%									data.Y		=	output DFT spectrum, if an input is observed then ThetaPlant %                                                   should be specified to eliminate the influence of the input in Y %                                                       size ny x number of frequencies %									data.U		=	input DFT spectrum, empty if Theta is empty %                                                   %									data.freq	=	vector of frequency values (Hz), dimension: number of frequencies x 1%									data.Ts		=	sampling time (s) %%		ThetaPlant			=	estimated value plant, noise, and initial conditions parameters, %                               empty if there is no observed input or A = 1; B = 0, Ig = 0;                               %								ThetaPlant = struct('A', [], 'B', [], 'Ig', [])%									ThetaPlant.A     =   1 x (OrderA+1)%                                                           ThetaPlant.A(r) = coefficient a(r-1) of Omega^(r-1) %									ThetaPlant.B     =   ny x nu x (OrderB+1)%                                                           ThetaPlant.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%									ThetaPlant.Ig    =   ny x (OrderIg+1) %%		Sel					=	structure with fields 'C', 'D', 'Ih'%									Sel = struct('C',[],'D',[], 'Ih', [])%									Sel.C = ny x ny x (OrderC+1)%										Sel.C(i,j,r) = 1 if coeff. c(i,j,r-1) is unknown%										Sel.C(i,j,r) = 0 if coeff. c(i,j,r-1) = 0%									Sel.D = 1 x (OrderD+1)%										Sel.D(r) = 1 if coeff. d(i,j,r-1) is unknown%										Sel.D(r) = 0 if coeff. d(i,j,r-1) = 0%									Sel.Ih = ny x (OrderIh+1)%										Sel.Ih(i,r) = 1 if coeff. ih(i,r-1) is unknown%										Sel.Ih(i,r) = 0 if coeff. ih(i,r-1) = 0%%		ModelVar			=	contains the information about the model to be identified%								structure with fields 'Transient', 'ThePlane', 'TheModel', 'RecipPlant', 'RecipNoise'%									ModelVar = struct('Transient', [], 'NoisePlane', [], 'Struct', [])%									ModelVar.Transient		=	1 then the initial conditions of the plant and/or noise are estimated%									ModelVar.NoisePlane		=	plane of the noise model%																	's':	continuous-time;%																	'w':	sqrt(s)-domain%																	'z':	discrete-time;%									ModelVar.PlantPlane		=	plane of the plant model (empty if Theta is empty) %																	's':	continuous-time;%																	'w':	sqrt(s)-domain%																	'z':	discrete-time;%%		IterVar				=	contains the information about the minimization procedure%								structure with fields 'LM', 'MaxIter', 'TolParam', 'TolCost', 'TraceOn'%									IterVar = struct('LM', [], 'MaxIter', [], 'TolParam', [], 'TolCost', [], 'TraceOn', [])%									IterVar.LM 			=	1 then then Levenberg-Marquardt minimization scheme is used%									IterVar.MaxIter 	=	maximum number of itterations of the minimization procedure%									IterVar.TolParam 	=	relative precision on parameter estimates%									IterVar.TolCost 	=	relative precision on cost function%									IterVar.TraceOn 	=	1 then output iterations (optional) %%		FigNum				=	number figure if a plot must be shown%                               (optional, default 0: no plot is shown)%%% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, February 2005 % All rights reserved.% Software can be used freely for non-commercial applications only.% Version 21 October 2011%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Initialisation of the variables %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%freq = data.freq;           % frequency vectorfreq = freq(:);% Check if DC and Nyquist belong to the frequency setif data.freq(1) == 0 data.DC = 1; else data.DC = 0; endif data.freq(end) == 1/(2*data.Ts) data.Nyquist = 1; else data.Nyquist = 0; endF = length(freq);           % number of frequenciesTs = data.Ts;               % sampling periodny = size(data.Y,1);        % number of outputs% check if ThetaPlant is available or nottry     if isempty(ThetaPlant)        ThetaPlant = struct('A', 1, 'B', zeros(ny, 1, 1), 'Ig', zeros(ny, 1));        ModelVar.PlantPlane = ModelVar.NoisePlane;        data.U = zeros(1, F);    end % ifcatch	ThetaPlant = struct('A', 1, 'B', zeros(ny, 1, 1), 'Ig', zeros(ny, 1));    ModelVar.PlantPlane = ModelVar.NoisePlane;    data.U = zeros(1, F);end % trynu = size(data.U, 1);switch ModelVar.PlantPlane	case 'z', x.Plant = exp(-sqrt(-1)*2*pi*freq*Ts);	case 's', x.Plant = sqrt(-1)*2*pi*freq;	case 'w', x.Plant = (sqrt(-1)*2*pi*freq).^0.5;endswitch ModelVar.NoisePlane	case 'z', x.Noise = exp(-sqrt(-1)*2*pi*freq*Ts);	case 's', x.Noise = sqrt(-1)*2*pi*freq;	case 'w', x.Noise = (sqrt(-1)*2*pi*freq).^0.5;end% Check whether starting values for the poles are available try     if isempty(ThetaPlant.D)        NoNoisePoles = 1;    else        NoNoisePoles = 0;    end % ifcatch    NoNoisePoles = 1;end % try% figure numbertry     if isempty(FigNum)        FigNum = 0;    end % ifcatch    FigNum = 0;end % tryTheta = ThetaPlant;%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Calculation output residuals %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% plant transfer functionPolyTransPlant = MIMO_ML_CalcPolyTrans(Theta, x);% output residual V = Y - G*U - TGdummy = zeros(1, nu, F);dummy(1,:,:) = data.U;GU = squeeze(sum(PolyTransPlant.G .* repmat(dummy, [ny, 1, 1]), 2));if ny == 1    GU = GU.';end % if single outputV = data.Y - GU - PolyTransPlant.Tg;%%%%%%%%%%%%%%%%%%%%%%%%%%%% Parameters for SISO fit %%%%%%%%%%%%%%%%%%%%%%%%%%%%Gc = [];SelA = [];SelB = [];OrderA = 0;OrderB = 0;OrderI = 0;Transient = 1;OrderC = size(Sel.C,3)-1;OrderD = size(Sel.D,2)-1;OrderIh = size(Sel.Ih,2)-1;TheModel = 'ARMAdet';LevenbergMarquardt = IterVar.LM;MaxItterations = IterVar.MaxIter;TolParam = IterVar.TolParam;TolCost = IterVar.TolCost;TraceOn = IterVar.TraceOn;d = zeros(1, OrderD+1);ih = zeros(1, OrderIh+1);Theta.C = zeros(ny, ny, OrderC+1);if NoNoisePoles == 1    Theta.D = zeros(1, OrderD+1);end % if no starting values noise polesTheta.Ih = zeros(ny, OrderIh+1);ThePlane = {ModelVar.PlantPlane,ModelVar.NoisePlane};%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% fit on weighted sum noise residuals to easily fit all the poles %%																  %%			ny													  %%			sum |V(i)/std(V(i))|^2								  %%			i=1													  %%																  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if NoNoisePoles == 1    YY = (sum(abs(V./repmat(std(V,[],2),1,F)).^2,1)).^0.5;    YY = YY.';    UU = zeros(size(YY));    [aa, bb, ig1, cc, dd, jhjh, s2, Costsiso, smax, smin, Cplant, Cnoise, wscale] = BoxJenkins(YY, UU, freq, Ts, Gc, SelA, SelB, OrderI, OrderC, OrderD, OrderIh, [], [], [], [], [], [],...                                                                                                0, ThePlane, TheModel, LevenbergMarquardt, MaxItterations, TolParam, TolCost, TraceOn);    Theta.D = dd;end % if no noise poles available%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% estimate zeros noise model of each output seperately %% and use this as approximation of the diagonal of C   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%DD = polyval(fliplr(Theta.D), x.Noise);OrderD = 0;for rr = 1:ny    YY = V(rr,:).';    UU = zeros(size(YY));    [aa, bb, ig1, cc, dd, jhjh, s2, Costsiso, smax, smin, Cplant, Cnoise, wscale] = BoxJenkins(YY.*DD, UU, freq, Ts, Gc, SelA, SelB, OrderI, OrderC, OrderD, OrderIh, [], [], [], [], [], [],...                                                                                             Transient, ThePlane, TheModel, LevenbergMarquardt, MaxItterations, TolParam, TolCost, TraceOn);    Theta.C(rr,rr,:) = cc;    Theta.Ih(rr,:) = jhjh;end % rr%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Comparison parametric and non-parametric estimates noise power spectra % %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if FigNum > 0	    % parametric noise power spectrum	data.Gc = zeros(nu,ny,F);		PolyTrans = CalcPolyTrans(Theta, x);	[TheError, CovE, gF, Err] = PredError(data, PolyTrans);	Sarma = CalcPowerSpectrum(PolyTrans, CovE);        % nonparametric noise power spectrum    Vdummy = zeros(ny, 1, F);    Vdummy(:,1,:) = V;    VTdummy = conj(permute(Vdummy, [2,1,3]));    Sy = repmat(Vdummy,[1,ny,1]) .* repmat(VTdummy, [ny,1,1]);	figure(FigNum)	mm = 0;	for jj = 1:ny		for ii = 1:ny			mm = mm+1;			subplot(ny, ny, mm)			plot(freq,db(squeeze(Sy(jj,ii,:)))/2,'k+',freq,db(squeeze(Sarma(jj,ii,:)))/2,'r');            xlabel('Frequency (Hz)')            ylabel('Noise power (dB)')		end % ii	end % jj    subplot(ny, ny, ceil(ny/2))    title('data: ''+''; initial model: red');	zoom on; shg	end % if plot the results