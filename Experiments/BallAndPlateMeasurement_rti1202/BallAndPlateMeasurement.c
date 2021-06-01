/*
 * BallAndPlateMeasurement.c
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

#include "BallAndPlateMeasurement_trc_ptr.h"
#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"

rtTimingBridge BallAndPlateMeasurem_TimingBrdg;

/* Block signals (default storage) */
B_BallAndPlateMeasurement_T BallAndPlateMeasurement_B;

/* Continuous states */
X_BallAndPlateMeasurement_T BallAndPlateMeasurement_X;

/* Block states (default storage) */
DW_BallAndPlateMeasurement_T BallAndPlateMeasurement_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_BallAndPlateMeasureme_T BallAndPlateMeasurement_PrevZCX;

/* External outputs (root outports fed by signals with default storage) */
ExtY_BallAndPlateMeasurement_T BallAndPlateMeasurement_Y;

/* Real-time model */
RT_MODEL_BallAndPlateMeasurem_T BallAndPlateMeasurement_M_;
RT_MODEL_BallAndPlateMeasurem_T *const BallAndPlateMeasurement_M =
  &BallAndPlateMeasurement_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2])++;
  if ((BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2]) > 39) {/* Sample time: [0.04s, 0.0s] */
    BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 12;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  BallAndPlateMeasurement_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * System initialize for enable system:
 *    '<S16>/Enabled Subsystem'
 *    '<S21>/Enabled Subsystem'
 *    '<S26>/Enabled Subsystem'
 */
void BallAndPl_EnabledSubsystem_Init(B_EnabledSubsystem_BallAndPla_T *localB,
  P_EnabledSubsystem_BallAndPla_T *localP)
{
  /* SystemInitialize for Outport: '<S17>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S16>/Enabled Subsystem'
 *    '<S21>/Enabled Subsystem'
 *    '<S26>/Enabled Subsystem'
 */
void BallAn_EnabledSubsystem_Disable(B_EnabledSubsystem_BallAndPla_T *localB,
  DW_EnabledSubsystem_BallAndPl_T *localDW, P_EnabledSubsystem_BallAndPla_T
  *localP)
{
  /* Disable for Outport: '<S17>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S16>/Enabled Subsystem'
 *    '<S21>/Enabled Subsystem'
 *    '<S26>/Enabled Subsystem'
 */
void BallAndP_EnabledSubsystem_Start(DW_EnabledSubsystem_BallAndPl_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S16>/Enabled Subsystem'
 *    '<S21>/Enabled Subsystem'
 *    '<S26>/Enabled Subsystem'
 */
void BallAndPlateMe_EnabledSubsystem(RT_MODEL_BallAndPlateMeasurem_T * const
  BallAndPlateMeasurement_M, real_T rtu_Enable, B_EnabledSubsystem_BallAndPla_T *
  localB, DW_EnabledSubsystem_BallAndPl_T *localDW,
  P_EnabledSubsystem_BallAndPla_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    if (rtu_Enable > 0.0) {
      localDW->EnabledSubsystem_MODE = true;
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        BallAn_EnabledSubsystem_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE) {
    /* SignalConversion generated from: '<S17>/Out1' incorporates:
     *  Constant: '<S17>/Constant'
     */
    localB->OutportBufferForOut1 = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S16>/Enabled Subsystem1'
 *    '<S21>/Enabled Subsystem1'
 *    '<S26>/Enabled Subsystem1'
 */
void BallAndP_EnabledSubsystem1_Init(B_EnabledSubsystem1_BallAndPl_T *localB,
  P_EnabledSubsystem1_BallAndPl_T *localP)
{
  /* SystemInitialize for Outport: '<S18>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S16>/Enabled Subsystem1'
 *    '<S21>/Enabled Subsystem1'
 *    '<S26>/Enabled Subsystem1'
 */
void BallA_EnabledSubsystem1_Disable(DW_EnabledSubsystem1_BallAndP_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S16>/Enabled Subsystem1'
 *    '<S21>/Enabled Subsystem1'
 *    '<S26>/Enabled Subsystem1'
 */
void BallAnd_EnabledSubsystem1_Start(DW_EnabledSubsystem1_BallAndP_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S16>/Enabled Subsystem1'
 *    '<S21>/Enabled Subsystem1'
 *    '<S26>/Enabled Subsystem1'
 */
void BallAndPlateM_EnabledSubsystem1(RT_MODEL_BallAndPlateMeasurem_T * const
  BallAndPlateMeasurement_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem1_BallAndPl_T *localB, DW_EnabledSubsystem1_BallAndP_T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S18>/Enable'
   */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem1_MODE = true;
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        BallA_EnabledSubsystem1_Disable(localDW);
      }
    }
  }

  if (localDW->EnabledSubsystem1_MODE && (rtmIsMajorTimeStep
       (BallAndPlateMeasurement_M) &&
       BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0)) {
    /* Inport: '<S18>/In1' */
    localB->In1 = rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem1' */
}

/* Model output function */
void BallAndPlateMeasurement_output(void)
{
  ZCEventType zcEvent;
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* set solver stop time */
    if (!(BallAndPlateMeasurement_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&BallAndPlateMeasurement_M->solverInfo,
                            ((BallAndPlateMeasurement_M->Timing.clockTickH0 + 1)
        * BallAndPlateMeasurement_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&BallAndPlateMeasurement_M->solverInfo,
                            ((BallAndPlateMeasurement_M->Timing.clockTick0 + 1) *
        BallAndPlateMeasurement_M->Timing.stepSize0 +
        BallAndPlateMeasurement_M->Timing.clockTickH0 *
        BallAndPlateMeasurement_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(BallAndPlateMeasurement_M)) {
    BallAndPlateMeasurement_M->Timing.t[0] = rtsiGetT
      (&BallAndPlateMeasurement_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2] == 0) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    BallAndPlateMeasurement_B.DataTypeConversion =
      (BallAndPlateMeasurement_P.Constant1_Value != 0.0);

    /* S-Function (rti_commonblock): '<S2>/S-Function1' */
    /* This comment workarounds a code generation problem */
    {
      /* --- BallAndPlateMeasurement/ETHERNET_UDP_RX_BL1: ==> Socket ID = (0) --- */
      /* dSPACE I/O Board DSETHERNET #1 Unit:RXUDP Group:RXUDP */

      /* variable frame size mode is adjusted */

      /* variable declarations */
      DsSSockAddrIn remoteAddr;
      UInt32 addrLen = sizeof(remoteAddr);
      Int32 realLen, tmpStatus;

      /* set remote IP and port initially to 0 within the socket structure */
      remoteAddr.sin_addr.s_addr = (UInt32) 0;
      remoteAddr.sin_port = (UInt16) 0;
      remoteAddr.sin_family = DSIOETH_AF_INET;

      /* whether block is enabled */
      if (BallAndPlateMeasurement_B.DataTypeConversion == 0) {
        /* block is disabled */
        /**/

        /* set output Received Bytes to 0 */
        BallAndPlateMeasurement_B.SFunction1_o4 = (uint32_T) 0;

        /* set output Status to state 1 indicating a disabled RX block */
        tmpStatus = 1;
      } else {
        /* block is enabled */
        /**/

        /* receive data from a socket and obtain the address of the sender */
        realLen =
          DsIoEth_recvfrom( DSIOETH_CONNECTION_ID_0,
                           (uint8_T *)
                           &BallAndPlateMeasurement_B.SFunction1_o1_n[0],
                           32U,
                           DSIOETH_FLAG_NONE,
                           (DsSSockAddr *) &remoteAddr,
                           &addrLen
                           );
        if (realLen > 0) {
          /* set output Status to state 0 indicating successfully received data */
          tmpStatus = 0;

          /* increment output Received Frames  */
          BallAndPlateMeasurement_B.SFunction1_o3 = (real_T)
            (BallAndPlateMeasurement_B.SFunction1_o3 + 1);

          /* set output Received Bytes  to real data length realLen */
          BallAndPlateMeasurement_B.SFunction1_o4 = (uint32_T) realLen;
        } else {
          /* realLen -1: No data received due to empty rx buffer *
           * realLen  0: Connection socket not ready (closed)    */
          tmpStatus = (realLen == -1) ? 2 : 3;

          /* no data received due to empty rx buffer or socket not ready yet */
          BallAndPlateMeasurement_B.SFunction1_o4 = (uint32_T) 0;
        }
      }                                // if (Inport_Enable == 0)

      /* assign receive status to the related outport */
      BallAndPlateMeasurement_B.SFunction1_o2_k = (uint32_T) tmpStatus;

      /* assign remote IP (s_addr: uint32) to the related outport as (uint8.uint8.uint8.uint8) */
      *((UInt32*) &BallAndPlateMeasurement_B.SFunction1_o5[0]) =
        remoteAddr.sin_addr.s_addr;

      /* assign remote port to the related outport */
      BallAndPlateMeasurement_B.SFunction1_o6 = DsIoEth_ntohs
        (remoteAddr.sin_port);
    }

    /* Outport: '<Root>/Status ' */
    BallAndPlateMeasurement_Y.Status = BallAndPlateMeasurement_B.SFunction1_o2_k;

    /* Outport: '<Root>/Frames ' */
    BallAndPlateMeasurement_Y.Frames = BallAndPlateMeasurement_B.SFunction1_o3;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S7>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S15>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S15>/S-Function1' incorporates:
         *  Constant: '<S7>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1,
               (Float64)(BallAndPlateMeasurement_P.Constant_Value * 1)
               );

            /* Set positions state for the selected incremental Encoder to VALID */
            DioCl2EncoderIn_setEncPosValidity
              (pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1,
               DIO_ENC_POSITION_VALID
               );

            /* Writes settings for the incremental Encoder */
            DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S7>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S14>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S7>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos_g = BallAndPlateMeasurement_P.Inc2Pos_Gain
      * BallAndPlateMeasurement_B.SFunction1_o1_o;

    /* Sum: '<S7>/AbsPosition' incorporates:
     *  Constant: '<S7>/Pos_offset'
     *  Constant: '<S7>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition_hs =
      (BallAndPlateMeasurement_B.Inc2Pos_g - BallAndPlateMeasurement_P.ZP_Value)
      - BallAndPlateMeasurement_P.Pos_offset_Value;

    /* Abs: '<S16>/Abs' */
    BallAndPlateMeasurement_B.Abs_c = fabs
      (BallAndPlateMeasurement_B.SFunction1_o2_n);

    /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem,
      &BallAndPlateMeasurement_DW.EnabledSubsystem,
      &BallAndPlateMeasurement_P.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem' */

    /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
     *  Constant: '<S16>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1_b =
      (BallAndPlateMeasurement_B.Abs_c <= BallAndPlateMeasurement_P.Const_Value);
  }

  /* TransferFcn: '<S16>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn_f = 0.0;
  BallAndPlateMeasurement_B.TransferFcn_f +=
    BallAndPlateMeasurement_P.TransferFcn_C *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_b;

  /* RelationalOperator: '<S16>/Relational Operator' incorporates:
   *  Constant: '<S16>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator_c =
    (BallAndPlateMeasurement_P.Const1_Value >=
     BallAndPlateMeasurement_B.TransferFcn_f);

  /* Logic: '<S16>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2_c =
    (BallAndPlateMeasurement_B.RelationalOperator1_b &&
     BallAndPlateMeasurement_B.RelationalOperator_c &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S16>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2_c,
    BallAndPlateMeasurement_B.Inc2Pos_g,
    &BallAndPlateMeasurement_B.EnabledSubsystem1,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S16>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Pp_A' incorporates:
     *  Gain: '<S7>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_A = BallAndPlateMeasurement_P.mm2m_Gain *
      BallAndPlateMeasurement_B.AbsPosition_hs;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement' */

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S8>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S20>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S20>/S-Function1' incorporates:
         *  Constant: '<S8>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
               (Float64)(BallAndPlateMeasurement_P.Constant_Value_d * 1)
               );

            /* Set positions state for the selected incremental Encoder to VALID */
            DioCl2EncoderIn_setEncPosValidity
              (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
               DIO_ENC_POSITION_VALID
               );

            /* Writes settings for the incremental Encoder */
            DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S8>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S19>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S8>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos_i =
      BallAndPlateMeasurement_P.Inc2Pos_Gain_j *
      BallAndPlateMeasurement_B.SFunction1_o1_g;

    /* Sum: '<S8>/AbsPosition' incorporates:
     *  Constant: '<S8>/Pos_offset'
     *  Constant: '<S8>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition_h =
      (BallAndPlateMeasurement_B.Inc2Pos_i -
       BallAndPlateMeasurement_P.ZP_Value_a) -
      BallAndPlateMeasurement_P.Pos_offset_Value_f;

    /* Abs: '<S21>/Abs' */
    BallAndPlateMeasurement_B.Abs_l = fabs
      (BallAndPlateMeasurement_B.SFunction1_o2_p);

    /* Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem_h,
      &BallAndPlateMeasurement_DW.EnabledSubsystem_h,
      &BallAndPlateMeasurement_P.EnabledSubsystem_h);

    /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem' */

    /* RelationalOperator: '<S21>/Relational Operator1' incorporates:
     *  Constant: '<S21>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1_p =
      (BallAndPlateMeasurement_B.Abs_l <=
       BallAndPlateMeasurement_P.Const_Value_d);
  }

  /* TransferFcn: '<S21>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn_d = 0.0;
  BallAndPlateMeasurement_B.TransferFcn_d +=
    BallAndPlateMeasurement_P.TransferFcn_C_j *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_k;

  /* RelationalOperator: '<S21>/Relational Operator' incorporates:
   *  Constant: '<S21>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator_n =
    (BallAndPlateMeasurement_P.Const1_Value_k >=
     BallAndPlateMeasurement_B.TransferFcn_d);

  /* Logic: '<S21>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2_k =
    (BallAndPlateMeasurement_B.RelationalOperator1_p &&
     BallAndPlateMeasurement_B.RelationalOperator_n &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2_k,
    BallAndPlateMeasurement_B.Inc2Pos_i,
    &BallAndPlateMeasurement_B.EnabledSubsystem1_m,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_m);

  /* End of Outputs for SubSystem: '<S21>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Pp_B' incorporates:
     *  Gain: '<S8>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_B = BallAndPlateMeasurement_P.mm2m_Gain_f *
      BallAndPlateMeasurement_B.AbsPosition_h;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement1' */

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Triggered SubSystem: '<S9>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S25>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S25>/S-Function1' incorporates:
         *  Constant: '<S9>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
               (Float64)(BallAndPlateMeasurement_P.Constant_Value_c * 1)
               );

            /* Set positions state for the selected incremental Encoder to VALID */
            DioCl2EncoderIn_setEncPosValidity
              (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
               DIO_ENC_POSITION_VALID
               );

            /* Writes settings for the incremental Encoder */
            DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
          }
        }
      }
    }

    /* End of Outputs for SubSystem: '<S9>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S24>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S9>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos = BallAndPlateMeasurement_P.Inc2Pos_Gain_i
      * BallAndPlateMeasurement_B.SFunction1_o1;

    /* Sum: '<S9>/AbsPosition' incorporates:
     *  Constant: '<S9>/Pos_offset'
     *  Constant: '<S9>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition = (BallAndPlateMeasurement_B.Inc2Pos -
      BallAndPlateMeasurement_P.ZP_Value_d) -
      BallAndPlateMeasurement_P.Pos_offset_Value_b;

    /* Abs: '<S26>/Abs' */
    BallAndPlateMeasurement_B.Abs = fabs(BallAndPlateMeasurement_B.SFunction1_o2);

    /* Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem_c,
      &BallAndPlateMeasurement_DW.EnabledSubsystem_c,
      &BallAndPlateMeasurement_P.EnabledSubsystem_c);

    /* End of Outputs for SubSystem: '<S26>/Enabled Subsystem' */

    /* RelationalOperator: '<S26>/Relational Operator1' incorporates:
     *  Constant: '<S26>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1 =
      (BallAndPlateMeasurement_B.Abs <= BallAndPlateMeasurement_P.Const_Value_i);
  }

  /* TransferFcn: '<S26>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn = 0.0;
  BallAndPlateMeasurement_B.TransferFcn +=
    BallAndPlateMeasurement_P.TransferFcn_C_m *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE;

  /* RelationalOperator: '<S26>/Relational Operator' incorporates:
   *  Constant: '<S26>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator =
    (BallAndPlateMeasurement_P.Const1_Value_n >=
     BallAndPlateMeasurement_B.TransferFcn);

  /* Logic: '<S26>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2 =
    (BallAndPlateMeasurement_B.RelationalOperator1 &&
     BallAndPlateMeasurement_B.RelationalOperator &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2,
    BallAndPlateMeasurement_B.Inc2Pos,
    &BallAndPlateMeasurement_B.EnabledSubsystem1_j,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S26>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outport: '<Root>/Pp_C' incorporates:
     *  Gain: '<S9>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_C = BallAndPlateMeasurement_P.mm2m_Gain_a *
      BallAndPlateMeasurement_B.AbsPosition;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2] == 0) {
    /* Gain: '<Root>/Gain2' */
    BallAndPlateMeasurement_B.Gain2 = (uint16_T)((uint16_T)((uint32_T)
      BallAndPlateMeasurement_P.Gain2_Gain *
      BallAndPlateMeasurement_B.SFunction1_o1_n[1]) << 1);

    /* Sum: '<Root>/Add' */
    BallAndPlateMeasurement_B.Add = (uint16_T)((uint32_T)
      BallAndPlateMeasurement_B.SFunction1_o1_n[0] +
      BallAndPlateMeasurement_B.Gain2);

    /* Outport: '<Root>/Pb_X' */
    BallAndPlateMeasurement_Y.Pb_X = BallAndPlateMeasurement_B.Add;

    /* Gain: '<Root>/Gain1' */
    BallAndPlateMeasurement_B.Gain1 = (uint16_T)((uint16_T)((uint32_T)
      BallAndPlateMeasurement_P.Gain1_Gain *
      BallAndPlateMeasurement_B.SFunction1_o1_n[5]) << 1);

    /* Sum: '<Root>/Add1' */
    BallAndPlateMeasurement_B.Add1 = (uint16_T)((uint32_T)
      BallAndPlateMeasurement_B.SFunction1_o1_n[4] +
      BallAndPlateMeasurement_B.Gain1);

    /* Outport: '<Root>/Pb_Y' */
    BallAndPlateMeasurement_Y.Pb_Y = BallAndPlateMeasurement_B.Add1;

    /* Delay: '<Root>/Delay' */
    BallAndPlateMeasurement_B.Delay = BallAndPlateMeasurement_DW.Delay_DSTATE;

    /* Switch: '<Root>/Switch' */
    if (0.0 > BallAndPlateMeasurement_P.Switch_Threshold) {
      BallAndPlateMeasurement_B.Switch = 0.0;
    } else {
      BallAndPlateMeasurement_B.Switch = BallAndPlateMeasurement_B.Delay;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Sum: '<Root>/Sum1' */
    BallAndPlateMeasurement_B.Sum1 = (real_T)BallAndPlateMeasurement_B.Add +
      BallAndPlateMeasurement_B.Switch;

    /* Delay: '<Root>/Delay1' */
    BallAndPlateMeasurement_B.Delay1 = BallAndPlateMeasurement_DW.Delay1_DSTATE;

    /* Switch: '<Root>/Switch1' */
    if (0.0 > BallAndPlateMeasurement_P.Switch1_Threshold) {
      BallAndPlateMeasurement_B.Switch1 = 0.0;
    } else {
      BallAndPlateMeasurement_B.Switch1 = BallAndPlateMeasurement_B.Delay1;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* Sum: '<Root>/Sum' */
    BallAndPlateMeasurement_B.Sum = (real_T)BallAndPlateMeasurement_B.Add1 +
      BallAndPlateMeasurement_B.Switch1;
  }

  /* ModelReference: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  MPC_Controller(&BallAndPlateMeasurement_Y.Pp_A,
                 &BallAndPlateMeasurement_Y.Pp_B,
                 &BallAndPlateMeasurement_Y.Pp_C,
                 &BallAndPlateMeasurement_B.Sum1, &BallAndPlateMeasurement_B.Sum,
                 &BallAndPlateMeasurement_P.Constant_Value_n,
                 &BallAndPlateMeasurement_P.Constant2_Value,
                 &BallAndPlateMeasurement_P.Constant3_Value,
                 &BallAndPlateMeasurement_P.Constant4_Value,
                 &BallAndPlateMeasurement_P.Constant5_Value,
                 &BallAndPlateMeasurement_B.Controller_o1,
                 &BallAndPlateMeasurement_B.Controller_o2,
                 &BallAndPlateMeasurement_B.Controller_o3,
                 &BallAndPlateMeasurement_Y.Pp_Aref,
                 &BallAndPlateMeasurement_Y.Pp_Bref,
                 &BallAndPlateMeasurement_Y.Pp_Cref,
                 &BallAndPlateMeasurement_Y.Pb_Xref,
                 &BallAndPlateMeasurement_Y.Pb_Yref,
                 &(BallAndPlateMeasurement_X.Controller_CSTATE[0]));

  /* Outport: '<Root>/I_A' */
  BallAndPlateMeasurement_Y.I_A = BallAndPlateMeasurement_B.Controller_o1;

  /* Outport: '<Root>/I_B' */
  BallAndPlateMeasurement_Y.I_B = BallAndPlateMeasurement_B.Controller_o2;

  /* Outport: '<Root>/I_C' */
  BallAndPlateMeasurement_Y.I_C = BallAndPlateMeasurement_B.Controller_o3;

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier' */

  /* Saturate: '<S4>/Saturation' */
  u0 = BallAndPlateMeasurement_B.Controller_o1;
  u1 = BallAndPlateMeasurement_P.Saturation_LowerSat;
  u2 = BallAndPlateMeasurement_P.Saturation_UpperSat;
  if (u0 > u2) {
    BallAndPlateMeasurement_B.Saturation_e = u2;
  } else if (u0 < u1) {
    BallAndPlateMeasurement_B.Saturation_e = u1;
  } else {
    BallAndPlateMeasurement_B.Saturation_e = u0;
  }

  /* End of Saturate: '<S4>/Saturation' */

  /* Gain: '<S4>/Current2V' */
  BallAndPlateMeasurement_B.Current2V_p =
    BallAndPlateMeasurement_P.Current2V_Gain *
    BallAndPlateMeasurement_B.Saturation_e;

  /* Gain: '<S4>/DSPscale' */
  BallAndPlateMeasurement_B.DSPscale_o = BallAndPlateMeasurement_P.DSPscale_Gain
    * BallAndPlateMeasurement_B.Current2V_p;
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S11>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- BallAndPlateMeasurement/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 1 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) BallAndPlateMeasurement_B.DSPscale_o;

      /* write value of CL1 DAC for output channel 1 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
        DAC_CLASS1_CHANNEL_1, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_1);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Saturate: '<S5>/Saturation' */
  u0 = BallAndPlateMeasurement_B.Controller_o2;
  u1 = BallAndPlateMeasurement_P.Saturation_LowerSat_a;
  u2 = BallAndPlateMeasurement_P.Saturation_UpperSat_g;
  if (u0 > u2) {
    BallAndPlateMeasurement_B.Saturation_l = u2;
  } else if (u0 < u1) {
    BallAndPlateMeasurement_B.Saturation_l = u1;
  } else {
    BallAndPlateMeasurement_B.Saturation_l = u0;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Gain: '<S5>/Current2V' */
  BallAndPlateMeasurement_B.Current2V_a =
    BallAndPlateMeasurement_P.Current2V_Gain_l *
    BallAndPlateMeasurement_B.Saturation_l;

  /* Gain: '<S5>/DSPscale' */
  BallAndPlateMeasurement_B.DSPscale_a =
    BallAndPlateMeasurement_P.DSPscale_Gain_j *
    BallAndPlateMeasurement_B.Current2V_a;
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S12>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- BallAndPlateMeasurement/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 2 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) BallAndPlateMeasurement_B.DSPscale_a;

      /* write value of CL1 DAC for output channel 2 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_2,
        DAC_CLASS1_CHANNEL_2, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_2);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */

  /* Saturate: '<S6>/Saturation' */
  u0 = BallAndPlateMeasurement_B.Controller_o3;
  u1 = BallAndPlateMeasurement_P.Saturation_LowerSat_m;
  u2 = BallAndPlateMeasurement_P.Saturation_UpperSat_j;
  if (u0 > u2) {
    BallAndPlateMeasurement_B.Saturation = u2;
  } else if (u0 < u1) {
    BallAndPlateMeasurement_B.Saturation = u1;
  } else {
    BallAndPlateMeasurement_B.Saturation = u0;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Gain: '<S6>/Current2V' */
  BallAndPlateMeasurement_B.Current2V =
    BallAndPlateMeasurement_P.Current2V_Gain_j *
    BallAndPlateMeasurement_B.Saturation;

  /* Gain: '<S6>/DSPscale' */
  BallAndPlateMeasurement_B.DSPscale = BallAndPlateMeasurement_P.DSPscale_Gain_h
    * BallAndPlateMeasurement_B.Current2V;
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S13>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- BallAndPlateMeasurement/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 3 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) BallAndPlateMeasurement_B.DSPscale;

      /* write value of CL1 DAC for output channel 3 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_3,
        DAC_CLASS1_CHANNEL_3, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_3);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier2' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (rti_commonblock): '<S1>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- BallAndPlateMeasurement/ETHERNET_SETUP_BL1 --- */
    /* dSPACE I/O Board DSETHERNET #1 Unit:SETUP Group:SETUP */
    {
      /* returns the link state of the ethernet connection. Number of available connectors: uint32_T) */
      BallAndPlateMeasurement_B.SFunction1_o1_h[0] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 0);
      BallAndPlateMeasurement_B.SFunction1_o1_h[1] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 1);
      BallAndPlateMeasurement_B.SFunction1_o1_h[2] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 2);

      /* returns the current IP address of the ethernet interface */
      *((UInt32*) (&BallAndPlateMeasurement_B.SFunction1_o2_m[0])) =
        DsIoEth_getIpAddress();
    }

    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- BallAndPlateMeasurement/ETHERNET_UDP_SETUP_BL1: ==> Socket ID = (0) --- */
    {
      /* dSPACE I/O Board DSETHERNET #1 Unit:SETUPUDP Group:SETUPUDP */

      /* gets the port state (open or closed) of the specified UDP socket */
      if ((DsIoEth_getPortState(DSIOETH_CONNECTION_ID_0) == DSIOETH_PORT_CLOSED))
      {
        /* Opens a non-blocking UDP connection. A Socket must be created before, using    *
         * DsIoEth_create(). It also flushs the related rx socket receive queue to ensure *
         * not to accept any data from a previously adjusted communication                */
        DsIoEth_open(DSIOETH_CONNECTION_ID_0);
      }

      /* reads out the pending management event (internal event queue must *
       * be always read, to prevent event queue overrun)                   */
      DsIoEth_getMgmtEvent(DSIOETH_CONNECTION_ID_0);
    }
  }
}

/* Model update function */
void BallAndPlateMeasurement_update(void)
{
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update for Delay: '<Root>/Delay' */
    BallAndPlateMeasurement_DW.Delay_DSTATE = BallAndPlateMeasurement_B.Switch;

    /* Update for Delay: '<Root>/Delay1' */
    BallAndPlateMeasurement_DW.Delay1_DSTATE = BallAndPlateMeasurement_B.Switch1;
  }

  /* Update for ModelReference: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  MPC_Controller_Update();
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    rt_ertODEUpdateContinuousStates(&BallAndPlateMeasurement_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++BallAndPlateMeasurement_M->Timing.clockTick0)) {
    ++BallAndPlateMeasurement_M->Timing.clockTickH0;
  }

  BallAndPlateMeasurement_M->Timing.t[0] = rtsiGetSolverStopTime
    (&BallAndPlateMeasurement_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.001, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    BallAndPlateMeasurement_M->Timing.clockTick1++;
    if (!BallAndPlateMeasurement_M->Timing.clockTick1) {
      BallAndPlateMeasurement_M->Timing.clockTickH1++;
    }
  }

  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M) &&
      BallAndPlateMeasurement_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.04s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.04, which is the step size
     * of the task. Size of "clockTick2" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    BallAndPlateMeasurement_M->Timing.clockTick2++;
    if (!BallAndPlateMeasurement_M->Timing.clockTick2) {
      BallAndPlateMeasurement_M->Timing.clockTickH2++;
    }
  }

  rate_scheduler();
}

/* Derivatives for root system: '<Root>' */
void BallAndPlateMeasurement_derivatives(void)
{
  XDot_BallAndPlateMeasurement_T *_rtXdot;
  _rtXdot = ((XDot_BallAndPlateMeasurement_T *)
             BallAndPlateMeasurement_M->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Derivatives for TransferFcn: '<S16>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = 0.0;
  _rtXdot->TransferFcn_CSTATE_b += BallAndPlateMeasurement_P.TransferFcn_A *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b +=
    BallAndPlateMeasurement_B.EnabledSubsystem.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Derivatives for TransferFcn: '<S21>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_k = 0.0;
  _rtXdot->TransferFcn_CSTATE_k += BallAndPlateMeasurement_P.TransferFcn_A_b *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_k;
  _rtXdot->TransferFcn_CSTATE_k +=
    BallAndPlateMeasurement_B.EnabledSubsystem_h.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement1' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Derivatives for TransferFcn: '<S26>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += BallAndPlateMeasurement_P.TransferFcn_A_p *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE +=
    BallAndPlateMeasurement_B.EnabledSubsystem_c.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement2' */

  /* Derivatives for ModelReference: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  MPC_Controller_Deriv(&(BallAndPlateMeasurement_X.Controller_CSTATE[0]),
                       &(((XDot_BallAndPlateMeasurement_T *)
    BallAndPlateMeasurement_M->derivs)->Controller_CSTATE[0]));
}

/* Model initialize function */
void BallAndPlateMeasurement_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)BallAndPlateMeasurement_M, 0,
                sizeof(RT_MODEL_BallAndPlateMeasurem_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&BallAndPlateMeasurement_M->solverInfo,
                          &BallAndPlateMeasurement_M->Timing.simTimeStep);
    rtsiSetTPtr(&BallAndPlateMeasurement_M->solverInfo, &rtmGetTPtr
                (BallAndPlateMeasurement_M));
    rtsiSetStepSizePtr(&BallAndPlateMeasurement_M->solverInfo,
                       &BallAndPlateMeasurement_M->Timing.stepSize0);
    rtsiSetdXPtr(&BallAndPlateMeasurement_M->solverInfo,
                 &BallAndPlateMeasurement_M->derivs);
    rtsiSetContStatesPtr(&BallAndPlateMeasurement_M->solverInfo, (real_T **)
                         &BallAndPlateMeasurement_M->contStates);
    rtsiSetNumContStatesPtr(&BallAndPlateMeasurement_M->solverInfo,
      &BallAndPlateMeasurement_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&BallAndPlateMeasurement_M->solverInfo,
      &BallAndPlateMeasurement_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&BallAndPlateMeasurement_M->solverInfo,
      &BallAndPlateMeasurement_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&BallAndPlateMeasurement_M->solverInfo,
      &BallAndPlateMeasurement_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&BallAndPlateMeasurement_M->solverInfo,
                          (&rtmGetErrorStatus(BallAndPlateMeasurement_M)));
    rtsiSetRTModelPtr(&BallAndPlateMeasurement_M->solverInfo,
                      BallAndPlateMeasurement_M);
  }

  rtsiSetSimTimeStep(&BallAndPlateMeasurement_M->solverInfo, MAJOR_TIME_STEP);
  BallAndPlateMeasurement_M->intgData.f[0] = BallAndPlateMeasurement_M->odeF[0];
  BallAndPlateMeasurement_M->contStates = ((X_BallAndPlateMeasurement_T *)
    &BallAndPlateMeasurement_X);
  rtsiSetSolverData(&BallAndPlateMeasurement_M->solverInfo, (void *)
                    &BallAndPlateMeasurement_M->intgData);
  rtsiSetSolverName(&BallAndPlateMeasurement_M->solverInfo,"ode1");
  rtmSetTPtr(BallAndPlateMeasurement_M,
             &BallAndPlateMeasurement_M->Timing.tArray[0]);
  BallAndPlateMeasurement_M->Timing.stepSize0 = 0.001;

  /* block I/O */
  (void) memset(((void *) &BallAndPlateMeasurement_B), 0,
                sizeof(B_BallAndPlateMeasurement_T));

  /* states (continuous) */
  {
    (void) memset((void *)&BallAndPlateMeasurement_X, 0,
                  sizeof(X_BallAndPlateMeasurement_T));
  }

  /* states (dwork) */
  (void) memset((void *)&BallAndPlateMeasurement_DW, 0,
                sizeof(DW_BallAndPlateMeasurement_T));

  /* external outputs */
  (void) memset((void *)&BallAndPlateMeasurement_Y, 0,
                sizeof(ExtY_BallAndPlateMeasurement_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    BallAndPlateMeasurement_rti_init_trc_pointers();
  }

  {
    static uint32_T *clockTickPtrs[3];
    static uint32_T *clockTickHPtrs[3];
    static real_T *taskTimePtrs[3];
    static uint32_T *taskCounterPtrs;
    BallAndPlateMeasurem_TimingBrdg.nTasks = 3;
    clockTickPtrs[0] = &(BallAndPlateMeasurement_M->Timing.clockTick0);
    clockTickHPtrs[0] = &(BallAndPlateMeasurement_M->Timing.clockTickH0);
    clockTickPtrs[1] = &(BallAndPlateMeasurement_M->Timing.clockTick1);
    clockTickHPtrs[1] = &(BallAndPlateMeasurement_M->Timing.clockTickH1);
    clockTickPtrs[2] = &(BallAndPlateMeasurement_M->Timing.clockTick2);
    clockTickHPtrs[2] = &(BallAndPlateMeasurement_M->Timing.clockTickH2);
    BallAndPlateMeasurem_TimingBrdg.clockTick = clockTickPtrs;
    BallAndPlateMeasurem_TimingBrdg.clockTickH = clockTickHPtrs;
    taskCounterPtrs = &(BallAndPlateMeasurement_M->Timing.TaskCounters.TID[0]);
    BallAndPlateMeasurem_TimingBrdg.taskCounter = taskCounterPtrs;
    taskTimePtrs[0] = &(BallAndPlateMeasurement_M->Timing.t[0]);
    taskTimePtrs[1] = (NULL);
    taskTimePtrs[2] = (NULL);
    BallAndPlateMeasurem_TimingBrdg.taskTime = taskTimePtrs;
  }

  /* Model Initialize function for ModelReference Block: '<Root>/Controller' */
  MPC_Controller_initialize(rtmGetErrorStatusPointer(BallAndPlateMeasurement_M),
    rtmGetStopRequestedPtr(BallAndPlateMeasurement_M),
    &(BallAndPlateMeasurement_M->solverInfo), &BallAndPlateMeasurem_TimingBrdg,
    0, 1, 2);

  /* Start for Enabled SubSystem: '<S16>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S16>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S16>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem1);

  /* End of Start for SubSystem: '<S16>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement' */

  /* Start for Enabled SubSystem: '<S21>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem_h);

  /* End of Start for SubSystem: '<S21>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S21>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start
    (&BallAndPlateMeasurement_DW.EnabledSubsystem1_m);

  /* End of Start for SubSystem: '<S21>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement1' */

  /* Start for Enabled SubSystem: '<S26>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem_c);

  /* End of Start for SubSystem: '<S26>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S26>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start
    (&BallAndPlateMeasurement_DW.EnabledSubsystem1_j);

  /* End of Start for SubSystem: '<S26>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement2' */
  BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o =
    UNINITIALIZED_ZCSIG;
  BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n =
    UNINITIALIZED_ZCSIG;
  BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC =
    UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Delay: '<Root>/Delay' */
  BallAndPlateMeasurement_DW.Delay_DSTATE =
    BallAndPlateMeasurement_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<Root>/Delay1' */
  BallAndPlateMeasurement_DW.Delay1_DSTATE =
    BallAndPlateMeasurement_P.Delay1_InitialCondition;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement' */
  /* InitializeConditions for TransferFcn: '<S16>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE_b = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem,
    &BallAndPlateMeasurement_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S16>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1,
    &BallAndPlateMeasurement_P.EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S16>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* InitializeConditions for TransferFcn: '<S21>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE_k = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem_h,
    &BallAndPlateMeasurement_P.EnabledSubsystem_h);

  /* End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1_m,
    &BallAndPlateMeasurement_P.EnabledSubsystem1_m);

  /* End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* InitializeConditions for TransferFcn: '<S26>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem_c,
    &BallAndPlateMeasurement_P.EnabledSubsystem_c);

  /* End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1_j,
    &BallAndPlateMeasurement_P.EnabledSubsystem1_j);

  /* End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement2' */

  /* SystemInitialize for ModelReference: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  MPC_Controller_Init(&(BallAndPlateMeasurement_X.Controller_CSTATE[0]));

  /* Enable for ModelReference: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  MPC_Controller_Enable();
}

/* Model terminate function */
void BallAndPlateMeasurement_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Terminate for Triggered SubSystem: '<S7>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S15>/S-Function1' incorporates:
   *  Constant: '<S7>/Constant'
   */

  /* --- BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<S7>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S14>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Terminate for Triggered SubSystem: '<S8>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S20>/S-Function1' incorporates:
   *  Constant: '<S8>/Constant'
   */

  /* --- BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<S8>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S19>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement1' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Terminate for Triggered SubSystem: '<S9>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S25>/S-Function1' incorporates:
   *  Constant: '<S9>/Constant'
   */

  /* --- BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<S9>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S24>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement2' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier' */
  /* Terminate for S-Function (rti_commonblock): '<S11>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_1);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */
  /* Terminate for S-Function (rti_commonblock): '<S12>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 2 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_2, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_2);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S13>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 3 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_3, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_3);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */
  {
    /* --- BallAndPlateMeasurement/ETHERNET_UDP_SETUP_BL1: ==> Socket ID = (0) --- */
    /* dSPACE I/O Board DSETHERNET #1 Unit:SETUPUDP Group:SETUPUDP */

    /* close a socket connection
     * After closing, the corresponding socket resource is still occupied.   *
     * If a connection has been closed and should be re-used for a different *
     * connection, or if a connection should be re-established it must be    *
     * re-opened using DsIoEth_open() again.                                 */
    DsIoEth_close(DSIOETH_CONNECTION_ID_0);
  }
}
