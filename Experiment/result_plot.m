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
cosy = 0.1*cos(4/10 * pi *t + pi/3);
siny = 0.1*cos(4/10 * pi *t + 2.5*pi/3);

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


figure;
plot(cosy, siny)
hold on;
plot(Pb_Xm, Pb_Ym)
xlabel('Position X [m]')
ylabel('Position Y [m]')
legend('Reference', 'Measured position')