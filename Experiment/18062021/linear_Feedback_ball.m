load("ModelParameters.mat")
I_b = 2.2578e-05;

%% Controller settings
% load("ExistingController.mat")
Ab = [0 1 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
Bb = [0 0; 0 g/(1+I_b/(m_b*r_b^2)); 0 0; -g/(1+I_b/(m_b*r_b^2)) 0];
Cb = [1 0 0 0; 0 0 1 0];

ballSystem = ss(Ab,Bb,Cb,zeros(2,2));
Q = [4 0 0 0;0 0.1 0 0;0 0 4 0;0 0 0 0.1];
R = 0.2*eye(2);
ballLQRgain = lqr(ballSystem, Q, R);
ballKgain = place(Ab,Bb,[-2.5 -2.49 -2.5 -2.51]);

% Designed controller
G = 10000;
L1 = tf([1/((200/3)) 1], [1/((200*3)) 1]);
L2 = tf([1/((200/6)) 1], [1/((200*6)) 1]);

Controller = G * L1 * L2; 
numc_mi = Controller.Numerator{1};
denc_mi = Controller.Denominator{1};
% 
% guy = load("ExistingController.mat");
% 
% guyController = tf(guy.numc_mi,guy.denc_mi);
% bode(Controller,guyController)