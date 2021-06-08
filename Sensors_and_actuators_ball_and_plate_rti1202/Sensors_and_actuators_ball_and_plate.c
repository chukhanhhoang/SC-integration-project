/*
 * Sensors_and_actuators_ball_and_plate.c
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

#include "Sensors_and_actuators_ball_and_plate_trc_ptr.h"
#include "Sensors_and_actuators_ball_and_plate.h"
#include "Sensors_and_actuators_ball_and_plate_private.h"

/* Block signals (default storage) */
B_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_B;

/* Continuous states */
X_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_X;

/* Block states (default storage) */
DW_Sensors_and_actuators_ball_T Sensors_and_actuators_ball_a_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Sensors_and_actuators_T Sensors_and_actuators_b_PrevZCX;

/* External inputs (root inport signals with default storage) */
ExtU_Sensors_and_actuators_ba_T Sensors_and_actuators_ball_an_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Sensors_and_actuators_ba_T Sensors_and_actuators_ball_an_Y;

/* Real-time model */
RT_MODEL_Sensors_and_actuator_T Sensors_and_actuators_ball_a_M_;
RT_MODEL_Sensors_and_actuator_T *const Sensors_and_actuators_ball_a_M =
  &Sensors_and_actuators_ball_a_M_;

/* Forward declaration for local functions */
static real_T Sensors_and_actuators_ball_norm(const real_T x[3]);

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
  int_T nXc = 25;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Sensors_and_actuators_ball_and_plate_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for atomic system:
 *    '<Root>/MATLAB Function1'
 *    '<Root>/MATLAB Function2'
 *    '<Root>/MATLAB Function4'
 */
void Sensors_and_act_MATLABFunction1(real_T rtu_u,
  B_MATLABFunction1_Sensors_and_T *localB)
{
  /* MATLAB Function 'MATLAB Function1': '<S9>:1' */
  if (rtu_u > 0.05) {
    /* '<S9>:1:2' */
    /* '<S9>:1:3' */
    localB->y = -0.03;
  } else {
    /* '<S9>:1:5' */
    localB->y = rtu_u;
  }
}

/*
 * System initialize for enable system:
 *    '<S76>/Enabled Subsystem'
 *    '<S81>/Enabled Subsystem'
 *    '<S86>/Enabled Subsystem'
 */
void Sensors_a_EnabledSubsystem_Init(B_EnabledSubsystem_Sensors_an_T *localB,
  P_EnabledSubsystem_Sensors_an_T *localP)
{
  /* SystemInitialize for Outport: '<S77>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S76>/Enabled Subsystem'
 *    '<S81>/Enabled Subsystem'
 *    '<S86>/Enabled Subsystem'
 */
void Sensor_EnabledSubsystem_Disable(B_EnabledSubsystem_Sensors_an_T *localB,
  DW_EnabledSubsystem_Sensors_a_T *localDW, P_EnabledSubsystem_Sensors_an_T
  *localP)
{
  /* Disable for Outport: '<S77>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S76>/Enabled Subsystem'
 *    '<S81>/Enabled Subsystem'
 *    '<S86>/Enabled Subsystem'
 */
void Sensors__EnabledSubsystem_Start(DW_EnabledSubsystem_Sensors_a_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S76>/Enabled Subsystem'
 *    '<S81>/Enabled Subsystem'
 *    '<S86>/Enabled Subsystem'
 */
void Sensors_and_ac_EnabledSubsystem(RT_MODEL_Sensors_and_actuator_T * const
  Sensors_and_actuators_ball_a_M, boolean_T rtu_Enable,
  B_EnabledSubsystem_Sensors_an_T *localB, DW_EnabledSubsystem_Sensors_a_T
  *localDW, P_EnabledSubsystem_Sensors_an_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S76>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S77>/Enable'
   */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem_MODE = true;
    } else {
      if (localDW->EnabledSubsystem_MODE) {
        Sensor_EnabledSubsystem_Disable(localB, localDW, localP);
      }
    }
  }

  if (localDW->EnabledSubsystem_MODE && rtmIsMajorTimeStep
      (Sensors_and_actuators_ball_a_M)) {
    /* SignalConversion generated from: '<S77>/Out1' incorporates:
     *  Constant: '<S77>/Constant'
     */
    localB->OutportBufferForOut1 = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S76>/Enabled Subsystem1'
 *    '<S81>/Enabled Subsystem1'
 *    '<S86>/Enabled Subsystem1'
 */
void Sensors__EnabledSubsystem1_Init(B_EnabledSubsystem1_Sensors_a_T *localB,
  P_EnabledSubsystem1_Sensors_a_T *localP)
{
  /* SystemInitialize for Outport: '<S78>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S76>/Enabled Subsystem1'
 *    '<S81>/Enabled Subsystem1'
 *    '<S86>/Enabled Subsystem1'
 */
void Senso_EnabledSubsystem1_Disable(DW_EnabledSubsystem1_Sensors__T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S76>/Enabled Subsystem1'
 *    '<S81>/Enabled Subsystem1'
 *    '<S86>/Enabled Subsystem1'
 */
void Sensors_EnabledSubsystem1_Start(DW_EnabledSubsystem1_Sensors__T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S76>/Enabled Subsystem1'
 *    '<S81>/Enabled Subsystem1'
 *    '<S86>/Enabled Subsystem1'
 */
void Sensors_and_a_EnabledSubsystem1(RT_MODEL_Sensors_and_actuator_T * const
  Sensors_and_actuators_ball_a_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem1_Sensors_a_T *localB, DW_EnabledSubsystem1_Sensors__T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S76>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S78>/Enable'
   */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    if (rtu_Enable) {
      localDW->EnabledSubsystem1_MODE = true;
    } else {
      if (localDW->EnabledSubsystem1_MODE) {
        Senso_EnabledSubsystem1_Disable(localDW);
      }
    }
  }

  if (localDW->EnabledSubsystem1_MODE && rtmIsMajorTimeStep
      (Sensors_and_actuators_ball_a_M)) {
    /* Inport: '<S78>/In1' */
    localB->In1 = rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem1' */
}

/* Function for MATLAB Function: '<Root>/MATLAB Function3' */
static real_T Sensors_and_actuators_ball_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  real_T absxk;
  real_T t;
  scale = 3.3121686421112381E-170;
  absxk = fabs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }

  absxk = fabs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrt(y);
}

/* Model output function */
void Sensors_and_actuators_ball_and_plate_output(void)
{
  ZCEventType zcEvent;
  int_T iy;
  real_T r0Oc[3];
  real_T CPi_rotated[9];
  real_T C1;
  real_T S1;
  real_T S3;
  real_T rCiBi[9];
  real_T tmp[4];
  real_T tmp_0[2];
  boolean_T zcEvent_0;
  int32_T i;
  real_T r0Oc_0[9];
  real_T C2[9];
  real_T UnitZp_idx_2;
  real_T UnitZp_idx_1;
  real_T UnitZp_idx_0;
  static const int8_T b[3] = { 0, 0, 1 };

  static const real_T r1C[9] = { 0.17, 0.0, 0.0, -0.085, 0.14722431864335458,
    0.0, -0.085, -0.14722431864335458, 0.0 };

  const real_T *tmp_1;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* set solver stop time */
    if (!(Sensors_and_actuators_ball_a_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Sensors_and_actuators_ball_a_M->solverInfo,
                            ((Sensors_and_actuators_ball_a_M->Timing.clockTickH0
        + 1) * Sensors_and_actuators_ball_a_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Sensors_and_actuators_ball_a_M->solverInfo,
                            ((Sensors_and_actuators_ball_a_M->Timing.clockTick0
        + 1) * Sensors_and_actuators_ball_a_M->Timing.stepSize0 +
        Sensors_and_actuators_ball_a_M->Timing.clockTickH0 *
        Sensors_and_actuators_ball_a_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Sensors_and_actuators_ball_a_M)) {
    Sensors_and_actuators_ball_a_M->Timing.t[0] = rtsiGetT
      (&Sensors_and_actuators_ball_a_M->solverInfo);
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S16>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S75>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init' */
      zcEvent_0 = (Sensors_and_actuators_ball_an_U.Init &&
                   (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o
                    != POS_ZCSIG));
      if (zcEvent_0) {
        /* S-Function (rti_commonblock): '<S75>/S-Function1' incorporates:
         *  Constant: '<S16>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1,
               (Float64)(Sensors_and_actuators_ball_an_P.Constant_Value * 1)
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

      /* Inport: '<Root>/Init' */
      Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o =
        Sensors_and_actuators_ball_an_U.Init;
    }

    /* End of Outputs for SubSystem: '<S16>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S74>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S16>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos_g =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_o;

    /* Sum: '<S16>/AbsPosition' incorporates:
     *  Constant: '<S16>/Pos_offset'
     *  Constant: '<S16>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition_hs =
      (Sensors_and_actuators_ball_an_B.Inc2Pos_g -
       Sensors_and_actuators_ball_an_P.ZP_Value) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value;

    /* Abs: '<S76>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs_c = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2_n);
  }

  /* Outputs for Enabled SubSystem: '<S76>/Enabled Subsystem' */
  /* Inport: '<Root>/Init' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S76>/Relational Operator1' incorporates:
     *  Constant: '<S76>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1_b =
      (Sensors_and_actuators_ball_an_B.Abs_c <=
       Sensors_and_actuators_ball_an_P.Const_Value);
  }

  /* TransferFcn: '<S76>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn_f = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn_f +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b;

  /* RelationalOperator: '<S76>/Relational Operator' incorporates:
   *  Constant: '<S76>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator_c =
    (Sensors_and_actuators_ball_an_P.Const1_Value >=
     Sensors_and_actuators_ball_an_B.TransferFcn_f);

  /* Logic: '<S76>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2_c =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1_b &&
     Sensors_and_actuators_ball_an_B.RelationalOperator_c &&
     Sensors_and_actuators_ball_an_U.Init);

  /* Outputs for Enabled SubSystem: '<S76>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2_c,
    Sensors_and_actuators_ball_an_B.Inc2Pos_g,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S76>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S16>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m_h =
      Sensors_and_actuators_ball_an_P.mm2m_Gain *
      Sensors_and_actuators_ball_an_B.AbsPosition_hs;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function1' */
    Sensors_and_act_MATLABFunction1(Sensors_and_actuators_ball_an_B.mm2m_h,
      &Sensors_and_actuators_ball_an_B.sf_MATLABFunction1);

    /* Outport: '<Root>/P_A' */
    Sensors_and_actuators_ball_an_Y.P_A =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.y;

    /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    Sensors_and_actuators_ball_an_B.DataTypeConversion =
      (Sensors_and_actuators_ball_an_P.Constant1_Value != 0.0);

    /* S-Function (rti_commonblock): '<S2>/S-Function1' incorporates:
     *  Outport: '<Root>/Frames '
     *  Outport: '<Root>/Status '
     */
    /* This comment workarounds a code generation problem */
    {
      /* --- Sensors_and_actuators_ball_and_plate/ETHERNET_UDP_RX_BL1: ==> Socket ID = (0) --- */
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
      if (Sensors_and_actuators_ball_an_B.DataTypeConversion == 0) {
        /* block is disabled */
        /**/

        /* set output Received Bytes to 0 */
        Sensors_and_actuators_ball_an_B.SFunction1_o4 = (uint32_T) 0;

        /* set output Status to state 1 indicating a disabled RX block */
        tmpStatus = 1;
      } else {
        /* block is enabled */
        /**/

        /* receive data from a socket and obtain the address of the sender */
        realLen =
          DsIoEth_recvfrom( DSIOETH_CONNECTION_ID_0,
                           (uint8_T *)
                           &Sensors_and_actuators_ball_an_B.SFunction1_o1_n[0],
                           32U,
                           DSIOETH_FLAG_NONE,
                           (DsSSockAddr *) &remoteAddr,
                           &addrLen
                           );
        if (realLen > 0) {
          /* set output Status to state 0 indicating successfully received data */
          tmpStatus = 0;

          /* increment output Received Frames  */
          Sensors_and_actuators_ball_an_Y.Frames = (real_T)
            (Sensors_and_actuators_ball_an_Y.Frames + 1);

          /* set output Received Bytes  to real data length realLen */
          Sensors_and_actuators_ball_an_B.SFunction1_o4 = (uint32_T) realLen;
        } else {
          /* realLen -1: No data received due to empty rx buffer *
           * realLen  0: Connection socket not ready (closed)    */
          tmpStatus = (realLen == -1) ? 2 : 3;

          /* no data received due to empty rx buffer or socket not ready yet */
          Sensors_and_actuators_ball_an_B.SFunction1_o4 = (uint32_T) 0;
        }
      }                                // if (Inport_Enable == 0)

      /* assign receive status to the related outport */
      Sensors_and_actuators_ball_an_Y.Status = (uint32_T) tmpStatus;

      /* assign remote IP (s_addr: uint32) to the related outport as (uint8.uint8.uint8.uint8) */
      *((UInt32*) &Sensors_and_actuators_ball_an_B.SFunction1_o5[0]) =
        remoteAddr.sin_addr.s_addr;

      /* assign remote port to the related outport */
      Sensors_and_actuators_ball_an_B.SFunction1_o6 = DsIoEth_ntohs
        (remoteAddr.sin_port);
    }

    /* Gain: '<Root>/Gain2' */
    Sensors_and_actuators_ball_an_B.Gain2 = (uint16_T)((uint16_T)((uint32_T)
      Sensors_and_actuators_ball_an_P.Gain2_Gain *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_n[1]) << 1);

    /* Outport: '<Root>/Xpos ' incorporates:
     *  Sum: '<Root>/Add'
     */
    Sensors_and_actuators_ball_an_Y.Xpos = (uint16_T)((uint32_T)
      Sensors_and_actuators_ball_an_B.SFunction1_o1_n[0] +
      Sensors_and_actuators_ball_an_B.Gain2);

    /* Gain: '<Root>/Gain1' */
    Sensors_and_actuators_ball_an_B.Gain1 = (uint16_T)((uint16_T)((uint32_T)
      Sensors_and_actuators_ball_an_P.Gain1_Gain *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_n[5]) << 1);

    /* Outport: '<Root>/Ypos ' incorporates:
     *  Sum: '<Root>/Add1'
     */
    Sensors_and_actuators_ball_an_Y.Ypos = (uint16_T)((uint32_T)
      Sensors_and_actuators_ball_an_B.SFunction1_o1_n[4] +
      Sensors_and_actuators_ball_an_B.Gain1);
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S17>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S80>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init1' */
      zcEvent_0 = (Sensors_and_actuators_ball_an_U.Init1 &&
                   (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n
                    != POS_ZCSIG));
      if (zcEvent_0) {
        /* S-Function (rti_commonblock): '<S80>/S-Function1' incorporates:
         *  Constant: '<S17>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
               (Float64)(Sensors_and_actuators_ball_an_P.Constant_Value_d * 1)
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

      /* Inport: '<Root>/Init1' */
      Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n =
        Sensors_and_actuators_ball_an_U.Init1;
    }

    /* End of Outputs for SubSystem: '<S17>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S79>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S17>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos_i =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain_j *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_g;

    /* Sum: '<S17>/AbsPosition' incorporates:
     *  Constant: '<S17>/Pos_offset'
     *  Constant: '<S17>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition_h =
      (Sensors_and_actuators_ball_an_B.Inc2Pos_i -
       Sensors_and_actuators_ball_an_P.ZP_Value_a) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value_f;

    /* Abs: '<S81>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs_l = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2_p);
  }

  /* Outputs for Enabled SubSystem: '<S81>/Enabled Subsystem' */
  /* Inport: '<Root>/Init1' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init1,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem_h,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem_h,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S81>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S81>/Relational Operator1' incorporates:
     *  Constant: '<S81>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1_p =
      (Sensors_and_actuators_ball_an_B.Abs_l <=
       Sensors_and_actuators_ball_an_P.Const_Value_d);
  }

  /* TransferFcn: '<S81>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn_d = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn_d +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C_j *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k;

  /* RelationalOperator: '<S81>/Relational Operator' incorporates:
   *  Constant: '<S81>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator_n =
    (Sensors_and_actuators_ball_an_P.Const1_Value_k >=
     Sensors_and_actuators_ball_an_B.TransferFcn_d);

  /* Logic: '<S81>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init1'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2_k =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1_p &&
     Sensors_and_actuators_ball_an_B.RelationalOperator_n &&
     Sensors_and_actuators_ball_an_U.Init1);

  /* Outputs for Enabled SubSystem: '<S81>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2_k,
    Sensors_and_actuators_ball_an_B.Inc2Pos_i,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1_m,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_m);

  /* End of Outputs for SubSystem: '<S81>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S17>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m_p =
      Sensors_and_actuators_ball_an_P.mm2m_Gain_f *
      Sensors_and_actuators_ball_an_B.AbsPosition_h;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function2' */
    Sensors_and_act_MATLABFunction1(Sensors_and_actuators_ball_an_B.mm2m_p,
      &Sensors_and_actuators_ball_an_B.sf_MATLABFunction2);

    /* Outport: '<Root>/P_B' */
    Sensors_and_actuators_ball_an_Y.P_B =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction2.y;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S18>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S85>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init2' */
      zcEvent_0 = (Sensors_and_actuators_ball_an_U.Init2 &&
                   (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC
                    != POS_ZCSIG));
      if (zcEvent_0) {
        /* S-Function (rti_commonblock): '<S85>/S-Function1' incorporates:
         *  Constant: '<S18>/Constant'
         */
        /* This comment workarounds a code generation problem */
        {
          /* --- Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_POS_SET_BL1 --- */
          /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
          {
            /* -- Position measurement enabled -- */

            /* Set counter position for the selected incremental Encoder (in lines) */
            DioCl2EncoderIn_setEncPosition
              (pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
               (Float64)(Sensors_and_actuators_ball_an_P.Constant_Value_c * 1)
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

      /* Inport: '<Root>/Init2' */
      Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC =
        Sensors_and_actuators_ball_an_U.Init2;
    }

    /* End of Outputs for SubSystem: '<S18>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S84>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S18>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain_i *
      Sensors_and_actuators_ball_an_B.SFunction1_o1;

    /* Sum: '<S18>/AbsPosition' incorporates:
     *  Constant: '<S18>/Pos_offset'
     *  Constant: '<S18>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition =
      (Sensors_and_actuators_ball_an_B.Inc2Pos -
       Sensors_and_actuators_ball_an_P.ZP_Value_d) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value_b;

    /* Abs: '<S86>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2);
  }

  /* Outputs for Enabled SubSystem: '<S86>/Enabled Subsystem' */
  /* Inport: '<Root>/Init2' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init2,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem_c,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem_c,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem_c);

  /* End of Outputs for SubSystem: '<S86>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S86>/Relational Operator1' incorporates:
     *  Constant: '<S86>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1 =
      (Sensors_and_actuators_ball_an_B.Abs <=
       Sensors_and_actuators_ball_an_P.Const_Value_i);
  }

  /* TransferFcn: '<S86>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C_m *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE;

  /* RelationalOperator: '<S86>/Relational Operator' incorporates:
   *  Constant: '<S86>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator =
    (Sensors_and_actuators_ball_an_P.Const1_Value_n >=
     Sensors_and_actuators_ball_an_B.TransferFcn);

  /* Logic: '<S86>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init2'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2 =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1 &&
     Sensors_and_actuators_ball_an_B.RelationalOperator &&
     Sensors_and_actuators_ball_an_U.Init2);

  /* Outputs for Enabled SubSystem: '<S86>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2,
    Sensors_and_actuators_ball_an_B.Inc2Pos,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1_j,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S86>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S18>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m =
      Sensors_and_actuators_ball_an_P.mm2m_Gain_a *
      Sensors_and_actuators_ball_an_B.AbsPosition;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function4' */
    Sensors_and_act_MATLABFunction1(Sensors_and_actuators_ball_an_B.mm2m,
      &Sensors_and_actuators_ball_an_B.sf_MATLABFunction4);

    /* Outport: '<Root>/P_C' */
    Sensors_and_actuators_ball_an_Y.P_C =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction4.y;

    /* Sum: '<Root>/Sum6' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Outport: '<Root>/Ypos '
     */
    Sensors_and_actuators_ball_an_B.Sum6 = (real_T)
      Sensors_and_actuators_ball_an_Y.Ypos -
      Sensors_and_actuators_ball_an_P.Constant10_Value;

    /* Outport: '<Root>/Xpos_m' incorporates:
     *  Gain: '<Root>/Gain5'
     */
    Sensors_and_actuators_ball_an_Y.Xpos_m =
      Sensors_and_actuators_ball_an_P.Gain5_Gain *
      Sensors_and_actuators_ball_an_B.Sum6;

    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/Constant4'
     *  Outport: '<Root>/Xpos '
     */
    Sensors_and_actuators_ball_an_B.Sum5 = (real_T)
      Sensors_and_actuators_ball_an_Y.Xpos -
      Sensors_and_actuators_ball_an_P.Constant4_Value;

    /* Outport: '<Root>/Ypos_m' incorporates:
     *  Gain: '<Root>/Gain'
     */
    Sensors_and_actuators_ball_an_Y.Ypos_m =
      Sensors_and_actuators_ball_an_P.Gain_Gain *
      Sensors_and_actuators_ball_an_B.Sum5;

    /* Reshape: '<S7>/ReshapeX0' incorporates:
     *  Constant: '<S7>/X0'
     */
    Sensors_and_actuators_ball_an_B.ReshapeX0[0] =
      Sensors_and_actuators_ball_an_P.X0_Value[0];
    Sensors_and_actuators_ball_an_B.ReshapeX0[1] =
      Sensors_and_actuators_ball_an_P.X0_Value[1];
    Sensors_and_actuators_ball_an_B.ReshapeX0[2] =
      Sensors_and_actuators_ball_an_P.X0_Value[2];
    Sensors_and_actuators_ball_an_B.ReshapeX0[3] =
      Sensors_and_actuators_ball_an_P.X0_Value[3];
  }

  /* Integrator: '<S7>/MemoryX' */
  if (Sensors_and_actuators_ball_a_DW.MemoryX_IWORK != 0) {
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[0] =
      Sensors_and_actuators_ball_an_B.ReshapeX0[0];
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[1] =
      Sensors_and_actuators_ball_an_B.ReshapeX0[1];
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[2] =
      Sensors_and_actuators_ball_an_B.ReshapeX0[2];
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[3] =
      Sensors_and_actuators_ball_an_B.ReshapeX0[3];
  }

  Sensors_and_actuators_ball_an_B.MemoryX[0] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[0];

  /* Reshape: '<S7>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[0] =
    Sensors_and_actuators_ball_an_B.MemoryX[0];

  /* Outport: '<Root>/estimated_ball' */
  Sensors_and_actuators_ball_an_Y.estimated_ball[0] =
    Sensors_and_actuators_ball_an_B.Reshapexhat[0];

  /* Integrator: '<S7>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[1] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[1];

  /* Reshape: '<S7>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[1] =
    Sensors_and_actuators_ball_an_B.MemoryX[1];

  /* Outport: '<Root>/estimated_ball' */
  Sensors_and_actuators_ball_an_Y.estimated_ball[1] =
    Sensors_and_actuators_ball_an_B.Reshapexhat[1];

  /* Integrator: '<S7>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[2] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[2];

  /* Reshape: '<S7>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[2] =
    Sensors_and_actuators_ball_an_B.MemoryX[2];

  /* Outport: '<Root>/estimated_ball' */
  Sensors_and_actuators_ball_an_Y.estimated_ball[2] =
    Sensors_and_actuators_ball_an_B.Reshapexhat[2];

  /* Integrator: '<S7>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[3] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[3];

  /* Reshape: '<S7>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[3] =
    Sensors_and_actuators_ball_an_B.MemoryX[3];

  /* Outport: '<Root>/estimated_ball' */
  Sensors_and_actuators_ball_an_Y.estimated_ball[3] =
    Sensors_and_actuators_ball_an_B.Reshapexhat[3];
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    Sensors_and_actuators_ball_an_B.Add2 =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.y +
      Sensors_and_actuators_ball_an_P.Constant9_Value;

    /* Sum: '<Root>/Add3' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    Sensors_and_actuators_ball_an_B.Add3 =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction2.y +
      Sensors_and_actuators_ball_an_P.Constant9_Value;

    /* Sum: '<Root>/Add4' incorporates:
     *  Constant: '<Root>/Constant9'
     */
    Sensors_and_actuators_ball_an_B.Add4 =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction4.y +
      Sensors_and_actuators_ball_an_P.Constant9_Value;

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* MATLAB Function 'MATLAB Function': '<S8>:1' */
    /* '<S8>:1:30' */
    /* '<S8>:1:25' */
    /* '<S8>:1:13' */
    /* '<S8>:1:14' */
    /* '<S8>:1:15' */
    /* '<S8>:1:16' */
    /* '<S8>:1:21' */
    C1 = ((Sensors_and_actuators_ball_an_B.Add2 +
           Sensors_and_actuators_ball_an_B.Add3) +
          Sensors_and_actuators_ball_an_B.Add4) * 0.33333333333333331;

    /* '<S8>:1:22' */
    r0Oc[2] = C1;

    /* '<S8>:1:25' */
    /* '<S8>:1:26' */
    /* '<S8>:1:29' */
    rCiBi[2] = Sensors_and_actuators_ball_an_B.Add2;
    rCiBi[5] = Sensors_and_actuators_ball_an_B.Add3;
    rCiBi[8] = Sensors_and_actuators_ball_an_B.Add4;
    rCiBi[0] = 0.17;
    rCiBi[1] = 0.0;
    r0Oc_0[0] = 0.0;
    r0Oc_0[3] = 0.0;
    r0Oc_0[6] = 0.0;
    rCiBi[3] = -0.085;
    rCiBi[4] = 0.14722431864335458;
    r0Oc_0[1] = 0.0;
    r0Oc_0[4] = 0.0;
    r0Oc_0[7] = 0.0;
    S1 = r0Oc[2];
    rCiBi[6] = -0.085;
    rCiBi[7] = -0.14722431864335458;
    r0Oc_0[2] = S1;
    r0Oc_0[5] = S1;
    r0Oc_0[8] = S1;
    for (i = 0; i < 9; i++) {
      CPi_rotated[i] = rCiBi[i] - r0Oc_0[i];
    }

    /* '<S8>:1:30' */
    /* '<S8>:1:32' */
    /* '<S8>:1:38' */
    UnitZp_idx_0 = CPi_rotated[0];
    S1 = UnitZp_idx_0 * UnitZp_idx_0;
    UnitZp_idx_0 = CPi_rotated[1];
    S1 += UnitZp_idx_0 * UnitZp_idx_0;
    UnitZp_idx_0 = CPi_rotated[2];
    S1 += UnitZp_idx_0 * UnitZp_idx_0;
    S1 = sqrt(S1);
    r0Oc[0] = CPi_rotated[0] / S1;
    r0Oc[1] = CPi_rotated[1] / S1;
    r0Oc[2] = CPi_rotated[2] / S1;

    /* '<S8>:1:39' */
    UnitZp_idx_0 = r0Oc[1] * CPi_rotated[8] - r0Oc[2] * CPi_rotated[7];
    UnitZp_idx_1 = r0Oc[2] * CPi_rotated[6] - r0Oc[0] * CPi_rotated[8];
    UnitZp_idx_2 = r0Oc[0] * CPi_rotated[7] - r0Oc[1] * CPi_rotated[6];

    /* '<S8>:1:40' */
    S3 = UnitZp_idx_0;
    S1 = S3 * S3;
    S3 = UnitZp_idx_1;
    S1 += S3 * S3;
    S3 = UnitZp_idx_2;
    S1 += S3 * S3;
    S1 = sqrt(S1);
    S3 = UnitZp_idx_0;
    S3 /= S1;
    UnitZp_idx_0 = S3;
    S3 = UnitZp_idx_1;
    S3 /= S1;
    UnitZp_idx_1 = S3;

    /* Outport: '<Root>/measured_theta2' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function'
     */
    /* '<S8>:1:41' */
    /* '<S8>:1:43' */
    Sensors_and_actuators_ball_an_Y.measured_theta2 = -r0Oc[2];
    Sensors_and_actuators_ball_an_Y.measured_theta2 = asin
      (Sensors_and_actuators_ball_an_Y.measured_theta2);

    /* MATLAB Function: '<Root>/MATLAB Function' */
    /* '<S8>:1:44' */
    Sensors_and_actuators_ball_an_B.theta3 = r0Oc[1] / sqrt(1.0 - r0Oc[2] *
      r0Oc[2]);
    Sensors_and_actuators_ball_an_B.theta3 = asin
      (Sensors_and_actuators_ball_an_B.theta3);

    /* Outport: '<Root>/measured_theta1' incorporates:
     *  MATLAB Function: '<Root>/MATLAB Function'
     */
    /* '<S8>:1:45' */
    Sensors_and_actuators_ball_an_Y.measured_theta1 = (r0Oc[0] * UnitZp_idx_1 -
      r0Oc[1] * UnitZp_idx_0) / sqrt(1.0 - r0Oc[2] * r0Oc[2]);
    Sensors_and_actuators_ball_an_Y.measured_theta1 = asin
      (Sensors_and_actuators_ball_an_Y.measured_theta1);

    /* MATLAB Function: '<Root>/MATLAB Function' */
    Sensors_and_actuators_ball_an_B.Zc = C1;
  }

  /* Sin: '<Root>/Sine Wave1' */
  Sensors_and_actuators_ball_an_B.SineWave1 = sin
    (Sensors_and_actuators_ball_an_P.SineWave1_Freq *
     Sensors_and_actuators_ball_a_M->Timing.t[0] +
     Sensors_and_actuators_ball_an_P.SineWave1_Phase) *
    Sensors_and_actuators_ball_an_P.SineWave1_Amp +
    Sensors_and_actuators_ball_an_P.SineWave1_Bias;

  /* Sin: '<Root>/Sine Wave' */
  Sensors_and_actuators_ball_an_B.SineWave = sin
    (Sensors_and_actuators_ball_an_P.SineWave_Freq *
     Sensors_and_actuators_ball_a_M->Timing.t[0] +
     Sensors_and_actuators_ball_an_P.SineWave_Phase) *
    Sensors_and_actuators_ball_an_P.SineWave_Amp +
    Sensors_and_actuators_ball_an_P.SineWave_Bias;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Outport: '<Root>/Xpos_m'
   *  Outport: '<Root>/Ypos_m'
   */
  Sensors_and_actuators_ball_an_B.Sum[0] =
    Sensors_and_actuators_ball_an_B.SineWave1 -
    Sensors_and_actuators_ball_an_Y.Xpos_m;
  Sensors_and_actuators_ball_an_B.Sum[1] =
    Sensors_and_actuators_ball_an_P.Constant5_Value -
    Sensors_and_actuators_ball_an_P.Constant5_Value;
  Sensors_and_actuators_ball_an_B.Sum[2] =
    Sensors_and_actuators_ball_an_B.SineWave -
    Sensors_and_actuators_ball_an_Y.Ypos_m;
  Sensors_and_actuators_ball_an_B.Sum[3] =
    Sensors_and_actuators_ball_an_P.Constant5_Value -
    Sensors_and_actuators_ball_an_P.Constant5_Value;

  /* Gain: '<Root>/Gain3' */
  for (i = 0; i < 2; i++) {
    Sensors_and_actuators_ball_an_B.Gain3[i] = 0.0;
    Sensors_and_actuators_ball_an_B.Gain3[i] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i] *
      Sensors_and_actuators_ball_an_B.Sum[0];
    Sensors_and_actuators_ball_an_B.Gain3[i] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i + 2] *
      Sensors_and_actuators_ball_an_B.Sum[1];
    Sensors_and_actuators_ball_an_B.Gain3[i] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i + 4] *
      Sensors_and_actuators_ball_an_B.Sum[2];
    Sensors_and_actuators_ball_an_B.Gain3[i] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i + 6] *
      Sensors_and_actuators_ball_an_B.Sum[3];
  }

  /* End of Gain: '<Root>/Gain3' */

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/Constant13'
   *  Constant: '<Root>/Constant14'
   */
  /* MATLAB Function 'MATLAB Function3': '<S11>:1' */
  /* '<S11>:1:27' */
  /* '<S11>:1:26' */
  /* '<S11>:1:25' */
  /* '<S11>:1:34' */
  /* '<S11>:1:16' */
  /* '<S11>:1:18' */
  /* '<S11>:1:19' */
  r0Oc[0] = 0.0;
  r0Oc[1] = 0.0;
  r0Oc[2] = Sensors_and_actuators_ball_an_P.Constant14_Value;

  /* '<S11>:1:22' */
  C1 = cos(Sensors_and_actuators_ball_an_B.Gain3[0]);

  /* '<S11>:1:22' */
  S1 = sin(Sensors_and_actuators_ball_an_B.Gain3[0]);

  /* '<S11>:1:22' */
  UnitZp_idx_0 = cos(Sensors_and_actuators_ball_an_B.Gain3[1]);

  /* '<S11>:1:22' */
  UnitZp_idx_1 = sin(Sensors_and_actuators_ball_an_B.Gain3[1]);

  /* '<S11>:1:22' */
  UnitZp_idx_2 = cos(Sensors_and_actuators_ball_an_P.Constant13_Value);

  /* '<S11>:1:22' */
  S3 = sin(Sensors_and_actuators_ball_an_P.Constant13_Value);

  /* '<S11>:1:25' */
  /* '<S11>:1:26' */
  /* '<S11>:1:27' */
  /* '<S11>:1:29' */
  CPi_rotated[1] = 0.0;
  CPi_rotated[4] = C1;
  CPi_rotated[7] = S1;
  CPi_rotated[2] = 0.0;
  CPi_rotated[5] = -S1;
  CPi_rotated[8] = C1;
  C2[0] = UnitZp_idx_0;
  C2[3] = 0.0;
  C2[6] = -UnitZp_idx_1;
  CPi_rotated[0] = 1.0;
  C2[1] = 0.0;
  CPi_rotated[3] = 0.0;
  C2[4] = 1.0;
  CPi_rotated[6] = 0.0;
  C2[7] = 0.0;
  C2[2] = UnitZp_idx_1;
  C2[5] = 0.0;
  C2[8] = UnitZp_idx_0;
  r0Oc_0[0] = UnitZp_idx_2;
  r0Oc_0[3] = S3;
  r0Oc_0[6] = 0.0;
  r0Oc_0[1] = -S3;
  r0Oc_0[4] = UnitZp_idx_2;
  r0Oc_0[7] = 0.0;
  for (i = 0; i < 3; i++) {
    for (iy = 0; iy < 3; iy++) {
      rCiBi[i + 3 * iy] = 0.0;
      C1 = rCiBi[3 * iy + i];
      C1 += C2[3 * iy] * CPi_rotated[i];
      rCiBi[i + 3 * iy] = C1;
      C1 = rCiBi[3 * iy + i];
      C1 += C2[3 * iy + 1] * CPi_rotated[i + 3];
      rCiBi[i + 3 * iy] = C1;
      C1 = rCiBi[3 * iy + i];
      C1 += C2[3 * iy + 2] * CPi_rotated[i + 6];
      rCiBi[i + 3 * iy] = C1;
    }

    r0Oc_0[3 * i + 2] = b[i];
  }

  for (i = 0; i < 3; i++) {
    for (iy = 0; iy < 3; iy++) {
      CPi_rotated[iy + 3 * i] = 0.0;
      UnitZp_idx_0 = CPi_rotated[3 * i + iy];
      UnitZp_idx_0 += r0Oc_0[3 * i] * rCiBi[iy];
      CPi_rotated[iy + 3 * i] = UnitZp_idx_0;
      UnitZp_idx_0 = CPi_rotated[3 * i + iy];
      UnitZp_idx_0 += r0Oc_0[3 * i + 1] * rCiBi[iy + 3];
      CPi_rotated[iy + 3 * i] = UnitZp_idx_0;
      UnitZp_idx_0 = CPi_rotated[3 * i + iy];
      UnitZp_idx_0 += r0Oc_0[3 * i + 2] * rCiBi[iy + 6];
      CPi_rotated[iy + 3 * i] = UnitZp_idx_0;
    }
  }

  /* '<S11>:1:32' */
  /* '<S11>:1:33' */
  for (iy = 0; iy < 3; iy++) {
    /* '<S11>:1:33' */
    /* '<S11>:1:34' */
    for (i = 0; i < 3; i++) {
      C1 = CPi_rotated[3 * i] * r1C[3 * iy];
      C1 += CPi_rotated[3 * i + 1] * r1C[3 * iy + 1];
      C1 += CPi_rotated[3 * i + 2] * r1C[3 * iy + 2];
      rCiBi[i + 3 * iy] = (r0Oc[i] + C1) - r1C[3 * iy + i];
    }
  }

  /* '<S11>:1:38' */
  Sensors_and_actuators_ball_an_B.motor1 = Sensors_and_actuators_ball_norm
    (&rCiBi[0]);

  /* '<S11>:1:39' */
  Sensors_and_actuators_ball_an_B.motor2 = Sensors_and_actuators_ball_norm
    (&rCiBi[3]);

  /* '<S11>:1:40' */
  Sensors_and_actuators_ball_an_B.motor3 = Sensors_and_actuators_ball_norm
    (&rCiBi[6]);

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */

  /* Sum: '<Root>/Add5' incorporates:
   *  Constant: '<Root>/Constant14'
   */
  Sensors_and_actuators_ball_an_B.Add5 = Sensors_and_actuators_ball_an_B.motor1
    - Sensors_and_actuators_ball_an_P.Constant14_Value;

  /* Gain: '<Root>/GainA' */
  Sensors_and_actuators_ball_an_B.GainA =
    Sensors_and_actuators_ball_an_P.GainA_Gain *
    Sensors_and_actuators_ball_an_B.Add5;

  /* Sum: '<Root>/Sum1' */
  Sensors_and_actuators_ball_an_B.Sum1 = Sensors_and_actuators_ball_an_B.GainA -
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.y;

  /* Gain: '<S4>/Gain' */
  Sensors_and_actuators_ball_an_B.Gain_n =
    Sensors_and_actuators_ball_an_P.Gain_Gain_l *
    Sensors_and_actuators_ball_an_B.Sum1;

  /* TransferFcn: '<S4>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_C *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE;
  Sensors_and_actuators_ball_an_B.LeadlagFilter +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_D *
    Sensors_and_actuators_ball_an_B.Gain_n;

  /* TransferFcn: '<S4>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter2 = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2 +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_C *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2 +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_D *
    Sensors_and_actuators_ball_an_B.LeadlagFilter;

  /* Integrator: '<S4>/Integrator1' incorporates:
   *  Constant: '<S4>/Constant'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE,
                       (Sensors_and_actuators_ball_an_P.Constant_Value_a));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator1_IC;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE >=
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat) {
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE =
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE <=
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator1 =
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE;

  /* End of Integrator: '<S4>/Integrator1' */

  /* Switch: '<Root>/Switch3' incorporates:
   *  Inport: '<Root>/CloseLoop_disable'
   *  Inport: '<Root>/controller_disable'
   *  Switch: '<Root>/Switch2'
   */
  if (Sensors_and_actuators_ball_an_U.CloseLoop_disable >=
      Sensors_and_actuators_ball_an_P.Switch3_Threshold) {
    Sensors_and_actuators_ball_an_B.Switch3 =
      Sensors_and_actuators_ball_an_B.TransferFcn_f;
  } else {
    if (Sensors_and_actuators_ball_an_U.controller_disable >=
        Sensors_and_actuators_ball_an_P.Switch2_Threshold) {
      /* Switch: '<Root>/Switch2' incorporates:
       *  Constant: '<Root>/Constant'
       */
      Sensors_and_actuators_ball_an_B.Switch2 =
        Sensors_and_actuators_ball_an_P.Constant_Value_i;
    } else {
      /* Sum: '<S4>/Sum' incorporates:
       *  Switch: '<Root>/Switch2'
       */
      Sensors_and_actuators_ball_an_B.Sum_i =
        Sensors_and_actuators_ball_an_B.LeadlagFilter2 +
        Sensors_and_actuators_ball_an_B.Integrator1;

      /* Switch: '<Root>/Switch2' */
      Sensors_and_actuators_ball_an_B.Switch2 =
        Sensors_and_actuators_ball_an_B.Sum_i;
    }

    Sensors_and_actuators_ball_an_B.Switch3 =
      Sensors_and_actuators_ball_an_B.Switch2;
  }

  /* End of Switch: '<Root>/Switch3' */

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier' */

  /* Saturate: '<S13>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Switch3;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat;
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat;
  if (C1 > UnitZp_idx_0) {
    Sensors_and_actuators_ball_an_B.Saturation_e = UnitZp_idx_0;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation_e = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation_e = C1;
  }

  /* End of Saturate: '<S13>/Saturation' */

  /* Gain: '<S13>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V_p =
    Sensors_and_actuators_ball_an_P.Current2V_Gain *
    Sensors_and_actuators_ball_an_B.Saturation_e;

  /* Gain: '<S13>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale_o =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain *
    Sensors_and_actuators_ball_an_B.Current2V_p;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S71>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 1 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) Sensors_and_actuators_ball_an_B.DSPscale_o;

      /* write value of CL1 DAC for output channel 1 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_1,
        DAC_CLASS1_CHANNEL_1, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_1);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Integrator: '<Root>/Integrator1' incorporates:
   *  Inport: '<Root>/reser_integrator1'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_g,
                       (Sensors_and_actuators_ball_an_U.reser_integrator1));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l =
        Sensors_and_actuators_ball_an_P.Integrator1_IC_i;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l >=
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_l) {
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l =
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_l;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l <=
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_p) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l =
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_p;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator1_h =
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l;

  /* End of Integrator: '<Root>/Integrator1' */

  /* Switch: '<Root>/Switch4' incorporates:
   *  Inport: '<Root>/CloseLoop_disable1'
   *  Inport: '<Root>/controller_disable1'
   *  Switch: '<Root>/Switch1'
   */
  if (Sensors_and_actuators_ball_an_U.CloseLoop_disable1 >=
      Sensors_and_actuators_ball_an_P.Switch4_Threshold) {
    Sensors_and_actuators_ball_an_B.Switch4 =
      Sensors_and_actuators_ball_an_B.TransferFcn_d;
  } else {
    if (Sensors_and_actuators_ball_an_U.controller_disable1 >=
        Sensors_and_actuators_ball_an_P.Switch1_Threshold) {
      /* Switch: '<Root>/Switch1' incorporates:
       *  Constant: '<Root>/Constant2'
       */
      Sensors_and_actuators_ball_an_B.Switch1 =
        Sensors_and_actuators_ball_an_P.Constant2_Value;
    } else {
      /* Switch: '<Root>/Switch1' */
      Sensors_and_actuators_ball_an_B.Switch1 =
        Sensors_and_actuators_ball_an_B.Integrator1_h;
    }

    Sensors_and_actuators_ball_an_B.Switch4 =
      Sensors_and_actuators_ball_an_B.Switch1;
  }

  /* End of Switch: '<Root>/Switch4' */

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Saturate: '<S14>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Switch4;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat_a;
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat_g;
  if (C1 > UnitZp_idx_0) {
    Sensors_and_actuators_ball_an_B.Saturation_l = UnitZp_idx_0;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation_l = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation_l = C1;
  }

  /* End of Saturate: '<S14>/Saturation' */

  /* Gain: '<S14>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V_a =
    Sensors_and_actuators_ball_an_P.Current2V_Gain_l *
    Sensors_and_actuators_ball_an_B.Saturation_l;

  /* Gain: '<S14>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale_a =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain_j *
    Sensors_and_actuators_ball_an_B.Current2V_a;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S72>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 2 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) Sensors_and_actuators_ball_an_B.DSPscale_a;

      /* write value of CL1 DAC for output channel 2 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_2,
        DAC_CLASS1_CHANNEL_2, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_2);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Sum: '<Root>/Add7' incorporates:
   *  Constant: '<Root>/Constant14'
   */
  Sensors_and_actuators_ball_an_B.Add7 = Sensors_and_actuators_ball_an_B.motor3
    - Sensors_and_actuators_ball_an_P.Constant14_Value;

  /* Gain: '<Root>/GainC' */
  Sensors_and_actuators_ball_an_B.GainC =
    Sensors_and_actuators_ball_an_P.GainC_Gain *
    Sensors_and_actuators_ball_an_B.Add7;

  /* Sum: '<Root>/Sum3' */
  Sensors_and_actuators_ball_an_B.Sum3 = Sensors_and_actuators_ball_an_B.GainC -
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction4.y;

  /* Gain: '<S6>/Gain' */
  Sensors_and_actuators_ball_an_B.Gain_k =
    Sensors_and_actuators_ball_an_P.Gain_Gain_lq *
    Sensors_and_actuators_ball_an_B.Sum3;

  /* TransferFcn: '<S6>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter_f = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter_f +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_C_d *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_d;
  Sensors_and_actuators_ball_an_B.LeadlagFilter_f +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_D_j *
    Sensors_and_actuators_ball_an_B.Gain_k;

  /* TransferFcn: '<S6>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_l = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_l +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_C_j *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_a;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_l +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_D_b *
    Sensors_and_actuators_ball_an_B.LeadlagFilter_f;

  /* Integrator: '<S6>/Integrator1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_m,
                       (Sensors_and_actuators_ball_an_P.Constant_Value_dy));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i =
        Sensors_and_actuators_ball_an_P.Integrator1_IC_m;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i >=
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_e) {
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i =
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_e;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i <=
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_g) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i =
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_g;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator1_j =
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i;

  /* End of Integrator: '<S6>/Integrator1' */

  /* Switch: '<Root>/Switch6' incorporates:
   *  Inport: '<Root>/CloseLoop_disable2'
   *  Inport: '<Root>/controller_disable2'
   *  Switch: '<Root>/Switch5'
   */
  if (Sensors_and_actuators_ball_an_U.CloseLoop_disable2 >=
      Sensors_and_actuators_ball_an_P.Switch6_Threshold) {
    Sensors_and_actuators_ball_an_B.Switch6 =
      Sensors_and_actuators_ball_an_B.TransferFcn;
  } else {
    if (Sensors_and_actuators_ball_an_U.controller_disable2 >=
        Sensors_and_actuators_ball_an_P.Switch5_Threshold) {
      /* Switch: '<Root>/Switch5' incorporates:
       *  Constant: '<Root>/Constant3'
       */
      Sensors_and_actuators_ball_an_B.Switch5 =
        Sensors_and_actuators_ball_an_P.Constant3_Value;
    } else {
      /* Sum: '<S6>/Sum' incorporates:
       *  Switch: '<Root>/Switch5'
       */
      Sensors_and_actuators_ball_an_B.Sum_ao =
        Sensors_and_actuators_ball_an_B.LeadlagFilter2_l +
        Sensors_and_actuators_ball_an_B.Integrator1_j;

      /* Switch: '<Root>/Switch5' */
      Sensors_and_actuators_ball_an_B.Switch5 =
        Sensors_and_actuators_ball_an_B.Sum_ao;
    }

    Sensors_and_actuators_ball_an_B.Switch6 =
      Sensors_and_actuators_ball_an_B.Switch5;
  }

  /* End of Switch: '<Root>/Switch6' */

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */

  /* Saturate: '<S15>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Switch6;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat_m;
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat_j;
  if (C1 > UnitZp_idx_0) {
    Sensors_and_actuators_ball_an_B.Saturation = UnitZp_idx_0;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation = C1;
  }

  /* End of Saturate: '<S15>/Saturation' */

  /* Gain: '<S15>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V =
    Sensors_and_actuators_ball_an_P.Current2V_Gain_j *
    Sensors_and_actuators_ball_an_B.Saturation;

  /* Gain: '<S15>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain_h *
    Sensors_and_actuators_ball_an_B.Current2V;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S73>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
    /* --- [RTI120X, DAC C1] - Channel: 3 --- */
    {
      /* define variables required for DAC realtime functions */
      Float64 inportDacData= 0.0;
      inportDacData = (real_T) Sensors_and_actuators_ball_an_B.DSPscale;

      /* write value of CL1 DAC for output channel 3 */
      DacCl1AnalogOut_setOutputValue(pRTIDacC1AnalogOut_Ch_3,
        DAC_CLASS1_CHANNEL_3, inportDacData);
      DacCl1AnalogOut_write(pRTIDacC1AnalogOut_Ch_3);
    }
  }

  /* End of Outputs for SubSystem: '<Root>/Outputs to Amplifier2' */

  /* Sum: '<Root>/Add6' incorporates:
   *  Constant: '<Root>/Constant14'
   */
  Sensors_and_actuators_ball_an_B.Add6 = Sensors_and_actuators_ball_an_B.motor2
    - Sensors_and_actuators_ball_an_P.Constant14_Value;

  /* Gain: '<Root>/GainB' */
  Sensors_and_actuators_ball_an_B.GainB =
    Sensors_and_actuators_ball_an_P.GainB_Gain *
    Sensors_and_actuators_ball_an_B.Add6;

  /* Gain: '<S4>/Integrator Gain' */
  Sensors_and_actuators_ball_an_B.IntegratorGain =
    Sensors_and_actuators_ball_an_P.IntegratorGain_Gain *
    Sensors_and_actuators_ball_an_B.LeadlagFilter2;

  /* Gain: '<S6>/Integrator Gain' */
  Sensors_and_actuators_ball_an_B.IntegratorGain_l =
    Sensors_and_actuators_ball_an_P.IntegratorGain_Gain_d *
    Sensors_and_actuators_ball_an_B.LeadlagFilter2_l;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* DataTypeConversion: '<S63>/Conversion' incorporates:
     *  Constant: '<S20>/KalmanGainL'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainL_Value[0], sizeof(real_T)
           << 3U);

    /* DataTypeConversion: '<S64>/Conversion' incorporates:
     *  Constant: '<S20>/KalmanGainM'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_c[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainM_Value[0], sizeof(real_T)
           << 3U);

    /* DataTypeConversion: '<S65>/Conversion' */
    Sensors_and_actuators_ball_an_B.Conversion_h = 0.0;

    /* DataTypeConversion: '<S66>/Conversion' incorporates:
     *  Constant: '<S20>/CovarianceZ'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_k[0],
           &Sensors_and_actuators_ball_an_P.CovarianceZ_Value[0], sizeof(real_T)
           << 4U);

    /* DataTypeConversion: '<S31>/Conversion' incorporates:
     *  Constant: '<S7>/P0'
     */
    for (i = 0; i < 16; i++) {
      Sensors_and_actuators_ball_an_B.Conversion_i[i] = (real32_T)
        Sensors_and_actuators_ball_an_P.P0_Value[i];
    }

    /* End of DataTypeConversion: '<S31>/Conversion' */
  }

  /* DataTypeConversion: '<S36>/Conversion' */
  Sensors_and_actuators_ball_an_B.Conversion_a[0] =
    Sensors_and_actuators_ball_an_B.MemoryX[0];
  Sensors_and_actuators_ball_an_B.Conversion_a[1] =
    Sensors_and_actuators_ball_an_B.MemoryX[1];
  Sensors_and_actuators_ball_an_B.Conversion_a[2] =
    Sensors_and_actuators_ball_an_B.MemoryX[2];
  Sensors_and_actuators_ball_an_B.Conversion_a[3] =
    Sensors_and_actuators_ball_an_B.MemoryX[3];

  /* Product: '<S40>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S7>/A'
   */
  tmp_1 = &Sensors_and_actuators_ball_an_P.A_Value[0];
  tmp[0] = Sensors_and_actuators_ball_an_B.Conversion_a[0];
  tmp[1] = Sensors_and_actuators_ball_an_B.Conversion_a[1];
  tmp[2] = Sensors_and_actuators_ball_an_B.Conversion_a[2];
  tmp[3] = Sensors_and_actuators_ball_an_B.Conversion_a[3];
  for (i = 0; i < 4; i++) {
    C1 = tmp_1[i] * tmp[0];
    C1 += tmp_1[i + 4] * tmp[1];
    C1 += tmp_1[i + 8] * tmp[2];
    C1 += tmp_1[i + 12] * tmp[3];
    Sensors_and_actuators_ball_an_B.Akxhatkk1[i] = C1;
  }

  /* End of Product: '<S40>/A[k]*xhat[k|k-1]' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Reshape: '<S7>/Reshapeu' incorporates:
     *  Outport: '<Root>/measured_theta1'
     *  Outport: '<Root>/measured_theta2'
     */
    Sensors_and_actuators_ball_an_B.Reshapeu[0] =
      Sensors_and_actuators_ball_an_Y.measured_theta1;
    Sensors_and_actuators_ball_an_B.Reshapeu[1] =
      Sensors_and_actuators_ball_an_Y.measured_theta2;
  }

  /* Outputs for Enabled SubSystem: '<S40>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S69>/Enable'
   */
  /* Product: '<S40>/B[k]*u[k]' incorporates:
   *  Constant: '<S7>/B'
   *  Product: '<S69>/C[k]*xhat[k|k-1]'
   *  Product: '<S69>/Product3'
   */
  tmp_1 = &Sensors_and_actuators_ball_an_P.B_Value[0];

  /* End of Outputs for SubSystem: '<S40>/MeasurementUpdate' */
  tmp_0[0] = Sensors_and_actuators_ball_an_B.Reshapeu[0];
  tmp_0[1] = Sensors_and_actuators_ball_an_B.Reshapeu[1];
  for (i = 0; i < 4; i++) {
    C1 = tmp_1[i] * tmp_0[0];
    C1 += tmp_1[i + 4] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Bkuk[i] = C1;
  }

  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Reshape: '<S7>/Reshapey' incorporates:
     *  Outport: '<Root>/Xpos_m'
     *  Outport: '<Root>/Ypos_m'
     */
    Sensors_and_actuators_ball_an_B.Reshapey[0] =
      Sensors_and_actuators_ball_an_Y.Xpos_m;
    Sensors_and_actuators_ball_an_B.Reshapey[1] =
      Sensors_and_actuators_ball_an_Y.Ypos_m;

    /* Outputs for Enabled SubSystem: '<S40>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S69>/Enable'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Constant: '<S7>/Enable' */
      if (Sensors_and_actuators_ball_an_P.Enable_Value) {
        Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = true;
      } else {
        if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE) {
          /* Disable for Outport: '<S69>/L*(y[k]-yhat[k|k-1])' */
          Sensors_and_actuators_ball_an_B.Product3[0] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3[1] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3[2] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3[3] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = false;
        }
      }

      /* End of Constant: '<S7>/Enable' */
    }

    /* End of Outputs for SubSystem: '<S40>/MeasurementUpdate' */
  }

  /* Outputs for Enabled SubSystem: '<S40>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S69>/Enable'
   */
  if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE) {
    /* Product: '<S69>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S7>/C'
     *  Product: '<S40>/B[k]*u[k]'
     *  Product: '<S69>/Product3'
     */
    tmp_1 = &Sensors_and_actuators_ball_an_P.C_Value[0];
    tmp[0] = Sensors_and_actuators_ball_an_B.Conversion_a[0];
    tmp[1] = Sensors_and_actuators_ball_an_B.Conversion_a[1];
    tmp[2] = Sensors_and_actuators_ball_an_B.Conversion_a[2];
    tmp[3] = Sensors_and_actuators_ball_an_B.Conversion_a[3];
    for (i = 0; i < 2; i++) {
      C1 = tmp_1[i] * tmp[0];
      C1 += tmp_1[i + 2] * tmp[1];
      C1 += tmp_1[i + 4] * tmp[2];
      C1 += tmp_1[i + 6] * tmp[3];
      Sensors_and_actuators_ball_an_B.Ckxhatkk1[i] = C1;
    }

    /* Product: '<S69>/D[k]*u[k]' incorporates:
     *  Constant: '<S7>/D'
     */
    tmp[0] = Sensors_and_actuators_ball_an_P.D_Value[0];
    tmp[1] = Sensors_and_actuators_ball_an_P.D_Value[1];
    tmp[2] = Sensors_and_actuators_ball_an_P.D_Value[2];
    tmp[3] = Sensors_and_actuators_ball_an_P.D_Value[3];
    tmp_0[0] = Sensors_and_actuators_ball_an_B.Reshapeu[0];
    tmp_0[1] = Sensors_and_actuators_ball_an_B.Reshapeu[1];
    C1 = tmp[0] * tmp_0[0];
    C1 += tmp[2] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Dkuk[0] = C1;

    /* Sum: '<S69>/Add1' */
    Sensors_and_actuators_ball_an_B.yhatkk1[0] =
      Sensors_and_actuators_ball_an_B.Ckxhatkk1[0] +
      Sensors_and_actuators_ball_an_B.Dkuk[0];

    /* Sum: '<S69>/Sum' */
    Sensors_and_actuators_ball_an_B.Sum_n[0] =
      Sensors_and_actuators_ball_an_B.Reshapey[0] -
      Sensors_and_actuators_ball_an_B.yhatkk1[0];

    /* Product: '<S69>/D[k]*u[k]' */
    C1 = tmp[1] * tmp_0[0];
    C1 += tmp[3] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Dkuk[1] = C1;

    /* Sum: '<S69>/Add1' */
    Sensors_and_actuators_ball_an_B.yhatkk1[1] =
      Sensors_and_actuators_ball_an_B.Ckxhatkk1[1] +
      Sensors_and_actuators_ball_an_B.Dkuk[1];

    /* Sum: '<S69>/Sum' */
    Sensors_and_actuators_ball_an_B.Sum_n[1] =
      Sensors_and_actuators_ball_an_B.Reshapey[1] -
      Sensors_and_actuators_ball_an_B.yhatkk1[1];

    /* Product: '<S69>/Product3' incorporates:
     *  Product: '<S40>/B[k]*u[k]'
     *  Product: '<S69>/C[k]*xhat[k|k-1]'
     */
    tmp_1 = &Sensors_and_actuators_ball_an_B.Conversion[0];
    tmp_0[0] = Sensors_and_actuators_ball_an_B.Sum_n[0];
    tmp_0[1] = Sensors_and_actuators_ball_an_B.Sum_n[1];
    for (i = 0; i < 4; i++) {
      C1 = tmp_1[i] * tmp_0[0];
      C1 += tmp_1[i + 4] * tmp_0[1];
      Sensors_and_actuators_ball_an_B.Product3[i] = C1;
    }
  }

  /* End of Outputs for SubSystem: '<S40>/MeasurementUpdate' */

  /* Sum: '<S40>/Add' */
  Sensors_and_actuators_ball_an_B.Add[0] =
    (Sensors_and_actuators_ball_an_B.Bkuk[0] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[0]) +
    Sensors_and_actuators_ball_an_B.Product3[0];
  Sensors_and_actuators_ball_an_B.Add[1] =
    (Sensors_and_actuators_ball_an_B.Bkuk[1] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[1]) +
    Sensors_and_actuators_ball_an_B.Product3[1];
  Sensors_and_actuators_ball_an_B.Add[2] =
    (Sensors_and_actuators_ball_an_B.Bkuk[2] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[2]) +
    Sensors_and_actuators_ball_an_B.Product3[2];
  Sensors_and_actuators_ball_an_B.Add[3] =
    (Sensors_and_actuators_ball_an_B.Bkuk[3] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[3]) +
    Sensors_and_actuators_ball_an_B.Product3[3];

  /* Reshape: '<S40>/Reshape' */
  Sensors_and_actuators_ball_an_B.Reshape[0] =
    Sensors_and_actuators_ball_an_B.Add[0];
  Sensors_and_actuators_ball_an_B.Reshape[1] =
    Sensors_and_actuators_ball_an_B.Add[1];
  Sensors_and_actuators_ball_an_B.Reshape[2] =
    Sensors_and_actuators_ball_an_B.Add[2];
  Sensors_and_actuators_ball_an_B.Reshape[3] =
    Sensors_and_actuators_ball_an_B.Add[3];

  /* Sum: '<Root>/Sum2' */
  Sensors_and_actuators_ball_an_B.Sum2 = Sensors_and_actuators_ball_an_B.GainB -
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction2.y;

  /* TransferFcn: '<Root>/Transfer Fcn1' */
  Sensors_and_actuators_ball_an_B.TransferFcn1 = 0.0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  Sensors_and_actuators_ball_an_B.TransferFcn1 += C1 *
    Sensors_and_actuators_ball_an_B.Sum2;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[1] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  S1 = C1 - UnitZp_idx_0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[2] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  C1 -= UnitZp_idx_0;
  Sensors_and_actuators_ball_an_B.TransferFcn1 += S1 *
    Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[0];
  Sensors_and_actuators_ball_an_B.TransferFcn1 += C1 *
    Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[1];

  /* Integrator: '<Root>/Integrator2' incorporates:
   *  Inport: '<Root>/reser_integrator'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator2_Reset_ZCE,
                       (Sensors_and_actuators_ball_an_U.reser_integrator));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator2_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator2_IC;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator2_CSTATE >=
      Sensors_and_actuators_ball_an_P.Integrator2_UpperSat) {
    Sensors_and_actuators_ball_an_X.Integrator2_CSTATE =
      Sensors_and_actuators_ball_an_P.Integrator2_UpperSat;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator2_CSTATE <=
        Sensors_and_actuators_ball_an_P.Integrator2_LowerSat) {
      Sensors_and_actuators_ball_an_X.Integrator2_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator2_LowerSat;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator2 =
    Sensors_and_actuators_ball_an_X.Integrator2_CSTATE;

  /* End of Integrator: '<Root>/Integrator2' */

  /* TransferFcn: '<Root>/Transfer Fcn2' */
  Sensors_and_actuators_ball_an_B.TransferFcn2 = 0.0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  Sensors_and_actuators_ball_an_B.TransferFcn2 += C1 * 0.0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[1] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  S1 = C1 - UnitZp_idx_0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[2] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  C1 -= UnitZp_idx_0;
  Sensors_and_actuators_ball_an_B.TransferFcn2 += S1 *
    Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[0];
  Sensors_and_actuators_ball_an_B.TransferFcn2 += C1 *
    Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[1];

  /* Integrator: '<Root>/Integrator3' incorporates:
   *  Inport: '<Root>/reser_integrator2'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator3_Reset_ZCE,
                       (Sensors_and_actuators_ball_an_U.reser_integrator2));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator3_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator3_IC;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator3_CSTATE >=
      Sensors_and_actuators_ball_an_P.Integrator3_UpperSat) {
    Sensors_and_actuators_ball_an_X.Integrator3_CSTATE =
      Sensors_and_actuators_ball_an_P.Integrator3_UpperSat;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator3_CSTATE <=
        Sensors_and_actuators_ball_an_P.Integrator3_LowerSat) {
      Sensors_and_actuators_ball_an_X.Integrator3_CSTATE =
        Sensors_and_actuators_ball_an_P.Integrator3_LowerSat;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator3 =
    Sensors_and_actuators_ball_an_X.Integrator3_CSTATE;

  /* End of Integrator: '<Root>/Integrator3' */

  /* TransferFcn: '<Root>/Transfer Fcn3' */
  Sensors_and_actuators_ball_an_B.TransferFcn3 = 0.0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  Sensors_and_actuators_ball_an_B.TransferFcn3 += C1 * 0.0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[1] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  S1 = C1 - UnitZp_idx_0;
  C1 = Sensors_and_actuators_ball_an_P.numc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  UnitZp_idx_0 = Sensors_and_actuators_ball_an_P.numc_mi[0] /
    Sensors_and_actuators_ball_an_P.denc_mi[0] *
    (Sensors_and_actuators_ball_an_P.denc_mi[2] /
     Sensors_and_actuators_ball_an_P.denc_mi[0]);
  C1 -= UnitZp_idx_0;
  Sensors_and_actuators_ball_an_B.TransferFcn3 += S1 *
    Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[0];
  Sensors_and_actuators_ball_an_B.TransferFcn3 += C1 *
    Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[1];
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S1>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Sensors_and_actuators_ball_and_plate/ETHERNET_SETUP_BL1 --- */
    /* dSPACE I/O Board DSETHERNET #1 Unit:SETUP Group:SETUP */
    {
      /* returns the link state of the ethernet connection. Number of available connectors: uint32_T) */
      Sensors_and_actuators_ball_an_B.SFunction1_o1_h[0] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 0);
      Sensors_and_actuators_ball_an_B.SFunction1_o1_h[1] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 1);
      Sensors_and_actuators_ball_an_B.SFunction1_o1_h[2] = (uint32_T)
        DsIoEth_getLinkState((UInt32) 2);

      /* returns the current IP address of the ethernet interface */
      *((UInt32*) (&Sensors_and_actuators_ball_an_B.SFunction1_o2_m[0])) =
        DsIoEth_getIpAddress();
    }

    /* Gain: '<S5>/Gain' */
    Sensors_and_actuators_ball_an_B.Gain_c =
      Sensors_and_actuators_ball_an_P.Gain_Gain_k * 0.0;
  }

  /* TransferFcn: '<S5>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter_j = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter_j +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_C_e *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_l;
  Sensors_and_actuators_ball_an_B.LeadlagFilter_j +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_D_k *
    Sensors_and_actuators_ball_an_B.Gain_c;

  /* TransferFcn: '<S5>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_n = 0.0;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_n +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_C_h *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_h;
  Sensors_and_actuators_ball_an_B.LeadlagFilter2_n +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_D_i *
    Sensors_and_actuators_ball_an_B.LeadlagFilter_j;

  /* Gain: '<S5>/Integrator Gain' */
  Sensors_and_actuators_ball_an_B.IntegratorGain_j =
    Sensors_and_actuators_ball_an_P.IntegratorGain_Gain_i *
    Sensors_and_actuators_ball_an_B.LeadlagFilter2_n;

  /* Integrator: '<S5>/Integrator1' incorporates:
   *  Constant: '<S5>/Constant'
   */
  /* Limited  Integrator  */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_l,
                       (Sensors_and_actuators_ball_an_P.Constant_Value_ar));
    zcEvent_0 = (zcEvent != NO_ZCEVENT);

    /* evaluate zero-crossings */
    if (zcEvent_0) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c =
        Sensors_and_actuators_ball_an_P.Integrator1_IC_k;
    }
  }

  if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c >=
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_f) {
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c =
      Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_f;
  } else {
    if (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c <=
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_i) {
      Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c =
        Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_i;
    }
  }

  Sensors_and_actuators_ball_an_B.Integrator1_l =
    Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c;

  /* End of Integrator: '<S5>/Integrator1' */

  /* Sum: '<S5>/Sum' */
  Sensors_and_actuators_ball_an_B.Sum_a =
    Sensors_and_actuators_ball_an_B.LeadlagFilter2_n +
    Sensors_and_actuators_ball_an_B.Integrator1_l;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S3>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* --- Sensors_and_actuators_ball_and_plate/ETHERNET_UDP_SETUP_BL1: ==> Socket ID = (0) --- */
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
void Sensors_and_actuators_ball_and_plate_update(void)
{
  /* Update for Integrator: '<S7>/MemoryX' */
  Sensors_and_actuators_ball_a_DW.MemoryX_IWORK = 0;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    rt_ertODEUpdateContinuousStates(&Sensors_and_actuators_ball_a_M->solverInfo);
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
  if (!(++Sensors_and_actuators_ball_a_M->Timing.clockTick0)) {
    ++Sensors_and_actuators_ball_a_M->Timing.clockTickH0;
  }

  Sensors_and_actuators_ball_a_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Sensors_and_actuators_ball_a_M->solverInfo);

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
    Sensors_and_actuators_ball_a_M->Timing.clockTick1++;
    if (!Sensors_and_actuators_ball_a_M->Timing.clockTick1) {
      Sensors_and_actuators_ball_a_M->Timing.clockTickH1++;
    }
  }
}

/* Derivatives for root system: '<Root>' */
void Sensors_and_actuators_ball_and_plate_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  real_T A;
  XDot_Sensors_and_actuators_ba_T *_rtXdot;
  _rtXdot = ((XDot_Sensors_and_actuators_ba_T *)
             Sensors_and_actuators_ball_a_M->derivs);

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Derivatives for TransferFcn: '<S76>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = 0.0;
  _rtXdot->TransferFcn_CSTATE_b += Sensors_and_actuators_ball_an_P.TransferFcn_A
    * Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Derivatives for TransferFcn: '<S81>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_k = 0.0;
  _rtXdot->TransferFcn_CSTATE_k +=
    Sensors_and_actuators_ball_an_P.TransferFcn_A_b *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k;
  _rtXdot->TransferFcn_CSTATE_k +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem_h.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement1' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Derivatives for TransferFcn: '<S86>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Sensors_and_actuators_ball_an_P.TransferFcn_A_p
    * Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem_c.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement2' */

  /* Derivatives for Integrator: '<S7>/MemoryX' */
  _rtXdot->MemoryX_CSTATE[0] = Sensors_and_actuators_ball_an_B.Reshape[0];
  _rtXdot->MemoryX_CSTATE[1] = Sensors_and_actuators_ball_an_B.Reshape[1];
  _rtXdot->MemoryX_CSTATE[2] = Sensors_and_actuators_ball_an_B.Reshape[2];
  _rtXdot->MemoryX_CSTATE[3] = Sensors_and_actuators_ball_an_B.Reshape[3];

  /* Derivatives for TransferFcn: '<S4>/LeadlagFilter' */
  _rtXdot->LeadlagFilter_CSTATE = 0.0;
  _rtXdot->LeadlagFilter_CSTATE +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_A *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE;
  _rtXdot->LeadlagFilter_CSTATE += Sensors_and_actuators_ball_an_B.Gain_n;

  /* Derivatives for TransferFcn: '<S4>/LeadlagFilter2' */
  _rtXdot->LeadlagFilter2_CSTATE = 0.0;
  _rtXdot->LeadlagFilter2_CSTATE +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_A *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE;
  _rtXdot->LeadlagFilter2_CSTATE +=
    Sensors_and_actuators_ball_an_B.LeadlagFilter;

  /* Derivatives for Integrator: '<S4>/Integrator1' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE <=
          Sensors_and_actuators_ball_an_P.Integrator1_LowerSat);
  usat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE >=
          Sensors_and_actuators_ball_an_P.Integrator1_UpperSat);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain < 0.0))) {
    _rtXdot->Integrator1_CSTATE = Sensors_and_actuators_ball_an_B.IntegratorGain;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S4>/Integrator1' */

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l <=
          Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_p);
  usat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l >=
          Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_l);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn1 > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn1 < 0.0))) {
    _rtXdot->Integrator1_CSTATE_l = Sensors_and_actuators_ball_an_B.TransferFcn1;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_l = 0.0;
  }

  /* End of Derivatives for Integrator: '<Root>/Integrator1' */

  /* Derivatives for TransferFcn: '<S6>/LeadlagFilter' */
  _rtXdot->LeadlagFilter_CSTATE_d = 0.0;
  _rtXdot->LeadlagFilter_CSTATE_d +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_A_k *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_d;
  _rtXdot->LeadlagFilter_CSTATE_d += Sensors_and_actuators_ball_an_B.Gain_k;

  /* Derivatives for TransferFcn: '<S6>/LeadlagFilter2' */
  _rtXdot->LeadlagFilter2_CSTATE_a = 0.0;
  _rtXdot->LeadlagFilter2_CSTATE_a +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_A_l *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_a;
  _rtXdot->LeadlagFilter2_CSTATE_a +=
    Sensors_and_actuators_ball_an_B.LeadlagFilter_f;

  /* Derivatives for Integrator: '<S6>/Integrator1' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i <=
          Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_g);
  usat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i >=
          Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_e);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain_l > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain_l < 0.0))) {
    _rtXdot->Integrator1_CSTATE_i =
      Sensors_and_actuators_ball_an_B.IntegratorGain_l;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_i = 0.0;
  }

  /* End of Derivatives for Integrator: '<S6>/Integrator1' */

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE[0] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn1_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[1] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn1_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[1];
  _rtXdot->TransferFcn1_CSTATE[1] +=
    Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[0];
  _rtXdot->TransferFcn1_CSTATE[0] += Sensors_and_actuators_ball_an_B.Sum2;

  /* Derivatives for Integrator: '<Root>/Integrator2' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator2_CSTATE <=
          Sensors_and_actuators_ball_an_P.Integrator2_LowerSat);
  usat = (Sensors_and_actuators_ball_an_X.Integrator2_CSTATE >=
          Sensors_and_actuators_ball_an_P.Integrator2_UpperSat);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn2 > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn2 < 0.0))) {
    _rtXdot->Integrator2_CSTATE = Sensors_and_actuators_ball_an_B.TransferFcn2;
  } else {
    /* in saturation */
    _rtXdot->Integrator2_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<Root>/Integrator2' */

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn2' */
  _rtXdot->TransferFcn2_CSTATE[0] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn2_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[0];
  _rtXdot->TransferFcn2_CSTATE[1] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn2_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[1];
  _rtXdot->TransferFcn2_CSTATE[1] +=
    Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[0];

  /* Derivatives for Integrator: '<Root>/Integrator3' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator3_CSTATE <=
          Sensors_and_actuators_ball_an_P.Integrator3_LowerSat);
  usat = (Sensors_and_actuators_ball_an_X.Integrator3_CSTATE >=
          Sensors_and_actuators_ball_an_P.Integrator3_UpperSat);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn3 > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.TransferFcn3 < 0.0))) {
    _rtXdot->Integrator3_CSTATE = Sensors_and_actuators_ball_an_B.TransferFcn3;
  } else {
    /* in saturation */
    _rtXdot->Integrator3_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<Root>/Integrator3' */

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn3' */
  _rtXdot->TransferFcn3_CSTATE[0] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[1] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn3_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[0];
  _rtXdot->TransferFcn3_CSTATE[1] = 0.0;
  A = -Sensors_and_actuators_ball_an_P.denc_mi[2] /
    Sensors_and_actuators_ball_an_P.denc_mi[0];
  _rtXdot->TransferFcn3_CSTATE[0] += A *
    Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[1];
  _rtXdot->TransferFcn3_CSTATE[1] +=
    Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[0];

  /* Derivatives for TransferFcn: '<S5>/LeadlagFilter' */
  _rtXdot->LeadlagFilter_CSTATE_l = 0.0;
  _rtXdot->LeadlagFilter_CSTATE_l +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter_A_g *
    Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_l;
  _rtXdot->LeadlagFilter_CSTATE_l += Sensors_and_actuators_ball_an_B.Gain_c;

  /* Derivatives for TransferFcn: '<S5>/LeadlagFilter2' */
  _rtXdot->LeadlagFilter2_CSTATE_h = 0.0;
  _rtXdot->LeadlagFilter2_CSTATE_h +=
    Sensors_and_actuators_ball_an_P.LeadlagFilter2_A_k *
    Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_h;
  _rtXdot->LeadlagFilter2_CSTATE_h +=
    Sensors_and_actuators_ball_an_B.LeadlagFilter_j;

  /* Derivatives for Integrator: '<S5>/Integrator1' */
  lsat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c <=
          Sensors_and_actuators_ball_an_P.Integrator1_LowerSat_i);
  usat = (Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c >=
          Sensors_and_actuators_ball_an_P.Integrator1_UpperSat_f);
  if (((!lsat) && (!usat)) || (lsat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain_j > 0.0)) || (usat &&
       (Sensors_and_actuators_ball_an_B.IntegratorGain_j < 0.0))) {
    _rtXdot->Integrator1_CSTATE_c =
      Sensors_and_actuators_ball_an_B.IntegratorGain_j;
  } else {
    /* in saturation */
    _rtXdot->Integrator1_CSTATE_c = 0.0;
  }

  /* End of Derivatives for Integrator: '<S5>/Integrator1' */
}

/* Model initialize function */
void Sensors_and_actuators_ball_and_plate_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Sensors_and_actuators_ball_a_M, 0,
                sizeof(RT_MODEL_Sensors_and_actuator_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
                          &Sensors_and_actuators_ball_a_M->Timing.simTimeStep);
    rtsiSetTPtr(&Sensors_and_actuators_ball_a_M->solverInfo, &rtmGetTPtr
                (Sensors_and_actuators_ball_a_M));
    rtsiSetStepSizePtr(&Sensors_and_actuators_ball_a_M->solverInfo,
                       &Sensors_and_actuators_ball_a_M->Timing.stepSize0);
    rtsiSetdXPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
                 &Sensors_and_actuators_ball_a_M->derivs);
    rtsiSetContStatesPtr(&Sensors_and_actuators_ball_a_M->solverInfo, (real_T **)
                         &Sensors_and_actuators_ball_a_M->contStates);
    rtsiSetNumContStatesPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
      &Sensors_and_actuators_ball_a_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
      &Sensors_and_actuators_ball_a_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&Sensors_and_actuators_ball_a_M->solverInfo,
       &Sensors_and_actuators_ball_a_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&Sensors_and_actuators_ball_a_M->solverInfo,
       &Sensors_and_actuators_ball_a_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
                          (&rtmGetErrorStatus(Sensors_and_actuators_ball_a_M)));
    rtsiSetRTModelPtr(&Sensors_and_actuators_ball_a_M->solverInfo,
                      Sensors_and_actuators_ball_a_M);
  }

  rtsiSetSimTimeStep(&Sensors_and_actuators_ball_a_M->solverInfo,
                     MAJOR_TIME_STEP);
  Sensors_and_actuators_ball_a_M->intgData.f[0] =
    Sensors_and_actuators_ball_a_M->odeF[0];
  Sensors_and_actuators_ball_a_M->contStates = ((X_Sensors_and_actuators_ball__T
    *) &Sensors_and_actuators_ball_an_X);
  rtsiSetSolverData(&Sensors_and_actuators_ball_a_M->solverInfo, (void *)
                    &Sensors_and_actuators_ball_a_M->intgData);
  rtsiSetSolverName(&Sensors_and_actuators_ball_a_M->solverInfo,"ode1");
  rtmSetTPtr(Sensors_and_actuators_ball_a_M,
             &Sensors_and_actuators_ball_a_M->Timing.tArray[0]);
  Sensors_and_actuators_ball_a_M->Timing.stepSize0 = 0.001;
  rtmSetFirstInitCond(Sensors_and_actuators_ball_a_M, 1);

  /* block I/O */
  (void) memset(((void *) &Sensors_and_actuators_ball_an_B), 0,
                sizeof(B_Sensors_and_actuators_ball__T));

  /* states (continuous) */
  {
    (void) memset((void *)&Sensors_and_actuators_ball_an_X, 0,
                  sizeof(X_Sensors_and_actuators_ball__T));
  }

  /* states (dwork) */
  (void) memset((void *)&Sensors_and_actuators_ball_a_DW, 0,
                sizeof(DW_Sensors_and_actuators_ball_T));

  /* external inputs */
  (void)memset(&Sensors_and_actuators_ball_an_U, 0, sizeof
               (ExtU_Sensors_and_actuators_ba_T));

  /* external outputs */
  (void) memset((void *)&Sensors_and_actuators_ball_an_Y, 0,
                sizeof(ExtY_Sensors_and_actuators_ba_T));

  {
    /* user code (registration function declaration) */
    /*Initialize global TRC pointers. */
    Sensors_and_actuators_ball_and_plate_rti_init_trc_pointers();
  }

  /* Start for Enabled SubSystem: '<S76>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S76>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S76>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1);

  /* End of Start for SubSystem: '<S76>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement' */

  /* Start for Enabled SubSystem: '<S81>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem_h);

  /* End of Start for SubSystem: '<S81>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S81>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_m);

  /* End of Start for SubSystem: '<S81>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement1' */

  /* Start for Enabled SubSystem: '<S86>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem_c);

  /* End of Start for SubSystem: '<S86>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S86>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_j);

  /* End of Start for SubSystem: '<S86>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement2' */

  /* Start for Enabled SubSystem: '<S40>/MeasurementUpdate' */
  Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S40>/MeasurementUpdate' */
  Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.Integrator2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.Integrator3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.Integrator1_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o = POS_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n = POS_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC = POS_ZCSIG;

  /* InitializeConditions for Integrator: '<S7>/MemoryX' */
  if (rtmIsFirstInitCond(Sensors_and_actuators_ball_a_M)) {
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[0] = 0.0;
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[1] = 0.0;
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[2] = 0.0;
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[3] = 0.0;
  }

  Sensors_and_actuators_ball_a_DW.MemoryX_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S7>/MemoryX' */

  /* InitializeConditions for TransferFcn: '<S4>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S4>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<S4>/Integrator1' */
  Sensors_and_actuators_ball_an_X.Integrator1_CSTATE =
    Sensors_and_actuators_ball_an_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_l =
    Sensors_and_actuators_ball_an_P.Integrator1_IC_i;

  /* InitializeConditions for TransferFcn: '<S6>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_d = 0.0;

  /* InitializeConditions for TransferFcn: '<S6>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_a = 0.0;

  /* InitializeConditions for Integrator: '<S6>/Integrator1' */
  Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_i =
    Sensors_and_actuators_ball_an_P.Integrator1_IC_m;

  /* InitializeConditions for Integrator: '<Root>/Integrator2' */
  Sensors_and_actuators_ball_an_X.Integrator2_CSTATE =
    Sensors_and_actuators_ball_an_P.Integrator2_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator3' */
  Sensors_and_actuators_ball_an_X.Integrator3_CSTATE =
    Sensors_and_actuators_ball_an_P.Integrator3_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[0] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn1' */
  Sensors_and_actuators_ball_an_X.TransferFcn1_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn2' */
  Sensors_and_actuators_ball_an_X.TransferFcn2_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn3' */
  Sensors_and_actuators_ball_an_X.TransferFcn3_CSTATE[1] = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/LeadlagFilter' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter_CSTATE_l = 0.0;

  /* InitializeConditions for TransferFcn: '<S5>/LeadlagFilter2' */
  Sensors_and_actuators_ball_an_X.LeadlagFilter2_CSTATE_h = 0.0;

  /* InitializeConditions for Integrator: '<S5>/Integrator1' */
  Sensors_and_actuators_ball_an_X.Integrator1_CSTATE_c =
    Sensors_and_actuators_ball_an_P.Integrator1_IC_k;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement' */
  /* InitializeConditions for TransferFcn: '<S76>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S76>/Enabled Subsystem' */
  Sensors_a_EnabledSubsystem_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem);

  /* End of SystemInitialize for SubSystem: '<S76>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S76>/Enabled Subsystem1' */
  Sensors__EnabledSubsystem1_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem1);

  /* End of SystemInitialize for SubSystem: '<S76>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* InitializeConditions for TransferFcn: '<S81>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S81>/Enabled Subsystem' */
  Sensors_a_EnabledSubsystem_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem_h,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem_h);

  /* End of SystemInitialize for SubSystem: '<S81>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S81>/Enabled Subsystem1' */
  Sensors__EnabledSubsystem1_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1_m,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem1_m);

  /* End of SystemInitialize for SubSystem: '<S81>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement1' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* InitializeConditions for TransferFcn: '<S86>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE = 0.0;

  /* SystemInitialize for Enabled SubSystem: '<S86>/Enabled Subsystem' */
  Sensors_a_EnabledSubsystem_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem_c,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem_c);

  /* End of SystemInitialize for SubSystem: '<S86>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S86>/Enabled Subsystem1' */
  Sensors__EnabledSubsystem1_Init
    (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1_j,
     &Sensors_and_actuators_ball_an_P.EnabledSubsystem1_j);

  /* End of SystemInitialize for SubSystem: '<S86>/Enabled Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement2' */

  /* SystemInitialize for Enabled SubSystem: '<S40>/MeasurementUpdate' */
  /* SystemInitialize for Outport: '<S69>/L*(y[k]-yhat[k|k-1])' */
  Sensors_and_actuators_ball_an_B.Product3[0] =
    Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
  Sensors_and_actuators_ball_an_B.Product3[1] =
    Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
  Sensors_and_actuators_ball_an_B.Product3[2] =
    Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
  Sensors_and_actuators_ball_an_B.Product3[3] =
    Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;

  /* End of SystemInitialize for SubSystem: '<S40>/MeasurementUpdate' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(Sensors_and_actuators_ball_a_M)) {
    rtmSetFirstInitCond(Sensors_and_actuators_ball_a_M, 0);
  }
}

/* Model terminate function */
void Sensors_and_actuators_ball_and_plate_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Terminate for Triggered SubSystem: '<S16>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S75>/S-Function1' incorporates:
   *  Constant: '<S16>/Constant'
   */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<S16>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S74>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement' */
  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Terminate for Triggered SubSystem: '<S17>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S80>/S-Function1' incorporates:
   *  Constant: '<S17>/Constant'
   */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<S17>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S79>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement1' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Terminate for Triggered SubSystem: '<S18>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S85>/S-Function1' incorporates:
   *  Constant: '<S18>/Constant'
   */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_POS_SET_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Set positions state for the selected incremental Encoder to INVALID */
    DioCl2EncoderIn_setEncPosValidity(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5,
      DIO_ENC_POSITION_INVALID);

    /* Writes settings for the incremental Encoder */
    DioCl2EncoderIn_write(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<S18>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S84>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement2' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier' */
  /* Terminate for S-Function (rti_commonblock): '<S71>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_1);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */
  /* Terminate for S-Function (rti_commonblock): '<S72>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 2 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_2, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_2);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S73>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 3 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_3, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_3);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S3>/S-Function1' */
  {
    /* --- Sensors_and_actuators_ball_and_plate/ETHERNET_UDP_SETUP_BL1: ==> Socket ID = (0) --- */
    /* dSPACE I/O Board DSETHERNET #1 Unit:SETUPUDP Group:SETUPUDP */

    /* close a socket connection
     * After closing, the corresponding socket resource is still occupied.   *
     * If a connection has been closed and should be re-used for a different *
     * connection, or if a connection should be re-established it must be    *
     * re-opened using DsIoEth_open() again.                                 */
    DsIoEth_close(DSIOETH_CONNECTION_ID_0);
  }
}
