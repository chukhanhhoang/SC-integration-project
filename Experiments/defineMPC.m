function mpc_controller = defineMPC()
    % Parameters Init
    g = 9.81; r = 0.17;
    m_m = 0.118;
    m_p = 0.9;
    I_p = m_p*0.04^2/12;
    K=11;
    C_v=16.5;
    r_b = 0.019;
    m_b = 0.024;
    I_b = m_b*r_b^2;

    I0 = (m_p+3*m_m)*g/(3*K);
    
    % Define system ball & plate system plant
    h = g/(1 + I_b/(m_b*r_b^2));
    Ac = [0 1 0 0;
          0 0 0 0;
          0 0 0 1;
          0 0 0 0]; % 4x4 matrix
    Bc = [0 0; 0 h; 0 0; -h 0]; % 4x2 matrix
    Cc = [1 0 0 0;
          0 0 1 0];
    Dc = diag([0 0]);
    sysc = ss(Ac, Bc, Cc, Dc);

    % Define MPC controller
    %% create MPC controller object with sample time
    mpc_controller = mpc(sysc, 0.04);
    %% specify prediction horizon
    mpc_controller.PredictionHorizon = 3;
    %% specify control horizon
    mpc_controller.ControlHorizon = 3;
    %% specify nominal values for inputs and outputs
    mpc_controller.Model.Nominal.U = [0;0];
    mpc_controller.Model.Nominal.Y = [0;0];
    %% specify constraints for MV and MV Rate
    mpc_controller.MV(1).Min = -0.08;
    mpc_controller.MV(1).Max = 0.08;
    mpc_controller.MV(2).Min = -0.08;
    mpc_controller.MV(2).Max = 0.08;
    %% specify constraints for OV
    mpc_controller.OV(1).Min = -0.3;
    mpc_controller.OV(1).Max = 0.3;
    mpc_controller.OV(2).Min = -0.3;
    mpc_controller.OV(2).Max = 0.3;
    %% specify weights
    mpc_controller.Weights.MV = [0.1 0.1];
    mpc_controller.Weights.MVRate = [0.1 0.1];
    mpc_controller.Weights.OV = [1 1];
    mpc_controller.Weights.ECR = 100000;
end