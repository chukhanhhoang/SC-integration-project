function ydot = plateToBallLinear(t, y, theta_1, theta_2, I_b, m_b, R_b)
    % y = [x, y, xdot, ydot]
    % ydot = [xdot, ydot, xddot, yddot]
    g = 9.81;

    ydot = [y(3:4);
            theta_1 * g/(1+I_b/(m_b*R_b^2));
            theta_2 * g/(1+I_b/(m_b*R_b^2))];
end