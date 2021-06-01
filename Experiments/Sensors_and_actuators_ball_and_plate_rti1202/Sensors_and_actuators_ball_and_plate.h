/*
 * Sensors_and_actuators_ball_and_plate.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Sensors_and_actuators_ball_and_plate".
 *
 * Model version              : 1.2
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  1 18:16:27 2021
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Sensors_and_actuators_ball_and_plate_h_
#define RTW_HEADER_Sensors_and_actuators_ball_and_plate_h_
#include <math.h>
#include <string.h>
#ifndef Sensors_and_actuators_ball_and_plate_COMMON_INCLUDES_
# define Sensors_and_actuators_ball_and_plate_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <dsIoEth.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif               /* Sensors_and_actuators_ball_and_plate_COMMON_INCLUDES_ */

#include "Sensors_and_actuators_ball_and_plate_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#define Sensors_and_actuators_ball_and_plate_M (Sensors_and_actuators_ball_a_M)

/* Block signals for system '<Root>/MATLAB Function' */
typedef struct {
  real_T theta1;                       /* '<Root>/MATLAB Function' */
  real_T theta2;                       /* '<Root>/MATLAB Function' */
  real_T theta3;                       /* '<Root>/MATLAB Function' */
  real_T Zc;                           /* '<Root>/MATLAB Function' */
} B_MATLABFunction_Sensors_and__T;

/* Block signals for system '<S123>/Enabled Subsystem' */
typedef struct {
  real_T OutportBufferForOut1;         /* '<S124>/Constant' */
} B_EnabledSubsystem_Sensors_an_T;

/* Block states (default storage) for system '<S123>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S123>/Enabled Subsystem' */
} DW_EnabledSubsystem_Sensors_a_T;

/* Block signals for system '<S123>/Enabled Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S125>/In1' */
} B_EnabledSubsystem1_Sensors_a_T;

/* Block states (default storage) for system '<S123>/Enabled Subsystem1' */
typedef struct {
  boolean_T EnabledSubsystem1_MODE;    /* '<S123>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_Sensors__T;

/* Block signals (default storage) */
typedef struct {
  real_T ReshapeX0[4];                 /* '<S4>/ReshapeX0' */
  real_T MemoryX[4];                   /* '<S4>/MemoryX' */
  real_T Reshapexhat[4];               /* '<S4>/Reshapexhat' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T SineWave1;                    /* '<Root>/Sine Wave1' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T Gain4[2];                     /* '<Root>/Gain4' */
  real_T ReshapeX0_f[6];               /* '<S5>/ReshapeX0' */
  real_T MemoryX_k[6];                 /* '<S5>/MemoryX' */
  real_T Reshapexhat_h[6];             /* '<S5>/Reshapexhat' */
  real_T Sum1[6];                      /* '<Root>/Sum1' */
  real_T Gain3[3];                     /* '<Root>/Gain3' */
  real_T Gain6[3];                     /* '<Root>/Gain6' */
  real_T Sum4;                         /* '<Root>/Sum4' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T Sum6;                         /* '<Root>/Sum6' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T Add3;                         /* '<Root>/Add3' */
  real_T Add4;                         /* '<Root>/Add4' */
  real_T Conversion[8];                /* '<S59>/Conversion' */
  real_T Conversion_c[8];              /* '<S60>/Conversion' */
  real_T Conversion_n;                 /* '<S61>/Conversion' */
  real_T Conversion_k[16];             /* '<S62>/Conversion' */
  real_T Conversion_a[4];              /* '<S32>/Conversion' */
  real_T Akxhatkk1[4];                 /* '<S36>/A[k]*xhat[k|k-1]' */
  real_T Reshapeu[2];                  /* '<S4>/Reshapeu' */
  real_T Bkuk[4];                      /* '<S36>/B[k]*u[k]' */
  real_T Reshapey[2];                  /* '<S4>/Reshapey' */
  real_T Add[4];                       /* '<S36>/Add' */
  real_T Reshape[4];                   /* '<S36>/Reshape' */
  real_T Conversion_nb[18];            /* '<S110>/Conversion' */
  real_T Conversion_k2[18];            /* '<S111>/Conversion' */
  real_T Conversion_d;                 /* '<S112>/Conversion' */
  real_T Conversion_j[36];             /* '<S113>/Conversion' */
  real_T Conversion_e[6];              /* '<S83>/Conversion' */
  real_T Akxhatkk1_b[6];               /* '<S87>/A[k]*xhat[k|k-1]' */
  real_T Reshapeu_g[3];                /* '<S5>/Reshapeu' */
  real_T Bkuk_n[6];                    /* '<S87>/B[k]*u[k]' */
  real_T Reshapey_m[3];                /* '<S5>/Reshapey' */
  real_T Add_l[6];                     /* '<S87>/Add' */
  real_T Reshape_h[6];                 /* '<S87>/Reshape' */
  real_T SFunction1_o1;                /* '<S131>/S-Function1' */
  real_T SFunction1_o2;                /* '<S131>/S-Function1' */
  real_T Inc2Pos;                      /* '<S14>/Inc2Pos' */
  real_T AbsPosition;                  /* '<S14>/AbsPosition' */
  real_T Abs;                          /* '<S133>/Abs' */
  real_T TransferFcn;                  /* '<S133>/Transfer Fcn' */
  real_T mm2m;                         /* '<S14>/mm2m' */
  real_T SFunction1_o1_g;              /* '<S126>/S-Function1' */
  real_T SFunction1_o2_p;              /* '<S126>/S-Function1' */
  real_T Inc2Pos_i;                    /* '<S13>/Inc2Pos' */
  real_T AbsPosition_h;                /* '<S13>/AbsPosition' */
  real_T Abs_l;                        /* '<S128>/Abs' */
  real_T TransferFcn_d;                /* '<S128>/Transfer Fcn' */
  real_T mm2m_p;                       /* '<S13>/mm2m' */
  real_T SFunction1_o1_o;              /* '<S121>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S121>/S-Function1' */
  real_T Inc2Pos_g;                    /* '<S12>/Inc2Pos' */
  real_T AbsPosition_hs;               /* '<S12>/AbsPosition' */
  real_T Abs_c;                        /* '<S123>/Abs' */
  real_T TransferFcn_f;                /* '<S123>/Transfer Fcn' */
  real_T mm2m_h;                       /* '<S12>/mm2m' */
  real_T Saturation;                   /* '<S11>/Saturation' */
  real_T Current2V;                    /* '<S11>/Current2V' */
  real_T DSPscale;                     /* '<S11>/DSPscale' */
  real_T Saturation_l;                 /* '<S10>/Saturation' */
  real_T Current2V_a;                  /* '<S10>/Current2V' */
  real_T DSPscale_a;                   /* '<S10>/DSPscale' */
  real_T Saturation_e;                 /* '<S9>/Saturation' */
  real_T Current2V_p;                  /* '<S9>/Current2V' */
  real_T DSPscale_o;                   /* '<S9>/DSPscale' */
  real_T motor1;                       /* '<Root>/MATLAB Function3' */
  real_T motor2;                       /* '<Root>/MATLAB Function3' */
  real_T motor3;                       /* '<Root>/MATLAB Function3' */
  real_T Ckxhatkk1[3];                 /* '<S116>/C[k]*xhat[k|k-1]' */
  real_T Dkuk[3];                      /* '<S116>/D[k]*u[k]' */
  real_T yhatkk1[3];                   /* '<S116>/Add1' */
  real_T Sum_p[3];                     /* '<S116>/Sum' */
  real_T Product3[6];                  /* '<S116>/Product3' */
  real_T Ckxhatkk1_e[2];               /* '<S65>/C[k]*xhat[k|k-1]' */
  real_T Dkuk_e[2];                    /* '<S65>/D[k]*u[k]' */
  real_T yhatkk1_g[2];                 /* '<S65>/Add1' */
  real_T Sum_i[2];                     /* '<S65>/Sum' */
  real_T Product3_h[4];                /* '<S65>/Product3' */
  uint32_T SFunction1_o4;              /* '<S2>/S-Function1' */
  uint32_T SFunction1_o1_h[3];         /* '<S1>/S-Function1' */
  real32_T Conversion_i[16];           /* '<S27>/Conversion' */
  real32_T Conversion_ks[36];          /* '<S78>/Conversion' */
  uint16_T SFunction1_o6;              /* '<S2>/S-Function1' */
  uint16_T Gain2;                      /* '<Root>/Gain2' */
  uint16_T Gain1;                      /* '<Root>/Gain1' */
  uint8_T SFunction1_o1_n[32];         /* '<S2>/S-Function1' */
  uint8_T SFunction1_o5[4];            /* '<S2>/S-Function1' */
  uint8_T SFunction1_o2_m[4];          /* '<S1>/S-Function1' */
  boolean_T DataTypeConversion;        /* '<Root>/Data Type Conversion' */
  boolean_T RelationalOperator1;       /* '<S133>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S133>/Relational Operator' */
  boolean_T LogicalOperator2;          /* '<S133>/Logical Operator2' */
  boolean_T RelationalOperator1_p;     /* '<S128>/Relational Operator1' */
  boolean_T RelationalOperator_n;      /* '<S128>/Relational Operator' */
  boolean_T LogicalOperator2_k;        /* '<S128>/Logical Operator2' */
  boolean_T RelationalOperator1_b;     /* '<S123>/Relational Operator1' */
  boolean_T RelationalOperator_c;      /* '<S123>/Relational Operator' */
  boolean_T LogicalOperator2_c;        /* '<S123>/Logical Operator2' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S133>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S128>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S128>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S123>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S123>/Enabled Subsystem' */
  B_MATLABFunction_Sensors_and__T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
  B_MATLABFunction_Sensors_and__T sf_MATLABFunction;/* '<Root>/MATLAB Function' */
} B_Sensors_and_actuators_ball__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum5_DWORK1;                  /* '<Root>/Sum5' */
  struct {
    real_T RECEIVED_FRAMES;
  } SFunction1_RWORK;                  /* '<S2>/S-Function1' */

  struct {
    real_T RX_DROPPED_FRAMES[2];
  } SFunction1_RWORK_c;                /* '<S3>/S-Function1' */

  uint32_T Add1_DWORK1;                /* '<Root>/Add1' */
  int_T MemoryX_IWORK;                 /* '<S4>/MemoryX' */
  int_T MemoryX_IWORK_g;               /* '<S5>/MemoryX' */
  uint16_T Add_DWORK1;                 /* '<Root>/Add' */
  boolean_T MeasurementUpdate_MODE;    /* '<S87>/MeasurementUpdate' */
  boolean_T MeasurementUpdate_MODE_e;  /* '<S36>/MeasurementUpdate' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_c;/* '<S133>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_m;/* '<S128>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_h;/* '<S128>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1;/* '<S123>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem;/* '<S123>/Enabled Subsystem' */
} DW_Sensors_and_actuators_ball_T;

/* Continuous states (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S4>/MemoryX' */
  real_T MemoryX_CSTATE_l[6];          /* '<S5>/MemoryX' */
  real_T TransferFcn_CSTATE;           /* '<S133>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S128>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S123>/Transfer Fcn' */
} X_Sensors_and_actuators_ball__T;

/* State derivatives (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S4>/MemoryX' */
  real_T MemoryX_CSTATE_l[6];          /* '<S5>/MemoryX' */
  real_T TransferFcn_CSTATE;           /* '<S133>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S128>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S123>/Transfer Fcn' */
} XDot_Sensors_and_actuators_ba_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE[4];         /* '<S4>/MemoryX' */
  boolean_T MemoryX_CSTATE_l[6];       /* '<S5>/MemoryX' */
  boolean_T TransferFcn_CSTATE;        /* '<S133>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_k;      /* '<S128>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S123>/Transfer Fcn' */
} XDis_Sensors_and_actuators_ba_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig_ZC;/* '<S14>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__n;/* '<S13>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__o;/* '<S12>/EMC_ENCODER_POS_SET_BL1' */
} PrevZCX_Sensors_and_actuators_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  boolean_T Init;                      /* '<Root>/Init' */
  boolean_T Init1;                     /* '<Root>/Init1' */
  boolean_T Init2;                     /* '<Root>/Init2' */
} ExtU_Sensors_and_actuators_ba_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint16_T Xpos;                       /* '<Root>/Xpos ' */
  uint16_T Ypos;                       /* '<Root>/Ypos ' */
  uint32_T Status;                     /* '<Root>/Status ' */
  real_T Frames;                       /* '<Root>/Frames ' */
  real_T I_A;                          /* '<Root>/I_A' */
  real_T I_B;                          /* '<Root>/I_B' */
  real_T I_C;                          /* '<Root>/I_C' */
  real_T Xpos_m;                       /* '<Root>/Xpos_m' */
  real_T Ypos_m;                       /* '<Root>/Ypos_m' */
} ExtY_Sensors_and_actuators_ba_T;

/* Parameters for system: '<S123>/Enabled Subsystem' */
struct P_EnabledSubsystem_Sensors_an_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S124>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S124>/Constant'
                                        */
};

/* Parameters for system: '<S123>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_Sensors_a_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S125>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_Sensors_and_actuators_ball__T_ {
  real_T I_0;                          /* Variable: I_0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T ballLQRgain[8];               /* Variable: ballLQRgain
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T plateLQRgain[18];             /* Variable: plateLQRgain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S65>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T Lykyhatkk1_Y0_k;              /* Expression: 0
                                        * Referenced by: '<S116>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Current2V_Gain;               /* Expression: 10/3
                                        * Referenced by: '<S9>/Current2V'
                                        */
  real_T DSPscale_Gain;                /* Expression: 1/10
                                        * Referenced by: '<S9>/DSPscale'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 3
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -3
                                        * Referenced by: '<S10>/Saturation'
                                        */
  real_T Current2V_Gain_l;             /* Expression: 10/3
                                        * Referenced by: '<S10>/Current2V'
                                        */
  real_T DSPscale_Gain_j;              /* Expression: 1/10
                                        * Referenced by: '<S10>/DSPscale'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 3
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: -3
                                        * Referenced by: '<S11>/Saturation'
                                        */
  real_T Current2V_Gain_j;             /* Expression: 10/3
                                        * Referenced by: '<S11>/Current2V'
                                        */
  real_T DSPscale_Gain_h;              /* Expression: 1/10
                                        * Referenced by: '<S11>/DSPscale'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ZP_Value;                     /* Expression: 29
                                        * Referenced by: '<S12>/ZP'
                                        */
  real_T Inc2Pos_Gain;                 /* Expression: 8e-3
                                        * Referenced by: '<S12>/Inc2Pos'
                                        */
  real_T Pos_offset_Value;             /* Expression: 0
                                        * Referenced by: '<S12>/Pos_offset'
                                        */
  real_T Const_Value;                  /* Expression: 0.01
                                        * Referenced by: '<S123>/Const'
                                        */
  real_T Const1_Value;                 /* Expression: -0.98
                                        * Referenced by: '<S123>/Const1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S123>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S123>/Transfer Fcn'
                                        */
  real_T mm2m_Gain;                    /* Expression: 0.001
                                        * Referenced by: '<S12>/mm2m'
                                        */
  real_T Constant_Value_d;             /* Expression: 10
                                        * Referenced by: '<S13>/Constant'
                                        */
  real_T ZP_Value_a;                   /* Expression: 29
                                        * Referenced by: '<S13>/ZP'
                                        */
  real_T Inc2Pos_Gain_j;               /* Expression: 8e-3
                                        * Referenced by: '<S13>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_f;           /* Expression: 0
                                        * Referenced by: '<S13>/Pos_offset'
                                        */
  real_T Const_Value_d;                /* Expression: 0.01
                                        * Referenced by: '<S128>/Const'
                                        */
  real_T Const1_Value_k;               /* Expression: -0.98
                                        * Referenced by: '<S128>/Const1'
                                        */
  real_T TransferFcn_A_b;              /* Computed Parameter: TransferFcn_A_b
                                        * Referenced by: '<S128>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_j;              /* Computed Parameter: TransferFcn_C_j
                                        * Referenced by: '<S128>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_f;                  /* Expression: 0.001
                                        * Referenced by: '<S13>/mm2m'
                                        */
  real_T Constant_Value_c;             /* Expression: 10
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T ZP_Value_d;                   /* Expression: 29
                                        * Referenced by: '<S14>/ZP'
                                        */
  real_T Inc2Pos_Gain_i;               /* Expression: 8e-3
                                        * Referenced by: '<S14>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_b;           /* Expression: 0
                                        * Referenced by: '<S14>/Pos_offset'
                                        */
  real_T Const_Value_i;                /* Expression: 0.01
                                        * Referenced by: '<S133>/Const'
                                        */
  real_T Const1_Value_n;               /* Expression: -0.98
                                        * Referenced by: '<S133>/Const1'
                                        */
  real_T TransferFcn_A_p;              /* Computed Parameter: TransferFcn_A_p
                                        * Referenced by: '<S133>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_m;              /* Computed Parameter: TransferFcn_C_m
                                        * Referenced by: '<S133>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_a;                  /* Expression: 0.001
                                        * Referenced by: '<S14>/mm2m'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T X0_Value[4];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S4>/X0'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: pi/5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: pi/5
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0.32
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T Constant8_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T X0_Value_e[6];                /* Expression: pInitialization.X0
                                        * Referenced by: '<S5>/X0'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1
                                        * Referenced by: '<Root>/Gain6'
                                        */
  real_T Constant2_Value;              /* Expression: 295
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain_Gain;                    /* Expression: -1/(515-70)*0.4
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Constant10_Value;             /* Expression: 227
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/(463-25)*0.4
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Constant7_Value;              /* Expression: 0.32
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T A_Value[16];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S4>/A'
                                        */
  real_T B_Value[8];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S4>/B'
                                        */
  real_T C_Value[8];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S4>/C'
                                        */
  real_T CovarianceZ_Value[16];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S16>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value[8];         /* Expression: pInitialization.L
                                        * Referenced by: '<S16>/KalmanGainL'
                                        */
  real_T KalmanGainM_Value[8];         /* Expression: pInitialization.M
                                        * Referenced by: '<S16>/KalmanGainM'
                                        */
  real_T D_Value[4];                   /* Expression: pInitialization.D
                                        * Referenced by: '<S4>/D'
                                        */
  real_T P0_Value[16];                 /* Expression: pInitialization.P0
                                        * Referenced by: '<S4>/P0'
                                        */
  real_T G_Value[16];                  /* Expression: pInitialization.G
                                        * Referenced by: '<S4>/G'
                                        */
  real_T H_Value[8];                   /* Expression: pInitialization.H
                                        * Referenced by: '<S4>/H'
                                        */
  real_T N_Value[8];                   /* Expression: pInitialization.N
                                        * Referenced by: '<S4>/N'
                                        */
  real_T Q_Value[16];                  /* Expression: pInitialization.Q
                                        * Referenced by: '<S4>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: pInitialization.R
                                        * Referenced by: '<S4>/R'
                                        */
  real_T A_Value_m[36];                /* Expression: pInitialization.A
                                        * Referenced by: '<S5>/A'
                                        */
  real_T B_Value_p[18];                /* Expression: pInitialization.B
                                        * Referenced by: '<S5>/B'
                                        */
  real_T C_Value_k[18];                /* Expression: pInitialization.C
                                        * Referenced by: '<S5>/C'
                                        */
  real_T CovarianceZ_Value_b[36];      /* Expression: pInitialization.Z
                                        * Referenced by: '<S67>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value_a[18];      /* Expression: pInitialization.L
                                        * Referenced by: '<S67>/KalmanGainL'
                                        */
  real_T KalmanGainM_Value_m[18];      /* Expression: pInitialization.M
                                        * Referenced by: '<S67>/KalmanGainM'
                                        */
  real_T D_Value_o[9];                 /* Expression: pInitialization.D
                                        * Referenced by: '<S5>/D'
                                        */
  real_T P0_Value_j[36];               /* Expression: pInitialization.P0
                                        * Referenced by: '<S5>/P0'
                                        */
  real_T G_Value_k[36];                /* Expression: pInitialization.G
                                        * Referenced by: '<S5>/G'
                                        */
  real_T H_Value_m[18];                /* Expression: pInitialization.H
                                        * Referenced by: '<S5>/H'
                                        */
  real_T N_Value_j[18];                /* Expression: pInitialization.N
                                        * Referenced by: '<S5>/N'
                                        */
  real_T Q_Value_f[36];                /* Expression: pInitialization.Q
                                        * Referenced by: '<S5>/Q'
                                        */
  real_T R_Value_j[9];                 /* Expression: pInitialization.R
                                        * Referenced by: '<S5>/R'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S4>/Enable'
                                        */
  boolean_T Enable_Value_c;            /* Expression: true()
                                        * Referenced by: '<S5>/Enable'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S133>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S133>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S128>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S128>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S123>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S123>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Sensors_and_actuators_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_Sensors_and_actuators_ball__T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][13];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    boolean_T firstInitCondFlag;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_P;

/* Block signals (default storage) */
extern B_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_B;

/* Continuous states (default storage) */
extern X_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_X;

/* Block states (default storage) */
extern DW_Sensors_and_actuators_ball_T Sensors_and_actuators_ball_a_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Sensors_and_actuators_ba_T Sensors_and_actuators_ball_an_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Sensors_and_actuators_ba_T Sensors_and_actuators_ball_an_Y;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Sensors_and_actuators_T Sensors_and_actuators_b_PrevZCX;

/* Model entry point functions */
extern void Sensors_and_actuators_ball_and_plate_initialize(void);
extern void Sensors_and_actuators_ball_and_plate_output(void);
extern void Sensors_and_actuators_ball_and_plate_update(void);
extern void Sensors_and_actuators_ball_and_plate_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Sensors_and_actuator_T *const Sensors_and_actuators_ball_a_M;

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
 * '<Root>' : 'Sensors_and_actuators_ball_and_plate'
 * '<S1>'   : 'Sensors_and_actuators_ball_and_plate/ETHERNET_SETUP_BL1'
 * '<S2>'   : 'Sensors_and_actuators_ball_and_plate/ETHERNET_UDP_RX_BL1'
 * '<S3>'   : 'Sensors_and_actuators_ball_and_plate/ETHERNET_UDP_SETUP_BL1'
 * '<S4>'   : 'Sensors_and_actuators_ball_and_plate/Kalman Filter'
 * '<S5>'   : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1'
 * '<S6>'   : 'Sensors_and_actuators_ball_and_plate/MATLAB Function'
 * '<S7>'   : 'Sensors_and_actuators_ball_and_plate/MATLAB Function1'
 * '<S8>'   : 'Sensors_and_actuators_ball_and_plate/MATLAB Function3'
 * '<S9>'   : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier'
 * '<S10>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1'
 * '<S11>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2'
 * '<S12>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement'
 * '<S13>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1'
 * '<S14>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2'
 * '<S15>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data'
 * '<S16>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL'
 * '<S17>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculateYhat'
 * '<S18>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CovarianceOutputConfigurator'
 * '<S19>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionA'
 * '<S20>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionB'
 * '<S21>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionC'
 * '<S22>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionD'
 * '<S23>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionEnable'
 * '<S24>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionG'
 * '<S25>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionH'
 * '<S26>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionN'
 * '<S27>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionP'
 * '<S28>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionP0'
 * '<S29>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionQ'
 * '<S30>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionR'
 * '<S31>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionReset'
 * '<S32>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionX'
 * '<S33>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionX0'
 * '<S34>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionu'
 * '<S35>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/MemoryP'
 * '<S36>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Observer'
 * '<S37>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ReducedQRN'
 * '<S38>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Reset'
 * '<S39>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Reshapeyhat'
 * '<S40>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionP0'
 * '<S41>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionQ'
 * '<S42>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionR'
 * '<S43>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/UseCurrentEstimator'
 * '<S44>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkA'
 * '<S45>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkB'
 * '<S46>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkC'
 * '<S47>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkD'
 * '<S48>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkEnable'
 * '<S49>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkG'
 * '<S50>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkH'
 * '<S51>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkN'
 * '<S52>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkP0'
 * '<S53>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkQ'
 * '<S54>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkR'
 * '<S55>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkReset'
 * '<S56>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkX0'
 * '<S57>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checku'
 * '<S58>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checky'
 * '<S59>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S60>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S61>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S62>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S63>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/Ground'
 * '<S64>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculateYhat/Ground'
 * '<S65>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Observer/MeasurementUpdate'
 * '<S66>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ReducedQRN/Ground'
 * '<S67>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL'
 * '<S68>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculateYhat'
 * '<S69>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CovarianceOutputConfigurator'
 * '<S70>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionA'
 * '<S71>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionB'
 * '<S72>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionC'
 * '<S73>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionD'
 * '<S74>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionEnable'
 * '<S75>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionG'
 * '<S76>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionH'
 * '<S77>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionN'
 * '<S78>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionP'
 * '<S79>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionP0'
 * '<S80>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionQ'
 * '<S81>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionR'
 * '<S82>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionReset'
 * '<S83>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionX'
 * '<S84>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionX0'
 * '<S85>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/DataTypeConversionu'
 * '<S86>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/MemoryP'
 * '<S87>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/Observer'
 * '<S88>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/ReducedQRN'
 * '<S89>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/Reset'
 * '<S90>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/Reshapeyhat'
 * '<S91>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/ScalarExpansionP0'
 * '<S92>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/ScalarExpansionQ'
 * '<S93>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/ScalarExpansionR'
 * '<S94>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/UseCurrentEstimator'
 * '<S95>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkA'
 * '<S96>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkB'
 * '<S97>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkC'
 * '<S98>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkD'
 * '<S99>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkEnable'
 * '<S100>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkG'
 * '<S101>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkH'
 * '<S102>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkN'
 * '<S103>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkP0'
 * '<S104>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkQ'
 * '<S105>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkR'
 * '<S106>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkReset'
 * '<S107>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checkX0'
 * '<S108>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checku'
 * '<S109>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/checky'
 * '<S110>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL/DataTypeConversionL'
 * '<S111>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL/DataTypeConversionM'
 * '<S112>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL/DataTypeConversionP'
 * '<S113>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL/DataTypeConversionZ'
 * '<S114>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculatePL/Ground'
 * '<S115>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/CalculateYhat/Ground'
 * '<S116>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/Observer/MeasurementUpdate'
 * '<S117>' : 'Sensors_and_actuators_ball_and_plate/Kalman Filter1/ReducedQRN/Ground'
 * '<S118>' : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1'
 * '<S119>' : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1'
 * '<S120>' : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1'
 * '<S121>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_BL1'
 * '<S122>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_POS_SET_BL1'
 * '<S123>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial'
 * '<S124>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem'
 * '<S125>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem1'
 * '<S126>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_BL1'
 * '<S127>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_POS_SET_BL1'
 * '<S128>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial'
 * '<S129>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem'
 * '<S130>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem1'
 * '<S131>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_BL1'
 * '<S132>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_POS_SET_BL1'
 * '<S133>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial'
 * '<S134>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem'
 * '<S135>' : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem1'
 * '<S136>' : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store'
 * '<S137>' : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store'
 * '<S138>' : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                  /* RTW_HEADER_Sensors_and_actuators_ball_and_plate_h_ */
