clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('FinalData.mat');

% Variables assign
Pb_X = FianlData.Y(1).Data;  
Pb_Y = FianlData.Y(3).Data;  

Pb_Xm = FianlData.Y(2).Data;  Pb_Xm = Pb_Xm(20000:40000);
Pb_Ym = FianlData.Y(4).Data;  Pb_Ym = Pb_Ym(20000:40000);

Pm_Am = FianlData.Y(5).Data;  Pm_Am = Pm_Am(1:40000);
Pm_Bm = FianlData.Y(6).Data;  Pm_Bm = Pm_Bm(1:40000);
Pm_Cm = FianlData.Y(7).Data;  Pm_Cm = Pm_Cm(1:40000);

t = 0:0.001:20;

figure;
plot(t, Pb_Xm)
hold on;
plot(t, Pb_Ym)
legend('Position X', 'Position Y');
xlabel('Time [s]')
ylabel('Ball position [m]')
ylim([-0.12, 0.12])

% figure;
% plot(t, Pm_Am)
% hold on;
% plot(t, Pm_Bm)
% plot(t, Pm_Cm)
% xlabel('Time [s]')
% ylabel('Motor position [m]')
% legend('Motor A', 'Motor B', 'Motor C')

figure; 
plot(Pb_Xm, Pb_Ym)
xlabel('Position X [m]')
ylabel('Position Y [m]')