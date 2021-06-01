/*
 * BallAndPlateMeasurement_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BallAndPlateMeasurement".
 *
 * Model version              : 1.13
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  1 17:08:16 2021
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_BallAndPlateMeasurement_private_h_
#define RTW_HEADER_BallAndPlateMeasurement_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#include "BallAndPlateMeasurement.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_1;
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_2;
extern DacCl1AnalogOutSDrvObject *pRTIDacC1AnalogOut_Ch_3;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3;
extern DioCl2EncoderInSDrvObject *pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5;
extern rtTimingBridge BallAndPlateMeasurem_TimingBrdg;
extern void BallAndPl_EnabledSubsystem_Init(B_EnabledSubsystem_BallAndPla_T
  *localB, P_EnabledSubsystem_BallAndPla_T *localP);
extern void BallAndP_EnabledSubsystem_Start(DW_EnabledSubsystem_BallAndPl_T
  *localDW);
extern void BallAn_EnabledSubsystem_Disable(B_EnabledSubsystem_BallAndPla_T
  *localB, DW_EnabledSubsystem_BallAndPl_T *localDW,
  P_EnabledSubsystem_BallAndPla_T *localP);
extern void BallAndPlateMe_EnabledSubsystem(RT_MODEL_BallAndPlateMeasurem_T *
  const BallAndPlateMeasurement_M, real_T rtu_Enable,
  B_EnabledSubsystem_BallAndPla_T *localB, DW_EnabledSubsystem_BallAndPl_T
  *localDW, P_EnabledSubsystem_BallAndPla_T *localP);
extern void BallAndP_EnabledSubsystem1_Init(B_EnabledSubsystem1_BallAndPl_T
  *localB, P_EnabledSubsystem1_BallAndPl_T *localP);
extern void BallAnd_EnabledSubsystem1_Start(DW_EnabledSubsystem1_BallAndP_T
  *localDW);
extern void BallA_EnabledSubsystem1_Disable(DW_EnabledSubsystem1_BallAndP_T
  *localDW);
extern void BallAndPlateM_EnabledSubsystem1(RT_MODEL_BallAndPlateMeasurem_T *
  const BallAndPlateMeasurement_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem1_BallAndPl_T *localB, DW_EnabledSubsystem1_BallAndP_T
  *localDW);

/* private model entry point functions */
extern void BallAndPlateMeasurement_derivatives(void);

#endif                       /* RTW_HEADER_BallAndPlateMeasurement_private_h_ */
