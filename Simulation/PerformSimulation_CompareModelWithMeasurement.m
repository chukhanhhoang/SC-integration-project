%% Load model parameters
load("RefferenceModel/ModelParameters.mat")

%% Set simulation settings
UseNonlinearPlant = 1;
SimulateEncoders = 1;
SimulateCamera = 1;
SimulateTimeDelays = 0; % Note: enabling this results in strange behavior, should be discussed
t_sim = 10;

%% Set controller settings
controllerFilename = "Controller_CompareModelWithMeasurement.slx";
I_init = 0;

%% Simulate model
load_system("RefferenceModel/BallAndPlateSimulation.slx");
set_param('BallAndPlateSimulation/Controller', 'ModelFile', controllerFilename)

out = sim("RefferenceModel/BallAndPlateSimulation.slx");

%% Plot results
subplot(3,1,1);
plot(out.P_Aref);
hold on;
plot(out.P_A);
subplot(3,1,2);
plot(out.P_Bref);
hold on;
plot(out.P_B);
subplot(3,1,3);
plot(out.P_Cref);
hold on;
plot(out.P_C);