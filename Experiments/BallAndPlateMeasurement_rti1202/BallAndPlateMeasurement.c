/*
 * BallAndPlateMeasurement.c
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

#include "BallAndPlateMeasurement_trc_ptr.h"
#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"

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
  int_T nXc = 3;
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
 *    '<S20>/Enabled Subsystem'
 *    '<S25>/Enabled Subsystem'
 *    '<S30>/Enabled Subsystem'
 */
void BallAndPl_EnabledSubsystem_Init(B_EnabledSubsystem_BallAndPla_T *localB,
  P_EnabledSubsystem_BallAndPla_T *localP)
{
  /* SystemInitialize for Outport: '<S21>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S20>/Enabled Subsystem'
 *    '<S25>/Enabled Subsystem'
 *    '<S30>/Enabled Subsystem'
 */
void BallAn_EnabledSubsystem_Disable(B_EnabledSubsystem_BallAndPla_T *localB,
  DW_EnabledSubsystem_BallAndPl_T *localDW, P_EnabledSubsystem_BallAndPla_T
  *localP)
{
  /* Disable for Outport: '<S21>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S20>/Enabled Subsystem'
 *    '<S25>/Enabled Subsystem'
 *    '<S30>/Enabled Subsystem'
 */
void BallAndP_EnabledSubsystem_Start(DW_EnabledSubsystem_BallAndPl_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S20>/Enabled Subsystem'
 *    '<S25>/Enabled Subsystem'
 *    '<S30>/Enabled Subsystem'
 */
void BallAndPlateMe_EnabledSubsystem(RT_MODEL_BallAndPlateMeasurem_T * const
  BallAndPlateMeasurement_M, real_T rtu_Enable, B_EnabledSubsystem_BallAndPla_T *
  localB, DW_EnabledSubsystem_BallAndPl_T *localDW,
  P_EnabledSubsystem_BallAndPla_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S21>/Enable'
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
    /* SignalConversion generated from: '<S21>/Out1' incorporates:
     *  Constant: '<S21>/Constant'
     */
    localB->OutportBufferForOut1 = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S20>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S20>/Enabled Subsystem1'
 *    '<S25>/Enabled Subsystem1'
 *    '<S30>/Enabled Subsystem1'
 */
void BallAndP_EnabledSubsystem1_Init(B_EnabledSubsystem1_BallAndPl_T *localB,
  P_EnabledSubsystem1_BallAndPl_T *localP)
{
  /* SystemInitialize for Outport: '<S22>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S20>/Enabled Subsystem1'
 *    '<S25>/Enabled Subsystem1'
 *    '<S30>/Enabled Subsystem1'
 */
void BallA_EnabledSubsystem1_Disable(DW_EnabledSubsystem1_BallAndP_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S20>/Enabled Subsystem1'
 *    '<S25>/Enabled Subsystem1'
 *    '<S30>/Enabled Subsystem1'
 */
void BallAnd_EnabledSubsystem1_Start(DW_EnabledSubsystem1_BallAndP_T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S20>/Enabled Subsystem1'
 *    '<S25>/Enabled Subsystem1'
 *    '<S30>/Enabled Subsystem1'
 */
void BallAndPlateM_EnabledSubsystem1(RT_MODEL_BallAndPlateMeasurem_T * const
  BallAndPlateMeasurement_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem1_BallAndPl_T *localB, DW_EnabledSubsystem1_BallAndP_T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S22>/Enable'
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

  if (localDW->EnabledSubsystem1_MODE && rtmIsMajorTimeStep
      (BallAndPlateMeasurement_M)) {
    /* Inport: '<S22>/In1' */
    localB->In1 = rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S20>/Enabled Subsystem1' */
}

/* Model output function */
void BallAndPlateMeasurement_output(void)
{
  int8_T rtAction;
  ZCEventType zcEvent;
  real_T u;
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

  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    BallAndPlateMeasurement_B.DataTypeConversion =
      (BallAndPlateMeasurement_P.Constant1_Value_a != 0.0);

    /* S-Function (rti_commonblock): '<S4>/S-Function1' incorporates:
     *  Outport: '<Root>/Frames '
     *  Outport: '<Root>/Status '
     */
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
          BallAndPlateMeasurement_Y.Frames = (real_T)
            (BallAndPlateMeasurement_Y.Frames + 1);

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
      BallAndPlateMeasurement_Y.Status = (uint32_T) tmpStatus;

      /* assign remote IP (s_addr: uint32) to the related outport as (uint8.uint8.uint8.uint8) */
      *((UInt32*) &BallAndPlateMeasurement_B.SFunction1_o5[0]) =
        remoteAddr.sin_addr.s_addr;

      /* assign remote port to the related outport */
      BallAndPlateMeasurement_B.SFunction1_o6 = DsIoEth_ntohs
        (remoteAddr.sin_port);
    }
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outputs for Triggered SubSystem: '<S10>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S19>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S19>/S-Function1' incorporates:
         *  Constant: '<S10>/Constant'
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

    /* End of Outputs for SubSystem: '<S10>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S18>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S10>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos_g = BallAndPlateMeasurement_P.Inc2Pos_Gain
      * BallAndPlateMeasurement_B.SFunction1_o1_o;

    /* Sum: '<S10>/AbsPosition' incorporates:
     *  Constant: '<S10>/Pos_offset'
     *  Constant: '<S10>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition_hs =
      (BallAndPlateMeasurement_B.Inc2Pos_g - BallAndPlateMeasurement_P.ZP_Value)
      - BallAndPlateMeasurement_P.Pos_offset_Value;

    /* Abs: '<S20>/Abs' */
    BallAndPlateMeasurement_B.Abs_c = fabs
      (BallAndPlateMeasurement_B.SFunction1_o2_n);

    /* Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem,
      &BallAndPlateMeasurement_DW.EnabledSubsystem,
      &BallAndPlateMeasurement_P.EnabledSubsystem);

    /* End of Outputs for SubSystem: '<S20>/Enabled Subsystem' */

    /* RelationalOperator: '<S20>/Relational Operator1' incorporates:
     *  Constant: '<S20>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1_b =
      (BallAndPlateMeasurement_B.Abs_c <= BallAndPlateMeasurement_P.Const_Value);
  }

  /* TransferFcn: '<S20>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn_f = 0.0;
  BallAndPlateMeasurement_B.TransferFcn_f +=
    BallAndPlateMeasurement_P.TransferFcn_C *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_b;

  /* RelationalOperator: '<S20>/Relational Operator' incorporates:
   *  Constant: '<S20>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator_c =
    (BallAndPlateMeasurement_P.Const1_Value >=
     BallAndPlateMeasurement_B.TransferFcn_f);

  /* Logic: '<S20>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2_c =
    (BallAndPlateMeasurement_B.RelationalOperator1_b &&
     BallAndPlateMeasurement_B.RelationalOperator_c &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2_c,
    BallAndPlateMeasurement_B.Inc2Pos_g,
    &BallAndPlateMeasurement_B.EnabledSubsystem1,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S20>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outport: '<Root>/Pp_A' incorporates:
     *  Gain: '<S10>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_A = BallAndPlateMeasurement_P.mm2m_Gain *
      BallAndPlateMeasurement_B.AbsPosition_hs;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement' */

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outputs for Triggered SubSystem: '<S11>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S24>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S24>/S-Function1' incorporates:
         *  Constant: '<S11>/Constant'
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

    /* End of Outputs for SubSystem: '<S11>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S23>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S11>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos_i =
      BallAndPlateMeasurement_P.Inc2Pos_Gain_j *
      BallAndPlateMeasurement_B.SFunction1_o1_g;

    /* Sum: '<S11>/AbsPosition' incorporates:
     *  Constant: '<S11>/Pos_offset'
     *  Constant: '<S11>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition_h =
      (BallAndPlateMeasurement_B.Inc2Pos_i -
       BallAndPlateMeasurement_P.ZP_Value_a) -
      BallAndPlateMeasurement_P.Pos_offset_Value_f;

    /* Abs: '<S25>/Abs' */
    BallAndPlateMeasurement_B.Abs_l = fabs
      (BallAndPlateMeasurement_B.SFunction1_o2_p);

    /* Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem_h,
      &BallAndPlateMeasurement_DW.EnabledSubsystem_h,
      &BallAndPlateMeasurement_P.EnabledSubsystem_h);

    /* End of Outputs for SubSystem: '<S25>/Enabled Subsystem' */

    /* RelationalOperator: '<S25>/Relational Operator1' incorporates:
     *  Constant: '<S25>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1_p =
      (BallAndPlateMeasurement_B.Abs_l <=
       BallAndPlateMeasurement_P.Const_Value_d);
  }

  /* TransferFcn: '<S25>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn_d = 0.0;
  BallAndPlateMeasurement_B.TransferFcn_d +=
    BallAndPlateMeasurement_P.TransferFcn_C_j *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_k;

  /* RelationalOperator: '<S25>/Relational Operator' incorporates:
   *  Constant: '<S25>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator_n =
    (BallAndPlateMeasurement_P.Const1_Value_k >=
     BallAndPlateMeasurement_B.TransferFcn_d);

  /* Logic: '<S25>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2_k =
    (BallAndPlateMeasurement_B.RelationalOperator1_p &&
     BallAndPlateMeasurement_B.RelationalOperator_n &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S25>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2_k,
    BallAndPlateMeasurement_B.Inc2Pos_i,
    &BallAndPlateMeasurement_B.EnabledSubsystem1_m,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_m);

  /* End of Outputs for SubSystem: '<S25>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outport: '<Root>/Pp_B' incorporates:
     *  Gain: '<S11>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_B = BallAndPlateMeasurement_P.mm2m_Gain_f *
      BallAndPlateMeasurement_B.AbsPosition_h;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement1' */

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outputs for Triggered SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S29>/Trigger'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      /* Constant: '<Root>/Init' */
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &BallAndPlateMeasurement_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC,
                         (BallAndPlateMeasurement_P.Init_Value));
      if (zcEvent != NO_ZCEVENT) {
        /* S-Function (rti_commonblock): '<S29>/S-Function1' incorporates:
         *  Constant: '<S12>/Constant'
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

    /* End of Outputs for SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S28>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S12>/Inc2Pos' */
    BallAndPlateMeasurement_B.Inc2Pos = BallAndPlateMeasurement_P.Inc2Pos_Gain_i
      * BallAndPlateMeasurement_B.SFunction1_o1;

    /* Sum: '<S12>/AbsPosition' incorporates:
     *  Constant: '<S12>/Pos_offset'
     *  Constant: '<S12>/ZP'
     */
    BallAndPlateMeasurement_B.AbsPosition = (BallAndPlateMeasurement_B.Inc2Pos -
      BallAndPlateMeasurement_P.ZP_Value_d) -
      BallAndPlateMeasurement_P.Pos_offset_Value_b;

    /* Abs: '<S30>/Abs' */
    BallAndPlateMeasurement_B.Abs = fabs(BallAndPlateMeasurement_B.SFunction1_o2);

    /* Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' */
    /* Constant: '<Root>/Init' */
    BallAndPlateMe_EnabledSubsystem(BallAndPlateMeasurement_M,
      BallAndPlateMeasurement_P.Init_Value,
      &BallAndPlateMeasurement_B.EnabledSubsystem_c,
      &BallAndPlateMeasurement_DW.EnabledSubsystem_c,
      &BallAndPlateMeasurement_P.EnabledSubsystem_c);

    /* End of Outputs for SubSystem: '<S30>/Enabled Subsystem' */

    /* RelationalOperator: '<S30>/Relational Operator1' incorporates:
     *  Constant: '<S30>/Const'
     */
    BallAndPlateMeasurement_B.RelationalOperator1 =
      (BallAndPlateMeasurement_B.Abs <= BallAndPlateMeasurement_P.Const_Value_i);
  }

  /* TransferFcn: '<S30>/Transfer Fcn' */
  BallAndPlateMeasurement_B.TransferFcn = 0.0;
  BallAndPlateMeasurement_B.TransferFcn +=
    BallAndPlateMeasurement_P.TransferFcn_C_m *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE;

  /* RelationalOperator: '<S30>/Relational Operator' incorporates:
   *  Constant: '<S30>/Const1'
   */
  BallAndPlateMeasurement_B.RelationalOperator =
    (BallAndPlateMeasurement_P.Const1_Value_n >=
     BallAndPlateMeasurement_B.TransferFcn);

  /* Logic: '<S30>/Logical Operator2' incorporates:
   *  Constant: '<Root>/Init'
   */
  BallAndPlateMeasurement_B.LogicalOperator2 =
    (BallAndPlateMeasurement_B.RelationalOperator1 &&
     BallAndPlateMeasurement_B.RelationalOperator &&
     (BallAndPlateMeasurement_P.Init_Value != 0.0));

  /* Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem1' */
  BallAndPlateM_EnabledSubsystem1(BallAndPlateMeasurement_M,
    BallAndPlateMeasurement_B.LogicalOperator2,
    BallAndPlateMeasurement_B.Inc2Pos,
    &BallAndPlateMeasurement_B.EnabledSubsystem1_j,
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S30>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Outport: '<Root>/Pp_C' incorporates:
     *  Gain: '<S12>/mm2m'
     */
    BallAndPlateMeasurement_Y.Pp_C = BallAndPlateMeasurement_P.mm2m_Gain_a *
      BallAndPlateMeasurement_B.AbsPosition;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Gain: '<Root>/Gain2' */
    BallAndPlateMeasurement_B.Gain2 = (uint16_T)((uint16_T)((uint32_T)
      BallAndPlateMeasurement_P.Gain2_Gain *
      BallAndPlateMeasurement_B.SFunction1_o1_n[1]) << 1);

    /* Outport: '<Root>/Pb_X' incorporates:
     *  Sum: '<Root>/Add'
     */
    BallAndPlateMeasurement_Y.Pb_X = (uint16_T)((uint32_T)
      BallAndPlateMeasurement_B.SFunction1_o1_n[0] +
      BallAndPlateMeasurement_B.Gain2);

    /* Gain: '<Root>/Gain1' */
    BallAndPlateMeasurement_B.Gain1 = (uint16_T)((uint16_T)((uint32_T)
      BallAndPlateMeasurement_P.Gain1_Gain *
      BallAndPlateMeasurement_B.SFunction1_o1_n[5]) << 1);

    /* Outport: '<Root>/Pb_Y' incorporates:
     *  Sum: '<Root>/Add1'
     */
    BallAndPlateMeasurement_Y.Pb_Y = (uint16_T)((uint32_T)
      BallAndPlateMeasurement_B.SFunction1_o1_n[4] +
      BallAndPlateMeasurement_B.Gain1);

    /* SwitchCase: '<Root>/Switch Case' incorporates:
     *  Constant: '<Root>/State'
     *  Constant: '<S2>/Constant'
     *  Constant: '<S2>/Constant1'
     *  Constant: '<S2>/Constant2'
     */
    if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
      u = BallAndPlateMeasurement_P.State_Value;
      if (u < 0.0) {
        u = ceil(u);
      } else {
        u = floor(u);
      }

      if (rtIsNaN(u) || rtIsInf(u)) {
        u = 0.0;
      } else {
        u = fmod(u, 4.294967296E+9);
      }

      switch (u < 0.0 ? -(int32_T)(uint32_T)-u : (int32_T)(uint32_T)u) {
       case 3:
        rtAction = 0;
        break;

       case 2:
        rtAction = 1;
        break;

       case 1:
        rtAction = 2;
        break;

       default:
        rtAction = 3;
        break;
      }

      BallAndPlateMeasurement_DW.SwitchCase_ActiveSubsystem = rtAction;
    } else {
      rtAction = BallAndPlateMeasurement_DW.SwitchCase_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/Run' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* ModelReference: '<S14>/Controller' incorporates:
       *  Constant: '<S14>/Constant'
       *  Constant: '<S14>/Constant1'
       *  Constant: '<S14>/Constant2'
       *  Constant: '<S14>/Constant3'
       *  Constant: '<S14>/Constant4'
       *  Outport: '<Root>/Pb_Xref'
       *  Outport: '<Root>/Pb_Yref'
       *  Outport: '<Root>/Pp_A'
       *  Outport: '<Root>/Pp_Aref'
       *  Outport: '<Root>/Pp_B'
       *  Outport: '<Root>/Pp_Bref'
       *  Outport: '<Root>/Pp_C'
       *  Outport: '<Root>/Pp_Cref'
       */
      Test_measurement_script(&BallAndPlateMeasurement_P.Constant_Value_n,
        &BallAndPlateMeasurement_P.Constant1_Value,
        &BallAndPlateMeasurement_P.Constant2_Value,
        &BallAndPlateMeasurement_P.Constant3_Value,
        &BallAndPlateMeasurement_P.Constant4_Value,
        &BallAndPlateMeasurement_B.Controller_o1,
        &BallAndPlateMeasurement_B.Controller_o2,
        &BallAndPlateMeasurement_B.Controller_o3,
        &BallAndPlateMeasurement_Y.Pp_Aref, &BallAndPlateMeasurement_Y.Pp_Bref,
        &BallAndPlateMeasurement_Y.Pp_Cref, &BallAndPlateMeasurement_Y.Pb_Xref,
        &BallAndPlateMeasurement_Y.Pb_Yref);

      /* Outport: '<Root>/I_A' incorporates:
       *  SignalConversion generated from: '<S14>/I_A'
       */
      BallAndPlateMeasurement_Y.I_A = BallAndPlateMeasurement_B.Controller_o1;

      /* Outport: '<Root>/I_B' incorporates:
       *  SignalConversion generated from: '<S14>/I_B'
       */
      BallAndPlateMeasurement_Y.I_B = BallAndPlateMeasurement_B.Controller_o2;

      /* Outport: '<Root>/I_C' incorporates:
       *  SignalConversion generated from: '<S14>/I_C'
       */
      BallAndPlateMeasurement_Y.I_C = BallAndPlateMeasurement_B.Controller_o3;

      /* End of Outputs for SubSystem: '<Root>/Run' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<Root>/CalibrateBallPosition' incorporates:
       *  ActionPort: '<S1>/Action Port'
       */
      /* SignalConversion generated from: '<S1>/I_A' */
      BallAndPlateMeasurement_B.OutportBufferForI_A_p2 = 0.0;

      /* SignalConversion generated from: '<S1>/I_B' */
      BallAndPlateMeasurement_B.OutportBufferForI_B_an = 0.0;

      /* SignalConversion generated from: '<S1>/I_C' */
      BallAndPlateMeasurement_B.OutportBufferForI_C_f3 = 0.0;

      /* SignalConversion generated from: '<S1>/Pb_Xoffset' */
      BallAndPlateMeasurement_B.OutportBufferForPb_Xoffset = 0.0;

      /* SignalConversion generated from: '<S1>/Pb_Yoffset' */
      BallAndPlateMeasurement_B.OutportBufferForPb_Yoffset = 0.0;

      /* SignalConversion generated from: '<S1>/Pb_SetOffset' */
      BallAndPlateMeasurement_B.OutportBufferForPb_SetOffset = 0.0;

      /* End of Outputs for SubSystem: '<Root>/CalibrateBallPosition' */
      break;

     case 2:
      /* Outputs for IfAction SubSystem: '<Root>/EnableMotors' incorporates:
       *  ActionPort: '<S6>/Action Port'
       */
      /* SignalConversion generated from: '<S6>/I_A' */
      BallAndPlateMeasurement_B.OutportBufferForI_A_p = 0.0;

      /* SignalConversion generated from: '<S6>/I_B' */
      BallAndPlateMeasurement_B.OutportBufferForI_B_a = 0.0;

      /* SignalConversion generated from: '<S6>/I_C' */
      BallAndPlateMeasurement_B.OutportBufferForI_C_f = 0.0;

      /* End of Outputs for SubSystem: '<Root>/EnableMotors' */
      break;

     case 3:
      /* Outputs for IfAction SubSystem: '<Root>/Disabled' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      BallAndPlateMeasurement_B.Constant =
        BallAndPlateMeasurement_P.Constant_Value_l;

      /* SignalConversion generated from: '<S2>/I_A' incorporates:
       *  Constant: '<S2>/Constant'
       */
      BallAndPlateMeasurement_B.OutportBufferForI_A =
        BallAndPlateMeasurement_B.Constant;
      BallAndPlateMeasurement_B.Constant1 =
        BallAndPlateMeasurement_P.Constant1_Value_d;

      /* SignalConversion generated from: '<S2>/I_B' incorporates:
       *  Constant: '<S2>/Constant1'
       */
      BallAndPlateMeasurement_B.OutportBufferForI_B =
        BallAndPlateMeasurement_B.Constant1;
      BallAndPlateMeasurement_B.Constant2 =
        BallAndPlateMeasurement_P.Constant2_Value_f;

      /* SignalConversion generated from: '<S2>/I_C' incorporates:
       *  Constant: '<S2>/Constant2'
       */
      BallAndPlateMeasurement_B.OutportBufferForI_C =
        BallAndPlateMeasurement_B.Constant2;

      /* End of Outputs for SubSystem: '<Root>/Disabled' */
      break;
    }

    /* End of SwitchCase: '<Root>/Switch Case' */

    /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier' */

    /* Saturate: '<S7>/Saturation' incorporates:
     *  Outport: '<Root>/I_A'
     */
    u = BallAndPlateMeasurement_Y.I_A;
    u1 = BallAndPlateMeasurement_P.Saturation_LowerSat;
    u2 = BallAndPlateMeasurement_P.Saturation_UpperSat;
    if (u > u2) {
      BallAndPlateMeasurement_B.Saturation_e = u2;
    } else if (u < u1) {
      BallAndPlateMeasurement_B.Saturation_e = u1;
    } else {
      BallAndPlateMeasurement_B.Saturation_e = u;
    }

    /* End of Saturate: '<S7>/Saturation' */

    /* Gain: '<S7>/Current2V' */
    BallAndPlateMeasurement_B.Current2V_p =
      BallAndPlateMeasurement_P.Current2V_Gain *
      BallAndPlateMeasurement_B.Saturation_e;

    /* Gain: '<S7>/DSPscale' */
    BallAndPlateMeasurement_B.DSPscale_o =
      BallAndPlateMeasurement_P.DSPscale_Gain *
      BallAndPlateMeasurement_B.Current2V_p;

    /* S-Function (rti_commonblock): '<S15>/S-Function1' */
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

    /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier' */

    /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */

    /* Saturate: '<S8>/Saturation' incorporates:
     *  Outport: '<Root>/I_B'
     */
    u = BallAndPlateMeasurement_Y.I_B;
    u1 = BallAndPlateMeasurement_P.Saturation_LowerSat_a;
    u2 = BallAndPlateMeasurement_P.Saturation_UpperSat_g;
    if (u > u2) {
      BallAndPlateMeasurement_B.Saturation_l = u2;
    } else if (u < u1) {
      BallAndPlateMeasurement_B.Saturation_l = u1;
    } else {
      BallAndPlateMeasurement_B.Saturation_l = u;
    }

    /* End of Saturate: '<S8>/Saturation' */

    /* Gain: '<S8>/Current2V' */
    BallAndPlateMeasurement_B.Current2V_a =
      BallAndPlateMeasurement_P.Current2V_Gain_l *
      BallAndPlateMeasurement_B.Saturation_l;

    /* Gain: '<S8>/DSPscale' */
    BallAndPlateMeasurement_B.DSPscale_a =
      BallAndPlateMeasurement_P.DSPscale_Gain_j *
      BallAndPlateMeasurement_B.Current2V_a;

    /* S-Function (rti_commonblock): '<S16>/S-Function1' */
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

    /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier1' */

    /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */

    /* Saturate: '<S9>/Saturation' incorporates:
     *  Outport: '<Root>/I_C'
     */
    u = BallAndPlateMeasurement_Y.I_C;
    u1 = BallAndPlateMeasurement_P.Saturation_LowerSat_m;
    u2 = BallAndPlateMeasurement_P.Saturation_UpperSat_j;
    if (u > u2) {
      BallAndPlateMeasurement_B.Saturation = u2;
    } else if (u < u1) {
      BallAndPlateMeasurement_B.Saturation = u1;
    } else {
      BallAndPlateMeasurement_B.Saturation = u;
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Gain: '<S9>/Current2V' */
    BallAndPlateMeasurement_B.Current2V =
      BallAndPlateMeasurement_P.Current2V_Gain_j *
      BallAndPlateMeasurement_B.Saturation;

    /* Gain: '<S9>/DSPscale' */
    BallAndPlateMeasurement_B.DSPscale =
      BallAndPlateMeasurement_P.DSPscale_Gain_h *
      BallAndPlateMeasurement_B.Current2V;

    /* S-Function (rti_commonblock): '<S17>/S-Function1' */
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

    /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier2' */

    /* Delay: '<Root>/Delay' */
    BallAndPlateMeasurement_B.Delay = BallAndPlateMeasurement_DW.Delay_DSTATE;

    /* Delay: '<Root>/Delay1' */
    BallAndPlateMeasurement_B.Delay1 = BallAndPlateMeasurement_DW.Delay1_DSTATE;

    /* Switch: '<Root>/Switch1' */
    if (BallAndPlateMeasurement_B.OutportBufferForPb_SetOffset >
        BallAndPlateMeasurement_P.Switch1_Threshold) {
      BallAndPlateMeasurement_B.Switch1 =
        BallAndPlateMeasurement_B.OutportBufferForPb_Yoffset;
    } else {
      BallAndPlateMeasurement_B.Switch1 = BallAndPlateMeasurement_B.Delay1;
    }

    /* End of Switch: '<Root>/Switch1' */

    /* Sum: '<Root>/Sum' incorporates:
     *  Outport: '<Root>/Pb_Y'
     */
    BallAndPlateMeasurement_B.Sum = (real_T)BallAndPlateMeasurement_Y.Pb_Y +
      BallAndPlateMeasurement_B.Switch1;

    /* Switch: '<Root>/Switch' */
    if (BallAndPlateMeasurement_B.OutportBufferForPb_SetOffset >
        BallAndPlateMeasurement_P.Switch_Threshold) {
      BallAndPlateMeasurement_B.Switch =
        BallAndPlateMeasurement_B.OutportBufferForPb_Xoffset;
    } else {
      BallAndPlateMeasurement_B.Switch = BallAndPlateMeasurement_B.Delay;
    }

    /* End of Switch: '<Root>/Switch' */

    /* Sum: '<Root>/Sum1' incorporates:
     *  Outport: '<Root>/Pb_X'
     */
    BallAndPlateMeasurement_B.Sum1 = (real_T)BallAndPlateMeasurement_Y.Pb_X +
      BallAndPlateMeasurement_B.Switch;

    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
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

    /* S-Function (rti_commonblock): '<S5>/S-Function1' */
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
  if (rtmIsMajorTimeStep(BallAndPlateMeasurement_M)) {
    /* Update for Delay: '<Root>/Delay' */
    BallAndPlateMeasurement_DW.Delay_DSTATE = BallAndPlateMeasurement_B.Switch;

    /* Update for Delay: '<Root>/Delay1' */
    BallAndPlateMeasurement_DW.Delay1_DSTATE = BallAndPlateMeasurement_B.Switch1;
  }

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
}

/* Derivatives for root system: '<Root>' */
void BallAndPlateMeasurement_derivatives(void)
{
  XDot_BallAndPlateMeasurement_T *_rtXdot;
  _rtXdot = ((XDot_BallAndPlateMeasurement_T *)
             BallAndPlateMeasurement_M->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Derivatives for TransferFcn: '<S20>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = 0.0;
  _rtXdot->TransferFcn_CSTATE_b += BallAndPlateMeasurement_P.TransferFcn_A *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b +=
    BallAndPlateMeasurement_B.EnabledSubsystem.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Derivatives for TransferFcn: '<S25>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_k = 0.0;
  _rtXdot->TransferFcn_CSTATE_k += BallAndPlateMeasurement_P.TransferFcn_A_b *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE_k;
  _rtXdot->TransferFcn_CSTATE_k +=
    BallAndPlateMeasurement_B.EnabledSubsystem_h.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement1' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Derivatives for TransferFcn: '<S30>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += BallAndPlateMeasurement_P.TransferFcn_A_p *
    BallAndPlateMeasurement_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE +=
    BallAndPlateMeasurement_B.EnabledSubsystem_c.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement2' */
}

/* Model initialize function */
void BallAndPlateMeasurement_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

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

  /* Model Initialize function for ModelReference Block: '<S14>/Controller' */
  Test_measurement_scr_initialize(rtmGetErrorStatusPointer
    (BallAndPlateMeasurement_M),
    &(BallAndPlateMeasurement_DW.Controller_InstanceData.rtm));

  /* Start for Enabled SubSystem: '<S20>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S20>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S20>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem1);

  /* End of Start for SubSystem: '<S20>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement' */

  /* Start for Enabled SubSystem: '<S25>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem_h);

  /* End of Start for SubSystem: '<S25>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S25>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start
    (&BallAndPlateMeasurement_DW.EnabledSubsystem1_m);

  /* End of Start for SubSystem: '<S25>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement1' */

  /* Start for Enabled SubSystem: '<S30>/Enabled Subsystem' */
  BallAndP_EnabledSubsystem_Start(&BallAndPlateMeasurement_DW.EnabledSubsystem_c);

  /* End of Start for SubSystem: '<S30>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S30>/Enabled Subsystem1' */
  BallAnd_EnabledSubsystem1_Start
    (&BallAndPlateMeasurement_DW.EnabledSubsystem1_j);

  /* End of Start for SubSystem: '<S30>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement2' */

  /* Start for SwitchCase: '<Root>/Switch Case' */
  BallAndPlateMeasurement_DW.SwitchCase_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<Root>/Disabled' */
  /* Start for Constant: '<S2>/Constant' */
  BallAndPlateMeasurement_B.Constant =
    BallAndPlateMeasurement_P.Constant_Value_l;

  /* Start for Constant: '<S2>/Constant1' */
  BallAndPlateMeasurement_B.Constant1 =
    BallAndPlateMeasurement_P.Constant1_Value_d;

  /* Start for Constant: '<S2>/Constant2' */
  BallAndPlateMeasurement_B.Constant2 =
    BallAndPlateMeasurement_P.Constant2_Value_f;

  /* End of Start for SubSystem: '<Root>/Disabled' */
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
  /* InitializeConditions for TransferFcn: '<S20>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE_b = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem,
    &BallAndPlateMeasurement_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1,
    &BallAndPlateMeasurement_P.EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE_k = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem_h,
    &BallAndPlateMeasurement_P.EnabledSubsystem_h);

  /* End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1_m,
    &BallAndPlateMeasurement_P.EnabledSubsystem1_m);

  /* End of SystemInitialize for SubSystem: '<S25>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* InitializeConditions for TransferFcn: '<S30>/Transfer Fcn' */
  BallAndPlateMeasurement_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem' */
  BallAndPl_EnabledSubsystem_Init(&BallAndPlateMeasurement_B.EnabledSubsystem_c,
    &BallAndPlateMeasurement_P.EnabledSubsystem_c);

  /* End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem1' */
  BallAndP_EnabledSubsystem1_Init(&BallAndPlateMeasurement_B.EnabledSubsystem1_j,
    &BallAndPlateMeasurement_P.EnabledSubsystem1_j);

  /* End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement2' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Run' */
  /* SystemInitialize for ModelReference: '<S14>/Controller' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Constant1'
   *  Constant: '<S14>/Constant2'
   *  Constant: '<S14>/Constant3'
   *  Constant: '<S14>/Constant4'
   *  Outport: '<Root>/Pb_Xref'
   *  Outport: '<Root>/Pb_Yref'
   *  Outport: '<Root>/Pp_A'
   *  Outport: '<Root>/Pp_Aref'
   *  Outport: '<Root>/Pp_B'
   *  Outport: '<Root>/Pp_Bref'
   *  Outport: '<Root>/Pp_C'
   *  Outport: '<Root>/Pp_Cref'
   */
  Test_measurement_script_Init(&BallAndPlateMeasurement_B.Controller_o1,
    &BallAndPlateMeasurement_B.Controller_o2,
    &BallAndPlateMeasurement_B.Controller_o3);

  /* SystemInitialize for Outport: '<Root>/I_A' incorporates:
   *  SignalConversion generated from: '<S14>/I_A'
   */
  BallAndPlateMeasurement_Y.I_A = BallAndPlateMeasurement_B.Controller_o1;

  /* SystemInitialize for Outport: '<Root>/I_B' incorporates:
   *  SignalConversion generated from: '<S14>/I_B'
   */
  BallAndPlateMeasurement_Y.I_B = BallAndPlateMeasurement_B.Controller_o2;

  /* SystemInitialize for Outport: '<Root>/I_C' incorporates:
   *  SignalConversion generated from: '<S14>/I_C'
   */
  BallAndPlateMeasurement_Y.I_C = BallAndPlateMeasurement_B.Controller_o3;

  /* SystemInitialize for Outport: '<Root>/Pp_Aref' incorporates:
   *  Outport: '<S14>/Pp_Aref'
   */
  BallAndPlateMeasurement_Y.Pp_Aref = BallAndPlateMeasurement_P.Pp_Aref_Y0;

  /* SystemInitialize for Outport: '<Root>/Pp_Bref' incorporates:
   *  Outport: '<S14>/Pp_Bref'
   */
  BallAndPlateMeasurement_Y.Pp_Bref = BallAndPlateMeasurement_P.Pp_Bref_Y0;

  /* SystemInitialize for Outport: '<Root>/Pp_Cref' incorporates:
   *  Outport: '<S14>/Pp_Cref'
   */
  BallAndPlateMeasurement_Y.Pp_Cref = BallAndPlateMeasurement_P.Pp_Cref_Y0;

  /* SystemInitialize for Outport: '<Root>/Pb_Xref' incorporates:
   *  Outport: '<S14>/Pb_Xref'
   */
  BallAndPlateMeasurement_Y.Pb_Xref = BallAndPlateMeasurement_P.Pb_Xref_Y0;

  /* SystemInitialize for Outport: '<Root>/Pb_Yref' incorporates:
   *  Outport: '<S14>/Pb_Yref'
   */
  BallAndPlateMeasurement_Y.Pb_Yref = BallAndPlateMeasurement_P.Pb_Yref_Y0;

  /* End of SystemInitialize for SubSystem: '<Root>/Run' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/CalibrateBallPosition' */
  /* SystemInitialize for SignalConversion generated from: '<S1>/I_A' */
  BallAndPlateMeasurement_B.OutportBufferForI_A_p2 = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S1>/I_B' */
  BallAndPlateMeasurement_B.OutportBufferForI_B_an = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S1>/I_C' */
  BallAndPlateMeasurement_B.OutportBufferForI_C_f3 = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S1>/Pb_Xoffset' */
  BallAndPlateMeasurement_B.OutportBufferForPb_Xoffset = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S1>/Pb_Yoffset' */
  BallAndPlateMeasurement_B.OutportBufferForPb_Yoffset = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S1>/Pb_SetOffset' */
  BallAndPlateMeasurement_B.OutportBufferForPb_SetOffset = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/CalibrateBallPosition' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/EnableMotors' */
  /* SystemInitialize for SignalConversion generated from: '<S6>/I_A' */
  BallAndPlateMeasurement_B.OutportBufferForI_A_p = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S6>/I_B' */
  BallAndPlateMeasurement_B.OutportBufferForI_B_a = 0.0;

  /* SystemInitialize for SignalConversion generated from: '<S6>/I_C' */
  BallAndPlateMeasurement_B.OutportBufferForI_C_f = 0.0;

  /* End of SystemInitialize for SubSystem: '<Root>/EnableMotors' */

  /* SystemInitialize for IfAction SubSystem: '<Root>/Disabled' */
  /* SystemInitialize for SignalConversion generated from: '<S2>/I_A' */
  BallAndPlateMeasurement_B.OutportBufferForI_A =
    BallAndPlateMeasurement_B.Constant;

  /* SystemInitialize for SignalConversion generated from: '<S2>/I_B' */
  BallAndPlateMeasurement_B.OutportBufferForI_B =
    BallAndPlateMeasurement_B.Constant1;

  /* SystemInitialize for SignalConversion generated from: '<S2>/I_C' */
  BallAndPlateMeasurement_B.OutportBufferForI_C =
    BallAndPlateMeasurement_B.Constant2;

  /* End of SystemInitialize for SubSystem: '<Root>/Disabled' */
}

/* Model terminate function */
void BallAndPlateMeasurement_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Terminate for Triggered SubSystem: '<S10>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S19>/S-Function1' incorporates:
   *  Constant: '<S10>/Constant'
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

  /* End of Terminate for SubSystem: '<S10>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S18>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Terminate for Triggered SubSystem: '<S11>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S24>/S-Function1' incorporates:
   *  Constant: '<S11>/Constant'
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

  /* End of Terminate for SubSystem: '<S11>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S23>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement1/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement1' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Terminate for Triggered SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S29>/S-Function1' incorporates:
   *  Constant: '<S12>/Constant'
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

  /* End of Terminate for SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S28>/S-Function1' */

  /* --- BallAndPlateMeasurement/Position Measurement2/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement2' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier' */
  /* Terminate for S-Function (rti_commonblock): '<S15>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_1);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */
  /* Terminate for S-Function (rti_commonblock): '<S16>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 2 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_2, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_2);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S17>/S-Function1' */

  /* --- BallAndPlateMeasurement/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 3 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_3, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_3);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S5>/S-Function1' */
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
