clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b g;

%% Define variables
syms theta_1 theta_2 omega_1 omega_2 z_C dz_C F_1 F_2 F_3 K C_v I_1 I_2 I_3 s;


% Motor positions
% Motor positions and velocities
z1 = z_C - r*theta_2;
z2 = z_C + r/2*theta_2 + sqrt(3)/2*r*theta_1;
z3 = z_C + r/2*theta_2 - sqrt(3)/2*r*theta_1;

% Motor velocities
%z1dot = -(2*r*cos(theta_2)*(z_C - r*sin(theta_2))*omega_2 + 2*r^2*sin(theta_2)*(cos(theta_2) - 1)*omega_2)/(2*(r^2*(cos(theta_2) - 1)^2 + (z_C - r*sin(theta_2))^2)^(1/2));
%z2dot = (2*(r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)*((r*sin(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_1)*sin(theta_2)*omega_1)/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1)*omega_2)/2) + 2*((r*cos(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 - (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2)*(z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2) + 3^(1/2)*r*sin(theta_1)*((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)*omega_1)/(2*((z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + (r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2));
%z3dot = (2*((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)*((3^(1/2)*r*cos(theta_1)*sin(theta_2)*omega_1)/2 - (r*sin(theta_2)*omega_2)/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1)*omega_2)/2) + 2*((r*cos(theta_2)*omega_2)/2 - (3^(1/2)*r*cos(theta_1)*cos(theta_2)*omega_1)/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2)*omega_2)/2)*(z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2) + 3^(1/2)*r*sin(theta_1)*((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)*omega_1)/(2*((z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + ((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2));

z1dot = dz_C - r*omega_2;
z2dot = dz_C + r/2*omega_2 + sqrt(3)/2*r*omega_1;
z3dot = dz_C + r/2*omega_2 - sqrt(3)/2*r*omega_1;


% Kinetic energy
T = 1/2*(m_p*dz_C^2 +I_p*(omega_1^2+omega_2^2)+m_m*(z1dot^2+z2dot^2+z3dot^2));
% Potential energy
V = m_m*g*(z1+z2+z3)+m_p*g*z_C;

%% Lagrange
q = [theta_1;theta_2;z_C];
qdot = [omega_1;omega_2;dz_C];

dTdqdot = simplify(partialdiff(T,qdot));
dTdq    = simplify(partialdiff(T,q));
dVdq    = simplify(partialdiff(V,q));

% Nonconservative forces
ztemp = [z1 z2 z3];
Ftemp = [F_1 F_2 F_3];
Qnc = 0;
for i = 1:length(ztemp)
    Qnc = Qnc+ calJacobian([0;0;ztemp(i)],q).'*[0;0;Ftemp(i)];
end

% Replace F by thrust*current - viscous force
Qnc_subs = simplify(subs(Qnc,Ftemp,[K*I_1-C_v*z1dot K*I_2-C_v*z2dot K*I_3-C_v*z3dot]));
%latex(Qnc_subs)

% Create symbolic functions

syms theta_1f(t) theta_2f(t) z_Cf(t) omega_1f(t) omega_2f(t) dz_Cf(t)
q_f = [theta_1f;theta_2f;z_Cf];
qdot_f = [omega_1f;omega_2f;dz_Cf];

% replace the variables with the functions
dTdqdotf = subs(dTdqdot,[q;qdot],[q_f;qdot_f]);
dTdqf    = subs(dTdq,[q;qdot],[q_f;qdot_f]);
dVdqf    = subs(dVdq,[q;qdot],[q_f;qdot_f]);
Qnc_subs = subs(Qnc_subs,[q;qdot],[q_f;qdot_f]);

eqn1 = diff(dTdqdotf,t)-dTdqf+dVdqf==Qnc_subs.';
eqn2 = diff(q_f,t)==qdot_f;

[V,S] = odeToVectorField([eqn1 eqn2.']);
M = matlabFunction(V,'vars',{'t','Y','C_v','I_1','I_2','I_3','I_p','K','g','m_m','m_p','r'},'file','motorPlateODElinear.m','Comments',char(S));