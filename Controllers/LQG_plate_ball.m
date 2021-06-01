%% Experiment setting
SimulateOrMeasure  = 0; % 0 for simulating, any other number for measuring
t_experiment = 33;


%% Load enviroment settings (Do not change)
if (SimulateOrMeasure == 0)
    % Simulation 
    addpath("../Simulation/RefferenceModel")
    load("ModelParameters.mat")
else
    % Measurement
    addpath("../Measurement/RefferenceModel")
end
  

%% Controller settings
% load("ExistingController.mat")
Ab = [0 1 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
Bb = [0 0; 0 g/(1+I_b/(m_b*r_b^2)); 0 0; -g/(1+I_b/(m_b*r_b^2)) 0];
Cb = [1 0 0 0; 0 0 1 0];

ballSystem = ss(Ab,Bb,Cb,zeros(2,2));
Q = [1 0 0 0;0 0 0 0;0 0 1 0;0 0 0 0];
R = 0.1*eye(2);
ballLQRgain = lqr(ballSystem, Q, R);

I_0 = (3*m_m + m_p)*g/(3*K);
M = diag([3/2*m_m*r^2,3/2*m_m*r^2,3*m_m+m_p]);
N = -diag([3/2*C_v*r^2,3/2*C_v*r^2,3*C_v]);
P = [0 sqrt(3)*r*K/2 -sqrt(3)*r*K/2; -r*K r*K/2 r*K/2; 1 1 1];

A = [zeros(3) eye(3);zeros(3) inv(M)*N];
B = [zeros(3);inv(M)*P];
C = [eye(3) zeros(3)];
D = zeros(3);
plateSystem = ss(A,B,C,D);

Qp = 10*eye(6);Qp(6,6)=0.001;Qp(4,4)=0.001;Qp(5,5)=0.001; Qp(3,3)=1;
Rp = 3*eye(3);
plateLQRgain = lqr(plateSystem, Qp, Rp);

controllerFilename = "LQG_plate_ball_controller.slx";

%% Overwrite some parameters
Tdelay_bob = 0;
Tdelay_mp = 0;
ts_camera = 0.033;
ts_mp = 0.033;
Ybop0 = [0.1;0;0;0];

%% Simulation settings
if (SimulateOrMeasure == 0) % (Do not change)
    UseNonlinearPlant = 1;
    SimulateEncoders = 0;
    SimulateCamera = 0;
    SimulateTimeDelays = 0; % Note: enabling this results in strange behavior
    SimulateFriction = 0; % Note: not jet implemented
    UseUserDefinedPlateReference = 1;
    UseUserDefinedBallReference = 1;

    ts_plateRef = ts_mp;
    ts_BallRef = ts_camera;

    % Create reference
    Pp_Aref_in = zeros(1,t_experiment/ts_plateRef);
    Pp_Bref_in = zeros(1,t_experiment/ts_plateRef);
    Pp_Cref_in = zeros(1,t_experiment/ts_plateRef);
    Pb_Xref_in = zeros(1,t_experiment/ts_BallRef);
    Pb_Yref_in = zeros(1,t_experiment/ts_BallRef);
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

%% Plot results
subplot(3,2,1);
plot(out.Pp_Aref);
hold on;
plot(0.32+out.Pp_A);
title("Plate position motor A")
subplot(3,2,3);
plot(out.Pp_Bref);
hold on;
plot(0.32+out.Pp_B);
title("Plate position motor B")
subplot(3,2,5);
plot(out.Pp_Cref);
hold on;
plot(0.32+out.Pp_C);
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