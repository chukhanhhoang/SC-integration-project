% Roll-Pitch-Yaw angles to motors position
% Roll (theta1): rotation about x-axis
% Pitch (theta2): rotation about y-axis
% Yaw (theta3): rotation about z-axis
% See page 12 and Appendix A (Multibody and Nonlinear Dynamics lecture
% notes for further reference
% Motors (1,2,3) -> (A,B,C)

function [theta1,theta2,theta3,Zc] = motorsToAngles2(motor1, motor2, motor3)

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
CPi_rotated = rBC+r0B-r0OC;
P1b = CPi_rotated(:,1);
P2b = CPi_rotated(:,2);
P3b = CPi_rotated(:,3);
disp(P3b)

%base frame unit vectors
UnitXp=P1b/sqrt(dot(P1b,P1b));
UnitZp=cross(UnitXp,P3b);
disp(UnitZp)
UnitZp=UnitZp/sqrt(dot(UnitZp,UnitZp)); %now length 1
disp(UnitXp)
disp(UnitZp)
UnitYp=cross(UnitXp,UnitZp);

theta2=asin(-UnitXp(3));
theta3=asin(UnitXp(2)/sqrt(1-UnitXp(3)^2));
disp(UnitYp(3));
disp(sqrt(1-UnitXp(3)^2));
theta1=asin(UnitYp(3)/sqrt(1-UnitXp(3)^2));

end