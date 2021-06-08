/*
 * Sensors_and_actuators_ball_and_plate.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Sensors_and_actuators_ball_and_plate".
 *
 * Model version              : 1.22
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  8 16:23:11 2021
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
#include "rt_zcfcn.h"

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

/* Block signals for system '<Root>/MATLAB Function1' */
typedef struct {
  real_T y;                            /* '<Root>/MATLAB Function1' */
} B_MATLABFunction1_Sensors_and_T;

/* Block signals for system '<S76>/Enabled Subsystem' */
typedef struct {
  real_T OutportBufferForOut1;         /* '<S77>/Constant' */
} B_EnabledSubsystem_Sensors_an_T;

/* Block states (default storage) for system '<S76>/Enabled Subsystem' */
typedef struct {
  boolean_T EnabledSubsystem_MODE;     /* '<S76>/Enabled Subsystem' */
} DW_EnabledSubsystem_Sensors_a_T;

/* Block signals for system '<S76>/Enabled Subsystem1' */
typedef struct {
  real_T In1;                          /* '<S78>/In1' */
} B_EnabledSubsystem1_Sensors_a_T;

/* Block states (default storage) for system '<S76>/Enabled Subsystem1' */
typedef struct {
  boolean_T EnabledSubsystem1_MODE;    /* '<S76>/Enabled Subsystem1' */
} DW_EnabledSubsystem1_Sensors__T;

/* Block signals (default storage) */
typedef struct {
  real_T Sum6;                         /* '<Root>/Sum6' */
  real_T Sum5;                         /* '<Root>/Sum5' */
  real_T ReshapeX0[4];                 /* '<S7>/ReshapeX0' */
  real_T MemoryX[4];                   /* '<S7>/MemoryX' */
  real_T Reshapexhat[4];               /* '<S7>/Reshapexhat' */
  real_T Add2;                         /* '<Root>/Add2' */
  real_T Add3;                         /* '<Root>/Add3' */
  real_T Add4;                         /* '<Root>/Add4' */
  real_T SineWave1;                    /* '<Root>/Sine Wave1' */
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T Sum[4];                       /* '<Root>/Sum' */
  real_T Gain3[2];                     /* '<Root>/Gain3' */
  real_T Add5;                         /* '<Root>/Add5' */
  real_T GainA;                        /* '<Root>/GainA' */
  real_T Sum1;                         /* '<Root>/Sum1' */
  real_T Gain_n;                       /* '<S4>/Gain' */
  real_T LeadlagFilter;                /* '<S4>/LeadlagFilter' */
  real_T LeadlagFilter2;               /* '<S4>/LeadlagFilter2' */
  real_T Integrator1;                  /* '<S4>/Integrator1' */
  real_T Switch3;                      /* '<Root>/Switch3' */
  real_T Integrator1_h;                /* '<Root>/Integrator1' */
  real_T Switch4;                      /* '<Root>/Switch4' */
  real_T Add7;                         /* '<Root>/Add7' */
  real_T GainC;                        /* '<Root>/GainC' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Gain_k;                       /* '<S6>/Gain' */
  real_T LeadlagFilter_f;              /* '<S6>/LeadlagFilter' */
  real_T LeadlagFilter2_l;             /* '<S6>/LeadlagFilter2' */
  real_T Integrator1_j;                /* '<S6>/Integrator1' */
  real_T Switch6;                      /* '<Root>/Switch6' */
  real_T Add6;                         /* '<Root>/Add6' */
  real_T GainB;                        /* '<Root>/GainB' */
  real_T IntegratorGain;               /* '<S4>/Integrator Gain' */
  real_T IntegratorGain_l;             /* '<S6>/Integrator Gain' */
  real_T Conversion[8];                /* '<S63>/Conversion' */
  real_T Conversion_c[8];              /* '<S64>/Conversion' */
  real_T Conversion_h;                 /* '<S65>/Conversion' */
  real_T Conversion_k[16];             /* '<S66>/Conversion' */
  real_T Conversion_a[4];              /* '<S36>/Conversion' */
  real_T Akxhatkk1[4];                 /* '<S40>/A[k]*xhat[k|k-1]' */
  real_T Reshapeu[2];                  /* '<S7>/Reshapeu' */
  real_T Bkuk[4];                      /* '<S40>/B[k]*u[k]' */
  real_T Reshapey[2];                  /* '<S7>/Reshapey' */
  real_T Add[4];                       /* '<S40>/Add' */
  real_T Reshape[4];                   /* '<S40>/Reshape' */
  real_T Sum2;                         /* '<Root>/Sum2' */
  real_T TransferFcn1;                 /* '<Root>/Transfer Fcn1' */
  real_T Integrator2;                  /* '<Root>/Integrator2' */
  real_T TransferFcn2;                 /* '<Root>/Transfer Fcn2' */
  real_T Integrator3;                  /* '<Root>/Integrator3' */
  real_T TransferFcn3;                 /* '<Root>/Transfer Fcn3' */
  real_T Gain_c;                       /* '<S5>/Gain' */
  real_T LeadlagFilter_j;              /* '<S5>/LeadlagFilter' */
  real_T LeadlagFilter2_n;             /* '<S5>/LeadlagFilter2' */
  real_T IntegratorGain_j;             /* '<S5>/Integrator Gain' */
  real_T Integrator1_l;                /* '<S5>/Integrator1' */
  real_T Sum_a;                        /* '<S5>/Sum' */
  real_T SFunction1_o1;                /* '<S84>/S-Function1' */
  real_T SFunction1_o2;                /* '<S84>/S-Function1' */
  real_T Inc2Pos;                      /* '<S18>/Inc2Pos' */
  real_T AbsPosition;                  /* '<S18>/AbsPosition' */
  real_T Abs;                          /* '<S86>/Abs' */
  real_T TransferFcn;                  /* '<S86>/Transfer Fcn' */
  real_T mm2m;                         /* '<S18>/mm2m' */
  real_T SFunction1_o1_g;              /* '<S79>/S-Function1' */
  real_T SFunction1_o2_p;              /* '<S79>/S-Function1' */
  real_T Inc2Pos_i;                    /* '<S17>/Inc2Pos' */
  real_T AbsPosition_h;                /* '<S17>/AbsPosition' */
  real_T Abs_l;                        /* '<S81>/Abs' */
  real_T TransferFcn_d;                /* '<S81>/Transfer Fcn' */
  real_T mm2m_p;                       /* '<S17>/mm2m' */
  real_T SFunction1_o1_o;              /* '<S74>/S-Function1' */
  real_T SFunction1_o2_n;              /* '<S74>/S-Function1' */
  real_T Inc2Pos_g;                    /* '<S16>/Inc2Pos' */
  real_T AbsPosition_hs;               /* '<S16>/AbsPosition' */
  real_T Abs_c;                        /* '<S76>/Abs' */
  real_T TransferFcn_f;                /* '<S76>/Transfer Fcn' */
  real_T mm2m_h;                       /* '<S16>/mm2m' */
  real_T Saturation;                   /* '<S15>/Saturation' */
  real_T Current2V;                    /* '<S15>/Current2V' */
  real_T DSPscale;                     /* '<S15>/DSPscale' */
  real_T Saturation_l;                 /* '<S14>/Saturation' */
  real_T Current2V_a;                  /* '<S14>/Current2V' */
  real_T DSPscale_a;                   /* '<S14>/DSPscale' */
  real_T Saturation_e;                 /* '<S13>/Saturation' */
  real_T Current2V_p;                  /* '<S13>/Current2V' */
  real_T DSPscale_o;                   /* '<S13>/DSPscale' */
  real_T motor1;                       /* '<Root>/MATLAB Function3' */
  real_T motor2;                       /* '<Root>/MATLAB Function3' */
  real_T motor3;                       /* '<Root>/MATLAB Function3' */
  real_T theta3;                       /* '<Root>/MATLAB Function' */
  real_T Zc;                           /* '<Root>/MATLAB Function' */
  real_T Ckxhatkk1[2];                 /* '<S69>/C[k]*xhat[k|k-1]' */
  real_T Dkuk[2];                      /* '<S69>/D[k]*u[k]' */
  real_T yhatkk1[2];                   /* '<S69>/Add1' */
  real_T Sum_n[2];                     /* '<S69>/Sum' */
  real_T Product3[4];                  /* '<S69>/Product3' */
  real_T Switch2;                      /* '<Root>/Switch2' */
  real_T Sum_i;                        /* '<S4>/Sum' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T Switch5;                      /* '<Root>/Switch5' */
  real_T Sum_ao;                       /* '<S6>/Sum' */
  uint32_T SFunction1_o4;              /* '<S2>/S-Function1' */
  uint32_T SFunction1_o1_h[3];         /* '<S1>/S-Function1' */
  real32_T Conversion_i[16];           /* '<S31>/Conversion' */
  uint16_T SFunction1_o6;              /* '<S2>/S-Function1' */
  uint16_T Gain2;                      /* '<Root>/Gain2' */
  uint16_T Gain1;                      /* '<Root>/Gain1' */
  uint8_T SFunction1_o1_n[32];         /* '<S2>/S-Function1' */
  uint8_T SFunction1_o5[4];            /* '<S2>/S-Function1' */
  uint8_T SFunction1_o2_m[4];          /* '<S1>/S-Function1' */
  boolean_T DataTypeConversion;        /* '<Root>/Data Type Conversion' */
  boolean_T RelationalOperator1;       /* '<S86>/Relational Operator1' */
  boolean_T RelationalOperator;        /* '<S86>/Relational Operator' */
  boolean_T LogicalOperator2;          /* '<S86>/Logical Operator2' */
  boolean_T RelationalOperator1_p;     /* '<S81>/Relational Operator1' */
  boolean_T RelationalOperator_n;      /* '<S81>/Relational Operator' */
  boolean_T LogicalOperator2_k;        /* '<S81>/Logical Operator2' */
  boolean_T RelationalOperator1_b;     /* '<S76>/Relational Operator1' */
  boolean_T RelationalOperator_c;      /* '<S76>/Relational Operator' */
  boolean_T LogicalOperator2_c;        /* '<S76>/Logical Operator2' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S86>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S86>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S81>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S81>/Enabled Subsystem' */
  B_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S76>/Enabled Subsystem1' */
  B_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S76>/Enabled Subsystem' */
  B_MATLABFunction1_Sensors_and_T sf_MATLABFunction4;/* '<Root>/MATLAB Function4' */
  B_MATLABFunction1_Sensors_and_T sf_MATLABFunction2;/* '<Root>/MATLAB Function2' */
  B_MATLABFunction1_Sensors_and_T sf_MATLABFunction1;/* '<Root>/MATLAB Function1' */
} B_Sensors_and_actuators_ball__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Sum6_DWORK1;                  /* '<Root>/Sum6' */
  struct {
    real_T RECEIVED_FRAMES;
  } SFunction1_RWORK;                  /* '<S2>/S-Function1' */

  struct {
    real_T RX_DROPPED_FRAMES[2];
  } SFunction1_RWORK_c;                /* '<S3>/S-Function1' */

  uint32_T Add1_DWORK1;                /* '<Root>/Add1' */
  int_T MemoryX_IWORK;                 /* '<S7>/MemoryX' */
  uint16_T Add_DWORK1;                 /* '<Root>/Add' */
  boolean_T MeasurementUpdate_MODE;    /* '<S40>/MeasurementUpdate' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_j;/* '<S86>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_c;/* '<S86>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1_m;/* '<S81>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem_h;/* '<S81>/Enabled Subsystem' */
  DW_EnabledSubsystem1_Sensors__T EnabledSubsystem1;/* '<S76>/Enabled Subsystem1' */
  DW_EnabledSubsystem_Sensors_a_T EnabledSubsystem;/* '<S76>/Enabled Subsystem' */
} DW_Sensors_and_actuators_ball_T;

/* Continuous states (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S7>/MemoryX' */
  real_T LeadlagFilter_CSTATE;         /* '<S4>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE;        /* '<S4>/LeadlagFilter2' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<Root>/Integrator1' */
  real_T LeadlagFilter_CSTATE_d;       /* '<S6>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE_a;      /* '<S6>/LeadlagFilter2' */
  real_T Integrator1_CSTATE_i;         /* '<S6>/Integrator1' */
  real_T TransferFcn1_CSTATE[2];       /* '<Root>/Transfer Fcn1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<Root>/Transfer Fcn2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T TransferFcn3_CSTATE[2];       /* '<Root>/Transfer Fcn3' */
  real_T LeadlagFilter_CSTATE_l;       /* '<S5>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE_h;      /* '<S5>/LeadlagFilter2' */
  real_T Integrator1_CSTATE_c;         /* '<S5>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S86>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S81>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S76>/Transfer Fcn' */
} X_Sensors_and_actuators_ball__T;

/* State derivatives (default storage) */
typedef struct {
  real_T MemoryX_CSTATE[4];            /* '<S7>/MemoryX' */
  real_T LeadlagFilter_CSTATE;         /* '<S4>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE;        /* '<S4>/LeadlagFilter2' */
  real_T Integrator1_CSTATE;           /* '<S4>/Integrator1' */
  real_T Integrator1_CSTATE_l;         /* '<Root>/Integrator1' */
  real_T LeadlagFilter_CSTATE_d;       /* '<S6>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE_a;      /* '<S6>/LeadlagFilter2' */
  real_T Integrator1_CSTATE_i;         /* '<S6>/Integrator1' */
  real_T TransferFcn1_CSTATE[2];       /* '<Root>/Transfer Fcn1' */
  real_T Integrator2_CSTATE;           /* '<Root>/Integrator2' */
  real_T TransferFcn2_CSTATE[2];       /* '<Root>/Transfer Fcn2' */
  real_T Integrator3_CSTATE;           /* '<Root>/Integrator3' */
  real_T TransferFcn3_CSTATE[2];       /* '<Root>/Transfer Fcn3' */
  real_T LeadlagFilter_CSTATE_l;       /* '<S5>/LeadlagFilter' */
  real_T LeadlagFilter2_CSTATE_h;      /* '<S5>/LeadlagFilter2' */
  real_T Integrator1_CSTATE_c;         /* '<S5>/Integrator1' */
  real_T TransferFcn_CSTATE;           /* '<S86>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_k;         /* '<S81>/Transfer Fcn' */
  real_T TransferFcn_CSTATE_b;         /* '<S76>/Transfer Fcn' */
} XDot_Sensors_and_actuators_ba_T;

/* State disabled  */
typedef struct {
  boolean_T MemoryX_CSTATE[4];         /* '<S7>/MemoryX' */
  boolean_T LeadlagFilter_CSTATE;      /* '<S4>/LeadlagFilter' */
  boolean_T LeadlagFilter2_CSTATE;     /* '<S4>/LeadlagFilter2' */
  boolean_T Integrator1_CSTATE;        /* '<S4>/Integrator1' */
  boolean_T Integrator1_CSTATE_l;      /* '<Root>/Integrator1' */
  boolean_T LeadlagFilter_CSTATE_d;    /* '<S6>/LeadlagFilter' */
  boolean_T LeadlagFilter2_CSTATE_a;   /* '<S6>/LeadlagFilter2' */
  boolean_T Integrator1_CSTATE_i;      /* '<S6>/Integrator1' */
  boolean_T TransferFcn1_CSTATE[2];    /* '<Root>/Transfer Fcn1' */
  boolean_T Integrator2_CSTATE;        /* '<Root>/Integrator2' */
  boolean_T TransferFcn2_CSTATE[2];    /* '<Root>/Transfer Fcn2' */
  boolean_T Integrator3_CSTATE;        /* '<Root>/Integrator3' */
  boolean_T TransferFcn3_CSTATE[2];    /* '<Root>/Transfer Fcn3' */
  boolean_T LeadlagFilter_CSTATE_l;    /* '<S5>/LeadlagFilter' */
  boolean_T LeadlagFilter2_CSTATE_h;   /* '<S5>/LeadlagFilter2' */
  boolean_T Integrator1_CSTATE_c;      /* '<S5>/Integrator1' */
  boolean_T TransferFcn_CSTATE;        /* '<S86>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_k;      /* '<S81>/Transfer Fcn' */
  boolean_T TransferFcn_CSTATE_b;      /* '<S76>/Transfer Fcn' */
} XDis_Sensors_and_actuators_ba_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator1_Reset_ZCE;    /* '<S4>/Integrator1' */
  ZCSigState Integrator1_Reset_ZCE_g;  /* '<Root>/Integrator1' */
  ZCSigState Integrator1_Reset_ZCE_m;  /* '<S6>/Integrator1' */
  ZCSigState Integrator2_Reset_ZCE;    /* '<Root>/Integrator2' */
  ZCSigState Integrator3_Reset_ZCE;    /* '<Root>/Integrator3' */
  ZCSigState Integrator1_Reset_ZCE_l;  /* '<S5>/Integrator1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig_ZC;/* '<S18>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__n;/* '<S17>/EMC_ENCODER_POS_SET_BL1' */
  ZCSigState EMC_ENCODER_POS_SET_BL1_Trig__o;/* '<S16>/EMC_ENCODER_POS_SET_BL1' */
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
  real_T controller_disable;           /* '<Root>/controller_disable' */
  real_T CloseLoop_disable;            /* '<Root>/CloseLoop_disable' */
  real_T reser_integrator;             /* '<Root>/reser_integrator' */
  boolean_T Init1;                     /* '<Root>/Init1' */
  real_T controller_disable1;          /* '<Root>/controller_disable1' */
  real_T CloseLoop_disable1;           /* '<Root>/CloseLoop_disable1' */
  real_T reser_integrator1;            /* '<Root>/reser_integrator1' */
  boolean_T Init2;                     /* '<Root>/Init2' */
  real_T controller_disable2;          /* '<Root>/controller_disable2' */
  real_T CloseLoop_disable2;           /* '<Root>/CloseLoop_disable2' */
  real_T reser_integrator2;            /* '<Root>/reser_integrator2' */
} ExtU_Sensors_and_actuators_ba_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T P_A;                          /* '<Root>/P_A' */
  uint16_T Xpos;                       /* '<Root>/Xpos ' */
  uint16_T Ypos;                       /* '<Root>/Ypos ' */
  uint32_T Status;                     /* '<Root>/Status ' */
  real_T Frames;                       /* '<Root>/Frames ' */
  real_T P_B;                          /* '<Root>/P_B' */
  real_T P_C;                          /* '<Root>/P_C' */
  real_T Xpos_m;                       /* '<Root>/Xpos_m' */
  real_T Ypos_m;                       /* '<Root>/Ypos_m' */
  real_T estimated_ball[4];            /* '<Root>/estimated_ball' */
  real_T measured_theta1;              /* '<Root>/measured_theta1' */
  real_T measured_theta2;              /* '<Root>/measured_theta2' */
} ExtY_Sensors_and_actuators_ba_T;

/* Parameters for system: '<S76>/Enabled Subsystem' */
struct P_EnabledSubsystem_Sensors_an_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S77>/Out1'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S77>/Constant'
                                        */
};

/* Parameters for system: '<S76>/Enabled Subsystem1' */
struct P_EnabledSubsystem1_Sensors_a_T_ {
  real_T Out1_Y0;                      /* Expression: [0]
                                        * Referenced by: '<S78>/Out1'
                                        */
};

/* Parameters (default storage) */
struct P_Sensors_and_actuators_ball__T_ {
  real_T ballLQRgain[8];               /* Variable: ballLQRgain
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T denc_mi[3];                   /* Variable: denc_mi
                                        * Referenced by:
                                        *   '<Root>/Transfer Fcn1'
                                        *   '<Root>/Transfer Fcn2'
                                        *   '<Root>/Transfer Fcn3'
                                        */
  real_T numc_mi[3];                   /* Variable: numc_mi
                                        * Referenced by:
                                        *   '<Root>/Transfer Fcn1'
                                        *   '<Root>/Transfer Fcn2'
                                        *   '<Root>/Transfer Fcn3'
                                        */
  real_T Switch5_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch5'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Switch2_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Lykyhatkk1_Y0;                /* Expression: 0
                                        * Referenced by: '<S69>/L*(y[k]-yhat[k|k-1])'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 3
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -3
                                        * Referenced by: '<S13>/Saturation'
                                        */
  real_T Current2V_Gain;               /* Expression: 10/3
                                        * Referenced by: '<S13>/Current2V'
                                        */
  real_T DSPscale_Gain;                /* Expression: 1/10
                                        * Referenced by: '<S13>/DSPscale'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: 3
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: -3
                                        * Referenced by: '<S14>/Saturation'
                                        */
  real_T Current2V_Gain_l;             /* Expression: 10/3
                                        * Referenced by: '<S14>/Current2V'
                                        */
  real_T DSPscale_Gain_j;              /* Expression: 1/10
                                        * Referenced by: '<S14>/DSPscale'
                                        */
  real_T Saturation_UpperSat_j;        /* Expression: 3
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: -3
                                        * Referenced by: '<S15>/Saturation'
                                        */
  real_T Current2V_Gain_j;             /* Expression: 10/3
                                        * Referenced by: '<S15>/Current2V'
                                        */
  real_T DSPscale_Gain_h;              /* Expression: 1/10
                                        * Referenced by: '<S15>/DSPscale'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<S16>/Constant'
                                        */
  real_T ZP_Value;                     /* Expression: 29
                                        * Referenced by: '<S16>/ZP'
                                        */
  real_T Inc2Pos_Gain;                 /* Expression: 8e-3
                                        * Referenced by: '<S16>/Inc2Pos'
                                        */
  real_T Pos_offset_Value;             /* Expression: 0
                                        * Referenced by: '<S16>/Pos_offset'
                                        */
  real_T Const_Value;                  /* Expression: 0.01
                                        * Referenced by: '<S76>/Const'
                                        */
  real_T Const1_Value;                 /* Expression: -0.98
                                        * Referenced by: '<S76>/Const1'
                                        */
  real_T TransferFcn_A;                /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<S76>/Transfer Fcn'
                                        */
  real_T TransferFcn_C;                /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<S76>/Transfer Fcn'
                                        */
  real_T mm2m_Gain;                    /* Expression: 0.001
                                        * Referenced by: '<S16>/mm2m'
                                        */
  real_T Constant_Value_d;             /* Expression: 10
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T ZP_Value_a;                   /* Expression: 29
                                        * Referenced by: '<S17>/ZP'
                                        */
  real_T Inc2Pos_Gain_j;               /* Expression: 8e-3
                                        * Referenced by: '<S17>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_f;           /* Expression: 0
                                        * Referenced by: '<S17>/Pos_offset'
                                        */
  real_T Const_Value_d;                /* Expression: 0.01
                                        * Referenced by: '<S81>/Const'
                                        */
  real_T Const1_Value_k;               /* Expression: -0.98
                                        * Referenced by: '<S81>/Const1'
                                        */
  real_T TransferFcn_A_b;              /* Computed Parameter: TransferFcn_A_b
                                        * Referenced by: '<S81>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_j;              /* Computed Parameter: TransferFcn_C_j
                                        * Referenced by: '<S81>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_f;                  /* Expression: 0.001
                                        * Referenced by: '<S17>/mm2m'
                                        */
  real_T Constant_Value_c;             /* Expression: 10
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T ZP_Value_d;                   /* Expression: 29
                                        * Referenced by: '<S18>/ZP'
                                        */
  real_T Inc2Pos_Gain_i;               /* Expression: 8e-3
                                        * Referenced by: '<S18>/Inc2Pos'
                                        */
  real_T Pos_offset_Value_b;           /* Expression: 0
                                        * Referenced by: '<S18>/Pos_offset'
                                        */
  real_T Const_Value_i;                /* Expression: 0.01
                                        * Referenced by: '<S86>/Const'
                                        */
  real_T Const1_Value_n;               /* Expression: -0.98
                                        * Referenced by: '<S86>/Const1'
                                        */
  real_T TransferFcn_A_p;              /* Computed Parameter: TransferFcn_A_p
                                        * Referenced by: '<S86>/Transfer Fcn'
                                        */
  real_T TransferFcn_C_m;              /* Computed Parameter: TransferFcn_C_m
                                        * Referenced by: '<S86>/Transfer Fcn'
                                        */
  real_T mm2m_Gain_a;                  /* Expression: 0.001
                                        * Referenced by: '<S18>/mm2m'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant10_Value;             /* Expression: 227
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Gain5_Gain;                   /* Expression: 1/(463-25)*0.4
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Constant4_Value;              /* Expression: 295
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(515-70)*0.4
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T X0_Value[4];                  /* Expression: pInitialization.X0
                                        * Referenced by: '<S7>/X0'
                                        */
  real_T Constant9_Value;              /* Expression: 0.32
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: pi/4
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave_Amp;                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: pi/4
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0.32
                                        * Referenced by: '<Root>/Constant14'
                                        */
  real_T GainA_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<Root>/GainA'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1000
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T LeadlagFilter_A;              /* Computed Parameter: LeadlagFilter_A
                                        * Referenced by: '<S4>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_C;              /* Computed Parameter: LeadlagFilter_C
                                        * Referenced by: '<S4>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_D;              /* Computed Parameter: LeadlagFilter_D
                                        * Referenced by: '<S4>/LeadlagFilter'
                                        */
  real_T LeadlagFilter2_A;             /* Computed Parameter: LeadlagFilter2_A
                                        * Referenced by: '<S4>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_C;             /* Computed Parameter: LeadlagFilter2_C
                                        * Referenced by: '<S4>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_D;             /* Computed Parameter: LeadlagFilter2_D
                                        * Referenced by: '<S4>/LeadlagFilter2'
                                        */
  real_T Constant_Value_a;             /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Integrator1_UpperSat;         /* Expression: 3
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Integrator1_LowerSat;         /* Expression: -3
                                        * Referenced by: '<S4>/Integrator1'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T Constant2_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Integrator1_IC_i;             /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_UpperSat_l;       /* Expression: 3
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Integrator1_LowerSat_p;       /* Expression: -3
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch4'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T GainC_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<Root>/GainC'
                                        */
  real_T Gain_Gain_lq;                 /* Expression: 1000
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T LeadlagFilter_A_k;            /* Computed Parameter: LeadlagFilter_A_k
                                        * Referenced by: '<S6>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_C_d;            /* Computed Parameter: LeadlagFilter_C_d
                                        * Referenced by: '<S6>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_D_j;            /* Computed Parameter: LeadlagFilter_D_j
                                        * Referenced by: '<S6>/LeadlagFilter'
                                        */
  real_T LeadlagFilter2_A_l;           /* Computed Parameter: LeadlagFilter2_A_l
                                        * Referenced by: '<S6>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_C_j;           /* Computed Parameter: LeadlagFilter2_C_j
                                        * Referenced by: '<S6>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_D_b;           /* Computed Parameter: LeadlagFilter2_D_b
                                        * Referenced by: '<S6>/LeadlagFilter2'
                                        */
  real_T Constant_Value_dy;            /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T Integrator1_IC_m;             /* Expression: 0
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator1_UpperSat_e;       /* Expression: 3
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Integrator1_LowerSat_g;       /* Expression: -3
                                        * Referenced by: '<S6>/Integrator1'
                                        */
  real_T Switch6_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<Root>/Switch6'
                                        */
  real_T GainB_Gain;                   /* Expression: 0.1
                                        * Referenced by: '<Root>/GainB'
                                        */
  real_T IntegratorGain_Gain;          /* Expression: 2*pi*10
                                        * Referenced by: '<S4>/Integrator Gain'
                                        */
  real_T IntegratorGain_Gain_d;        /* Expression: 2*pi*10
                                        * Referenced by: '<S6>/Integrator Gain'
                                        */
  real_T A_Value[16];                  /* Expression: pInitialization.A
                                        * Referenced by: '<S7>/A'
                                        */
  real_T B_Value[8];                   /* Expression: pInitialization.B
                                        * Referenced by: '<S7>/B'
                                        */
  real_T C_Value[8];                   /* Expression: pInitialization.C
                                        * Referenced by: '<S7>/C'
                                        */
  real_T CovarianceZ_Value[16];        /* Expression: pInitialization.Z
                                        * Referenced by: '<S20>/CovarianceZ'
                                        */
  real_T KalmanGainL_Value[8];         /* Expression: pInitialization.L
                                        * Referenced by: '<S20>/KalmanGainL'
                                        */
  real_T KalmanGainM_Value[8];         /* Expression: pInitialization.M
                                        * Referenced by: '<S20>/KalmanGainM'
                                        */
  real_T D_Value[4];                   /* Expression: pInitialization.D
                                        * Referenced by: '<S7>/D'
                                        */
  real_T P0_Value[16];                 /* Expression: pInitialization.P0
                                        * Referenced by: '<S7>/P0'
                                        */
  real_T G_Value[16];                  /* Expression: pInitialization.G
                                        * Referenced by: '<S7>/G'
                                        */
  real_T H_Value[8];                   /* Expression: pInitialization.H
                                        * Referenced by: '<S7>/H'
                                        */
  real_T N_Value[8];                   /* Expression: pInitialization.N
                                        * Referenced by: '<S7>/N'
                                        */
  real_T Q_Value[16];                  /* Expression: pInitialization.Q
                                        * Referenced by: '<S7>/Q'
                                        */
  real_T R_Value[4];                   /* Expression: pInitialization.R
                                        * Referenced by: '<S7>/R'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator2_UpperSat;         /* Expression: 3
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator2_LowerSat;         /* Expression: -3
                                        * Referenced by: '<Root>/Integrator2'
                                        */
  real_T Integrator3_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator3_UpperSat;         /* Expression: 3
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Integrator3_LowerSat;         /* Expression: -3
                                        * Referenced by: '<Root>/Integrator3'
                                        */
  real_T Constant_Value_ar;            /* Expression: 0
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 1000
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T LeadlagFilter_A_g;            /* Computed Parameter: LeadlagFilter_A_g
                                        * Referenced by: '<S5>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_C_e;            /* Computed Parameter: LeadlagFilter_C_e
                                        * Referenced by: '<S5>/LeadlagFilter'
                                        */
  real_T LeadlagFilter_D_k;            /* Computed Parameter: LeadlagFilter_D_k
                                        * Referenced by: '<S5>/LeadlagFilter'
                                        */
  real_T LeadlagFilter2_A_k;           /* Computed Parameter: LeadlagFilter2_A_k
                                        * Referenced by: '<S5>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_C_h;           /* Computed Parameter: LeadlagFilter2_C_h
                                        * Referenced by: '<S5>/LeadlagFilter2'
                                        */
  real_T LeadlagFilter2_D_i;           /* Computed Parameter: LeadlagFilter2_D_i
                                        * Referenced by: '<S5>/LeadlagFilter2'
                                        */
  real_T IntegratorGain_Gain_i;        /* Expression: 2*pi*10
                                        * Referenced by: '<S5>/Integrator Gain'
                                        */
  real_T Integrator1_IC_k;             /* Expression: 0
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Integrator1_UpperSat_f;       /* Expression: 3
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  real_T Integrator1_LowerSat_i;       /* Expression: -3
                                        * Referenced by: '<S5>/Integrator1'
                                        */
  boolean_T Enable_Value;              /* Expression: true()
                                        * Referenced by: '<S7>/Enable'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_j;/* '<S86>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_c;/* '<S86>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1_m;/* '<S81>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem_h;/* '<S81>/Enabled Subsystem' */
  P_EnabledSubsystem1_Sensors_a_T EnabledSubsystem1;/* '<S76>/Enabled Subsystem1' */
  P_EnabledSubsystem_Sensors_an_T EnabledSubsystem;/* '<S76>/Enabled Subsystem' */
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
  real_T odeF[1][25];
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
 * '<S4>'   : 'Sensors_and_actuators_ball_and_plate/HighBandWidth Controller A'
 * '<S5>'   : 'Sensors_and_actuators_ball_and_plate/HighBandWidth Controller B'
 * '<S6>'   : 'Sensors_and_actuators_ball_and_plate/HighBandWidth Controller C'
 * '<S7>'   : 'Sensors_and_actuators_ball_and_plate/Kalman Filter'
 * '<S8>'   : 'Sensors_and_actuators_ball_and_plate/MATLAB Function'
 * '<S9>'   : 'Sensors_and_actuators_ball_and_plate/MATLAB Function1'
 * '<S10>'  : 'Sensors_and_actuators_ball_and_plate/MATLAB Function2'
 * '<S11>'  : 'Sensors_and_actuators_ball_and_plate/MATLAB Function3'
 * '<S12>'  : 'Sensors_and_actuators_ball_and_plate/MATLAB Function4'
 * '<S13>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier'
 * '<S14>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1'
 * '<S15>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2'
 * '<S16>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement'
 * '<S17>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1'
 * '<S18>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2'
 * '<S19>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data'
 * '<S20>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL'
 * '<S21>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculateYhat'
 * '<S22>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CovarianceOutputConfigurator'
 * '<S23>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionA'
 * '<S24>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionB'
 * '<S25>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionC'
 * '<S26>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionD'
 * '<S27>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionEnable'
 * '<S28>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionG'
 * '<S29>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionH'
 * '<S30>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionN'
 * '<S31>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionP'
 * '<S32>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionP0'
 * '<S33>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionQ'
 * '<S34>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionR'
 * '<S35>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionReset'
 * '<S36>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionX'
 * '<S37>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionX0'
 * '<S38>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/DataTypeConversionu'
 * '<S39>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/MemoryP'
 * '<S40>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Observer'
 * '<S41>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ReducedQRN'
 * '<S42>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Reset'
 * '<S43>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Reshapeyhat'
 * '<S44>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionP0'
 * '<S45>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionQ'
 * '<S46>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ScalarExpansionR'
 * '<S47>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/UseCurrentEstimator'
 * '<S48>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkA'
 * '<S49>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkB'
 * '<S50>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkC'
 * '<S51>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkD'
 * '<S52>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkEnable'
 * '<S53>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkG'
 * '<S54>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkH'
 * '<S55>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkN'
 * '<S56>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkP0'
 * '<S57>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkQ'
 * '<S58>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkR'
 * '<S59>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkReset'
 * '<S60>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checkX0'
 * '<S61>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checku'
 * '<S62>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/checky'
 * '<S63>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionL'
 * '<S64>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionM'
 * '<S65>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionP'
 * '<S66>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/DataTypeConversionZ'
 * '<S67>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculatePL/Ground'
 * '<S68>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/CalculateYhat/Ground'
 * '<S69>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/Observer/MeasurementUpdate'
 * '<S70>'  : 'Sensors_and_actuators_ball_and_plate/Kalman Filter/ReducedQRN/Ground'
 * '<S71>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1'
 * '<S72>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1'
 * '<S73>'  : 'Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1'
 * '<S74>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_BL1'
 * '<S75>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_POS_SET_BL1'
 * '<S76>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial'
 * '<S77>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem'
 * '<S78>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement/Initial/Enabled Subsystem1'
 * '<S79>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_BL1'
 * '<S80>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_POS_SET_BL1'
 * '<S81>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial'
 * '<S82>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem'
 * '<S83>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement1/Initial/Enabled Subsystem1'
 * '<S84>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_BL1'
 * '<S85>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_POS_SET_BL1'
 * '<S86>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial'
 * '<S87>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem'
 * '<S88>'  : 'Sensors_and_actuators_ball_and_plate/Position Measurement2/Initial/Enabled Subsystem1'
 * '<S89>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store'
 * '<S90>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store'
 * '<S91>'  : 'Sensors_and_actuators_ball_and_plate/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                  /* RTW_HEADER_Sensors_and_actuators_ball_and_plate_h_ */
