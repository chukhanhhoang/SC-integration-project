function [Theta, Cost, smax, smin] = MIMO_ML_NewtonGaussStep(data, x, xMat, OldTheta, Sel, ModelVar, Lambda);%%%	[Theta, Cost, smax, smin] = MIMO_ML_NewtonGaussStep(data, x, xMat, OldTheta, Sel, ModelVar, Lambda)%%%	Output parameters%%		Theta		=	new estimate plant, noise, and initial conditions parameters%						structure with fields 'A', 'B', 'Ig'%							Theta = struct('A',[],'B',[], 'Ig', [])%							Theta.A = 1 x (OrderA+1)%								Theta.A(r) = coefficient a(r-1) of Omega^(r-1) %							Theta.B = ny x nu x (OrderB+1)%								Theta.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%							Theta.Ig = ny x (OrderIg+1)%								Theta.Ig(i,r) = coefficient ig(i,r-1) of Omega^(r-1) %						Note:	all coefficients (except those for which Sel = 0) are free%								during the minimization + in each iteration step the following%								constraints are imposed:%									norm([a, vec(b), vec(ig)] = 1%%		Cost		=	value of the cost function in the last iteration step%%		smax		=	largest singular value of the Jacobian matrix%%		smin		=	smallest singular value of the Jacobian matrix%%%	Input parameters%%		data		=	structure containing the non-parametric data required for the identification%							data.Y          =	output DFT spectra of 1 or nu independent MIMO experiments %                                                   1 MIMO experiment:   ny x F %                                                	nu MIMO experiments: ny x nu x F %							data.U          =	input DFT spectra of 1 or nu independent MIMO experiments %                                                	1 MIMO experiment:   nu x F %                                               	nu MIMO experiments: nu x nu x F %							data.freq       =	vector of frequency values (Hz), size: F x 1%							data.Ts         =	sampling time (s)%							data.CY         =	(sample) noise covariance matrix of Y %                                               	1 MIMO experiment:   ny x ny x F %                                                	nu MIMO experiments: ny x ny x nu x F %                           data.CU         =   (sample) noise covariance matrix of U  %                                                   1 MIMO experiment:   nu x nu x F %                                                	nu MIMO experiments: nu x nu x nu x F %                           data.CYU        =   (sample) noise covariance matrix of U %                                                	1 MIMO experiment:   ny x nu x F %                                               	nu MIMO experiments: ny x nu x nu x F %							data.sqrtCYinv	=	CY^(-0.5); if OE %                                                	1 MIMO experiment:   ny x ny x F %                                               	nu MIMO experiments: ny x ny x nu x F %							data.DC			=	1 if DC present otherwise 0%							data.Nyquist	=	1 if Nyquist frequency present otherwise 0%                           data.NumberExp  =   number of independent MIMO experiments (1 or nu) %%		x			=	structure containing (jwk) or (zk^-1) values%							x.Plant	=	plant model, size: F x 1%%		xMat		=	structure with tables of powers of (jwk)^r or (zk^-r)%							xMat.Plant		=	plant model, size: F x max order%%		OldTheta	=	previous estimate plant, noise, and initial conditions parameters%						structure with fields 'A', 'B', 'Ig'%						OldTheta = struct('A',[],'B',[], 'Ig', [])%							OldTheta.A = 1 x (OrderA+1)%								OldTheta.A(r) = coefficient a(r-1) of Omega^(r-1) %							OldTheta.B = ny x nu x (OrderB+1)%								OldTheta.B(i,j,r) = coefficient b(i,j,r-1) of Omega^(r-1)%							OldTheta.Ig = ny x (OrderIg+1)%								OldTheta.Ig(i,r) = coefficient ig(i,r-1) of Omega^(r-1) %						Note:	all coefficients (except those for which Sel = 0) are free%								during the minimization + in each iteration step the following%								constraints are imposed:%									norm([a, vec(b), vec(ig)] = 1%%		Sel			=	structure with fields 'A', 'B', 'Ig'%							Sel = struct('A',[],'B',[], 'Ig', [])%							Sel.A = 1 x (OrderA+1)%								Sel.A(r) = 1 if coeff. a(r-1) is unknown%								Sel.A(r) = 0 if coeff. a(r-1) = 0%							Sel.B = ny x nu x (OrderB+1)%								Sel.B(i,j,r) = 1 if coeff. b(i,j,r-1) is unknown%								Sel.B(i,j,r) = 0 if coeff. b(i,j,r-1) = 0%							Sel.Ig = ny x (OrderIg+1)%								Sel.Ig(i,r) = 1 if coeff. ig(i,r-1) is unknown%								Sel.Ig(i,r) = 0 if coeff. ig(i,r-1) = 0%%		ModelVar		=	contains the information about the model to be identified%							structure with fields 'Transient', 'ThePlane', 'TheModel', 'Reciprocal', ...%								ModelVar.Transient		=	1 then the initial conditions of the plant and/or noise are estimated%								ModelVar.PlantPlane		=	plane of the plant model%																's':	continuous-time;%																'w':	sqrt(s)-domain%																'z':	discrete-time;%																'':		plane not defined%								ModelVar.Struct			=	model structure%                                                               'EIV':  errors-in-variables (noisy input-output data)%                                                               'OE':	generalised output error (known input, noisy output)%								ModelVar.RecipPlant		=	1 if plant model is reciprocal: G(i,j) = G(j,i)%								ModelVar.nu				=	number of inputs%								ModelVar.ny				= 	number of outputs%								ModelVar.na				=	order polynomial A%								ModelVar.nb				= 	order matrix polynomial B%								ModelVar.nig			=	order vector polynomial Ig%		Lambda			=	Levenberg-Marquardt parameter%%% Copyright (c) Rik Pintelon, Vrije Universiteit Brussel - dept. ELEC, November 2009% All rights reserved.% Software can be used freely for non-commercial applications only.%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% initialisation of the variables %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%F = length(data.freq);                          % number of frequenciesNumberExp = data.NumberExp;                     % number of independent MIMO experimentsny = ModelVar.ny;                               % number of outputsnu = ModelVar.nu;                               % number of inputsna = ModelVar.na;                               % order A polynomialnb = ModelVar.nb;                               % order B matrix polynomialnig = ModelVar.nig;                             % order Ig vector polynomialntheta = (na+1) + (nb+1)*nu*ny + (nig+1)*ny;    % total number of parametersTheJacob = zeros(NumberExp*ny*F, ntheta);       % the jacobian matrix of all MIMO experimentsTheError = zeros(NumberExp*ny*F, 1);            % the prediction error vector of all MIMO experimentsdataee = data;                                  % information about 1 MIMO experiment (see below)dataee.Y = zeros(ny, F);                        % output of 1 MIMO experimentdataee.U = zeros(nu, F);                        % input of 1 MIMO experimentdataee.CY = zeros(ny, ny, F);                   % output covariance of 1 MIMO experimentswitch ModelVar.Struct    case 'EIV'        dataee.CU = zeros(nu, nu, F);           % input covariance of 1 MIMO experiment        dataee.CYU = zeros(ny, nu, F);          % output-input covariance of 1 MIMO experiment    case 'OE'        dataee.sqrtCYinv = zeros(ny, ny, F);end % switch%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% calculate the variation of the free model parameters %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% transfer functions and polynomialsPolyTrans = MIMO_ML_CalcPolyTrans(OldTheta, x);for ee = 1:NumberExp        % data of MIMO experiment no. ee    if NumberExp > 1        dataee.Y(:,:) = data.Y(:,ee,:);        dataee.U(:,:) = data.U(:,ee,:);        dataee.CY(:,:,:) = data.CY(:,:,ee,:);         switch ModelVar.Struct            case 'EIV'                dataee.CU(:,:,:) = data.CU(:,:,ee,:);                dataee.CYU(:,:,:) = data.CYU(:,:,ee,:);                          case 'OE'                dataee.sqrtCYinv(:,:,:) = data.sqrtCYinv(:,:,ee,:);        end % switch    else % 1 MIMO experiment        dataee.Y(:,:) = data.Y;        dataee.U(:,:) = data.U;        dataee.CY(:,:,:) = data.CY;        switch ModelVar.Struct            case 'EIV'                dataee.CU(:,:,:) = data.CU;                dataee.CYU(:,:,:) = data.CYU;                          case 'OE'                dataee.sqrtCYinv(:,:,:) = data.sqrtCYinv;        end % switch    end % if more than 1 MIMO experiment        % calculate a hermitian square root of the inverse      % of the covariance of the output error (NY-G*NU).    switch ModelVar.Struct        case 'EIV'            PolyTrans = MIMO_ML_InvCovOutputError(dataee, PolyTrans);        case 'OE'            PolyTrans.sqrtCEinv = dataee.sqrtCYinv;    end % switch    % prediction Error, and sample covariance matrix CovE of the prediction error    Error = MIMO_ML_PredError(dataee, PolyTrans);    % Jacobian matrix of prediction error w.r.t. ALL model parameters    Jacob = MIMO_ML_Jacob(dataee, xMat, Error, PolyTrans, ModelVar);    % put the different frequency contributions on top of each other    % frequency contributions on top of each other    % size Jacob in: ny x ntheta x F    % size Jacob out: ny*F x ntheta    Jacob = reshape(permute(Jacob, [1,3,2]), [ny*F, ntheta]);        % put experiment no. ee in the Jacobian matrix and prediction error vector    SelectRows = [(ee-1)*ny*F+1:ee*ny*F];    TheError(SelectRows) = Error(:);    TheJacob(SelectRows, :) = Jacob;   end % ee, number of MIMO experiments% impose the common parameter structure and eliminate the excess parameters % size Jacob in: ny*F x ntheta% size Jacob out: ny*F x number of free model parametersTheJacob = MIMO_ML_AddSelectColumns(TheJacob, Sel, ModelVar);% scaling of the columns of the Jacobian matrix to improve the condition number TheScale = sum(abs(TheJacob.^2), 1).^0.5;IndexZeroes = find(TheScale == 0);TheScale(IndexZeroes) = 1;TheJacob = TheJacob ./ repmat(TheScale, [size(TheJacob, 1), 1]);% calculate the parameter variation DeltaParam[u, ss, v] = svd([real(TheJacob); imag(TheJacob)], 0);nn =1;smax = ss(1,1);smin = ss(end-nn, end-nn);diags = diag(ss);diags = diags(1:end-nn);DeltaParam = -v*diag([diags./(diags.^2+Lambda); zeros(nn,1)])*(u.'*[real(TheError);imag(TheError)]);% denormalisation parameter variationDeltaParam = DeltaParam ./ TheScale.';%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% extract the plant model parameters from DeltaParam %% order in DeltaParam: a, b, ig                      %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Theta = MIMO_ML_ExtractParam(DeltaParam, OldTheta, Sel);	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% Impose constraints on updated parameters %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%Theta = MIMO_ML_Constrain(Theta, ModelVar);%%%%%%%%%%%%%%%%%% cost function %%%%%%%%%%%%%%%%%%Cost = MIMO_ML_Cost(data, Theta, x, ModelVar);