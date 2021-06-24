clear; clc; close all;

% Parameters Init
g = 9.81; r = 0.17;
m_m = 0.118;
m_p = 0.9;
I_p = m_p*0.04^2/12;
K=11;
C_v=16.5;
r_b = 0.019;
m_b = 0.024;
I_b = m_b*r_b^2;

I0 = (m_p+3*m_m)*g/(3*K);

motorPlateInit = [0;0;0;0;0;0.32];
ballPosInit = [0;0;0;0];
%load("mpc_controller.mat");

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

% Define MPC controller
%% create MPC controller object with sample time
mpc_controller = mpc(sysc, 0.04);
%% specify prediction horizon
mpc_controller.PredictionHorizon = 20;
%% specify control horizon
mpc_controller.ControlHorizon = 10;
%% specify nominal values for inputs and outputs
mpc_controller.Model.Nominal.U = [0;0];
mpc_controller.Model.Nominal.Y = [0;0];
%% specify constraints for MV and MV Rate
mpc_controller.MV(1).Min = -0.08;
mpc_controller.MV(1).Max = 0.08;
mpc_controller.MV(2).Min = -0.08;
mpc_controller.MV(2).Max = 0.08;
%% specify constraints for OV
mpc_controller.OV(1).Min = -0.3;
mpc_controller.OV(1).Max = 0.3;
mpc_controller.OV(2).Min = -0.3;
mpc_controller.OV(2).Max = 0.3;
%% specify weights
mpc_controller.Weights.MV = [0.1 0.1];
mpc_controller.Weights.MVRate = [0.1 0.1];
mpc_controller.Weights.OV = [1 1];
mpc_controller.Weights.ECR = 100000;

% Start simulation
result = sim("totalSystem.slx");

% Visualization
t = 0:0.001:10;

figure;
plot(t, result.P_A, t, result.P_B, t, result.P_C);
legend("P_A", "P_B", "P_C")
title("Measured position of the 3 motors")

% figure;
% plot(t, result.r_X, t, result.r_Y)

figure;
plot(result.r_X, result.r_Y)
title("Reference trajectory of the ball on the plate")

figure;
r_ball_x = result.r_ball(:, 1);
r_ball_y = result.r_ball(:, 2);
P_ball_x = result.P_ball(:, 1);
P_ball_y = result.P_ball(:, 2);

plot(t, r_ball_x, t, r_ball_y);
hold on;
plot(t, P_ball_x, 'LineWidth', 2, 'Color', 'red');
plot(t, P_ball_y, 'LineWidth', 2, 'Color', 'green');
legend('r_x', 'r_y', 'P_x', 'P_y');
title("Reference and measured position of the ball")



%% Controller init
%**** linear plant model*****
%
%  X(s)      Km/m
%  --- = -------------
%  I(s)    s(s+Cv/m)
%
% with x in [m] and i in [A]

% Ts=1/2000;
% Ts_Outer= 0.1;
% 
% m=0.367;
% Km=11;
% Cv=16.5;
% 
% Kp=Km/m;
% p=-Cv/m;
% 
% Hp=zpk([],[0 -Cv/m],Km/m);
% 
% 
% % Controller
% 
% B=200; %was 300 wl
% % choose the controller gain such that the open loop magnitude is 0dB at w=B
% % the plant magnitude at w=B is:
% P_magn=Kp/(B*sqrt(p^2+B^2));
% % the controller magnitude at w=B is:
% C_magn=1/(B*18);
% %The required controller gain to make the open loop magnitude 0dB at w=B must then be:
% Kc=0.6*1/(P_magn*C_magn);%wl:gain multiplied by 0.2
% 
% Hc=zpk([-B/3 -B/6],[-3*B -6*B 0],Kc);
% 
% sisotool(Hp,Hc)
% 
% % same controller minus the integrator for dSPACE implementation.
% % integrator is added as separate block, where the saturation limits can be
% % set to avoid integrator wind-up.
% 
% Hc_mi=zpk([-B/3 -B/6],[-3*B -6*B],Kc);
% [numc_mi,denc_mi]=tfdata(Hc_mi,'v');