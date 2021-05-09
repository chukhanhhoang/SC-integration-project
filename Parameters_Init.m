clc; clear; close all;

%% Define Parameters of the system
m_m = 0.118; m_p = 0.682; m = 1/3*m_p+m_m; %TODO: Fix m_m and m_p
K = 11; g = 9.81; Cv = 16.5;
Zc = 0.352;

%% Define transfer function of Motor
numerator = [K];
denominator = [m Cv 0];
sysM = tf(numerator, denominator);