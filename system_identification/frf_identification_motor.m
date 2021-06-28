clc; clear; close all;
addpath(genpath(pwd)); % Add files;

load('Motor1.mat');
load('Motor2.mat');
load('Motor3.mat');


% Variables assign
u_A = Motor1.Y(1).Data;  u_A = u_A';
r_A  = Motor1.Y(7).Data; r_A = r_A';
e_A  = Motor1.Y(4).Data; e_A = -e_A';

u_B = Motor2.Y(2).Data;  u_B = u_B';
r_B  = Motor2.Y(8).Data; r_B = r_B';
e_B  = Motor2.Y(5).Data; e_B = -e_B';

u_C = Motor3.Y(3).Data;  u_C = u_C';
r_C  = Motor3.Y(9).Data; r_C = r_C';
e_C  = Motor3.Y(6).Data; e_C = -e_C';

% Define identified parameters
Fs = 1000;
nfft = 2 * Fs;
overlap = round(nfft/2);
window = hann(nfft);

[S_A, hz_A] = tfestimate(r_A, u_A, window, overlap, nfft, Fs);
[PS_A, hz_A] = tfestimate(r_A, e_A, window, overlap, nfft, Fs);

[S_B, hz_B] = tfestimate(r_B, u_B, window, overlap, nfft, Fs);
[PS_B, hz_B] = tfestimate(r_B, e_B, window, overlap, nfft, Fs);

[S_C, hz_C] = tfestimate(r_C, u_C, window, overlap, nfft, Fs);
[PS_C, hz_C] = tfestimate(r_C, e_C, window, overlap, nfft, Fs);

H_A = -PS_A ./ S_A;
H_B = -PS_B ./ S_B;
H_C = -PS_C ./ S_C;


%% Computation

% Magitude in dB
dB_H_A = mag2db(abs(H_A));
phase_H_A = rad2deg(angle(H_A));

dB_H_B = mag2db(abs(H_B));
phase_H_B = rad2deg(angle(H_B));

dB_H_C = mag2db(abs(H_C));
phase_H_C = rad2deg(angle(H_C));

% Coherence
[c_du_A,fc_du_A] = mscohere(r_A, u_A, window, overlap, nfft, Fs);
[c_de_A,fc_de_A] = mscohere(r_A, e_A, window, overlap, nfft, Fs);

[c_du_B,fc_du_B] = mscohere(r_B, u_B, window, overlap, nfft, Fs);
[c_de_B,fc_de_B] = mscohere(r_B, e_B, window, overlap, nfft, Fs);

[c_du_C,fc_du_C] = mscohere(r_C, u_C, window, overlap, nfft, Fs);
[c_de_C,fc_de_C] = mscohere(r_C, e_C, window, overlap, nfft, Fs);

%% Visualization

% Mag
figure;
subplot(211);
semilogx(hz_A, dB_H_A);
hold on;
semilogx(hz_B, dB_H_B);
semilogx(hz_C, dB_H_C);
grid on;
xlabel('Frequency [Hz]');
ylabel('Magnitude [dB]');
legend('Motor A', 'Motor B', 'Motor C')

subplot(212);
semilogx(hz_A,  phase_H_A);
hold on;
semilogx(hz_B,  phase_H_B);
semilogx(hz_C,  phase_H_C);
grid on;
xlabel('Frequency [Hz]');
ylabel('Phase [deg]');
legend('Motor A', 'Motor B', 'Motor C')

% Coherence
figure;
plot(fc_du_A, c_du_A, fc_de_A, c_de_A, ...
    fc_du_B, c_du_B, fc_de_B, c_de_B, ...
    fc_du_C, c_du_C, fc_de_C, c_de_C);
grid on;
xlabel('Frequency [Hz]');
ylabel('C(f)');
legend('Sensitivity of Motor A', 'Process Sensitivity of Motor A', ...
       'Sensitivity of Motor B', 'Process Sensitivity of Motor B', ...
       'Sensitivity of Motor C', 'Process Sensitivity of Motor C')

