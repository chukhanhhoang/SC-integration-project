clear all; clc;

%% Modelling of the motors-plate-ball system

%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b;

%% Define variables
syms theta_1(t) theta_2(t) theta_3(t) z_C x(t) y(t) z_b(t) omega1 omega2;

% Motor positions
z1 = ((z_C - r*sin(theta_2))^2 + (r*(cos(theta_2) - 1))^2)^(1/2);
z2 = ((z_C + (r*sin(theta_2))/2 + (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + (r/2 - (r*cos(theta_2))/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);
z3 = ((z_C + (r*sin(theta_2))/2 - (3^(1/2)*r*cos(theta_2)*sin(theta_1))/2)^2 + ((3^(1/2)*r)/2 - (3^(1/2)*r*cos(theta_1))/2)^2 + ((r*cos(theta_2))/2 - r/2 + (3^(1/2)*r*sin(theta_1)*sin(theta_2))/2)^2)^(1/2);

% Find cos and sin
C1 = cos(theta_1);S1 = sin(theta_1);C2 = cos(theta_2);S2 = sin(theta_2);C3 = cos(theta_3);S3 = sin(theta_3);

% Rotation matrices
RotZ = [C3 S3 0; -S3 C3 0; 0 0 1];
RotY = [C2 0 -S2; 0 1 0; S2 0 C2];
RotX = [1 0 0; 0 C1 S1; 0 -S1 C1];

A10 = RotX*RotY*RotZ; A01 = A10.';

% Find positions

theta_3 = 0; % No rotation around z-axis
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r0Oc = [0;0;z_C];
r1ball_contact = [0;0;r_b];
r0ball_contact = A01*r1ball_contact;

% Find velocities
z_b = (x*(sin(theta_1)*sin(theta_3) + cos(theta_1)*cos(theta_3)*sin(theta_2)) - y*(cos(theta_3)*sin(theta_1) - cos(theta_1)*sin(theta_2)*sin(theta_3)) - cos(theta_1)*cos(theta_2)*(z_C))/(- cos(theta_1)*cos(theta_2));
%r0b = [x;y;z_b];
%rb_calc = [0 0 1]*A10*(r0b-r0Oc);

r0b = [x;y;z_b];
v_b = diff(r0b,t); % velocity of the ball
v_C = diff(r0Oc,t); % velocity of the center
theta_dot = diff([theta_1; theta_2; theta_3],t); %angular velocity of the plate
v_contact = v_C + cross(theta_dot,r0b-r0ball_contact-r0Oc); % v_contact = v_C + theta_dot x r_contact/C
%v_b_via_others = v_contact + cross([omega1; omega2; omega3],r_b*A01*[0;0;1]);
omega1 = -(A01*[0;1;0]).'*(v_b-v_contact);
omega2 =  (A01*[1;0;0]).'*(v_b-v_contact);


%% Find energy
