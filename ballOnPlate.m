clear all; clc;
%% Define parameters
syms r r_b m_m m_p I_p m_b I_b r_b g;

%% Define variables
syms theta_1 theta_2 z_C x y z dtheta_1 dtheta_2 dz_C d2theta_1 d2theta_2 d2z_C;
sym_var = [theta_1 theta_2 z_C x y z];

q   = [theta_1 theta_2 z_C];
dq  = [dtheta_1 dtheta_2 dz_C];
d2q = [d2theta_1 d2theta_2 d2z_C];
%% Ball moment of inertia about the momentary fixed point
J_b = I_b*eye(3)+ m_b*([0;0;r_b].'*[0;0;r_b]*eye(3)-[0;0;r_b]*[0;0;r_b].');

%% Rotation matrix
theta_3 = 0; % No rotation around z-axis

% Find cos and sin to accelerate calculations
C1 = cos(theta_1);S1 = sin(theta_1);C2 = cos(theta_2);S2 = sin(theta_2);C3 = cos(theta_3);S3 = sin(theta_3);

% Rotation matrices
RotZ = [C3 S3 0; -S3 C3 0; 0 0 1];
RotY = [C2 0 -S2; 0 1 0; S2 0 C2];
RotX = [1 0 0; 0 C1 S1; 0 -S1 C1];

A10 = RotX*RotY*RotZ; A01 = A10.';

%% Set up Euler equation

% Find z as func of x y theta etc
z_solve = solve([0 0 1]*(A10*[x;y;z-z_C])==r_b,z);

% Symbolic functions
syms theta_1f(t) theta_2f(t) z_Cf(t) xf(t) yf(t) zf(t);
sym_func = [theta_1f theta_2f z_Cf xf yf zf];
A10f = subs(A10,sym_var,sym_func);
A01f = subs(A01,sym_var,sym_func);
zf = subs(z_solve,sym_var,sym_func);

% Position vectors and velocities
rM = [xf;yf;zf]; % in e0
O0O1 = [0;0;z_Cf]; %in e0
theta = [theta_1f;theta_2f;0];
Omega10 = diff(theta); %in e0
O1M = [xf;yf;zf-z_Cf]; %in e0
% vM_R0 = vM_R1 + v(O1)_R1 + Omega x O1M
vM_R1_e0 = diff([xf;yf;zf])-diff(O0O1)-cross(Omega10,O1M); %in e0
vM_r1_e1 = A10f*vM_R1_e0;
omegab_1 = -1/r_b*([0;1;0]'*vM_r1_e1); %in e1
omegab_2 =  1/r_b*([1;0;0]'*vM_r1_e1); %in e1
omegab_3 = 0; %in e1

ae = diff(O0O1,2)+ cross(diff(Omega10),O1M) + cross(Omega10,cross(Omega10,O1M)); %in e0
ac = 2*cross(Omega10,vM_R1_e0); %in e0

% Forces:
Fg = m_b*g*[0;0;-1]; %in e0
Fie = -m_b*ae; %in e0
Fic = -m_b*ac; %in e0
F = Fg+Fie+Fic;
F_e1 = A10f*F; %in e1
totalMoment = cross([0;0;r_b],F_e1); %in e1
angularMomentum = J_b*[omegab_1;omegab_2;omegab_3]; %in e1
eqn = diff(angularMomentum)==totalMoment;

%Replace func by var
qf = [theta_1f(t) theta_2f(t) z_Cf(t)];
dqf = diff(qf);
d2qf = diff(qf,2);

eqn_toSolve = subs(eqn,[qf dqf d2qf],[q dq d2q])
[V,S]=odeToVectorField(eqn_toSolve)
M = matlabFunction(V,'vars',{'Y','m_b', 'I_b', 'r_b', 'g','theta_1', 'theta_2', 'z_C', 'dtheta_1', 'dtheta_2', 'dz_C', 'd2theta_1', 'd2theta_2', 'd2z_C'},'file','ballOnPlateODE.m','Comments',char(S));