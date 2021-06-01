%% Experiment setting
SimulateOrMeasure  = 1; % 0 for simulating, any other number for measuring
t_experiment = 10;

%% Controller settings
controllerFilename = "Test_measurement_script";

%% Load enviroment settings (Do not change)
addpath("../Controllers")
if (SimulateOrMeasure == 0)
    % Simulation 
    addpath("../Simulation/RefferenceModel")
    load("ModelParameters.mat")
else
    % Measurement
    addpath("../Measurements/RefferenceModel")
end
  
%% Simulation settings
if (SimulateOrMeasure == 0) % (Do not change)
    UseNonlinearPlant = 1;
    SimulateEncoders = 1;
    SimulateCamera = 1;
    SimulateTimeDelays = 0; % Note: enabling this results in strange behavior
    SimulateFriction = 0; % Note: not jet implemented

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
    UseUserDefinedPlateReference = 1;
    UseUserDefinedBallReference = 1;
    disp("Loading measurement model");
    load_system("BallAndPlateMeasurement.slx");
    set_param('BallAndPlateMeasurement/Run/Controller', 'ModelFile', controllerFilename)
    
    % Build measurement model
    disp("Building measurement model");
    rtwbuild('BallAndPlateMeasurement');
    close_system("BallAndPlateSimulation.slx",0);
    fprintf("\n\n\n\n------------------------------Finished building------------------------------\n\n");
    
    % Wait for measurement results
    disp("Once the measurement is completed and the data is saved to ""Measurement.mat"" in the ""Experiments"" folder, press any key to continue.");
    pause();
    load("Measurement.mat");
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