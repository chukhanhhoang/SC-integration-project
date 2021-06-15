clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('data0416_3points_ballplate.mat');

% Variables assign
u_th1 = data0416_3points.Y(3).Data;
u_th2 = data0416_3points.Y(4).Data;

r_bX  = data0416_3points.Y(5).Data;
r_bY  = data0416_3points.Y(6).Data;

e_bX  = data0416_3points.Y(1).Data;
e_bY  = data0416_3points.Y(2).Data;