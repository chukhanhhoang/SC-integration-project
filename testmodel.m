clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b;

%% Define variables
syms theta_1(t) theta_2(t) theta_3(t) z_C(t) x(t) y(t) z_b(t) omega1 omega2;

z_C = 0;
% Motor positions
z1 = ((z_C - r*sin(theta_2))^2 + (r*(cos(theta_2) - 1))^2)^(1/2);
z2 = ((z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + (r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);
z3 = ((z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + ((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);

z1dot = diff(z1,t);
z2dot = diff(z2,t);
z3dot = diff(z3,t);