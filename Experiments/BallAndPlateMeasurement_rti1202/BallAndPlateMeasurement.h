/*
 * BallAndPlateMeasurement.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BallAndPlateMeasurement".
 *
 * Model version              : 1.11
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  1 19:38:40 2021
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BallAndPlateMeasurement_h_
#define RTW_HEADER_BallAndPlateMeasurement_h_
#include <math.h>
#include <string.h>
#ifndef BallAndPlateMeasurement_COMMON_INCLUDES_
# define BallAndPlateMeasurement_COMMON_INCLUDES_
#include <brtenv.h>
#include <rtkernel.h>
#include <rti_assert.h>
#include <rtidefineddatatypes.h>
#include <dsIoEth.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                            /* BallAndPlateMeasurement_COMMON_INCLUDES_ */

#include "BallAndPlateMeasurement_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "Test_measurement_script.h"
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
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

/* Block signals for system '<S20>/Enabled Subsystem' */
typedef struct {
  real_T OutportBufferForOut1;         /* '<S21>/Constant' */
} B_EnabledSubsystem_BallAndPla_T;

/* Block states (default storage) for system '<S20>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S20>/Enabled Subsystem' */
} DW_EnabledSubsystem_BallAndPl_T;

/* Block signals for system '<S20>/Enabled Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S22>/In1' */
} B_EnabledSubsystem1_BallAndPl_T;

/* Block states (default storage) for system '<S20>/Enabled Subsystem1' */
typedef struct {
  boolean_T EnabledSubsystem1_MODE;    /* '<S20>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_BallAndP_T;

/* Block signals (default storage) */
typedef struct {
  real_T Delay;                        /* '<Root>/Delay' */
  real_T Delay1;                       /* '<Root>/Delay1' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Constant;                     /* '<S2>/Constant' */
  real_T OutportBufferForI_A;          /* '<S2>/Constant' */
  real_T Constant1;                    /* '<S2>/Constant1' */
  real_T OutportBufferForI_B;          /* '<S2>/Constant1' */
  real_T Constant2;                    /* '<S2>/Constant2' */
  real_T OutportBufferForI_C;          /* '<S2>/Constant2' */
  real_T OutportBufferForI_A_p;
  real_T OutportBufferForI_B_a;
  real_T OutportBufferForI_C_f;
  real_T OutportBufferForI_A_p2;
  real_T OutportBufferForI_B_an;
  real_T OutportBufferForI_C_f3;
  real_T OutportBufferForPb_Xoffset;
  real_T OutportBufferForPb_Yoffset;
  real_T OutportBufferForPb_SetOffset;
  real_T Controller_o1;                /* '<S14>/Controller' */
  real_T Controller_o2;                /* '<S14>/Controller' */
  real_T Controller_o3;                /* '<S14>/Controller' */
  real_T SFunction1_o1;                /* '<S28>/S-Function1' */
  real_T SFunction1_o2;                /* '<S28>/S-Function1' */
  real_T Inc2Pos;                      /* '<S12>/Inc2Pos' */
  real_T AbsPosition;                  /* '<S12>/AbsPosition' */
  real_T Abs;                          /* '<S30>/Abs' */
  real_T TransferFcn;                  /* '<S30>/Transfer Fcn' */
  real_T SFunction1_o1_g;              /* '<S23>/S-Function1' */
  real_T SFunction1_o2_p;              /* '<S23>/S-Function1' */
  real_T Inc2Pos_i;                    /* '<S11>/Inc2Pos' */
  real_T AbsPosition_h;                /* '<S11>/AbsPosition' */
  real_T Abs_l;                        /* '<S25>/Abs' */
  real_T TransferFcn_d;                /* '<S25>/Transfer Fcn' */
  real_T SFunction1_o1_o;              /* '<S18>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S18>/S-Function1' */
  real_T Inc2Pos_g;                    /* '<S10>/Inc2Pos' */
  real_T AbsPosition_hs;               /* '<S10>/AbsPosition' */
  real_T Abs_c;                        /* '<S20>/Abs' */
  real_T TransferFcn_f;                /* '<S20>/Transfer Fcn' */
  real_T Saturation;                   /* '<S9>/Saturation' */
  real_T Current2V;                    /* '<S9>/Current2V' */
  real_T DSPscale;                     /* '<S9>/DSPscale' */
  real_T Saturation_l;                 /* '<S8>/Saturation' */
  real_T Current2V_a;                  /* '<S8>/Current2V' */
  real_T DSPscale_a;                   /* '<S8>/DSPscale' */
  real_T Saturation_e;                 /* '<S7>/Saturation' */
  real_T Current2V_p;                  /* '<S7>/Current2V' */
  real_T DSPscale_o;                   /* '<S7>/DSPscale' */
  uint32_T SFunction1_o4;              /* '<S4>/S-Function1' */
  uint32_T SFunction1_o1_h[3];         /* '<S3>/S-Function1' */
  uint16_T SFunction1_o6;              /* '<S4>/S-Function1' */
  uint16_T Gain2;                      /* '<Root>/Gain2' */
  uint16_T Gain1;                      /* '<Root>/Gain1' */
  uint8_T SFunction1_o1_n[32];         /* '<S4>/S-Function1' */
  uint8_T SFunction1_o5[4];            /* '<S4>/S-Function1' */
  uint8_T SFunction1_o2_m[4];          /* '<S3>/S-Function1' */
  boolean_T DataTypeConversion;        /* '<Root>/Data Type Conversion' */
  boolean_T RelationalOperator1;       /* '<S30>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S30>/Relational Operator' */
  boolean_T LogicalOperator2;          /* '<S30>/Logical Operator2' */
  boolean_T RelationalOperator1_p;     /* '<S25>/Relational Operator1' */
  boolean_T RelationalOperator_n;      /* '<S25>/Relational Operator' */
  boolean_T LogicalOperator2_k;        /* '<S25>/Logical Operator2' */
  boolean_T RelationalOperator1_b;     /* '<S20>/Relational Operator1' */
  boolean_T RelationalOperator_c;      /* '<S20>/Relational Operator' */
  boolean_T LogicalOperator2_c;        /* '<S20>/Logical Operator2' */
  B_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1_j;/* '<S30>/Enabled Subsystem1' */
  B_EnabledSubsystem_BallAndPla_T EnabledSubsystem_c;/* '<S30>/Enabled Subsystem' */
  B_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1_m;/* '<S25>/Enabled Subsystem1' */
  B_EnabledSubsystem_BallAndPla_T EnabledSubsystem_h;/* '<S25>/Enabled Subsystem' */
  B_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1;/* '<S20>/Enabled Subsystem1' */
  B_EnabledSubsystem_BallAndPla_T EnabledSubsystem;/* '<S20>/Enabled Subsystem' */
} B_BallAndPlateMeasurement_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  real_T Delay1_DSTATE;                /* '<Root>/Delay1' */
  real_T Sum_DWORK1;                   /* '<Root>/Sum' */
  struct {
    real_T RECEIVED_FRAMES;
  } SFunction1_RWORK;                  /* '<S4>/S-Function1' */

  struct {
    real_T RX_DROPPED_FRAMES[2];
  } SFunction1_RWORK_c;                /* '<S5>/S-Function1' */

  uint32_T Add1_DWORK1;                /* '<Root>/Add1' */
  uint16_T Add_DWORK1;                 /* '<Root>/Add' */
  int8_T SwitchCase_ActiveSubsystem;   /* '<Root>/Switch Case' */
  MdlrefDW_Test_measurement_scr_T Controller_InstanceData;/* '<S14>/Controller' */
  DW_EnabledSubsystem1_BallAndP_T EnabledSubsystem1_j;/* '<S30>/Enabled Subsystem1' */
  DW_EnabledSubsystem_BallAndPl_T EnabledSubsystem_c;/* '<S30>/Enabled Subsystem' */
  DW_EnabledSubsystem1_BallAndP_T EnabledSubsystem1_m;/* '<S25>/Enabled Subsystem1' */
  DW_EnabledSubsystem_BallAndPl_T EnabledSubsystem_h;/* '<S25>/Enabled Subsystem' */
  DW_EnabledSubsystem1_BallAndP_T EnabledSubsystem1;/* '<S20>/Enabled Subsystem1' */
  DW_EnabledSubsystem_BallAndPl_T EnabledSubsystem;/* '<S20>/Enabled Subsystem' */
} DW_BallAndPlateMeasurement_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S30>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S25>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S20>/Transfer Fcn' */
} X_BallAndPlateMeasurement_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn_CSTATE;           /* '<S30>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S25>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S20>/Transfer Fcn' */
} XDot_BallAndPlateMeasurement_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn_CSTATE;        /* '<S30>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_k;      /* '<S25>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S20>/Transfer Fcn' */
} XDis_BallAndPlateMeasurement_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig_ZC;/* '<S12>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__n;/* '<S11>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__o;/* '<S10>/EMC_ENCODER_POS_SET_BL1' */
} PrevZCX_BallAndPlateMeasureme_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T Status;                     /* '<Root>/Status ' */
  real_T Frames;                       /* '<Root>/Frames ' */
  real_T Pp_A;                         /* '<Root>/Pp_A' */
  real_T Pp_B;                         /* '<Root>/Pp_B' */
  real_T Pp_C;                         /* '<Root>/Pp_C' */
  uint16_T Pb_X;                       /* '<Root>/Pb_X' */
  uint16_T Pb_Y;                       /* '<Root>/Pb_Y' */
  real_T I_A;                          /* '<Root>/I_A' */
  real_T I_B;                          /* '<Root>/I_B' */
  real_T I_C;                          /* '<Root>/I_C' */
  real_T Pp_Aref;                      /* '<Root>/Pp_Aref' */
  real_T Pp_Bref;                      /* '<Root>/Pp_Bref' */
  real_T Pp_Cref;                      /* '<Root>/Pp_Cref' */
  real_T Pb_Xref;                      /* '<Root>/Pb_Xref' */
  real_T Pb_Yref;                      /* '<Root>/Pb_Yref' */
} ExtY_BallAndPlateMeasurement_T;

/* Parameters for system: '<S20>/Enabled Subsystem' */
struct P_EnabledSubsystem_BallAndPla_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S21>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S21>/Constant'
                                        */
};

/* Parameters for system: '<S20>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_BallAndPl_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S22>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_BallAndPlateMeasurement_T_ {
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Current2V_Gain;               /* Expression: 10/3
                                        * Referenced by: '<S7>/Current2V'
                                        */
  real_T DSPscale_Gain;                /* Expression: 1/10
                                        * Referenced by: '<S7>/DSPscale'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -3
                                        * Referenced by: '<S8>/Saturation'
                                        */
  real_T Current2V_Gain_l;             /* Expression: 10/3
                                        * Referenced by: '<S8>/Current2V'
                                        */
  real_T DSPscale_Gain_j;              /* Expression: 1/10
                                        * Referenced by: '<S8>/DSPscale'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: -3
                                        * Referenced by: '<S9>/Saturation'
                                        */
  real_T Current2V_Gain_j;             /* Expression: 10/3
                                        * Referenced by: '<S9>/Current2V'
                                        */
  real_T DSPscale_Gain_h;              /* Expression: 1/10
                                        * Referenced by: '<S9>/DSPscale'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T ZP_Value;                     /* Expression: 29
                                        * Referenced by: '<S10>/ZP'
                                        */
  real_T Inc2Pos_Gain;                 /* Expression: 8e-3
                                        * Referenced by: '<S10>/Inc2Pos'
                                        */
  real_T Pos_offset_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/Pos_offset'
                                        */
  real_T Const_Value;                  /* Expression: 0.01
                                        * Referenced by: '<S20>/Const'
                                        */
  real_T Const1_Value;                 /* Expression: -0.98
                                        * Referenced by: '<S20>/Const1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S20>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S20>/Transfer Fcn'
                                        */
  real_T mm2m_Gain;                    /* Expression: 0.001
                                        * Referenced by: '<S10>/mm2m'
                                        */
  real_T Constant_Value_d;             /* Expression: 10
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T ZP_Value_a;                   /* Expression: 29
                                        * Referenced by: '<S11>/ZP'
                                        */
  real_T Inc2Pos_Gain_j;               /* Expression: 8e-3
                                        * Referenced by: '<S11>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_f;           /* Expression: 0
                                        * Referenced by: '<S11>/Pos_offset'
                                        */
  real_T Const_Value_d;                /* Expression: 0.01
                                        * Referenced by: '<S25>/Const'
                                        */
  real_T Const1_Value_k;               /* Expression: -0.98
                                        * Referenced by: '<S25>/Const1'
                                        */
  real_T TransferFcn_A_b;              /* Computed Parameter: TransferFcn_A_b
                                        * Referenced by: '<S25>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_j;              /* Computed Parameter: TransferFcn_C_j
                                        * Referenced by: '<S25>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_f;                  /* Expression: 0.001
                                        * Referenced by: '<S11>/mm2m'
                                        */
  real_T Constant_Value_c;             /* Expression: 10
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T ZP_Value_d;                   /* Expression: 29
                                        * Referenced by: '<S12>/ZP'
                                        */
  real_T Inc2Pos_Gain_i;               /* Expression: 8e-3
                                        * Referenced by: '<S12>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_b;           /* Expression: 0
                                        * Referenced by: '<S12>/Pos_offset'
                                        */
  real_T Const_Value_i;                /* Expression: 0.01
                                        * Referenced by: '<S30>/Const'
                                        */
  real_T Const1_Value_n;               /* Expression: -0.98
                                        * Referenced by: '<S30>/Const1'
                                        */
  real_T TransferFcn_A_p;              /* Computed Parameter: TransferFcn_A_p
                                        * Referenced by: '<S30>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_m;              /* Computed Parameter: TransferFcn_C_m
                                        * Referenced by: '<S30>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_a;                  /* Expression: 0.001
                                        * Referenced by: '<S12>/mm2m'
                                        */
  real_T Pp_Aref_Y0;                   /* Computed Parameter: Pp_Aref_Y0
                                        * Referenced by: '<S14>/Pp_Aref'
                                        */
  real_T Pp_Bref_Y0;                   /* Computed Parameter: Pp_Bref_Y0
                                        * Referenced by: '<S14>/Pp_Bref'
                                        */
  real_T Pp_Cref_Y0;                   /* Computed Parameter: Pp_Cref_Y0
                                        * Referenced by: '<S14>/Pp_Cref'
                                        */
  real_T Pb_Xref_Y0;                   /* Computed Parameter: Pb_Xref_Y0
                                        * Referenced by: '<S14>/Pb_Xref'
                                        */
  real_T Pb_Yref_Y0;                   /* Computed Parameter: Pb_Yref_Y0
                                        * Referenced by: '<S14>/Pb_Yref'
                                        */
  real_T Constant_Value_n;             /* Expression: 0
                                        * Referenced by: '<S14>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant4'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Init_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Init'
                                        */
  real_T State_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/State'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  P_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1_j;/* '<S30>/Enabled Subsystem1' */
  P_EnabledSubsystem_BallAndPla_T EnabledSubsystem_c;/* '<S30>/Enabled Subsystem' */
  P_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1_m;/* '<S25>/Enabled Subsystem1' */
  P_EnabledSubsystem_BallAndPla_T EnabledSubsystem_h;/* '<S25>/Enabled Subsystem' */
  P_EnabledSubsystem1_BallAndPl_T EnabledSubsystem1;/* '<S20>/Enabled Subsystem1' */
  P_EnabledSubsystem_BallAndPla_T EnabledSubsystem;/* '<S20>/Enabled Subsystem' */
};

/* Real-time Model Data Structure */
struct tag_RTM_BallAndPlateMeasureme_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_BallAndPlateMeasurement_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][3];
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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_BallAndPlateMeasurement_T BallAndPlateMeasurement_P;

/* Block signals (default storage) */
extern B_BallAndPlateMeasurement_T BallAndPlateMeasurement_B;

/* Continuous states (default storage) */
extern X_BallAndPlateMeasurement_T BallAndPlateMeasurement_X;

/* Block states (default storage) */
extern DW_BallAndPlateMeasurement_T BallAndPlateMeasurement_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_BallAndPlateMeasurement_T BallAndPlateMeasurement_Y;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_BallAndPlateMeasureme_T BallAndPlateMeasurement_PrevZCX;

/* Model block global parameters (default storage) */
extern real_T rtP_UseUserDefinedBallReference;/* Variable: UseUserDefinedBallReference
                                               * Referenced by: '<S14>/Controller'
                                               */
extern real_T rtP_UseUserDefinedPlateReference;/* Variable: UseUserDefinedPlateReference
                                                * Referenced by: '<S14>/Controller'
                                                */

/* Model entry point functions */
extern void BallAndPlateMeasurement_initialize(void);
extern void BallAndPlateMeasurement_output(void);
extern void BallAndPlateMeasurement_update(void);
extern void BallAndPlateMeasurement_terminate(void);

/* Real-time Model object */
extern RT_MODEL_BallAndPlateMeasurem_T *const BallAndPlateMeasurement_M;

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
 * '<Root>' : 'BallAndPlateMeasurement'
 * '<S1>'   : 'BallAndPlateMeasurement/CalibrateBallPosition'
 * '<S2>'   : 'BallAndPlateMeasurement/Disabled'
 * '<S3>'   : 'BallAndPlateMeasurement/ETHERNET_SETUP_BL1'
 * '<S4>'   : 'BallAndPlateMeasurement/ETHERNET_UDP_RX_BL1'
 * '<S5>'   : 'BallAndPlateMeasurement/ETHERNET_UDP_SETUP_BL1'
 * '<S6>'   : 'BallAndPlateMeasurement/EnableMotors'
 * '<S7>'   : 'BallAndPlateMeasurement/Outputs to Amplifier'
 * '<S8>'   : 'BallAndPlateMeasurement/Outputs to Amplifier1'
 * '<S9>'   : 'BallAndPlateMeasurement/Outputs to Amplifier2'
 * '<S10>'  : 'BallAndPlateMeasurement/Position Measurement'
 * '<S11>'  : 'BallAndPlateMeasurement/Position Measurement1'
 * '<S12>'  : 'BallAndPlateMeasurement/Position Measurement2'
 * '<S13>'  : 'BallAndPlateMeasurement/RTI Data'
 * '<S14>'  : 'BallAndPlateMeasurement/Run'
 * '<S15>'  : 'BallAndPlateMeasurement/Outputs to Amplifier/DAC_CLASS1_BL1'
 * '<S16>'  : 'BallAndPlateMeasurement/Outputs to Amplifier1/DAC_CLASS1_BL1'
 * '<S17>'  : 'BallAndPlateMeasurement/Outputs to Amplifier2/DAC_CLASS1_BL1'
 * '<S18>'  : 'BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_BL1'
 * '<S19>'  : 'BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_POS_SET_BL1'
 * '<S20>'  : 'BallAndPlateMeasurement/Position Measurement/Initial'
 * '<S21>'  : 'BallAndPlateMeasurement/Position Measurement/Initial/Enabled Subsystem'
 * '<S22>'  : 'BallAndPlateMeasurement/Position Measurement/Initial/Enabled Subsystem1'
 * '<S23>'  : 'BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_BL1'
 * '<S24>'  : 'BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_POS_SET_BL1'
 * '<S25>'  : 'BallAndPlateMeasurement/Position Measurement1/Initial'
 * '<S26>'  : 'BallAndPlateMeasurement/Position Measurement1/Initial/Enabled Subsystem'
 * '<S27>'  : 'BallAndPlateMeasurement/Position Measurement1/Initial/Enabled Subsystem1'
 * '<S28>'  : 'BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_BL1'
 * '<S29>'  : 'BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_POS_SET_BL1'
 * '<S30>'  : 'BallAndPlateMeasurement/Position Measurement2/Initial'
 * '<S31>'  : 'BallAndPlateMeasurement/Position Measurement2/Initial/Enabled Subsystem'
 * '<S32>'  : 'BallAndPlateMeasurement/Position Measurement2/Initial/Enabled Subsystem1'
 * '<S33>'  : 'BallAndPlateMeasurement/RTI Data/RTI Data Store'
 * '<S34>'  : 'BallAndPlateMeasurement/RTI Data/RTI Data Store/RTI Data Store'
 * '<S35>'  : 'BallAndPlateMeasurement/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                               /* RTW_HEADER_BallAndPlateMeasurement_h_ */
