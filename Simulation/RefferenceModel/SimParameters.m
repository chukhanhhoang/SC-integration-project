clear all;
load("ExistingController.mat")

C_v = 16.5;
% I_p = m_p*0.04^2/12;
K = 11;
g = 9.81;
m_m = 0.118;
m_p = 0.9;
r = 0.17;
m_b = 0.024;
% I_b =  m_b*r_b^2;
r_b = 0.019;
I_p = m_p*0.04^2/12;
I_b =  m_b*r_b^2; %Has to be changed


Zoffset = 0.32;
fs = 1000;
ts_mp = 1/1000;
ts_camera = ts_mp*round((1/30)/ts_mp); % Actual framerate should be 1/30, but rounded to nearest multiple of ts_mp, to prevent issues with Simulink
EncStepSize = 1*10^-9; % To be determined
CameraStepSize = 1*10^-9; % To be determined
Tdelay_mp = 1*10^-9; % To be determined
Tdelay_bob = 1*10^-9; % To be determined

I_max = 3;
I_min = -3;

Ymp0 =  [0; 0; 0; 0; 0; Zoffset];
Ybop0 = [0; 0; 0; 0];

save("ModelParameters.mat")