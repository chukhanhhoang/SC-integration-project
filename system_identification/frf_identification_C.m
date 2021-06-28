clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('Motor3.mat');

% Variables assign
u_C = Motor3.Y(3).Data;  u_C = u_C';
r_C  = Motor3.Y(9).Data; r_C = r_C';
e_C  = Motor3.Y(6).Data; e_C = -e_C';

% Define identified parameters
Fs = 1000;
nfft = 2 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_X, hz_X] = tfestimate(r_C, u_C, window, overlap, nfft, Fs);
[PS_X, hz_X] = tfestimate(r_C, e_C, window, overlap, nfft, Fs);

H_X = -PS_X ./ S_X;


%% Computation

% Magitude in dB
dB_H_X = mag2db(abs(H_X));
phase_H_X = rad2deg(angle(H_X));

% Coherence
[c_du_X,fc_du_X] = mscohere(r_C, u_C, window, overlap, nfft, Fs);
[c_de_X,fc_de_X] = mscohere(r_C, e_C, window, overlap, nfft, Fs);


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
legend('Coherence of Sensitivity', 'Coherence of Process Sensitivity')

xlabel('Frequency [Hz]');
ylabel('C(f)');


