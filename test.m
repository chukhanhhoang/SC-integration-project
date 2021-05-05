clear all; clc;

% Test1: angles-> motors -> angles
theta1 = 0.08; theta2 = 0.009; theta3 = 0; Zc = 0.35;

[motor1, motor2, motor3] = anglesToMotors(theta1,theta2,theta3,Zc);

[theta1t1,theta2t1,theta3m,Zct1] = motorsToAngles(motor1, motor2, motor3);

%Test2: motors -> angles -> motors
motor1 = 0.37; motor2 = 0.34; motor3 = 0.3513;

[theta1t2,theta2t2,theta3t2,Zct2] = motorsToAngles(motor1, motor2, motor3);
[motor1t2, motor2t2, motor3t2] = anglesToMotors(theta1t2,theta2t2,theta3t2,Zct2);
