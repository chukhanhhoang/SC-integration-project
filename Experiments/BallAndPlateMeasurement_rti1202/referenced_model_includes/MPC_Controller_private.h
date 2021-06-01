/*
 * MPC_Controller_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "MPC_Controller".
 *
 * Model version              : 1.30
 * Simulink Coder version : 9.2 (R2019b) 18-Jul-2019
 * C source code generated on : Tue Jun  1 16:44:25 2021
 *
 * Target selection: rti1202.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Custom Processor->Custom
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_MPC_Controller_private_h_
#define RTW_HEADER_MPC_Controller_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       ((rtmGetSimTimeStep((rtm))) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(sti, tid)      (MPC_Controller_TimingBrdg->taskCounter[MPC_Controller_GlobalTID[sti]] == 0)
#endif

/* Macros for accessing real-time model data structure */
#ifndef rtmGetClockTick0
# define rtmGetClockTick0()            ( *((MPC_Controller_TimingBrdg->clockTick[MPC_Controller_GlobalTID[0]])) )
#endif

#ifndef rtmGetClockTick1
# define rtmGetClockTick1()            ( *((MPC_Controller_TimingBrdg->clockTick[MPC_Controller_GlobalTID[1]])) )
#endif

#ifndef rtmGetClockTick2
# define rtmGetClockTick2()            ( *((MPC_Controller_TimingBrdg->clockTick[MPC_Controller_GlobalTID[2]])) )
#endif

#ifndef rtmGetClockTickH0
# define rtmGetClockTickH0()           ( *(MPC_Controller_TimingBrdg->clockTickH[MPC_Controller_GlobalTID[0]]) )
#endif

#ifndef rtmGetClockTickH1
# define rtmGetClockTickH1()           ( *(MPC_Controller_TimingBrdg->clockTickH[MPC_Controller_GlobalTID[1]]) )
#endif

#ifndef rtmGetClockTickH2
# define rtmGetClockTickH2()           ( *(MPC_Controller_TimingBrdg->clockTickH[MPC_Controller_GlobalTID[2]]) )
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        (*((rtm)->Timing.simTimeStep))
#endif

#ifndef rtmGetSimTimeStepPointer
# define rtmGetSimTimeStepPointer(rtm) (rtm)->Timing.simTimeStep
#endif

#ifndef rtmSetSimTimeStepPointer
# define rtmSetSimTimeStepPointer(rtm, val) ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      (*((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) (*((rtm)->Timing.stopRequestedFlag) = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedPtr
# define rtmSetStopRequestedPtr(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetT
# define rtmGetT()                     (*(MPC_Controller_TimingBrdg->taskTime[0]))
#endif

extern int_T MPC_Controller_GlobalTID[3];
extern const rtTimingBridge *MPC_Controller_TimingBrdg;

#ifndef MPC_Controller_MDLREF_HIDE_CHILD_

extern P_MPC_Controller_T MPC_Controller_P_g;

#endif                                 /*MPC_Controller_MDLREF_HIDE_CHILD_*/
#endif                                /* RTW_HEADER_MPC_Controller_private_h_ */
