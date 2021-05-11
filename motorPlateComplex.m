clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b g;

%% Define variables
syms theta_1 theta_2 omega_1 omega_2 z_C F_1 F_2 F_3 K C_v I_1 I_2 I_3 s;


% Motor positions
%z1 = ((z_C - r*sin(theta_2))^2 + (r*(cos(theta_2) - 1))^2)^(1/2);
%z2 = ((z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + (r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);
%z3 = ((z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + ((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);
z1 = z_C - r*sin(theta_2);
z2 = z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2;
z3 = z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2;

% Motor velocities
%z1dot = -(2*r*cos(theta_2)*(z_C - r*sin(theta_2))*omega_2 + 2*r^2*sin(theta_2)*(cos(theta_2) - 1)*omega_2)/(2*(r^2*(cos(theta_2) - 1)^2 + (z_C - r*sin(theta_2))^2)^(1/2));
%z2dot = (2*(r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)*((r*sin(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_1)*sin(theta_2)*omega_1)/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1)*omega_2)/2) + 2*((r*cos(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 - (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2)*(z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2) + 3^(1/2)*r*sin(theta_1)*((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)*omega_1)/(2*((z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + (r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2));
%z3dot = (2*((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)*((3^(1/2)*r*cos(theta_1)*sin(theta_2)*omega_1)/2 - (r*sin(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1)*omega_2)/2) + 2*((r*cos(theta_2)*omega_2)/2 - (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2)*(z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2) + 3^(1/2)*r*sin(theta_1)*((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)*omega_1)/(2*((z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + ((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2));

z1dot = - r*cos(theta_2)*omega_2;
z2dot = (r*cos(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 - (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2;
z3dot = (r*cos(theta_2)*omega_2)/2 - (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2;


% Kinetic energy
T = 1/2*(I_p*(omega_1^2+omega_2^2)+m_m*(z1dot^2+z2dot^2+z3dot^2));
% Potential energy
V = m_m*g*(z1+z2+z3);

%% Lagrange
q = [theta_1;theta_2];
qdot = [omega_1;omega_2];

dTdqdot = simplify(partialdiff(T,qdot));
dTdq    = simplify(partialdiff(T,q));
dVdq    = simplify(partialdiff(V,q));