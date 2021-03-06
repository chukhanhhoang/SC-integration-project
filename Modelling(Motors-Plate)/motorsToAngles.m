% Roll-Pitch-Yaw angles to motors position
% Roll (theta1): rotation about x-axis
% Pitch (theta2): rotation about y-axis
% Yaw (theta3): rotation about z-axis
% See page 12 and Appendix A (Multibody and Nonlinear Dynamics lecture
% notes for further reference
% Motors (1,2,3) -> (A,B,C)

function [theta1,theta2,theta3,Zc] = motorsToAngles(motor1, motor2, motor3)

%% Define parameters
r = 0.17;
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r0B = [r0B1 r0B2 r0B3];
%r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r1C = r0B;

%% Find Zc
Zc = 1/3*(motor1+motor2+motor3);
r0Oc = [0;0;Zc];

%% Assemble matrices
rBC = [0 0 0; 0 0 0; motor1 motor2 motor3];
r0OC = [r0Oc r0Oc r0Oc];

%% Find A10 (Using \ operator to solve a system of linear equation since the matrix r1C is singular)
A10 = (r1C')\((rBC+r0B-r0OC)');

%% Find angles
theta2 = asin(-A10(1,3));
theta1 = asin(1/cos(theta2)*A10(2,3));
theta3 = asin(1/cos(theta2)*A10(1,2));
end