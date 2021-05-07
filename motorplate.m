clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b g;

%% Define variables
syms theta_1 theta_2 omega_1 omega_2 F_1 F_2 F_3 K C_v I_1 I_2 I_3 s;

% Motor positions and velocities
z1 = -r*theta_2;
z2 = r/2*theta_2 + sqrt(3)/2*r*theta_1;
z3 = r/2*theta_2 - sqrt(3)/2*r*theta_1;

z1dot = -r*omega_2;
z2dot = r/2*omega_2 + sqrt(3)/2*r*omega_1;
z3dot = r/2*omega_2 - sqrt(3)/2*r*omega_1;

% Kinetic energy
T = 1/2*(I_p*(omega_1^2+omega_2^2)+m_m*(z1dot^2+z2dot^2+z3dot^2));
% Potential energy
V = m_m*g*(z1+z2+z3);

%% Lagrange
q = [theta_1;theta_2];
qdot = [omega_1;omega_2];

dTdqdot = simplify(partialdiff(T,qdot));
M = ((3*m_m*r^2 + 2*I_p))/2*eye(2);
% M*[omega_1;omega_2]-dTdqdot.' must equal zeros

ztemp = [z1 z2 z3];
Ftemp = [F_1 F_2 F_3];
Qnc = 0;
for i = 1:length(ztemp)
    Qnc = Qnc+ calJacobian([0;0;ztemp(i)],q).'*[0;0;Ftemp(i)];
end

% Replace F by thrust*current - viscous force
Qnc_subs = simplify(subs(Qnc,Ftemp,[K*I_1-C_v*z1dot K*I_2-C_v*z2dot K*I_3-C_v*z3dot]));

% Separate I and qdot
Qnc_I = [-(r*(3^(1/2)*I_3*K - 3^(1/2)*I_2*K))/2;-(r*(2*I_1*K - I_2*K - I_3*K))/2];
Qnc_qdot = [-(3*C_v*omega_1*r^2)/2;-(3*C_v*omega_2*r^2)/2];

% Move Qnc_qdot to left side, N*qdot = -Qnc_qdot
N = (3*C_v*r^2)/2*eye(2);

%% Find the transfer matrix
% Factorize Qnc_I=P*[I1;I2;I3]
P = r/2*K*[0  sqrt(3) -sqrt(3)  ; -2 1 1];

% The transfer matrix is G_thetaI = (Ms^2+Ns)^-1*P
G = simplify(inv(M*s^2+N*s)*P)
