clc; clear; close all;

% Define System parameters
g = 9.81;
r_b = 0.019;
m_b = 0.024;
I_b = m_b*r_b^2;

% Load reference signal data
load("mpc1_RefSignal.mat");
load("mpc1_MDSignal.mat");

% Define system ball & plate system plant
h = g/(1 + I_b/(m_b*r_b^2));
Ac = [0 1 0 0;
      0 0 0 0;
      0 0 0 1;
      0 0 0 0]; % 4x4 matrix
Bc = [0 0; 0 h; 0 0; -h 0]; % 4x2 matrix
Cc = [1 0 0 0;
      0 0 1 0];
Dc = diag([0 0]);

sysc = ss(Ac, Bc, Cc, Dc);

%% create MPC controller object with sample time
mpc1 = mpc(sysc, 0.04);
%% specify prediction horizon
mpc1.PredictionHorizon = 20;
%% specify control horizon
mpc1.ControlHorizon = 5;
%% specify nominal values for inputs and outputs
mpc1.Model.Nominal.U = [0;0];
mpc1.Model.Nominal.Y = [0;0];
%% specify constraints for MV and MV Rate
mpc1.MV(1).Min = -0.1;
mpc1.MV(1).Max = 0.1;
mpc1.MV(2).Min = -0.1;
mpc1.MV(2).Max = 0.1;
%% specify constraints for OV
mpc1.OV(1).Min = -0.3;
mpc1.OV(1).Max = 0.3;
mpc1.OV(2).Min = -0.3;
mpc1.OV(2).Max = 0.3;
%% specify weights
mpc1.Weights.MV = [0 0];
mpc1.Weights.MVRate = [0.1 0.1];
mpc1.Weights.OV = [1 1];
mpc1.Weights.ECR = 100000;
%% specify simulation options
options = mpcsimopt();
options.RefLookAhead = 'off';
options.MDLookAhead = 'off';
options.Constraints = 'on';
options.OpenLoop = 'off';
%% run simulation
sim(mpc1, 251, mpc1_RefSignal, mpc1_MDSignal, options);
