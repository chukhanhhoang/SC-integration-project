clear all; clc;

g = 9.81; r = 0.17;
m_m = 0.118;
m_p = 0.9;
I_p = m_p*0.04^2/12;
K=11;
C_v=16.5;
r_b = 0.019;
m_b = 0.024;
I_b = m_b*r_b^2;

motorPlateInit = [0;0;0;0;0;0.32];
ballPosInit = [0;0;0;0];