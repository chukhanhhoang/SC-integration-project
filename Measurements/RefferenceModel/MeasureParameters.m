% Designed controller
clear all;
G = 10000;
L1 = tf([1/((200/3)) 1], [1/((200*3)) 1]);
L2 = tf([1/((200/6)) 1], [1/((200*6)) 1]);

Controller = G * L1 * L2; 
Default_numc_mi = Controller.Numerator{1};
Default_denc_mi = Controller.Denominator{1};

f = 1;
LowPass = tf([1],[1/(2*pi*f) 1]);
LowPass_numc_mi = LowPass.Numerator{1};
LowPass_denc_mi = LowPass.Denominator{1};

save("MeasureParameters.mat")
