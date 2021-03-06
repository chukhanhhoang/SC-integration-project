% Roll-Pitch-Yaw angles to motors position
% Roll (theta1): rotation about x-axis
% Pitch (theta2): rotation about y-axis
% Yaw (theta3): rotation about z-axis
% See page 12 and Appendix A (Multibody and Nonlinear Dynamics lecture
% notes for further reference
% Motors (1,2,3) -> (A,B,C)

function [motor1, motor2, motor3] = anglesToMotors(theta1,theta2,theta3,Zc)

%% Define parameters
r = 0.17;
r0B1 = [r; 0; 0];      
r0B2 = [-0.5*r; (sqrt(3)/2)*r; 0];
r0B3 = [-0.5*r; -(sqrt(3)/2)*r; 0];
r0B = [r0B1 r0B2 r0B3];
%r1C1 = r0B1; r1C2 = r0B2; r1C3 = r0B3;
r1C = r0B;
r0Oc = [0;0;Zc];

% Find cos and sin to accelerate calculations
C1 = cos(theta1);S1 = sin(theta1);C2 = cos(theta2);S2 = sin(theta2);C3 = cos(theta3);S3 = sin(theta3);

% Rotation matrices
RotZ = [C3 S3 0; -S3 C3 0; 0 0 1];
RotY = [C2 0 -S2; 0 1 0; S2 0 C2];
RotX = [1 0 0; 0 C1 S1; 0 -S1 C1];

A10 = RotX*RotY*RotZ; A01 = A10';

% Find rCiBi (Vectors representing the motors)
rCiBi = zeros(3,3);
for i=1:3
    rCiBi(:,i) = r0Oc + A01*r1C(:,i) - r0B(:,i);
end

% Outputs to motor are the lengths of the vectors
motor1 = norm(rCiBi(:,1));
motor2 = norm(rCiBi(:,2));
motor3 = norm(rCiBi(:,3));
end

