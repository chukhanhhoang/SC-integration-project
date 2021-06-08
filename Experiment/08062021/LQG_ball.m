load("ModelParameters.mat")
I_b = 2.2578e-05;

%% Controller settings
load("ExistingController.mat")
Ab = [0 1 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
Bb = [0 0; 0 g/(1+I_b/(m_b*r_b^2)); 0 0; -g/(1+I_b/(m_b*r_b^2)) 0];
Cb = [1 0 0 0; 0 0 1 0];

ballSystem = ss(Ab,Bb,Cb,zeros(2,2));
Q = [4 0 0 0;0 0 0 0;0 0 4 0;0 0 0 0];
R = 0.1*eye(2);
ballLQRgain = lqr(ballSystem, Q, R);
