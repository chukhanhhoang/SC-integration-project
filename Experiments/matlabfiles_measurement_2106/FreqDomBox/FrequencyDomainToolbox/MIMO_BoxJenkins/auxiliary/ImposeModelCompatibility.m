function [Theta0, Sel, ModelVar] = ImposeModelCompatibility(Theta0, Sel, ModelVar);%% function [Theta0, Sel, ModelVar] = ImposeModelCompatibility(Theta0, Sel, ModelVar);%%	The coefficients are chosen such that Y = B/A U + Ig/A + C/D E + Ih/D%	is valid for the BJ, OE, ARMA, and ARMAX model structures%%	Input/Output parameters%%		Theta0				=	starting value plant, noise, and initial conditions parameters%								Theta0 = struct('A',[],'B',[], 'Ig', [], 'C',[],'D',[], 'Ih', [])%									Theta0.A = 1 x (OrderA+1)%										Theta0.A(r) = coefficient a(r-1) of Omega^(r-1) %									Theta0.B = ny x nu x (OrderB+1)%										Theta0.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%									Theta0.Ig = ny x (OrderIg+1)%										Theta0.Ig(i,r) = coefficient ig(i,r-1) of Omega^(r-1) %									Theta0.C = ny x ny x (OrderA+1)%										Theta0.C(i,j,r) = coefficient c(i,j,r-1) of Omega^(r-1) %									Theta0.D = 1 x (OrderD+1)%										Theta0.D(r) = coefficient d(r-1) of Omega^(r-1)%									Theta0.Ih = ny x (OrderIh+1)%										Theta0.Ih(i,r) = coefficient ih(i,r-1) of Omega^(r-1)%%		Sel					=	selects the parameters to be estimated; 1 = estimated; 0 = known %								Sel = struct('A',[],'B',[], 'Ig', [], 'C',[],'D',[], 'Ih', [])%									Sel.A = 1 x (OrderA+1)%										Sel.A(r) = 1 if coeff. a(r-1) is unknown%										Sel.A(r) = 0 if coeff. a(r-1) = 0%									Sel.B = ny x nu x (OrderB+1)%										Sel.B(i,j,r) = 1 if coeff. b(i,j,r-1) is unknown%										Sel.B(i,j,r) = 0 if coeff. b(i,j,r-1) = 0%									Sel.Ig = ny x (OrderIg+1)%										Sel.Ig(i,r) = 1 if coeff. ig(i,r-1) is unknown%										Sel.Ig(i,r) = 0 if coeff. ig(i,r-1) = 0%									Sel.C = ny x ny x (OrderC+1)%										Sel.C(i,j,r) = 1 if coeff. c(i,j,r-1) is unknown%										Sel.C(i,j,r) = 0 if coeff. c(i,j,r-1) = 0%									Sel.D = 1 x (OrderD+1)%										Sel.D(r) = 1 if coeff. d(r-1) is unknown%										Sel.D(r) = 0 if coeff. d(r-1) = 0%									Sel.Ih = ny x (OrderIh+1)%										Sel.Ih(i,r) = 1 if coeff. ih(i,r-1) is unknown%										Sel.Ih(i,r) = 0 if coeff. ih(i,r-1) = 0%%		ModelVar			=	contains the information about the model to be identified%								structure with fields 'Transient', 'ThePlane', 'TheModel', 'Reciprocal'%									ModelVar = struct('Transient', [], 'PlantPlane', [], 'NoisePlane', [], 'Struct', [], 'Reciprocal',[])%									ModelVar.Transient		=	1 then the initial conditions of the plant and/or noise are estimated%									ModelVar.PlantPlane		=	plane of the plant model%																	's':	continuous-time;%																	'w':	sqrt(s)-domain%																	'z':	discrete-time;%																	'':		plane not defined%									ModelVar.NoisePlane		=	plane of the noise model%																	's':	continuous-time;%																	'w':	sqrt(s)-domain%																	'z':	discrete-time;%																	'':		plane not defined%									ModelVar.Struct			=	model structure%																	'BJ':		Box-Jenkins%																	'OE':		output error (plant model only)%																	'ARMA':		autoregressive moving average (noise model only)%																	'ARMAX':	autoregressive moving average with exogenous input%									ModelVar.DiagNoiseModel	=	1 if noise model is diagonal%									ModelVar.RecipPlant		=	1 if plant model is reciprocal: G(i,j) = G(j,i)%									ModelVar.RecipNoise		=	1 if noise model is reciprocal: H(i,j) = H(j,i)%									ModelVar.nu				=	number of inputs%									ModelVar.ny				= 	number of outputs%									ModelVar.na				=	order polynomial A%									ModelVar.nb				= 	order matrix polynomial B%									ModelVar.nig			=	order vector polynomial Ig%									ModelVar.nc				=	order matrix polynomial C%									ModelVar.nd				=	order polynomial D%									ModelVar.nih			=	order vector polynomial Ih%%% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, 2004 % All rights reserved.% Software can be used freely for non-commercial applications only.% Version April 2008%ny = ModelVar.ny;	% number of outputsnu = ModelVar.nu;	% number of inputs%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% for an OE model structure the noise model has no dynamics %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if strcmp(ModelVar.Struct, 'OE')	Sel.C = zeros(ny,ny,1);	Sel.D = 0;	Sel.Ih = zeros(ny,1);	Theta0.C = eye(ny);	Theta0.D = 1;	Theta0.Ih = zeros(ny,1);    ModelVar.NoisePlane = '';end % if OE%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% for an ARMA model structure the plant model does not exist %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if strcmp(ModelVar.Struct, 'ARMA')	Sel.A = 0;	Sel.B = zeros(ny,nu,1);	Sel.Ig = zeros(ny,1);	Theta0.A = 1;	Theta0.B = zeros(ny,nu);	Theta0.Ig = zeros(ny,1);    ModelVar.PlantPlane = '';end % if ARMA%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% for an ARMAX model structure the plant and noise transient terms are %% indistinguishable and the plant and noise models have the same poles %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if strcmp(ModelVar.Struct, 'ARMAX')	Sel.D = zeros(size(Sel.A));	Sel.Ih = zeros(ny,1);	Theta0.D = Theta0.A;	Theta0.Ih = zeros(ny,1);    ModelVar.NoisePlane = ModelVar.PlantPlane;end % if ARMAX%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% if no transient terms are estimated then the plant and %% noise transient parameters do not exist                %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if ~ModelVar.Transient	Sel.Ig = zeros(ny,1);	Sel.Ih = zeros(ny,1);	Theta0.Ig = zeros(ny,1);	Theta0.Ih = zeros(ny,1);end % if no transient%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% imposes the common plant and noise model parameter structure for the reciprocal case %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% plant model %%%%%%%%%%%%%%%%if ModelVar.RecipPlant		if ~strcmp(ModelVar.Struct, 'ARMA')			for jj = 1:nu							% column index			for ii = 1+jj:ny					% row index				lji = jj + ny*(ii-1);			% block position coefficients b(jj,ii) polynomial						% reciprocity plant model						if lji <= nu*ny					% test for rectangular matrices					Sel.B(jj,ii,:) = zeros(size(Sel.B(jj,ii,:)));					Theta0.B(jj,ii,:) = Theta0.B(ii,jj,:);				end % if								end % ii		end % jj	end % if not ARMAend % if reciprocal plant%%%%%%%%%%%%%%%% noise model %%%%%%%%%%%%%%%%	if ModelVar.RecipNoise		if ~strcmp(ModelVar.Struct, 'OE')				for jj = 1:ny							% column index			for ii = 1+jj:ny					% row index							% reciprocity noise model				Sel.C(jj,ii,:) = zeros(size(Sel.C(jj,ii,:)));							end % ii		end % jj		% rotate the polynomial matrix to make it as symmetric as possible		Theta0.C = MakeSymmetric(Theta0.C);		% impose symmetry when the matrix after rotation is not symmetric        nc = size(Theta0.C,3)-1;		for ll = 1:nc+1				Theta0.C(:,:,ll) = (Theta0.C(:,:,ll) + Theta0.C(:,:,ll).')/2;			end % ll	end % if not OEend % if reciprocal noise model%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% add the orders of the polynomials to ModelVar  %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%ModelVar.na = size(Sel.A,2) - 1;	% order polynomial AModelVar.nb = size(Sel.B,3) - 1;	% order matrix polynomial BModelVar.nig = size(Sel.Ig,2) - 1;	% order vector polynomial IgModelVar.nc = size(Sel.C,3) - 1;	% order matrix polynomial CModelVar.nd = size(Sel.D,2) - 1;	% order polynomial DModelVar.nih = size(Sel.Ih,2) - 1;	% order vector polynomial Ih%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% check whether the noise model transfer function is diagonal or not %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%if ~strcmp(ModelVar.Struct, 'OE')		ny = ModelVar.ny;	SumSel = 0;		for jj = 1:ny		for ii = 1+jj:ny			SumSel = SumSel + sum(squeeze(Sel.C(ii,jj,:) + Sel.C(jj,ii,:)));		end % ii	end % jj		if ~(SumSel == 0)		SumSel = 1;	end		ModelVar.DiagNoiseModel = ~SumSel;	else	ModelVar.DiagNoiseModel = 1;end % if not OE% diagonal C-matrix has less parameters than a symmetric C-matrixif ModelVar.DiagNoiseModel	ModelVar.RecipNoise = 0;end % if diagonal C