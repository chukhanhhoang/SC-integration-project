%% Experiment setting
SimulateOrMeasure  = 0; % 0 for simulating, any other number for measuring
t_experiment = 10;

%% Controller settings
controllerFilename = "LQG_ball.slx";

load("ModelParameters.mat")
I_b = 2.2578e-05;

Ab = [0 1 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
Bb = [0 0; 0 g/(1+I_b/(m_b*r_b^2)); 0 0; -g/(1+I_b/(m_b*r_b^2)) 0];
Cb = [1 0 0 0; 0 0 1 0];

ballSystem = ss(Ab,Bb,Cb,zeros(2,2));
Q = [4 0 0 0;0 0.1 0 0;0 0 4 0;0 0 0 0.1];
R = 0.5*eye(2);
% ballLQRgain = lqr(ballSystem, Q, R);
% eig(Ab-Bb*ballLQRgain)
ballLQRgain = place(Ab,Bb,[-2.5 -2.49 -2.5 -2.51]);

ballFFgain = [-1/(m_b*g)*(m_b+I_b/r_b^2);1/(m_b*g)*(m_b+I_b/r_b^2)];

% Designed controller
G = 10000;
L1 = tf([1/((200/3)) 1], [1/((200*3)) 1]);
L2 = tf([1/((200/6)) 1], [1/((200*6)) 1]);

Controller = G * L1 * L2; 
numc_mi = Controller.Numerator{1};
denc_mi = Controller.Denominator{1};

%% Load enviroment settings (Do not change)
addpath("../Controllers")
if (SimulateOrMeasure == 0)
    % Simulation 
    addpath("../Simulation/RefferenceModel")
    load("ModelParameters.mat")
else
    % Measurement
    addpath("../Measurements/RefferenceModel")
    load("MeasureParameters.mat")
    UseUserDefinedPlateReference = true;
    UseUserDefinedBallReference = true;
end
  
%% Simulation settings
if (SimulateOrMeasure == 0) % (Do not change)
    UseNonlinearPlant = 1;
    SimulateEncoders = 1;
    SimulateCamera = 1;
    SimulateTimeDelays = 0; % Note: enabling this results in strange behavior
    SimulateFriction = 0; % Note: not jet implemented
    UseUserDefinedPlateReference = 1;
    UseUserDefinedBallReference = 1;

    ts_plateRef = ts_mp;
    ts_BallRef = ts_camera;

    % Create reference
    Pp_Aref_in = zeros(1,round(t_experiment/ts_plateRef));
    Pp_Bref_in = zeros(1,round(t_experiment/ts_plateRef));
    Pp_Cref_in = zeros(1,round(t_experiment/ts_plateRef));
    Pb_Xref_in = zeros(1,round(t_experiment/ts_BallRef));
    Pb_Yref_in = zeros(1,round(t_experiment/ts_BallRef));
end % (Do not change)

%% Measurement settings
if (SimulateOrMeasure == 0) % (Do not change)
    % Will likely remain empty
end % (Do not change)

%% Perform Experiment (Do not change)
if (SimulateOrMeasure == 0)
    % Setup simulation
    load_system("BallAndPlateSimulation.slx");
    set_param('BallAndPlateSimulation/Controller', 'ModelFile', controllerFilename)

    % Run simulation
    out = sim("BallAndPlateSimulation.slx");
    close_system("BallAndPlateSimulation.slx",0);
else
    % Setup measurement system
    disp("Loading measurement model");
    load_system("BallAndPlateMeasurement.slx");
    configSet = getActiveConfigSet('BallAndPlateMeasurement');
    load_system(controllerFilename);
    [pathstr, name, ext] = fileparts(controllerFilename);
    try
        set_param(configSet,'Name','Build');
        attachConfigSetCopy(name, configSet)
    catch
        % Do nothing
    end
    setActiveConfigSet(name,'Build');
    set_param('BallAndPlateMeasurement/Run/Controller', 'ModelFile', controllerFilename);
    save_system(name);
    
    % Build measurement model
    Simulink.fileGenControl('set', 'CacheFolder', "BuildDir/Cache", 'CodeGenFolder', "BuildDir", 'createDir', true);
    disp("Building measurement model");
    rtwbuild('BallAndPlateMeasurement');
    setActiveConfigSet(name,'Configuration');
    close_system(name, 0);
    close_system("BallAndPlateSimulation.slx",0);
    
    % Wait for measurement results
    disp("Once the measurement is completed and the data is saved to ""Measurement.mat"", press any key to continue.");
    return;
%     pause();
%     load("Measurement.mat");
    % Todo import data
    
end

%% Plot results
subplot(3,2,1);
plot(out.Pp_Aref);
hold on;
plot(out.Pp_A);
title("Plate position motor A")
subplot(3,2,3);
plot(out.Pp_Bref);
hold on;
plot(out.Pp_B);
title("Plate position motor B")
subplot(3,2,5);
plot(out.Pp_Cref);
hold on;
plot(out.Pp_C);
title("Plate position motor C")

subplot(3,2,2);
plot(out.Pb_Xref);
hold on;
plot(out.Pb_X);
title("Ball position X")
subplot(3,2,4);
plot(out.Pb_Yref);
hold on;
plot(out.Pb_Y);
title("Ball position Y")
subplot(3,2,6);
plot(out.Pb_Xref, out.Pb_Yref);
hold on;
plot(out.Pb_X, out.Pb_Y);
title("Ball position XY")