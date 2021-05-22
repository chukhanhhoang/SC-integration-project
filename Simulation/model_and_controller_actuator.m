%**** linear plant model*****
%
%  X(s)      Km/m
%  --- = -------------
%  I(s)    s(s+Cv/m)
%
% with x in [m] and i in [A]

Ts=1/2000;
Ts_Outer= 0.1;

m=0.367;
Km=11;
Cv=16.5;

Kp=Km/m;
p=-Cv/m;

Hp=zpk([],[0 -Cv/m],Km/m);


% Controller

B=200; %was 300 wl
% choose the controller gain such that the open loop magnitude is 0dB at w=B
% the plant magnitude at w=B is:
P_magn=Kp/(B*sqrt(p^2+B^2));
% the controller magnitude at w=B is:
C_magn=1/(B*18);
%The required controller gain to make the open loop magnitude 0dB at w=B must then be:
Kc=0.6*1/(P_magn*C_magn);%wl:gain multiplied by 0.2

Hc=zpk([-B/3 -B/6],[-3*B -6*B 0],Kc);

sisotool(Hp,Hc)

% same controller minus the integrator for dSPACE implementation.
% integrator is added as separate block, where the saturation limits can be
% set to avoid integrator wind-up.

Hc_mi=zpk([-B/3 -B/6],[-3*B -6*B],Kc);
[numc_mi,denc_mi]=tfdata(Hc_mi,'v');




