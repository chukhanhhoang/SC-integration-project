

function dydt = AngleToPosition(t, y)
    % dim of y: 8 x 1 [q qdot] q = [x y alpha beta]
    
    % Define system parameters
    % TODO: Define all system parameters
    Ib = 0; % Moment of inertia of the ball
    Ip = 0; % Moment of inertia of the plate
    r  = 0; % Radius of the ball
    m  = 0; % Mass   of the ball
    g  = 9.81;
    
    a1 = m+Ib/r^2; a2 = m*r; a3 = Ib/r; a4 = m*g; a5 = m;
    b1 = m*r^2;    b2 = 2*Ib+Ip;
    
    % Define M, H and S
    M = [a1 0 a2 a3;
         0 a1 a3 a2;
         a2 a3 b1+2*a5*y(1)^2+b2 a5*y(1)*y(2);
         a3 a2 a5*y(1)*y(2) b1+2*a5*y(2)^2+b2];
    invM = inv(M);
    
    H = [2*a5*y(1)*y(7)^2-a5*y(2)*y(7)*y(8)-a4*sin(y(3));
         2*a5*y(2)*y(8)^2-a5*y(1)*y(7)*y(8)-a4*sin(y(4));
         a5*(4*y(1)*y(5)*y(7)+y(2)*y(5)*y(8)+y(1)*y(6)*y(8))-a4*y(1)*cos(y(3));
         a5*(4*y(2)*y(6)*y(8)+y(1)*y(6)*y(7)+y(2)*y(5)*y(7))-a4*y(2)*cos(y(4))];
     
    S = [0 0 0 0;
         0 0 0 0;
         0 0 1 0;
         0 0 0 1];
    
    taux = 0; tauy = 0; % TODO: Define external forces
    tau = [0; 0; taux; tauy];
    
    dydt = [y(5:8);
            -invM*H+invM*S*tau];
end