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
ballPosInit = [0.1;0;0.1;0];
load("mpc_controller.mat");
%load("mpc1.mat")

% Start simulation
result = sim("totalSystem.slx");

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

% Visualization
t = 0:0.001:40;

figure;
plot(t, result.P_A, t, result.P_B, t, result.P_C);
legend("P_A", "P_B", "P_C")
title("Measured position of the 3 motors")

% figure;
% plot(t, result.r_X, t, result.r_Y)

figure;
plot(result.r_X, result.r_Y)
title("Trajectory of the ball on the plate")



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