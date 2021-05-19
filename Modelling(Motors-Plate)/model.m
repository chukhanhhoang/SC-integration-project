clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b;

%% Define variables
syms theta_1(t) theta_2(t) theta_3(t) z_C(t) x(t) y(t) omega1 omega2 omega3;

%% Convert angles to motors
theta_3 = 0; % No rotation around z-axis
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r0Oc = [0;0;z_C];

% Find cos and sin to accelerate calculations
C1 = cos(theta_1);S1 = sin(theta_1);C2 = cos(theta_2);S2 = sin(theta_2);C3 = cos(theta_3);S3 = sin(theta_3);

% Rotation matrices
RotZ = [C3 S3 0; -S3 C3 0; 0 0 1];
RotY = [C2 0 -S2; 0 1 0; S2 0 C2];
RotX = [1 0 0; 0 C1 S1; 0 -S1 C1];

A10 = RotX*RotY*RotZ; A01 = A10.';

% Find rCiBi (Vectors representing the motors)
rC1B1 = r0Oc + A01*r1C1 - r0B1;
rC2B2 = r0Oc + A01*r1C2 - r0B2;
rC3B3 = r0Oc + A01*r1C3 - r0B3;


% Outputs to motor are the lengths of the vectors
motor1 = simplify(norm(rC1B1));
motor2 = simplify(norm(rC2B2));
motor3 = simplify(norm(rC3B3));

z1 = z_C - r*sin(theta_2);
z2 = z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2;
z3 = z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2;
z1dot = diff(z1,t)
z2dot = diff(z2,t)
z3dot = diff(z3,t)