/*
 * Sensors_and_actuators_ball_and_plate.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Sensors_and_actuators_ball_and_plate".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  1 17:40:28 2021
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

/* Block signals for system '<S19>/Enabled Subsystem' */
typedef struct {
  real_T OutportBufferForOut1;         /* '<S20>/Constant' */
} B_EnabledSubsystem_Sensors_an_T;

/* Block states (default storage) for system '<S19>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S19>/Enabled Subsystem' */
} DW_EnabledSubsystem_Sensors_a_T;

/* Block signals for system '<S19>/Enabled Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S21>/In1' */
} B_EnabledSubsystem1_Sensors_a_T;

/* Block states (default storage) for system '<S19>/Enabled Subsystem1' */
typedef struct {
  boolean_T EnabledSubsystem1_MODE;    /* '<S19>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_Sensors__T;

/* Block signals (default storage) */
typedef struct {
  real_T Integrator2;                  /* '<S4>/Integrator2' */
  real_T Sum;                          /* '<S4>/Sum' */
  real_T TransferFcn2;                 /* '<S4>/Transfer Fcn2' */
  real_T Integrator2_m;                /* '<S5>/Integrator2' */
  real_T Sum_l;                        /* '<S5>/Sum' */
  real_T TransferFcn2_n;               /* '<S5>/Transfer Fcn2' */
  real_T Integrator2_o;                /* '<S6>/Integrator2' */
  real_T Sum_a;                        /* '<S6>/Sum' */
  real_T TransferFcn2_l;               /* '<S6>/Transfer Fcn2' */
  real_T SFunction1_o1;                /* '<S27>/S-Function1' */
  real_T SFunction1_o2;                /* '<S27>/S-Function1' */
  real_T Inc2Pos;                      /* '<S12>/Inc2Pos' */
  real_T AbsPosition;                  /* '<S12>/AbsPosition' */
  real_T Abs;                          /* '<S29>/Abs' */
  real_T TransferFcn;                  /* '<S29>/Transfer Fcn' */
  real_T mm2m;                         /* '<S12>/mm2m' */
  real_T SFunction1_o1_g;              /* '<S22>/S-Function1' */
  real_T SFunction1_o2_p;              /* '<S22>/S-Function1' */
  real_T Inc2Pos_i;                    /* '<S11>/Inc2Pos' */
  real_T AbsPosition_h;                /* '<S11>/AbsPosition' */
  real_T Abs_l;                        /* '<S24>/Abs' */
  real_T TransferFcn_d;                /* '<S24>/Transfer Fcn' */
  real_T mm2m_p;                       /* '<S11>/mm2m' */
  real_T SFunction1_o1_o;              /* '<S17>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S17>/S-Function1' */
  real_T Inc2Pos_g;                    /* '<S10>/Inc2Pos' */
  real_T AbsPosition_hs;               /* '<S10>/AbsPosition' */
  real_T Abs_c;                        /* '<S19>/Abs' */
  real_T TransferFcn_f;                /* '<S19>/Transfer Fcn' */
  real_T mm2m_h;                       /* '<S10>/mm2m' */
  real_T Saturation;                   /* '<S9>/Saturation' */
  real_T Current2V;                    /* '<S9>/Current2V' */
  real_T DSPscale;                     /* '<S9>/DSPscale' */
  real_T Saturation_l;                 /* '<S8>/Saturation' */
  real_T Current2V_a;                  /* '<S8>/Current2V' */
  real_T DSPscale_a;                   /* '<S8>/DSPscale' */
  real_T Saturation_e;                 /* '<S7>/Saturation' */
  real_T Current2V_p;                  /* '<S7>/Current2V' */
  real_T DSPscale_o;                   /* '<S7>/DSPscale' */
  uint32_T SFunction1_o4;              /* '<S2>/S-Function1' */
  uint32_T SFunction1_o1_h[3];         /* '<S1>/S-Function1' */
  uint16_T SFunction1_o6;              /* '<S2>/S-Function1' */
  uint16_T Gain2;                      /* '<Root>/Gain2' */
  uint16_T Gain1;                      /* '<Root>/Gain1' */
  uint8_T SFunction1_o1_n[32];         /* '<S2>/S-Function1' */
  uint8_T SFunction1_o5[4];            /* '<S2>/S-Function1' */
  uint8_T SFunction1_o2_m[4];          /* '<S1>/S-Function1' */
  boolean_T DataTypeConversion;        /* '<Root>/Data Type Conversion' */
  boolean_T RelationalOperator1;       /* '<S29>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S29>/Relational Operator' */
  boolean_T LogicalOperator2;          /* '<S29>/Logical Operator2' */
  boolean_T RelationalOperator1_p;     /* '<S24>/Relational Operator1' */
  boolean_T RelationalOperator_n;      /* '<S24>/Relational Operator' */
  boolean_T LogicalOperator2_k;        /* '<S24>/Logical Operator2' */
  boolean_T RelationalOperator1_b;     /* '<S19>/Relational Operator1' */
  boolean_T RelationalOperator_c;      /* '<S19>/Relational Operator' */
  boolean_T LogicalOperator2_c;        /* '<S19>/Logical Operator2' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S29>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S29>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S24>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S24>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S19>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S19>/Enabled Subsystem' */
} B_Sensors_and_actuators_ball__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    real_T RECEIVED_FRAMES;
  } SFunction1_RWORK;                  /* '<S2>/S-Function1' */

  struct {
    real_T RX_DROPPED_FRAMES[2];
  } SFunction1_RWORK_c;                /* '<S3>/S-Function1' */

  uint32_T Add1_DWORK1;                /* '<Root>/Add1' */
  uint16_T Add_DWORK1;                 /* '<Root>/Add' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_j;/* '<S29>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_c;/* '<S29>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_m;/* '<S24>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_h;/* '<S24>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1;/* '<S19>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem;/* '<S19>/Enabled Subsystem' */
} DW_Sensors_and_actuators_ball_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<S4>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_i;         /* '<S5>/Integrator2' */
  real_T TransferFcn2_CSTATE_o[2];     /* '<S5>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_e;         /* '<S6>/Integrator2' */
  real_T TransferFcn2_CSTATE_b[2];     /* '<S6>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE;           /* '<S29>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S19>/Transfer Fcn' */
} X_Sensors_and_actuators_ball__T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator2_CSTATE;           /* '<S4>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<S4>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_i;         /* '<S5>/Integrator2' */
  real_T TransferFcn2_CSTATE_o[2];     /* '<S5>/Transfer Fcn2' */
  real_T Integrator2_CSTATE_e;         /* '<S6>/Integrator2' */
  real_T TransferFcn2_CSTATE_b[2];     /* '<S6>/Transfer Fcn2' */
  real_T TransferFcn_CSTATE;           /* '<S29>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S24>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S19>/Transfer Fcn' */
} XDot_Sensors_and_actuators_ba_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator2_CSTATE;        /* '<S4>/Integrator2' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<S4>/Transfer Fcn2' */
  boolean_T Integrator2_CSTATE_i;      /* '<S5>/Integrator2' */
  boolean_T TransferFcn2_CSTATE_o[2];  /* '<S5>/Transfer Fcn2' */
  boolean_T Integrator2_CSTATE_e;      /* '<S6>/Integrator2' */
  boolean_T TransferFcn2_CSTATE_b[2];  /* '<S6>/Transfer Fcn2' */
  boolean_T TransferFcn_CSTATE;        /* '<S29>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_k;      /* '<S24>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S19>/Transfer Fcn' */
} XDis_Sensors_and_actuators_ba_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig_ZC;/* '<S12>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__n;/* '<S11>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__o;/* '<S10>/EMC_ENCODER_POS_SET_BL1' */
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
} ExtY_Sensors_and_actuators_ba_T;

/* Parameters for system: '<S19>/Enabled Subsystem' */
struct P_EnabledSubsystem_Sensors_an_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S20>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S20>/Constant'
                                        */
};

/* Parameters for system: '<S19>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_Sensors_a_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S21>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_Sensors_and_actuators_ball__T_ {
  real_T denc_mi[3];                   /* Variable: denc_mi
                                        * Referenced by:
                                        *   '<S4>/Transfer Fcn2'
                                        *   '<S5>/Transfer Fcn2'
                                        *   '<S6>/Transfer Fcn2'
                                        */
  real_T numc_mi[3];                   /* Variable: numc_mi
                                        * Referenced by:
                                        *   '<S4>/Transfer Fcn2'
                                        *   '<S5>/Transfer Fcn2'
                                        *   '<S6>/Transfer Fcn2'
                                        */
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
                                        * Referenced by: '<S19>/Const'
                                        */
  real_T Const1_Value;                 /* Expression: -0.98
                                        * Referenced by: '<S19>/Const1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S19>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S19>/Transfer Fcn'
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
                                        * Referenced by: '<S24>/Const'
                                        */
  real_T Const1_Value_k;               /* Expression: -0.98
                                        * Referenced by: '<S24>/Const1'
                                        */
  real_T TransferFcn_A_b;              /* Computed Parameter: TransferFcn_A_b
                                        * Referenced by: '<S24>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_j;              /* Computed Parameter: TransferFcn_C_j
                                        * Referenced by: '<S24>/Transfer Fcn'
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
                                        * Referenced by: '<S29>/Const'
                                        */
  real_T Const1_Value_n;               /* Expression: -0.98
                                        * Referenced by: '<S29>/Const1'
                                        */
  real_T TransferFcn_A_p;              /* Computed Parameter: TransferFcn_A_p
                                        * Referenced by: '<S29>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_m;              /* Computed Parameter: TransferFcn_C_m
                                        * Referenced by: '<S29>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_a;                  /* Expression: 0.001
                                        * Referenced by: '<S12>/mm2m'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_UpperSat;         /* Expression: 3
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_LowerSat;         /* Expression: -3
                                        * Referenced by: '<S4>/Integrator2'
                                        */
  real_T Integrator2_IC_m;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_UpperSat_k;       /* Expression: 3
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_LowerSat_k;       /* Expression: -3
                                        * Referenced by: '<S5>/Integrator2'
                                        */
  real_T Integrator2_IC_p;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Integrator2_UpperSat_i;       /* Expression: 3
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  real_T Integrator2_LowerSat_a;       /* Expression: -3
                                        * Referenced by: '<S6>/Integrator2'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S29>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S29>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S24>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S24>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S19>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S19>/Enabled Subsystem' */
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
  real_T odeF[1][12];
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
 * '<S4>'   : 'Sensors_and_actuators_ball_and_plate/Motor Controller A'
 * '<S5>'   : 'Sensors_and_actuators_ball_and_plate/Motor Controller B'
 * '<S6>'   : 'Sensors_and_actuators_ball_and_plate/Motor Controller C'
 * '<S7>'   : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier'
 * '<S8>'   : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1'
 * '<S9>'   : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2'
 * '<S10>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement'
 * '<S11>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1'
 * '<S12>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2'
 * '<S13>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data'
 * '<S14>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1'
 * '<S15>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1'
 * '<S16>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1'
 * '<S17>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_BL1'
 * '<S18>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_POS_SET_BL1'
 * '<S19>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial'
 * '<S20>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem'
 * '<S21>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem1'
 * '<S22>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_BL1'
 * '<S23>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_POS_SET_BL1'
 * '<S24>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial'
 * '<S25>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem'
 * '<S26>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem1'
 * '<S27>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_BL1'
 * '<S28>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_POS_SET_BL1'
 * '<S29>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial'
 * '<S30>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem'
 * '<S31>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem1'
 * '<S32>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store'
 * '<S33>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store'
 * '<S34>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                  /* RTW_HEADER_Sensors_and_actuators_ball_and_plate_h_ */
