clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('theta2_trial3.mat');

% Variables assign
u_th2 = theta2_trial3.Y(4).Data;
d_bX  = theta2_trial3.Y(2).Data;
e_bX  = theta2_trial3.Y(5).Data; e_bX = -e_bX;

% Define identified parameters
Fs = 1000;
nfft = 4 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_X, hz_X] = tfestimate(d_bX, u_th2, window, overlap, nfft, Fs);
[PS_X, hz_X] = tfestimate(d_bX, e_bX, window, overlap, nfft, Fs);

H_X = -PS_X ./ S_X;


%% Computation

% Magitude in dB
dB_H_X = mag2db(abs(H_X));
phase_H_X = rad2deg(angle(H_X));

% Coherence
[c_du_X,fc_du_X] = mscohere(d_bX, u_th2, window, overlap, nfft, Fs);
[c_de_X,fc_de_X] = mscohere(d_bX, e_bX, window, overlap, nfft, Fs);

%% Visualization

% Mag
figure;
subplot(211);
semilogx(hz_X, dB_H_X);
xlabel('Frequency [Hz]');
ylabel('Magnitude [dB]');

subplot(212);
semilogx(hz_X,  phase_H_X);
xlabel('Frequency [Hz]');
ylabel('Phase [deg]');

% Coherence
figure;
plot(fc_du_X, c_du_X, ...
    fc_de_X, c_de_X);
title('Coherence Function (var: 0.01)');
xlabel('Frequency [Hz]');
ylabel('C(f)');


