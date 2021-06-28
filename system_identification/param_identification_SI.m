clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('Motor1withPos.mat');

% Variables assign
u_A = Motor1withPos.Y(1).Data;   u_A = u_A';
P_A  = Motor1withPos.Y(4).Data;  P_A = P_A';
r_A  = Motor1withPos.Y(7).Data;  r_A = r_A';


%% Fit OE model for Gyr
% cra([P_A, r_A]); % nk = 0
% cra([u_A, r_A]); % nk = 1

G_OE_ur = oe([u_A, r_A], [6 8 0])
figure();
resid([u_A r_A], G_OE_ur);

G_OE_yr = oe([P_A, r_A], [4 4 0])
figure();
resid([P_A r_A], G_OE_yr);

G_OE = G_OE_yr / G_OE_ur;