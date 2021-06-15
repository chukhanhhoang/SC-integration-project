clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('data0416_3points_ballplate.mat');

% Variables assign
u_th1 = data0416_3points.Y(3).Data;
d_bY  = data0416_3points.Y(5).Data;
e_bY  = data0416_3points.Y(2).Data;

% Define identified parameters
Fs = 1000;
nfft = 4 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_Y, hz_Y] = tfestimate(d_bY, u_th1, window, overlap, nfft, Fs);
[PS_Y, hz_Y] = tfestimate(d_bY, e_bY, window, overlap, nfft, Fs);

H_Y = -PS_Y ./ S_Y;


%% Computation

% Magitude in dB
dB_H_Y = mag2db(abs(H_Y));
phase_H_Y = rad2deg(angle(H_Y));

% Coherence
[c_du_Y,fc_du_Y] = mscohere(d_bY, u_th1, window, overlap, nfft, Fs);
[c_de_Y,fc_de_Y] = mscohere(d_bY, e_bY, window, overlap, nfft, Fs);

%% Visualization

% Mag
figure;
subplot(211);
semilogx(hz_Y, dB_H_Y);
xlabel('Frequency [Hz]');
ylabel('Magnitude [dB]');

subplot(212);
semilogx(hz_Y,  phase_H_Y);
xlabel('Frequency [Hz]');
ylabel('Phase [deg]');

% Coherence
figure;
plot(fc_du_Y, c_du_Y, ...
    fc_de_Y, c_de_Y);
title('Coherence Function (var: 0.01)');
xlabel('Frequency [Hz]');
ylabel('C(f)');


