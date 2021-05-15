function V = motorPlateODElinear(t,Y,C_v,I_1,I_2,I_3,I_p,K,g,m_m,m_p,r)
%MOTORPLATEODELINEAR
%    V = MOTORPLATEODELINEAR(T,Y,C_V,I_1,I_2,I_3,I_P,K,G,M_M,M_P,R)

%    This function was generated by the Symbolic Math Toolbox version 58.4.
%    13-May-2021 20:04:38

%matrix([[omega_2f], [omega_1f], [dz_Cf], [theta_1f], [theta_2f], [z_Cf]])
t2 = I_p.*2.0;
t3 = Y(1);
t4 = Y(2);
t5 = Y(3);
t6 = r.^2;
t7 = I_2.*K;
t8 = I_3.*K;
t9 = sqrt(3.0);
t10 = -t7;
t11 = -t8;
t12 = m_m.*t6.*3.0;
t13 = t2+t12;
t14 = 1.0./t13;
V = [r.*t14.*(t7+t8-I_1.*K.*2.0-C_v.*r.*t3.*3.0);-r.*t14.*(t8.*t9+t9.*t10+C_v.*r.*t4.*3.0);-(m_p+t10+t11+C_v.*t5.*3.0+g.*m_m.*3.0-I_1.*K)./(m_m.*3.0+m_p);t4;t3;t5];
