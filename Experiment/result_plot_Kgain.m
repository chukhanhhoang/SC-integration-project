clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('XY_position_2806.mat');

% Variables assign
Pb_Xm = XY_position_2806.Y(1).Data;  Pb_Xm = Pb_Xm(20000:40000);
Pb_Ym = XY_position_2806.Y(2).Data;  Pb_Ym = Pb_Ym(20000:40000);

t = 0:0.001:20;
cosy = 0.1*cos(4/10 * pi *t + 3.5*pi/3);
siny = 0.1*cos(4/10 * pi *t + 5.*pi/3);

figure;
subplot(2,1,1)
plot(t, cosy);
hold on;
plot(t, Pb_Xm)

legend('Reference X', 'Measured position X');
xlabel('Time [s]')
ylabel('Ball position [m]')

subplot(2,1,2)
plot(t, siny);
hold on;
plot(t, Pb_Ym)
legend('Reference Y', 'Measured position Y');
xlabel('Time [s]')
ylabel('Ball position [m]')

% figure;
% plot(t, Pm_Am)
% hold on;
% plot(t, Pm_Bm)
% plot(t, Pm_Cm)
% xlabel('Time [s]')
% ylabel('Motor position [m]')
% legend('Motor A', 'Motor B', 'Motor C')

figure; 
plot(cosy, siny)
hold on;
plot(Pb_Xm, Pb_Ym)
xlabel('Position X [m]')
ylabel('Position Y [m]')
legend('Reference', 'Measured position')
ylim([-0.1, 0.1])