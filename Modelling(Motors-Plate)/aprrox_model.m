clear all; clc;

%% Modelling of the motors-plate-ball system (Approx the rotation matrix to a linear matrix)

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b;

%% Define variables
syms theta_1(t) theta_2(t) theta_3(t) z_C(t) x(t) y(t) z_b omega1 omega2;

%% Convert angles to motors
theta_3 = 0; % No rotation around z-axis
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r0Oc = [0;0;z_C];

% Find cos and sin to accelerate calculations
%C1 = cos(theta_1);S1 = sin(theta_1);C2 = cos(theta_2);S2 = sin(theta_2);C3 = cos(theta_3);S3 = sin(theta_3);

% Rotation matrices
%RotZ = [C3 S3 0; -S3 C3 0; 0 0 1];
RotY = [1 0 -theta_2; 0 1 0; theta_2 0 1];
RotX = [1 0 0; 0 1 theta_1; 0 -theta_1 1];

A10 = RotX*RotY; A01 = A10.';

% Find rCiBi (Vectors representing the motors)
rC1B1 = r0Oc + A01*r1C1 - r0B1;
rC2B2 = r0Oc + A01*r1C2 - r0B2;
rC3B3 = r0Oc + A01*r1C3 - r0B3;


% Outputs to motor are the lengths of the vectors
z1 = [0 0 1]*rC1B1;
z2 = [0 0 1]*rC2B2;
z3 = [0 0 1]*rC3B3;

% Some positions
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r0Oc = [0;0;z_C];
r1ball_contact = [0;0;r_b];
r0ball_contact = A01*r1ball_contact;
%r0b = [x;y;z_b];
%rb_calc = [0 0 1]*A10*(r0b-r0Oc);
z_b = r_b - (- z_C(t) + theta_2(t)*x(t) - theta_1(t)*y(t));
r0b = [x;y;z_b];
v_b = diff(r0b,t); % velocity of the ball
v_C = diff(r0Oc,t); % velocity of the center
theta_dot = diff([theta_1; theta_2; theta_3],t); %angular velocity of the plate
v_contact = v_C + cross(theta_dot,r0b-r0ball_contact-r0Oc); % v_contact = v_C + theta_dot x r_contact/C
omega1 = -(A01*[0;1;0]).'*(v_b-v_contact);
omega2 =  (A01*[1;0;0]).'*(v_b-v_contact);