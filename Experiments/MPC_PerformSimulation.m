%% Experiment setting
SimulateOrMeasure  = 0; % 0 for simulating, any other number for measuring
t_experiment = 20;

%% Controller settings
mpc_controller = defineMPC();
controllerFilename = "MPC_Controller.slx";

%% Load enviroment settings (Do not change)
addpath("../Controllers")
if (SimulateOrMeasure == 0)
    % Simulation 
    addpath("../Simulation/RefferenceModel")
    load("ModelParameters.mat")
else
    % Measurement
    addpath("../Measurement/RefferenceModel")
end
  
%% Simulation settings
if (SimulateOrMeasure == 0) % (Do not change)
    UseNonlinearPlant = 1;
    SimulateEncoders = 1;
    SimulateCamera = 1;
    SimulateTimeDelays = 0; % Note: enabling this results in strange behavior
    SimulateFriction = 0; % Note: not jet implemented
    UseUserDefinedPlateReference = 0;
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
    % Perform measurement, code not jet implemented
end

t = out.tout;

%% Plot results
subplot(3,2,1);
plot(t, out.Pp_Aref);
hold on;
plot(t, out.Pp_A);
xlabel("Time [s]");
ylabel("Position [m]");
title("Plate position motor A")

subplot(3,2,3);
plot(t, out.Pp_Bref);
hold on;
plot(t, out.Pp_B);
xlabel("Time [s]");
ylabel("Position [m]");
title("Plate position motor B")

subplot(3,2,5);
plot(t, out.Pp_Cref);
hold on;
plot(t, out.Pp_C);
xlabel("Time [s]");
ylabel("Position [m]");
title("Plate position motor C")

subplot(3,2,2);
plot(t, out.Pb_Xref);
hold on;
plot(t, out.Pb_X);
xlabel("Time [s]");
ylabel("Position [m]");
legend("Reference", "Measrued")
title("Ball position X")

subplot(3,2,4);
plot(t, out.Pb_Yref);
hold on;
plot(t, out.Pb_Y);
xlabel("Time [s]");
ylabel("Position [m]");
legend("Reference", "Measrued")
title("Ball position Y")

subplot(3,2,6);
plot(out.Pb_Xref, out.Pb_Yref);
hold on;
plot(out.Pb_X, out.Pb_Y);
xlabel("Position [m]");
ylabel("Position [m]");
legend("Reference", "Measrued")
title("Ball position XY")