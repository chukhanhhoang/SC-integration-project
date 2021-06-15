load("ModelParameters.mat")
I_b = 2.2578e-05;

%% Controller settings
% load("ExistingController.mat")
Ab = [0 1 0 0; 0 0 0 0; 0 0 0 1; 0 0 0 0];
Bb = [0 0; 0 g/(1+I_b/(m_b*r_b^2)); 0 0; -g/(1+I_b/(m_b*r_b^2)) 0];
Cb = [1 0 0 0; 0 0 1 0];

ballSystem = ss(Ab,Bb,Cb,zeros(2,2));
Q = [4 0 0 0;0 0 0 0;0 0 4 0;0 0 0 0];
R = 0.2*eye(2);
% ballLQRgain = lqr(ballSystem, Q, R);
ballLQRgain = place(Ab,Bb,[-2.5,-2.49,-2.5,-2.51]);

I_0 = (3*m_m + m_p)*g/(3*K);
M = diag([3/2*m_m*r^2,3/2*m_m*r^2,3*m_m+m_p]);
N = -diag([3/2*C_v*r^2,3/2*C_v*r^2,3*C_v]);
P = [0 sqrt(3)*r*K/2 -sqrt(3)*r*K/2; -r*K r*K/2 r*K/2; 1 1 1];

A = [zeros(3) eye(3);zeros(3) inv(M)*N];
B = [zeros(3);inv(M)*P];
C = [eye(3) zeros(3)];
D = zeros(3);
plateSystem = ss(A,B,C,D);

Qp = 10*eye(6);Qp(6,6)=0.001;Qp(4,4)=0.001;Qp(5,5)=0.001; Qp(3,3)=1;
Rp = 3*eye(3);
plateLQRgain = lqr(plateSystem, Qp, Rp);

% Designed controller
% G = 10000;
% L1 = tf([1/((200/3)) 1], [1/((200*3)) 1]);
% L2 = tf([1/((200/6)) 1], [1/((200*6)) 1]);

% Controller = G * L1 * L2; 
% numc_mi = Controller.Numerator{1};
% denc_mi = Controller.Denominator{1};
% 
% guy = load("ExistingController.mat");
% 
% guyController = tf(guy.numc_mi,guy.denc_mi);
% bode(Controller,guyController)