clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('Motor1withPos.mat');

% Variables assign
u_A = Motor1withPos.Y(1).Data;  u_A = u_A';
r_A  = Motor1withPos.Y(7).Data; r_A = r_A';
e_A  = Motor1withPos.Y(4).Data; e_A = -e_A';

% Define identified parameters
Fs = 1000;
nfft = 4 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_X, hz_X] = tfestimate(r_A, u_A, window, overlap, nfft, Fs);
[PS_X, hz_X] = tfestimate(r_A, e_A, window, overlap, nfft, Fs);

H_X = -PS_X ./ S_X;


%% Computation

% Magitude in dB
dB_H_X = mag2db(abs(H_X));
phase_H_X = rad2deg(angle(H_X));

% Coherence
[c_du_X,fc_du_X] = mscohere(r_A, u_A, window, overlap, nfft, Fs);
[c_de_X,fc_de_X] = mscohere(r_A, e_A, window, overlap, nfft, Fs);

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


