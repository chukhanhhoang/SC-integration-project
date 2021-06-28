clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('Motor1.mat');

% Variables assign
u_A = Motor1.Y(1).Data;  u_A = u_A';
r_A  = Motor1.Y(7).Data; r_A = r_A';
e_A  = Motor1.Y(4).Data; e_A = -e_A';

% Define identified parameters
Fs = 1000;
nfft = 4 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_X, hz_X] = tfestimate(r_A, u_A, window, overlap, nfft, Fs);
[PS_X, hz_X] = tfestimate(r_A, e_A, window, overlap, nfft, Fs);

H_X = -PS_X ./ S_X;

% Designed controller
G = 10000;
L1 = tf([1/((200/3)) 1], [1/((200*3)) 1]);
L2 = tf([1/((200/6)) 1], [1/((200*6)) 1]);
s  = tf([1], [1 0]);

Controller = G * L1 * L2 * s; 
C_freqresp = freqresp(Controller, H_X);
C_real = real(C_freqresp); C_real = reshape(C_real, [1, 2001]);
C_imag = imag(C_freqresp); C_imag = reshape(C_imag, [1, 2001]);

figure;
plot(C_real, C_imag)

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


