/*
 * Code generation for system model 'MPC_Controller'
 * For more details, see corresponding source file MPC_Controller.c
 *
 */

#ifndef RTW_HEADER_MPC_Controller_h_
#define RTW_HEADER_MPC_Controller_h_
#include <math.h>
#include <string.h>
#ifndef MPC_Controller_COMMON_INCLUDES_
# define MPC_Controller_COMMON_INCLUDES_
#include <rti_assert.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* MPC_Controller_COMMON_INCLUDES_ */

#include "MPC_Controller_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "model_reference_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Block signals for model 'MPC_Controller' */
#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  real_T dv[2520];
  real_T DataTypeConversion1[2];       /* '<S8>/Data Type Conversion1' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T TransferFcn2;                 /* '<S3>/Transfer Fcn2' */
  real_T Sum_k;                        /* '<S4>/Sum' */
  real_T TransferFcn2_c;               /* '<S4>/Transfer Fcn2' */
  real_T Sum_h;                        /* '<S5>/Sum' */
  real_T TransferFcn2_i;               /* '<S5>/Transfer Fcn2' */
  real_T xk1[4];                       /* '<S28>/optimizer' */
  real_T u[2];                         /* '<S28>/optimizer' */
  real_T motor1;                       /* '<Root>/MATLAB Function' */
  real_T motor2;                       /* '<Root>/MATLAB Function' */
  real_T motor3;                       /* '<Root>/MATLAB Function' */
  boolean_T iAout[120];                /* '<S28>/optimizer' */
} B_MPC_Controller_c_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'MPC_Controller' */
#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  real_T last_mv_DSTATE[2];            /* '<S8>/last_mv' */
  real_T last_x_PreviousInput[4];      /* '<S8>/last_x' */
  real_T lastSin;                      /* '<S7>/Sine Wave' */
  real_T lastCos;                      /* '<S7>/Sine Wave' */
  real_T lastSin_j;                    /* '<S7>/Sine Wave1' */
  real_T lastCos_f;                    /* '<S7>/Sine Wave1' */
  int32_T systemEnable;                /* '<S7>/Sine Wave' */
  int32_T systemEnable_h;              /* '<S7>/Sine Wave1' */
  boolean_T Memory_PreviousInput[120]; /* '<S8>/Memory' */
} DW_MPC_Controller_f_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/* Continuous states for model 'MPC_Controller' */
#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<S3>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_f;         /* '<S4>/Integrator2' */
  real_T TransferFcn2_CSTATE_e[2];     /* '<S4>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_m;         /* '<S5>/Integrator2' */
  real_T TransferFcn2_CSTATE_p[2];     /* '<S5>/Transfer Fcn2' */
} X_MPC_Controller_n_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/* State derivatives for model 'MPC_Controller' */
#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<S3>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_f;         /* '<S4>/Integrator2' */
  real_T TransferFcn2_CSTATE_e[2];     /* '<S4>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_m;         /* '<S5>/Integrator2' */
  real_T TransferFcn2_CSTATE_p[2];     /* '<S5>/Transfer Fcn2' */
} XDot_MPC_Controller_n_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/* State Disabled for model 'MPC_Controller' */
#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S3>/Integrator2' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S3>/Transfer Fcn2' */
  boolean_T Integrator2_CSTATE_f;      /* '<S4>/Integrator2' */
  boolean_T TransferFcn2_CSTATE_e[2];  /* '<S4>/Transfer Fcn2' */
  boolean_T Integrator2_CSTATE_m;      /* '<S5>/Integrator2' */
  boolean_T TransferFcn2_CSTATE_p[2];  /* '<S5>/Transfer Fcn2' */
} XDis_MPC_Controller_n_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

/* Parameters (default storage) */
struct P_MPC_Controller_T_ {
  real_T Gain1_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.1
                                        * Referenced by: '<S7>/Gain'
                                        */
  real_T last_x_InitialCondition[4];   /* Expression: lastx+xoff
                                        * Referenced by: '<S8>/last_x'
                                        */
  real_T last_mv_InitialCondition[2];  /* Expression: lastu+uoff
                                        * Referenced by: '<S8>/last_mv'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<S7>/Sine Wave'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 1
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_Hsin;               /* Computed Parameter: SineWave1_Hsin
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_HCos;               /* Computed Parameter: SineWave1_HCos
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_PSin;               /* Computed Parameter: SineWave1_PSin
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T SineWave1_PCos;               /* Computed Parameter: SineWave1_PCos
                                        * Referenced by: '<S7>/Sine Wave1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T md_zero_Value;                /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/md_zero'
                                        */
  real_T umin_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/umin_zero'
                                        */
  real_T umin_scale_Gain[2];           /* Expression: RMVscale
                                        * Referenced by: '<S8>/umin_scale'
                                        */
  real_T umax_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/umax_zero'
                                        */
  real_T umax_scale_Gain[2];           /* Expression: RMVscale
                                        * Referenced by: '<S8>/umax_scale'
                                        */
  real_T ymin_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/ymin_zero'
                                        */
  real_T ymin_scale_Gain[2];           /* Expression: RYscale
                                        * Referenced by: '<S8>/ymin_scale'
                                        */
  real_T ymax_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/ymax_zero'
                                        */
  real_T ymax_scale_Gain[2];           /* Expression: RYscale
                                        * Referenced by: '<S8>/ymax_scale'
                                        */
  real_T E_zero_Value[2];              /* Expression: zeros(1,2)
                                        * Referenced by: '<S2>/E_zero'
                                        */
  real_T umin_scale4_Gain[2];      /* Expression: MVscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S8>/umin_scale4'
                                    */
  real_T F_zero_Value[2];              /* Expression: zeros(1,2)
                                        * Referenced by: '<S2>/F_zero'
                                        */
  real_T ymin_scale1_Gain[2];       /* Expression: Yscale(:,ones(1,max(nCC,1)))'
                                     * Referenced by: '<S8>/ymin_scale1'
                                     */
  real_T G_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/G_zero'
                                        */
  real_T S_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/S_zero'
                                        */
  real_T ymin_scale2_Gain;         /* Expression: MDscale(:,ones(1,max(nCC,1)))'
                                    * Referenced by: '<S8>/ymin_scale2'
                                    */
  real_T switch_zero_Value;            /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/switch_zero'
                                        */
  real_T extmv_zero_Value[2];          /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/ext.mv_zero'
                                        */
  real_T extmv_scale_Gain[2];          /* Expression: RMVscale
                                        * Referenced by: '<S8>/ext.mv_scale'
                                        */
  real_T mvtarget_zero_Value[2];       /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/mv.target_zero'
                                        */
  real_T extmv_scale1_Gain[2];         /* Expression: RMVscale
                                        * Referenced by: '<S8>/ext.mv_scale1'
                                        */
  real_T ywt_zero_Value[2];            /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/y.wt_zero'
                                        */
  real_T uwt_zero_Value[2];            /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/u.wt_zero'
                                        */
  real_T duwt_zero_Value[2];           /* Expression: zeros(2,1)
                                        * Referenced by: '<S2>/du.wt_zero'
                                        */
  real_T ecrwt_zero_Value;             /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/ecr.wt_zero'
                                        */
  real_T umin_scale1_Gain[2];          /* Expression: MVscale
                                        * Referenced by: '<S8>/umin_scale1'
                                        */
  real_T theta3_Value;                 /* Expression: 0
                                        * Referenced by: '<Root>/theta3'
                                        */
  real_T Zc_Value;                     /* Expression: 0.32
                                        * Referenced by: '<Root>/Zc'
                                        */
  real_T p_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/p_zero'
                                        */
  real_T m_zero_Value;                 /* Expression: zeros(1,1)
                                        * Referenced by: '<S2>/m_zero'
                                        */
  real_T umin_scale3_Gain[42];         /* Expression: MVscale(:,ones(1,p+1))'
                                        * Referenced by: '<S8>/umin_scale3'
                                        */
  real_T umin_scale5_Gain[42];         /* Expression: Yscale(:,ones(1,p+1))'
                                        * Referenced by: '<S8>/umin_scale5'
                                        */
  real_T constant_Value[2];            /* Expression: lastu+uoff
                                        * Referenced by: '<S8>/constant'
                                        */
  real_T umin_scale2_Gain[2];          /* Expression: MVscale
                                        * Referenced by: '<S8>/umin_scale2'
                                        */
  real_T ym_zero_Value[2];             /* Expression: zeros(nym,1)
                                        * Referenced by: '<S8>/ym_zero'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Integrator2_UpperSat;         /* Expression: 3
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Integrator2_LowerSat;         /* Expression: -3
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Integrator2_IC_c;             /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_UpperSat_g;       /* Expression: 3
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_LowerSat_a;       /* Expression: -3
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_UpperSat_j;       /* Expression: 3
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_LowerSat_j;       /* Expression: -3
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch4'
                                        */
  uint16_T MatrixDimensionCheck_P1[29];
                                  /* Computed Parameter: MatrixDimensionCheck_P1
                                   * Referenced by: '<S9>/Matrix Dimension Check'
                                   */
  uint16_T MatrixDimensionCheck_P2[18];
                                  /* Computed Parameter: MatrixDimensionCheck_P2
                                   * Referenced by: '<S9>/Matrix Dimension Check'
                                   */
  uint16_T MatrixDimensionCheck_P3;    /* Expression: nrow
                                        * Referenced by: '<S9>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4;    /* Expression: ncol
                                        * Referenced by: '<S9>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P5;    /* Expression: nsteps
                                        * Referenced by: '<S9>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P6;    /* Expression: isltv
                                        * Referenced by: '<S9>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_j[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_j
                                 * Referenced by: '<S10>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_a[18];
                                /* Computed Parameter: MatrixDimensionCheck_P2_a
                                 * Referenced by: '<S10>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_l;  /* Expression: nrow
                                        * Referenced by: '<S10>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_j;  /* Expression: ncol
                                        * Referenced by: '<S10>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P5_h;  /* Expression: nsteps
                                        * Referenced by: '<S10>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P6_n;  /* Expression: isltv
                                        * Referenced by: '<S10>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_o[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_o
                                 * Referenced by: '<S11>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_l[18];
                                /* Computed Parameter: MatrixDimensionCheck_P2_l
                                 * Referenced by: '<S11>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_k;  /* Expression: nrow
                                        * Referenced by: '<S11>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_jp; /* Expression: ncol
                                        * Referenced by: '<S11>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P5_o;  /* Expression: nsteps
                                        * Referenced by: '<S11>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P6_j;  /* Expression: isltv
                                        * Referenced by: '<S11>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_o1[29];
                               /* Computed Parameter: MatrixDimensionCheck_P1_o1
                                * Referenced by: '<S12>/Matrix Dimension Check'
                                */
  uint16_T MatrixDimensionCheck_P2_h[3];
                                /* Computed Parameter: MatrixDimensionCheck_P2_h
                                 * Referenced by: '<S12>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_i;  /* Expression: nrow
                                        * Referenced by: '<S12>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_n;  /* Expression: ncol
                                        * Referenced by: '<S12>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_i[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_i
                                 * Referenced by: '<S13>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_o[2];
                                /* Computed Parameter: MatrixDimensionCheck_P2_o
                                 * Referenced by: '<S13>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_c;  /* Expression: nrow
                                        * Referenced by: '<S13>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_c;  /* Expression: ncol
                                        * Referenced by: '<S13>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_a[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_a
                                 * Referenced by: '<S14>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_m[4];
                                /* Computed Parameter: MatrixDimensionCheck_P2_m
                                 * Referenced by: '<S14>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_n;  /* Expression: nrow
                                        * Referenced by: '<S14>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_k;  /* Expression: ncol
                                        * Referenced by: '<S14>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_f[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_f
                                 * Referenced by: '<S15>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_f[4];
                                /* Computed Parameter: MatrixDimensionCheck_P2_f
                                 * Referenced by: '<S15>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_a;  /* Expression: nrow
                                        * Referenced by: '<S15>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_jn; /* Expression: ncol
                                        * Referenced by: '<S15>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P1_h[29];
                                /* Computed Parameter: MatrixDimensionCheck_P1_h
                                 * Referenced by: '<S16>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P2_p[5];
                                /* Computed Parameter: MatrixDimensionCheck_P2_p
                                 * Referenced by: '<S16>/Matrix Dimension Check'
                                 */
  uint16_T MatrixDimensionCheck_P3_n0; /* Expression: nrow
                                        * Referenced by: '<S16>/Matrix Dimension Check'
                                        */
  uint16_T MatrixDimensionCheck_P4_jc; /* Expression: ncol
                                        * Referenced by: '<S16>/Matrix Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1[29];
                                  /* Computed Parameter: VectorDimensionCheck_P1
                                   * Referenced by: '<S17>/Vector Dimension Check'
                                   */
  uint16_T VectorDimensionCheck_P2[6];
                                  /* Computed Parameter: VectorDimensionCheck_P2
                                   * Referenced by: '<S17>/Vector Dimension Check'
                                   */
  uint16_T VectorDimensionCheck_P1_d[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_d
                                 * Referenced by: '<S18>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_m[6];
                                /* Computed Parameter: VectorDimensionCheck_P2_m
                                 * Referenced by: '<S18>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P1_k[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_k
                                 * Referenced by: '<S19>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_j;
                                /* Computed Parameter: VectorDimensionCheck_P2_j
                                 * Referenced by: '<S19>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P1_m[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_m
                                 * Referenced by: '<S20>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_b[6];
                                /* Computed Parameter: VectorDimensionCheck_P2_b
                                 * Referenced by: '<S20>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3;    /* Expression: n
                                        * Referenced by: '<S20>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4;    /* Expression: option
                                        * Referenced by: '<S20>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_b[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_b
                                 * Referenced by: '<S21>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_k[18];
                                /* Computed Parameter: VectorDimensionCheck_P2_k
                                 * Referenced by: '<S21>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3_b;  /* Expression: n
                                        * Referenced by: '<S21>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_h;  /* Expression: option
                                        * Referenced by: '<S21>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_h[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_h
                                 * Referenced by: '<S22>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_kt[2];
                               /* Computed Parameter: VectorDimensionCheck_P2_kt
                                * Referenced by: '<S22>/Vector Dimension Check'
                                */
  uint16_T VectorDimensionCheck_P3_e;  /* Expression: n
                                        * Referenced by: '<S22>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_n;  /* Expression: option
                                        * Referenced by: '<S22>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_g[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_g
                                 * Referenced by: '<S23>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_d[4];
                                /* Computed Parameter: VectorDimensionCheck_P2_d
                                 * Referenced by: '<S23>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3_a;  /* Expression: n
                                        * Referenced by: '<S23>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_f;  /* Expression: option
                                        * Referenced by: '<S23>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_f[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_f
                                 * Referenced by: '<S24>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_l[4];
                                /* Computed Parameter: VectorDimensionCheck_P2_l
                                 * Referenced by: '<S24>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3_br; /* Expression: n
                                        * Referenced by: '<S24>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_e;  /* Expression: option
                                        * Referenced by: '<S24>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_l[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_l
                                 * Referenced by: '<S25>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_bk[4];
                               /* Computed Parameter: VectorDimensionCheck_P2_bk
                                * Referenced by: '<S25>/Vector Dimension Check'
                                */
  uint16_T VectorDimensionCheck_P3_n;  /* Expression: n
                                        * Referenced by: '<S25>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_m;  /* Expression: option
                                        * Referenced by: '<S25>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_i[29];
                                /* Computed Parameter: VectorDimensionCheck_P1_i
                                 * Referenced by: '<S26>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P2_i[4];
                                /* Computed Parameter: VectorDimensionCheck_P2_i
                                 * Referenced by: '<S26>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3_h;  /* Expression: n
                                        * Referenced by: '<S26>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_ey; /* Expression: option
                                        * Referenced by: '<S26>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P1_ky[29];
                               /* Computed Parameter: VectorDimensionCheck_P1_ky
                                * Referenced by: '<S27>/Vector Dimension Check'
                                */
  uint16_T VectorDimensionCheck_P2_h[9];
                                /* Computed Parameter: VectorDimensionCheck_P2_h
                                 * Referenced by: '<S27>/Vector Dimension Check'
                                 */
  uint16_T VectorDimensionCheck_P3_hb; /* Expression: n
                                        * Referenced by: '<S27>/Vector Dimension Check'
                                        */
  uint16_T VectorDimensionCheck_P4_l;  /* Expression: option
                                        * Referenced by: '<S27>/Vector Dimension Check'
                                        */
  boolean_T Memory_InitialCondition[120];/* Expression: iA
                                          * Referenced by: '<S8>/Memory'
                                          */
};

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_MPC_Controller_T {
  const char_T **errorStatus;
  RTWSolverInfo *solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize0;
    SimTimeStep *simTimeStep;
    boolean_T *stopRequestedFlag;
  } Timing;
};

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_MPC_Controller_T rtm;
} MdlrefDW_MPC_Controller_T;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/* Model block global parameters (default storage) */
extern real_T rtP_UseUserDefinedBallReference;/* Variable: UseUserDefinedBallReference
                                               * Referenced by: '<Root>/Constant'
                                               */
extern real_T rtP_UseUserDefinedPlateReference;/* Variable: UseUserDefinedPlateReference
                                                * Referenced by: '<Root>/Constant1'
                                                */
extern real_T rtP_denc_mi[3];          /* Variable: denc_mi
                                        * Referenced by:
                                        *   '<S3>/Transfer Fcn2'
                                        *   '<S4>/Transfer Fcn2'
                                        *   '<S5>/Transfer Fcn2'
                                        */
extern real_T rtP_numc_mi[3];          /* Variable: numc_mi
                                        * Referenced by:
                                        *   '<S3>/Transfer Fcn2'
                                        *   '<S4>/Transfer Fcn2'
                                        *   '<S5>/Transfer Fcn2'
                                        */
extern void MPC_Controller_Init(real_T *localX_);
extern void MPC_Controller_Reset(real_T *localX_);
extern void MPC_Controller_Enable(void);
extern void MPC_Controller_Deriv(real_T *localX_, real_T *localXdot_);
extern void MPC_Controller_Update(void);
extern void MPC_Controller(const real_T *rtu_Pp_A, const real_T *rtu_Pp_B, const
  real_T *rtu_Pp_C, const real_T *rtu_Pb_X, const real_T *rtu_Pb_Y, const real_T
  *rtu_Pp_Aref_in, const real_T *rtu_Pp_Bref_in, const real_T *rtu_Pp_Cref_in,
  const real_T *rtu_Pb_Xref_in, const real_T *rtu_Pb_Yref_in, real_T *rty_I_A,
  real_T *rty_I_B, real_T *rty_I_C, real_T *rty_Pp_Aref, real_T *rty_Pp_Bref,
  real_T *rty_Pp_Cref, real_T *rty_Pb_Xref, real_T *rty_Pb_Yref, real_T *localX_);

/* Model reference registration function */
extern void MPC_Controller_initialize(const char_T **rt_errorStatus, boolean_T
  *rt_stopRequested, RTWSolverInfo *rt_solverInfo, const rtTimingBridge
  *timingBridge, int_T mdlref_TID0, int_T mdlref_TID1, int_T mdlref_TID2);

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

extern MdlrefDW_MPC_Controller_T MPC_Controller_MdlrefDW;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_MPC_Controller_c_T MPC_Controller_B;

/* Block states (default storage) */
extern DW_MPC_Controller_f_T MPC_Controller_DW;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MPC_Controller'
 * '<S1>'   : 'MPC_Controller/MATLAB Function'
 * '<S2>'   : 'MPC_Controller/MPC Controller'
 * '<S3>'   : 'MPC_Controller/Motor Controller A'
 * '<S4>'   : 'MPC_Controller/Motor Controller B'
 * '<S5>'   : 'MPC_Controller/Motor Controller C'
 * '<S6>'   : 'MPC_Controller/RTI Data'
 * '<S7>'   : 'MPC_Controller/reference angle'
 * '<S8>'   : 'MPC_Controller/MPC Controller/MPC'
 * '<S9>'   : 'MPC_Controller/MPC Controller/MPC/MPC Matrix Signal Check'
 * '<S10>'  : 'MPC_Controller/MPC Controller/MPC/MPC Matrix Signal Check1'
 * '<S11>'  : 'MPC_Controller/MPC Controller/MPC/MPC Matrix Signal Check2'
 * '<S12>'  : 'MPC_Controller/MPC Controller/MPC/MPC Preview Signal Check'
 * '<S13>'  : 'MPC_Controller/MPC Controller/MPC/MPC Preview Signal Check1'
 * '<S14>'  : 'MPC_Controller/MPC Controller/MPC/MPC Preview Signal Check2'
 * '<S15>'  : 'MPC_Controller/MPC Controller/MPC/MPC Preview Signal Check3'
 * '<S16>'  : 'MPC_Controller/MPC Controller/MPC/MPC Preview Signal Check4'
 * '<S17>'  : 'MPC_Controller/MPC Controller/MPC/MPC Scalar Signal Check'
 * '<S18>'  : 'MPC_Controller/MPC Controller/MPC/MPC Scalar Signal Check1'
 * '<S19>'  : 'MPC_Controller/MPC Controller/MPC/MPC Scalar Signal Check2'
 * '<S20>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check'
 * '<S21>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check1'
 * '<S22>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check11'
 * '<S23>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check2'
 * '<S24>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check3'
 * '<S25>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check4'
 * '<S26>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check5'
 * '<S27>'  : 'MPC_Controller/MPC Controller/MPC/MPC Vector Signal Check6'
 * '<S28>'  : 'MPC_Controller/MPC Controller/MPC/optimizer'
 * '<S29>'  : 'MPC_Controller/MPC Controller/MPC/optimizer/optimizer'
 * '<S30>'  : 'MPC_Controller/RTI Data/RTI Data Store'
 * '<S31>'  : 'MPC_Controller/RTI Data/RTI Data Store/RTI Data Store'
 * '<S32>'  : 'MPC_Controller/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                                 /* RTW_HEADER_MPC_Controller_h_ */
