clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('FRF_0511_1.mat');

% Variables assign
u = FRF_0511_1.Y(4).Data;
d = FRF_0511_1.Y(3).Data;
r = FRF_0511_1.Y(2).Data;
P = FRF_0511_1.Y(1).Data;

plot(P);