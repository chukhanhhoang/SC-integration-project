/*
 * Sensors_and_actuators_ball_and_plate.c
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
  int_T nXc = 13;
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
 *    '<Root>/MATLAB Function'
 *    '<Root>/MATLAB Function1'
 */
void Sensors_and_actu_MATLABFunction(real_T rtu_motor1, real_T rtu_motor2,
  real_T rtu_motor3, B_MATLABFunction_Sensors_and__T *localB)
{
  real_T Zc;
  real_T CPi_rotated[9];
  real_T c;
  real_T tmp[9];
  real_T r0Oc[9];
  int32_T i;
  real_T UnitZp;
  real_T r0Oc_idx_0;
  real_T r0Oc_idx_1;
  real_T r0Oc_idx_2;
  real_T UnitZp_idx_0;
  real_T UnitZp_idx_1;
  real_T UnitZp_idx_2;

  /* MATLAB Function 'MATLAB Function': '<S6>:1' */
  /* '<S6>:1:30' */
  /* '<S6>:1:25' */
  /* '<S6>:1:13' */
  /* '<S6>:1:14' */
  /* '<S6>:1:15' */
  /* '<S6>:1:16' */
  /* '<S6>:1:21' */
  Zc = ((rtu_motor1 + rtu_motor2) + rtu_motor3) * 0.33333333333333331;

  /* '<S6>:1:22' */
  r0Oc_idx_2 = Zc;

  /* '<S6>:1:25' */
  /* '<S6>:1:26' */
  /* '<S6>:1:29' */
  tmp[2] = rtu_motor1;
  tmp[5] = rtu_motor2;
  tmp[8] = rtu_motor3;
  tmp[0] = 0.17;
  tmp[1] = 0.0;
  r0Oc[0] = 0.0;
  r0Oc[3] = 0.0;
  r0Oc[6] = 0.0;
  tmp[3] = -0.085;
  tmp[4] = 0.14722431864335458;
  r0Oc[1] = 0.0;
  r0Oc[4] = 0.0;
  r0Oc[7] = 0.0;
  tmp[6] = -0.085;
  tmp[7] = -0.14722431864335458;
  r0Oc[2] = r0Oc_idx_2;
  r0Oc[5] = r0Oc_idx_2;
  r0Oc[8] = r0Oc_idx_2;
  for (i = 0; i < 9; i++) {
    CPi_rotated[i] = tmp[i] - r0Oc[i];
  }

  /* '<S6>:1:30' */
  /* '<S6>:1:32' */
  /* '<S6>:1:38' */
  r0Oc_idx_2 = CPi_rotated[0];
  c = r0Oc_idx_2 * r0Oc_idx_2;
  r0Oc_idx_2 = CPi_rotated[1];
  c += r0Oc_idx_2 * r0Oc_idx_2;
  r0Oc_idx_2 = CPi_rotated[2];
  c += r0Oc_idx_2 * r0Oc_idx_2;
  c = sqrt(c);
  r0Oc_idx_0 = CPi_rotated[0] / c;
  r0Oc_idx_1 = CPi_rotated[1] / c;
  r0Oc_idx_2 = CPi_rotated[2] / c;

  /* '<S6>:1:39' */
  UnitZp_idx_0 = r0Oc_idx_1 * CPi_rotated[8] - r0Oc_idx_2 * CPi_rotated[7];
  UnitZp_idx_1 = r0Oc_idx_2 * CPi_rotated[6] - r0Oc_idx_0 * CPi_rotated[8];
  UnitZp_idx_2 = r0Oc_idx_0 * CPi_rotated[7] - r0Oc_idx_1 * CPi_rotated[6];

  /* '<S6>:1:40' */
  UnitZp = UnitZp_idx_0;
  c = UnitZp * UnitZp;
  UnitZp = UnitZp_idx_1;
  c += UnitZp * UnitZp;
  UnitZp = UnitZp_idx_2;
  c += UnitZp * UnitZp;
  c = sqrt(c);
  UnitZp = UnitZp_idx_0;
  UnitZp /= c;
  UnitZp_idx_0 = UnitZp;
  UnitZp = UnitZp_idx_1;
  UnitZp /= c;
  UnitZp_idx_1 = UnitZp;

  /* '<S6>:1:41' */
  /* '<S6>:1:43' */
  localB->theta2 = -r0Oc_idx_2;
  localB->theta2 = asin(localB->theta2);

  /* '<S6>:1:44' */
  localB->theta3 = r0Oc_idx_1 / sqrt(1.0 - r0Oc_idx_2 * r0Oc_idx_2);
  localB->theta3 = asin(localB->theta3);

  /* '<S6>:1:45' */
  localB->theta1 = (r0Oc_idx_0 * UnitZp_idx_1 - r0Oc_idx_1 * UnitZp_idx_0) /
    sqrt(1.0 - r0Oc_idx_2 * r0Oc_idx_2);
  localB->theta1 = asin(localB->theta1);
  localB->Zc = Zc;
}

/*
 * System initialize for enable system:
 *    '<S123>/Enabled Subsystem'
 *    '<S128>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 */
void Sensors_a_EnabledSubsystem_Init(B_EnabledSubsystem_Sensors_an_T *localB,
  P_EnabledSubsystem_Sensors_an_T *localP)
{
  /* SystemInitialize for Outport: '<S124>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S123>/Enabled Subsystem'
 *    '<S128>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 */
void Sensor_EnabledSubsystem_Disable(B_EnabledSubsystem_Sensors_an_T *localB,
  DW_EnabledSubsystem_Sensors_a_T *localDW, P_EnabledSubsystem_Sensors_an_T
  *localP)
{
  /* Disable for Outport: '<S124>/Out1' */
  localB->OutportBufferForOut1 = localP->Out1_Y0;
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Start for enable system:
 *    '<S123>/Enabled Subsystem'
 *    '<S128>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 */
void Sensors__EnabledSubsystem_Start(DW_EnabledSubsystem_Sensors_a_T *localDW)
{
  localDW->EnabledSubsystem_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S123>/Enabled Subsystem'
 *    '<S128>/Enabled Subsystem'
 *    '<S133>/Enabled Subsystem'
 */
void Sensors_and_ac_EnabledSubsystem(RT_MODEL_Sensors_and_actuator_T * const
  Sensors_and_actuators_ball_a_M, boolean_T rtu_Enable,
  B_EnabledSubsystem_Sensors_an_T *localB, DW_EnabledSubsystem_Sensors_a_T
  *localDW, P_EnabledSubsystem_Sensors_an_T *localP)
{
  /* Outputs for Enabled SubSystem: '<S123>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S124>/Enable'
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
    /* SignalConversion generated from: '<S124>/Out1' incorporates:
     *  Constant: '<S124>/Constant'
     */
    localB->OutportBufferForOut1 = localP->Constant_Value;
  }

  /* End of Outputs for SubSystem: '<S123>/Enabled Subsystem' */
}

/*
 * System initialize for enable system:
 *    '<S123>/Enabled Subsystem1'
 *    '<S128>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 */
void Sensors__EnabledSubsystem1_Init(B_EnabledSubsystem1_Sensors_a_T *localB,
  P_EnabledSubsystem1_Sensors_a_T *localP)
{
  /* SystemInitialize for Outport: '<S125>/Out1' */
  localB->In1 = localP->Out1_Y0;
}

/*
 * Disable for enable system:
 *    '<S123>/Enabled Subsystem1'
 *    '<S128>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 */
void Senso_EnabledSubsystem1_Disable(DW_EnabledSubsystem1_Sensors__T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Start for enable system:
 *    '<S123>/Enabled Subsystem1'
 *    '<S128>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 */
void Sensors_EnabledSubsystem1_Start(DW_EnabledSubsystem1_Sensors__T *localDW)
{
  localDW->EnabledSubsystem1_MODE = false;
}

/*
 * Output and update for enable system:
 *    '<S123>/Enabled Subsystem1'
 *    '<S128>/Enabled Subsystem1'
 *    '<S133>/Enabled Subsystem1'
 */
void Sensors_and_a_EnabledSubsystem1(RT_MODEL_Sensors_and_actuator_T * const
  Sensors_and_actuators_ball_a_M, boolean_T rtu_Enable, real_T rtu_In1,
  B_EnabledSubsystem1_Sensors_a_T *localB, DW_EnabledSubsystem1_Sensors__T
  *localDW)
{
  /* Outputs for Enabled SubSystem: '<S123>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S125>/Enable'
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
    /* Inport: '<S125>/In1' */
    localB->In1 = rtu_In1;
  }

  /* End of Outputs for SubSystem: '<S123>/Enabled Subsystem1' */
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
  real_T r0Oc[3];
  real_T C1;
  real_T S1;
  real_T C2;
  real_T S2;
  real_T C3;
  real_T S3;
  real_T A10[9];
  real_T rCiBi[9];
  int32_T i;
  real_T tmp[4];
  real_T tmp_0[2];
  real_T tmp_1[6];
  real_T tmp_2[6];
  boolean_T zcEvent;
  real_T C2_0[9];
  real_T C3_0[9];
  int32_T i_0;
  static const int8_T b[3] = { 0, 0, 1 };

  static const real_T r1C[9] = { 0.17, 0.0, 0.0, -0.085, 0.14722431864335458,
    0.0, -0.085, -0.14722431864335458, 0.0 };

  const real_T *tmp_3;
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

  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
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

    /* Reshape: '<S4>/ReshapeX0' incorporates:
     *  Constant: '<S4>/X0'
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

  /* Integrator: '<S4>/MemoryX' */
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

  /* Reshape: '<S4>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[0] =
    Sensors_and_actuators_ball_an_B.MemoryX[0];

  /* Integrator: '<S4>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[1] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[1];

  /* Reshape: '<S4>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[1] =
    Sensors_and_actuators_ball_an_B.MemoryX[1];

  /* Integrator: '<S4>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[2] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[2];

  /* Reshape: '<S4>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[2] =
    Sensors_and_actuators_ball_an_B.MemoryX[2];

  /* Integrator: '<S4>/MemoryX' */
  Sensors_and_actuators_ball_an_B.MemoryX[3] =
    Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[3];

  /* Reshape: '<S4>/Reshapexhat' */
  Sensors_and_actuators_ball_an_B.Reshapexhat[3] =
    Sensors_and_actuators_ball_an_B.MemoryX[3];

  /* Sin: '<Root>/Sine Wave' */
  Sensors_and_actuators_ball_an_B.SineWave = sin
    (Sensors_and_actuators_ball_an_P.SineWave_Freq *
     Sensors_and_actuators_ball_a_M->Timing.t[0] +
     Sensors_and_actuators_ball_an_P.SineWave_Phase) *
    Sensors_and_actuators_ball_an_P.SineWave_Amp +
    Sensors_and_actuators_ball_an_P.SineWave_Bias;

  /* Sin: '<Root>/Sine Wave1' */
  Sensors_and_actuators_ball_an_B.SineWave1 = sin
    (Sensors_and_actuators_ball_an_P.SineWave1_Freq *
     Sensors_and_actuators_ball_a_M->Timing.t[0] +
     Sensors_and_actuators_ball_an_P.SineWave1_Phase) *
    Sensors_and_actuators_ball_an_P.SineWave1_Amp +
    Sensors_and_actuators_ball_an_P.SineWave1_Bias;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<Root>/Constant4'
   */
  Sensors_and_actuators_ball_an_B.Sum[0] =
    Sensors_and_actuators_ball_an_B.SineWave -
    Sensors_and_actuators_ball_an_B.Reshapexhat[0];
  Sensors_and_actuators_ball_an_B.Sum[1] =
    Sensors_and_actuators_ball_an_P.Constant3_Value -
    Sensors_and_actuators_ball_an_B.Reshapexhat[1];
  Sensors_and_actuators_ball_an_B.Sum[2] =
    Sensors_and_actuators_ball_an_B.SineWave1 -
    Sensors_and_actuators_ball_an_B.Reshapexhat[2];
  Sensors_and_actuators_ball_an_B.Sum[3] =
    Sensors_and_actuators_ball_an_P.Constant4_Value -
    Sensors_and_actuators_ball_an_B.Reshapexhat[3];

  /* Gain: '<Root>/Gain4' */
  for (i_0 = 0; i_0 < 2; i_0++) {
    Sensors_and_actuators_ball_an_B.Gain4[i_0] = 0.0;
    Sensors_and_actuators_ball_an_B.Gain4[i_0] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i_0] *
      Sensors_and_actuators_ball_an_B.Sum[0];
    Sensors_and_actuators_ball_an_B.Gain4[i_0] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i_0 + 2] *
      Sensors_and_actuators_ball_an_B.Sum[1];
    Sensors_and_actuators_ball_an_B.Gain4[i_0] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i_0 + 4] *
      Sensors_and_actuators_ball_an_B.Sum[2];
    Sensors_and_actuators_ball_an_B.Gain4[i_0] +=
      Sensors_and_actuators_ball_an_P.ballLQRgain[i_0 + 6] *
      Sensors_and_actuators_ball_an_B.Sum[3];
  }

  /* End of Gain: '<Root>/Gain4' */

  /* MATLAB Function: '<Root>/MATLAB Function3' incorporates:
   *  Constant: '<Root>/Constant13'
   *  Constant: '<Root>/Constant14'
   */
  /* MATLAB Function 'MATLAB Function3': '<S8>:1' */
  /* '<S8>:1:27' */
  /* '<S8>:1:26' */
  /* '<S8>:1:25' */
  /* '<S8>:1:34' */
  /* '<S8>:1:16' */
  /* '<S8>:1:18' */
  /* '<S8>:1:19' */
  r0Oc[0] = 0.0;
  r0Oc[1] = 0.0;
  r0Oc[2] = Sensors_and_actuators_ball_an_P.Constant14_Value;

  /* '<S8>:1:22' */
  C1 = cos(Sensors_and_actuators_ball_an_B.Gain4[0]);

  /* '<S8>:1:22' */
  S1 = sin(Sensors_and_actuators_ball_an_B.Gain4[0]);

  /* '<S8>:1:22' */
  C2 = cos(Sensors_and_actuators_ball_an_B.Gain4[1]);

  /* '<S8>:1:22' */
  S2 = sin(Sensors_and_actuators_ball_an_B.Gain4[1]);

  /* '<S8>:1:22' */
  C3 = cos(Sensors_and_actuators_ball_an_P.Constant13_Value);

  /* '<S8>:1:22' */
  S3 = sin(Sensors_and_actuators_ball_an_P.Constant13_Value);

  /* '<S8>:1:25' */
  /* '<S8>:1:26' */
  /* '<S8>:1:27' */
  /* '<S8>:1:29' */
  A10[1] = 0.0;
  A10[4] = C1;
  A10[7] = S1;
  A10[2] = 0.0;
  A10[5] = -S1;
  A10[8] = C1;
  C2_0[0] = C2;
  C2_0[3] = 0.0;
  C2_0[6] = -S2;
  A10[0] = 1.0;
  C2_0[1] = 0.0;
  A10[3] = 0.0;
  C2_0[4] = 1.0;
  A10[6] = 0.0;
  C2_0[7] = 0.0;
  C2_0[2] = S2;
  C2_0[5] = 0.0;
  C2_0[8] = C2;
  C3_0[0] = C3;
  C3_0[3] = S3;
  C3_0[6] = 0.0;
  C3_0[1] = -S3;
  C3_0[4] = C3;
  C3_0[7] = 0.0;
  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      rCiBi[i_0 + 3 * i] = 0.0;
      C1 = rCiBi[3 * i + i_0];
      C1 += C2_0[3 * i] * A10[i_0];
      rCiBi[i_0 + 3 * i] = C1;
      C1 = rCiBi[3 * i + i_0];
      C1 += C2_0[3 * i + 1] * A10[i_0 + 3];
      rCiBi[i_0 + 3 * i] = C1;
      C1 = rCiBi[3 * i + i_0];
      C1 += C2_0[3 * i + 2] * A10[i_0 + 6];
      rCiBi[i_0 + 3 * i] = C1;
    }

    C3_0[3 * i_0 + 2] = b[i_0];
  }

  for (i_0 = 0; i_0 < 3; i_0++) {
    for (i = 0; i < 3; i++) {
      A10[i + 3 * i_0] = 0.0;
      C1 = A10[3 * i_0 + i];
      C1 += C3_0[3 * i_0] * rCiBi[i];
      A10[i + 3 * i_0] = C1;
      C1 = A10[3 * i_0 + i];
      C1 += C3_0[3 * i_0 + 1] * rCiBi[i + 3];
      A10[i + 3 * i_0] = C1;
      C1 = A10[3 * i_0 + i];
      C1 += C3_0[3 * i_0 + 2] * rCiBi[i + 6];
      A10[i + 3 * i_0] = C1;
    }
  }

  /* '<S8>:1:32' */
  /* '<S8>:1:33' */
  for (i = 0; i < 3; i++) {
    /* '<S8>:1:33' */
    /* '<S8>:1:34' */
    for (i_0 = 0; i_0 < 3; i_0++) {
      C1 = A10[3 * i_0] * r1C[3 * i];
      C1 += A10[3 * i_0 + 1] * r1C[3 * i + 1];
      C1 += A10[3 * i_0 + 2] * r1C[3 * i + 2];
      rCiBi[i_0 + 3 * i] = (r0Oc[i_0] + C1) - r1C[3 * i + i_0];
    }
  }

  /* '<S8>:1:38' */
  Sensors_and_actuators_ball_an_B.motor1 = Sensors_and_actuators_ball_norm
    (&rCiBi[0]);

  /* '<S8>:1:39' */
  Sensors_and_actuators_ball_an_B.motor2 = Sensors_and_actuators_ball_norm
    (&rCiBi[3]);

  /* '<S8>:1:40' */
  Sensors_and_actuators_ball_an_B.motor3 = Sensors_and_actuators_ball_norm
    (&rCiBi[6]);

  /* End of MATLAB Function: '<Root>/MATLAB Function3' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  Sensors_and_actu_MATLABFunction(Sensors_and_actuators_ball_an_B.motor1,
    Sensors_and_actuators_ball_an_B.motor2,
    Sensors_and_actuators_ball_an_B.motor3,
    &Sensors_and_actuators_ball_an_B.sf_MATLABFunction1);
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Reshape: '<S5>/ReshapeX0' incorporates:
     *  Constant: '<S5>/X0'
     */
    for (i = 0; i < 6; i++) {
      Sensors_and_actuators_ball_an_B.ReshapeX0_f[i] =
        Sensors_and_actuators_ball_an_P.X0_Value_e[i];
    }

    /* End of Reshape: '<S5>/ReshapeX0' */
  }

  for (i = 0; i < 6; i++) {
    /* Integrator: '<S5>/MemoryX' */
    if (Sensors_and_actuators_ball_a_DW.MemoryX_IWORK_g != 0) {
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[i] =
        Sensors_and_actuators_ball_an_B.ReshapeX0_f[i];
    }

    Sensors_and_actuators_ball_an_B.MemoryX_k[i] =
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[i];

    /* End of Integrator: '<S5>/MemoryX' */

    /* Reshape: '<S5>/Reshapexhat' */
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[i] =
      Sensors_and_actuators_ball_an_B.MemoryX_k[i];
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant8'
   */
  Sensors_and_actuators_ball_an_B.Sum1[0] =
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.theta1 -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[0];
  Sensors_and_actuators_ball_an_B.Sum1[1] =
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.theta2 -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[1];
  Sensors_and_actuators_ball_an_B.Sum1[2] =
    Sensors_and_actuators_ball_an_B.sf_MATLABFunction1.Zc -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[2];
  Sensors_and_actuators_ball_an_B.Sum1[3] =
    Sensors_and_actuators_ball_an_P.Constant8_Value -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[3];
  Sensors_and_actuators_ball_an_B.Sum1[4] =
    Sensors_and_actuators_ball_an_P.Constant8_Value -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[4];
  Sensors_and_actuators_ball_an_B.Sum1[5] =
    Sensors_and_actuators_ball_an_P.Constant8_Value -
    Sensors_and_actuators_ball_an_B.Reshapexhat_h[5];

  /* Gain: '<Root>/Gain3' */
  for (i_0 = 0; i_0 < 3; i_0++) {
    Sensors_and_actuators_ball_an_B.Gain3[i_0] = 0.0;
    for (i = 0; i < 6; i++) {
      Sensors_and_actuators_ball_an_B.Gain3[i_0] +=
        Sensors_and_actuators_ball_an_P.plateLQRgain[3 * i + i_0] *
        Sensors_and_actuators_ball_an_B.Sum1[i];
    }
  }

  /* End of Gain: '<Root>/Gain3' */

  /* Gain: '<Root>/Gain6' */
  Sensors_and_actuators_ball_an_B.Gain6[0] =
    Sensors_and_actuators_ball_an_P.Gain6_Gain *
    Sensors_and_actuators_ball_an_B.Gain3[0];
  Sensors_and_actuators_ball_an_B.Gain6[1] =
    Sensors_and_actuators_ball_an_P.Gain6_Gain *
    Sensors_and_actuators_ball_an_B.Gain3[1];
  Sensors_and_actuators_ball_an_B.Gain6[2] =
    Sensors_and_actuators_ball_an_P.Gain6_Gain *
    Sensors_and_actuators_ball_an_B.Gain3[2];

  /* Sum: '<Root>/Sum4' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  Sensors_and_actuators_ball_an_B.Sum4 = Sensors_and_actuators_ball_an_B.Gain6[0]
    + Sensors_and_actuators_ball_an_P.I_0;

  /* Outport: '<Root>/I_A' */
  Sensors_and_actuators_ball_an_Y.I_A = Sensors_and_actuators_ball_an_B.Sum4;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  Sensors_and_actuators_ball_an_B.Sum3 = Sensors_and_actuators_ball_an_B.Gain6[1]
    + Sensors_and_actuators_ball_an_P.I_0;

  /* Outport: '<Root>/I_B' */
  Sensors_and_actuators_ball_an_Y.I_B = Sensors_and_actuators_ball_an_B.Sum3;

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/Constant9'
   */
  Sensors_and_actuators_ball_an_B.Sum2 = Sensors_and_actuators_ball_an_B.Gain6[2]
    + Sensors_and_actuators_ball_an_P.I_0;

  /* Outport: '<Root>/I_C' */
  Sensors_and_actuators_ball_an_Y.I_C = Sensors_and_actuators_ball_an_B.Sum2;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Sum: '<Root>/Sum5' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Outport: '<Root>/Xpos '
     */
    Sensors_and_actuators_ball_an_B.Sum5 = (real_T)
      Sensors_and_actuators_ball_an_Y.Xpos -
      Sensors_and_actuators_ball_an_P.Constant2_Value;

    /* Outport: '<Root>/Xpos_m' incorporates:
     *  Gain: '<Root>/Gain'
     */
    Sensors_and_actuators_ball_an_Y.Xpos_m =
      Sensors_and_actuators_ball_an_P.Gain_Gain *
      Sensors_and_actuators_ball_an_B.Sum5;

    /* Sum: '<Root>/Sum6' incorporates:
     *  Constant: '<Root>/Constant10'
     *  Outport: '<Root>/Ypos '
     */
    Sensors_and_actuators_ball_an_B.Sum6 = (real_T)
      Sensors_and_actuators_ball_an_Y.Ypos -
      Sensors_and_actuators_ball_an_P.Constant10_Value;

    /* Outport: '<Root>/Ypos_m' incorporates:
     *  Gain: '<Root>/Gain5'
     */
    Sensors_and_actuators_ball_an_Y.Ypos_m =
      Sensors_and_actuators_ball_an_P.Gain5_Gain *
      Sensors_and_actuators_ball_an_B.Sum6;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier' */

  /* Saturate: '<S9>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Sum4;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat;
  C2 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat;
  if (C1 > C2) {
    Sensors_and_actuators_ball_an_B.Saturation_e = C2;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation_e = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation_e = C1;
  }

  /* End of Saturate: '<S9>/Saturation' */

  /* Gain: '<S9>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V_p =
    Sensors_and_actuators_ball_an_P.Current2V_Gain *
    Sensors_and_actuators_ball_an_B.Saturation_e;

  /* Gain: '<S9>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale_o =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain *
    Sensors_and_actuators_ball_an_B.Current2V_p;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S118>/S-Function1' */
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

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Saturate: '<S10>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Sum3;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat_a;
  C2 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat_g;
  if (C1 > C2) {
    Sensors_and_actuators_ball_an_B.Saturation_l = C2;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation_l = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation_l = C1;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Gain: '<S10>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V_a =
    Sensors_and_actuators_ball_an_P.Current2V_Gain_l *
    Sensors_and_actuators_ball_an_B.Saturation_l;

  /* Gain: '<S10>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale_a =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain_j *
    Sensors_and_actuators_ball_an_B.Current2V_a;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S119>/S-Function1' */
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

  /* Outputs for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */

  /* Saturate: '<S11>/Saturation' */
  C1 = Sensors_and_actuators_ball_an_B.Sum2;
  S1 = Sensors_and_actuators_ball_an_P.Saturation_LowerSat_m;
  C2 = Sensors_and_actuators_ball_an_P.Saturation_UpperSat_j;
  if (C1 > C2) {
    Sensors_and_actuators_ball_an_B.Saturation = C2;
  } else if (C1 < S1) {
    Sensors_and_actuators_ball_an_B.Saturation = S1;
  } else {
    Sensors_and_actuators_ball_an_B.Saturation = C1;
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Gain: '<S11>/Current2V' */
  Sensors_and_actuators_ball_an_B.Current2V =
    Sensors_and_actuators_ball_an_P.Current2V_Gain_j *
    Sensors_and_actuators_ball_an_B.Saturation;

  /* Gain: '<S11>/DSPscale' */
  Sensors_and_actuators_ball_an_B.DSPscale =
    Sensors_and_actuators_ball_an_P.DSPscale_Gain_h *
    Sensors_and_actuators_ball_an_B.Current2V;
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* S-Function (rti_commonblock): '<S120>/S-Function1' */
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

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S122>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init' */
      zcEvent = (Sensors_and_actuators_ball_an_U.Init &&
                 (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o
                  != POS_ZCSIG));
      if (zcEvent) {
        /* S-Function (rti_commonblock): '<S122>/S-Function1' incorporates:
         *  Constant: '<S12>/Constant'
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

    /* End of Outputs for SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S121>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S12>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos_g =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_o;

    /* Sum: '<S12>/AbsPosition' incorporates:
     *  Constant: '<S12>/Pos_offset'
     *  Constant: '<S12>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition_hs =
      (Sensors_and_actuators_ball_an_B.Inc2Pos_g -
       Sensors_and_actuators_ball_an_P.ZP_Value) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value;

    /* Abs: '<S123>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs_c = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2_n);
  }

  /* Outputs for Enabled SubSystem: '<S123>/Enabled Subsystem' */
  /* Inport: '<Root>/Init' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem);

  /* End of Outputs for SubSystem: '<S123>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S123>/Relational Operator1' incorporates:
     *  Constant: '<S123>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1_b =
      (Sensors_and_actuators_ball_an_B.Abs_c <=
       Sensors_and_actuators_ball_an_P.Const_Value);
  }

  /* TransferFcn: '<S123>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn_f = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn_f +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b;

  /* RelationalOperator: '<S123>/Relational Operator' incorporates:
   *  Constant: '<S123>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator_c =
    (Sensors_and_actuators_ball_an_P.Const1_Value >=
     Sensors_and_actuators_ball_an_B.TransferFcn_f);

  /* Logic: '<S123>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2_c =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1_b &&
     Sensors_and_actuators_ball_an_B.RelationalOperator_c &&
     Sensors_and_actuators_ball_an_U.Init);

  /* Outputs for Enabled SubSystem: '<S123>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2_c,
    Sensors_and_actuators_ball_an_B.Inc2Pos_g,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1);

  /* End of Outputs for SubSystem: '<S123>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S12>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m_h =
      Sensors_and_actuators_ball_an_P.mm2m_Gain *
      Sensors_and_actuators_ball_an_B.AbsPosition_hs;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Sum: '<Root>/Add2' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    Sensors_and_actuators_ball_an_B.Add2 =
      Sensors_and_actuators_ball_an_B.mm2m_h +
      Sensors_and_actuators_ball_an_P.Constant7_Value;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S13>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S127>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init1' */
      zcEvent = (Sensors_and_actuators_ball_an_U.Init1 &&
                 (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n
                  != POS_ZCSIG));
      if (zcEvent) {
        /* S-Function (rti_commonblock): '<S127>/S-Function1' incorporates:
         *  Constant: '<S13>/Constant'
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

    /* End of Outputs for SubSystem: '<S13>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S126>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S13>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos_i =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain_j *
      Sensors_and_actuators_ball_an_B.SFunction1_o1_g;

    /* Sum: '<S13>/AbsPosition' incorporates:
     *  Constant: '<S13>/Pos_offset'
     *  Constant: '<S13>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition_h =
      (Sensors_and_actuators_ball_an_B.Inc2Pos_i -
       Sensors_and_actuators_ball_an_P.ZP_Value_a) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value_f;

    /* Abs: '<S128>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs_l = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2_p);
  }

  /* Outputs for Enabled SubSystem: '<S128>/Enabled Subsystem' */
  /* Inport: '<Root>/Init1' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init1,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem_h,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem_h,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem_h);

  /* End of Outputs for SubSystem: '<S128>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S128>/Relational Operator1' incorporates:
     *  Constant: '<S128>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1_p =
      (Sensors_and_actuators_ball_an_B.Abs_l <=
       Sensors_and_actuators_ball_an_P.Const_Value_d);
  }

  /* TransferFcn: '<S128>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn_d = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn_d +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C_j *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k;

  /* RelationalOperator: '<S128>/Relational Operator' incorporates:
   *  Constant: '<S128>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator_n =
    (Sensors_and_actuators_ball_an_P.Const1_Value_k >=
     Sensors_and_actuators_ball_an_B.TransferFcn_d);

  /* Logic: '<S128>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init1'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2_k =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1_p &&
     Sensors_and_actuators_ball_an_B.RelationalOperator_n &&
     Sensors_and_actuators_ball_an_U.Init1);

  /* Outputs for Enabled SubSystem: '<S128>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2_k,
    Sensors_and_actuators_ball_an_B.Inc2Pos_i,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1_m,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_m);

  /* End of Outputs for SubSystem: '<S128>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S13>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m_p =
      Sensors_and_actuators_ball_an_P.mm2m_Gain_f *
      Sensors_and_actuators_ball_an_B.AbsPosition_h;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Sum: '<Root>/Add3' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    Sensors_and_actuators_ball_an_B.Add3 =
      Sensors_and_actuators_ball_an_B.mm2m_p +
      Sensors_and_actuators_ball_an_P.Constant7_Value;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Outputs for Triggered SubSystem: '<S14>/EMC_ENCODER_POS_SET_BL1' incorporates:
     *  TriggerPort: '<S132>/Trigger'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Inport: '<Root>/Init2' */
      zcEvent = (Sensors_and_actuators_ball_an_U.Init2 &&
                 (Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC
                  != POS_ZCSIG));
      if (zcEvent) {
        /* S-Function (rti_commonblock): '<S132>/S-Function1' incorporates:
         *  Constant: '<S14>/Constant'
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

    /* End of Outputs for SubSystem: '<S14>/EMC_ENCODER_POS_SET_BL1' */

    /* S-Function (rti_commonblock): '<S131>/S-Function1' */
    /* This comment workarounds a code generation problem */

    /* Gain: '<S14>/Inc2Pos' */
    Sensors_and_actuators_ball_an_B.Inc2Pos =
      Sensors_and_actuators_ball_an_P.Inc2Pos_Gain_i *
      Sensors_and_actuators_ball_an_B.SFunction1_o1;

    /* Sum: '<S14>/AbsPosition' incorporates:
     *  Constant: '<S14>/Pos_offset'
     *  Constant: '<S14>/ZP'
     */
    Sensors_and_actuators_ball_an_B.AbsPosition =
      (Sensors_and_actuators_ball_an_B.Inc2Pos -
       Sensors_and_actuators_ball_an_P.ZP_Value_d) -
      Sensors_and_actuators_ball_an_P.Pos_offset_Value_b;

    /* Abs: '<S133>/Abs' */
    Sensors_and_actuators_ball_an_B.Abs = fabs
      (Sensors_and_actuators_ball_an_B.SFunction1_o2);
  }

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  /* Inport: '<Root>/Init2' */
  Sensors_and_ac_EnabledSubsystem(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_U.Init2,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem_c,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem_c,
    &Sensors_and_actuators_ball_an_P.EnabledSubsystem_c);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* RelationalOperator: '<S133>/Relational Operator1' incorporates:
     *  Constant: '<S133>/Const'
     */
    Sensors_and_actuators_ball_an_B.RelationalOperator1 =
      (Sensors_and_actuators_ball_an_B.Abs <=
       Sensors_and_actuators_ball_an_P.Const_Value_i);
  }

  /* TransferFcn: '<S133>/Transfer Fcn' */
  Sensors_and_actuators_ball_an_B.TransferFcn = 0.0;
  Sensors_and_actuators_ball_an_B.TransferFcn +=
    Sensors_and_actuators_ball_an_P.TransferFcn_C_m *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE;

  /* RelationalOperator: '<S133>/Relational Operator' incorporates:
   *  Constant: '<S133>/Const1'
   */
  Sensors_and_actuators_ball_an_B.RelationalOperator =
    (Sensors_and_actuators_ball_an_P.Const1_Value_n >=
     Sensors_and_actuators_ball_an_B.TransferFcn);

  /* Logic: '<S133>/Logical Operator2' incorporates:
   *  Inport: '<Root>/Init2'
   */
  Sensors_and_actuators_ball_an_B.LogicalOperator2 =
    (Sensors_and_actuators_ball_an_B.RelationalOperator1 &&
     Sensors_and_actuators_ball_an_B.RelationalOperator &&
     Sensors_and_actuators_ball_an_U.Init2);

  /* Outputs for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  Sensors_and_a_EnabledSubsystem1(Sensors_and_actuators_ball_a_M,
    Sensors_and_actuators_ball_an_B.LogicalOperator2,
    Sensors_and_actuators_ball_an_B.Inc2Pos,
    &Sensors_and_actuators_ball_an_B.EnabledSubsystem1_j,
    &Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_j);

  /* End of Outputs for SubSystem: '<S133>/Enabled Subsystem1' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Gain: '<S14>/mm2m' */
    Sensors_and_actuators_ball_an_B.mm2m =
      Sensors_and_actuators_ball_an_P.mm2m_Gain_a *
      Sensors_and_actuators_ball_an_B.AbsPosition;
  }

  /* End of Outputs for SubSystem: '<Root>/Position Measurement2' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Sum: '<Root>/Add4' incorporates:
     *  Constant: '<Root>/Constant7'
     */
    Sensors_and_actuators_ball_an_B.Add4 = Sensors_and_actuators_ball_an_B.mm2m
      + Sensors_and_actuators_ball_an_P.Constant7_Value;

    /* DataTypeConversion: '<S59>/Conversion' incorporates:
     *  Constant: '<S16>/KalmanGainL'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainL_Value[0], sizeof(real_T)
           << 3U);

    /* DataTypeConversion: '<S60>/Conversion' incorporates:
     *  Constant: '<S16>/KalmanGainM'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_c[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainM_Value[0], sizeof(real_T)
           << 3U);

    /* DataTypeConversion: '<S61>/Conversion' */
    Sensors_and_actuators_ball_an_B.Conversion_n = 0.0;

    /* DataTypeConversion: '<S62>/Conversion' incorporates:
     *  Constant: '<S16>/CovarianceZ'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_k[0],
           &Sensors_and_actuators_ball_an_P.CovarianceZ_Value[0], sizeof(real_T)
           << 4U);

    /* DataTypeConversion: '<S27>/Conversion' incorporates:
     *  Constant: '<S4>/P0'
     */
    for (i = 0; i < 16; i++) {
      Sensors_and_actuators_ball_an_B.Conversion_i[i] = (real32_T)
        Sensors_and_actuators_ball_an_P.P0_Value[i];
    }

    /* End of DataTypeConversion: '<S27>/Conversion' */
  }

  /* DataTypeConversion: '<S32>/Conversion' */
  Sensors_and_actuators_ball_an_B.Conversion_a[0] =
    Sensors_and_actuators_ball_an_B.MemoryX[0];
  Sensors_and_actuators_ball_an_B.Conversion_a[1] =
    Sensors_and_actuators_ball_an_B.MemoryX[1];
  Sensors_and_actuators_ball_an_B.Conversion_a[2] =
    Sensors_and_actuators_ball_an_B.MemoryX[2];
  Sensors_and_actuators_ball_an_B.Conversion_a[3] =
    Sensors_and_actuators_ball_an_B.MemoryX[3];

  /* Product: '<S36>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S4>/A'
   */
  tmp_3 = &Sensors_and_actuators_ball_an_P.A_Value[0];
  tmp[0] = Sensors_and_actuators_ball_an_B.Conversion_a[0];
  tmp[1] = Sensors_and_actuators_ball_an_B.Conversion_a[1];
  tmp[2] = Sensors_and_actuators_ball_an_B.Conversion_a[2];
  tmp[3] = Sensors_and_actuators_ball_an_B.Conversion_a[3];
  for (i_0 = 0; i_0 < 4; i_0++) {
    C1 = tmp_3[i_0] * tmp[0];
    C1 += tmp_3[i_0 + 4] * tmp[1];
    C1 += tmp_3[i_0 + 8] * tmp[2];
    C1 += tmp_3[i_0 + 12] * tmp[3];
    Sensors_and_actuators_ball_an_B.Akxhatkk1[i_0] = C1;
  }

  /* End of Product: '<S36>/A[k]*xhat[k|k-1]' */
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* MATLAB Function: '<Root>/MATLAB Function' */
    Sensors_and_actu_MATLABFunction(Sensors_and_actuators_ball_an_B.Add2,
      Sensors_and_actuators_ball_an_B.Add3, Sensors_and_actuators_ball_an_B.Add4,
      &Sensors_and_actuators_ball_an_B.sf_MATLABFunction);

    /* Reshape: '<S4>/Reshapeu' */
    Sensors_and_actuators_ball_an_B.Reshapeu[0] =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction.theta1;
    Sensors_and_actuators_ball_an_B.Reshapeu[1] =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction.theta2;
  }

  /* Outputs for Enabled SubSystem: '<S36>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  /* Product: '<S36>/B[k]*u[k]' incorporates:
   *  Constant: '<S4>/B'
   *  Product: '<S65>/C[k]*xhat[k|k-1]'
   *  Product: '<S65>/Product3'
   */
  tmp_3 = &Sensors_and_actuators_ball_an_P.B_Value[0];

  /* End of Outputs for SubSystem: '<S36>/MeasurementUpdate' */
  tmp_0[0] = Sensors_and_actuators_ball_an_B.Reshapeu[0];
  tmp_0[1] = Sensors_and_actuators_ball_an_B.Reshapeu[1];
  for (i_0 = 0; i_0 < 4; i_0++) {
    C1 = tmp_3[i_0] * tmp_0[0];
    C1 += tmp_3[i_0 + 4] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Bkuk[i_0] = C1;
  }

  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Reshape: '<S4>/Reshapey' incorporates:
     *  Outport: '<Root>/Xpos_m'
     *  Outport: '<Root>/Ypos_m'
     */
    Sensors_and_actuators_ball_an_B.Reshapey[0] =
      Sensors_and_actuators_ball_an_Y.Xpos_m;
    Sensors_and_actuators_ball_an_B.Reshapey[1] =
      Sensors_and_actuators_ball_an_Y.Ypos_m;

    /* Outputs for Enabled SubSystem: '<S36>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S65>/Enable'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Constant: '<S4>/Enable' */
      if (Sensors_and_actuators_ball_an_P.Enable_Value) {
        Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE_e = true;
      } else {
        if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE_e) {
          /* Disable for Outport: '<S65>/L*(y[k]-yhat[k|k-1])' */
          Sensors_and_actuators_ball_an_B.Product3_h[0] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3_h[1] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3_h[2] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_an_B.Product3_h[3] =
            Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
          Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE_e = false;
        }
      }

      /* End of Constant: '<S4>/Enable' */
    }

    /* End of Outputs for SubSystem: '<S36>/MeasurementUpdate' */
  }

  /* Outputs for Enabled SubSystem: '<S36>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S65>/Enable'
   */
  if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE_e) {
    /* Product: '<S65>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S4>/C'
     *  Product: '<S36>/B[k]*u[k]'
     *  Product: '<S65>/Product3'
     */
    tmp_3 = &Sensors_and_actuators_ball_an_P.C_Value[0];
    tmp[0] = Sensors_and_actuators_ball_an_B.Conversion_a[0];
    tmp[1] = Sensors_and_actuators_ball_an_B.Conversion_a[1];
    tmp[2] = Sensors_and_actuators_ball_an_B.Conversion_a[2];
    tmp[3] = Sensors_and_actuators_ball_an_B.Conversion_a[3];
    for (i_0 = 0; i_0 < 2; i_0++) {
      C1 = tmp_3[i_0] * tmp[0];
      C1 += tmp_3[i_0 + 2] * tmp[1];
      C1 += tmp_3[i_0 + 4] * tmp[2];
      C1 += tmp_3[i_0 + 6] * tmp[3];
      Sensors_and_actuators_ball_an_B.Ckxhatkk1_e[i_0] = C1;
    }

    /* Product: '<S65>/D[k]*u[k]' incorporates:
     *  Constant: '<S4>/D'
     */
    tmp[0] = Sensors_and_actuators_ball_an_P.D_Value[0];
    tmp[1] = Sensors_and_actuators_ball_an_P.D_Value[1];
    tmp[2] = Sensors_and_actuators_ball_an_P.D_Value[2];
    tmp[3] = Sensors_and_actuators_ball_an_P.D_Value[3];
    tmp_0[0] = Sensors_and_actuators_ball_an_B.Reshapeu[0];
    tmp_0[1] = Sensors_and_actuators_ball_an_B.Reshapeu[1];
    C1 = tmp[0] * tmp_0[0];
    C1 += tmp[2] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Dkuk_e[0] = C1;

    /* Sum: '<S65>/Add1' */
    Sensors_and_actuators_ball_an_B.yhatkk1_g[0] =
      Sensors_and_actuators_ball_an_B.Ckxhatkk1_e[0] +
      Sensors_and_actuators_ball_an_B.Dkuk_e[0];

    /* Sum: '<S65>/Sum' */
    Sensors_and_actuators_ball_an_B.Sum_i[0] =
      Sensors_and_actuators_ball_an_B.Reshapey[0] -
      Sensors_and_actuators_ball_an_B.yhatkk1_g[0];

    /* Product: '<S65>/D[k]*u[k]' */
    C1 = tmp[1] * tmp_0[0];
    C1 += tmp[3] * tmp_0[1];
    Sensors_and_actuators_ball_an_B.Dkuk_e[1] = C1;

    /* Sum: '<S65>/Add1' */
    Sensors_and_actuators_ball_an_B.yhatkk1_g[1] =
      Sensors_and_actuators_ball_an_B.Ckxhatkk1_e[1] +
      Sensors_and_actuators_ball_an_B.Dkuk_e[1];

    /* Sum: '<S65>/Sum' */
    Sensors_and_actuators_ball_an_B.Sum_i[1] =
      Sensors_and_actuators_ball_an_B.Reshapey[1] -
      Sensors_and_actuators_ball_an_B.yhatkk1_g[1];

    /* Product: '<S65>/Product3' incorporates:
     *  Product: '<S36>/B[k]*u[k]'
     *  Product: '<S65>/C[k]*xhat[k|k-1]'
     */
    tmp_3 = &Sensors_and_actuators_ball_an_B.Conversion[0];
    tmp_0[0] = Sensors_and_actuators_ball_an_B.Sum_i[0];
    tmp_0[1] = Sensors_and_actuators_ball_an_B.Sum_i[1];
    for (i_0 = 0; i_0 < 4; i_0++) {
      C1 = tmp_3[i_0] * tmp_0[0];
      C1 += tmp_3[i_0 + 4] * tmp_0[1];
      Sensors_and_actuators_ball_an_B.Product3_h[i_0] = C1;
    }
  }

  /* End of Outputs for SubSystem: '<S36>/MeasurementUpdate' */

  /* Sum: '<S36>/Add' */
  Sensors_and_actuators_ball_an_B.Add[0] =
    (Sensors_and_actuators_ball_an_B.Bkuk[0] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[0]) +
    Sensors_and_actuators_ball_an_B.Product3_h[0];
  Sensors_and_actuators_ball_an_B.Add[1] =
    (Sensors_and_actuators_ball_an_B.Bkuk[1] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[1]) +
    Sensors_and_actuators_ball_an_B.Product3_h[1];
  Sensors_and_actuators_ball_an_B.Add[2] =
    (Sensors_and_actuators_ball_an_B.Bkuk[2] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[2]) +
    Sensors_and_actuators_ball_an_B.Product3_h[2];
  Sensors_and_actuators_ball_an_B.Add[3] =
    (Sensors_and_actuators_ball_an_B.Bkuk[3] +
     Sensors_and_actuators_ball_an_B.Akxhatkk1[3]) +
    Sensors_and_actuators_ball_an_B.Product3_h[3];

  /* Reshape: '<S36>/Reshape' */
  Sensors_and_actuators_ball_an_B.Reshape[0] =
    Sensors_and_actuators_ball_an_B.Add[0];
  Sensors_and_actuators_ball_an_B.Reshape[1] =
    Sensors_and_actuators_ball_an_B.Add[1];
  Sensors_and_actuators_ball_an_B.Reshape[2] =
    Sensors_and_actuators_ball_an_B.Add[2];
  Sensors_and_actuators_ball_an_B.Reshape[3] =
    Sensors_and_actuators_ball_an_B.Add[3];
  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* DataTypeConversion: '<S110>/Conversion' incorporates:
     *  Constant: '<S67>/KalmanGainL'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_nb[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainL_Value_a[0], 18U * sizeof
           (real_T));

    /* DataTypeConversion: '<S111>/Conversion' incorporates:
     *  Constant: '<S67>/KalmanGainM'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_k2[0],
           &Sensors_and_actuators_ball_an_P.KalmanGainM_Value_m[0], 18U * sizeof
           (real_T));

    /* DataTypeConversion: '<S112>/Conversion' */
    Sensors_and_actuators_ball_an_B.Conversion_d = 0.0;

    /* DataTypeConversion: '<S113>/Conversion' incorporates:
     *  Constant: '<S67>/CovarianceZ'
     */
    memcpy(&Sensors_and_actuators_ball_an_B.Conversion_j[0],
           &Sensors_and_actuators_ball_an_P.CovarianceZ_Value_b[0], 36U * sizeof
           (real_T));

    /* DataTypeConversion: '<S78>/Conversion' incorporates:
     *  Constant: '<S5>/P0'
     */
    for (i = 0; i < 36; i++) {
      Sensors_and_actuators_ball_an_B.Conversion_ks[i] = (real32_T)
        Sensors_and_actuators_ball_an_P.P0_Value_j[i];
    }

    /* End of DataTypeConversion: '<S78>/Conversion' */
  }

  /* DataTypeConversion: '<S83>/Conversion' */
  for (i = 0; i < 6; i++) {
    Sensors_and_actuators_ball_an_B.Conversion_e[i] =
      Sensors_and_actuators_ball_an_B.MemoryX_k[i];
  }

  /* End of DataTypeConversion: '<S83>/Conversion' */

  /* Product: '<S87>/A[k]*xhat[k|k-1]' incorporates:
   *  Constant: '<S5>/A'
   */
  tmp_3 = &Sensors_and_actuators_ball_an_P.A_Value_m[0];
  for (i = 0; i < 6; i++) {
    tmp_1[i] = Sensors_and_actuators_ball_an_B.Conversion_e[i];
  }

  for (i_0 = 0; i_0 < 6; i_0++) {
    tmp_2[i_0] = 0.0;
    for (i = 0; i < 6; i++) {
      C1 = tmp_2[i_0];
      C1 += tmp_3[6 * i + i_0] * tmp_1[i];
      tmp_2[i_0] = C1;
    }

    Sensors_and_actuators_ball_an_B.Akxhatkk1_b[i_0] = tmp_2[i_0];
  }

  /* End of Product: '<S87>/A[k]*xhat[k|k-1]' */

  /* Reshape: '<S5>/Reshapeu' */
  Sensors_and_actuators_ball_an_B.Reshapeu_g[0] =
    Sensors_and_actuators_ball_an_B.Gain6[0];
  Sensors_and_actuators_ball_an_B.Reshapeu_g[1] =
    Sensors_and_actuators_ball_an_B.Gain6[1];
  Sensors_and_actuators_ball_an_B.Reshapeu_g[2] =
    Sensors_and_actuators_ball_an_B.Gain6[2];

  /* Outputs for Enabled SubSystem: '<S87>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S116>/Enable'
   */
  /* Product: '<S87>/B[k]*u[k]' incorporates:
   *  Constant: '<S5>/B'
   *  Product: '<S116>/C[k]*xhat[k|k-1]'
   *  Product: '<S116>/Product3'
   */
  tmp_3 = &Sensors_and_actuators_ball_an_P.B_Value_p[0];

  /* End of Outputs for SubSystem: '<S87>/MeasurementUpdate' */
  r0Oc[0] = Sensors_and_actuators_ball_an_B.Reshapeu_g[0];
  r0Oc[1] = Sensors_and_actuators_ball_an_B.Reshapeu_g[1];
  r0Oc[2] = Sensors_and_actuators_ball_an_B.Reshapeu_g[2];
  for (i_0 = 0; i_0 < 6; i_0++) {
    C1 = tmp_3[i_0] * r0Oc[0];
    C1 += tmp_3[i_0 + 6] * r0Oc[1];
    C1 += tmp_3[i_0 + 12] * r0Oc[2];
    Sensors_and_actuators_ball_an_B.Bkuk_n[i_0] = C1;
  }

  if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
    /* Reshape: '<S5>/Reshapey' */
    Sensors_and_actuators_ball_an_B.Reshapey_m[0] =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction.theta1;
    Sensors_and_actuators_ball_an_B.Reshapey_m[1] =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction.theta2;
    Sensors_and_actuators_ball_an_B.Reshapey_m[2] =
      Sensors_and_actuators_ball_an_B.sf_MATLABFunction.Zc;

    /* Outputs for Enabled SubSystem: '<S87>/MeasurementUpdate' incorporates:
     *  EnablePort: '<S116>/Enable'
     */
    if (rtmIsMajorTimeStep(Sensors_and_actuators_ball_a_M)) {
      /* Constant: '<S5>/Enable' */
      if (Sensors_and_actuators_ball_an_P.Enable_Value_c) {
        Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = true;
      } else {
        if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE) {
          /* Disable for Outport: '<S116>/L*(y[k]-yhat[k|k-1])' */
          for (i = 0; i < 6; i++) {
            Sensors_and_actuators_ball_an_B.Product3[i] =
              Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0_k;
          }

          /* End of Disable for Outport: '<S116>/L*(y[k]-yhat[k|k-1])' */
          Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = false;
        }
      }

      /* End of Constant: '<S5>/Enable' */
    }

    /* End of Outputs for SubSystem: '<S87>/MeasurementUpdate' */
  }

  /* Outputs for Enabled SubSystem: '<S87>/MeasurementUpdate' incorporates:
   *  EnablePort: '<S116>/Enable'
   */
  if (Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE) {
    /* Product: '<S116>/C[k]*xhat[k|k-1]' incorporates:
     *  Constant: '<S5>/C'
     *  Product: '<S116>/Product3'
     *  Product: '<S87>/B[k]*u[k]'
     */
    tmp_3 = &Sensors_and_actuators_ball_an_P.C_Value_k[0];
    for (i = 0; i < 6; i++) {
      tmp_1[i] = Sensors_and_actuators_ball_an_B.Conversion_e[i];
    }

    for (i_0 = 0; i_0 < 3; i_0++) {
      r0Oc[i_0] = 0.0;
      for (i = 0; i < 6; i++) {
        C1 = r0Oc[i_0];
        C1 += tmp_3[3 * i + i_0] * tmp_1[i];
        r0Oc[i_0] = C1;
      }

      Sensors_and_actuators_ball_an_B.Ckxhatkk1[i_0] = r0Oc[i_0];
    }

    /* Product: '<S116>/D[k]*u[k]' incorporates:
     *  Constant: '<S5>/D'
     */
    memcpy(&A10[0], &Sensors_and_actuators_ball_an_P.D_Value_o[0], 9U * sizeof
           (real_T));
    r0Oc[0] = Sensors_and_actuators_ball_an_B.Reshapeu_g[0];
    r0Oc[1] = Sensors_and_actuators_ball_an_B.Reshapeu_g[1];
    r0Oc[2] = Sensors_and_actuators_ball_an_B.Reshapeu_g[2];
    for (i = 0; i < 3; i++) {
      C1 = A10[i] * r0Oc[0];
      C1 += A10[i + 3] * r0Oc[1];
      C1 += A10[i + 6] * r0Oc[2];
      Sensors_and_actuators_ball_an_B.Dkuk[i] = C1;

      /* Sum: '<S116>/Add1' */
      Sensors_and_actuators_ball_an_B.yhatkk1[i] =
        Sensors_and_actuators_ball_an_B.Ckxhatkk1[i] +
        Sensors_and_actuators_ball_an_B.Dkuk[i];

      /* Sum: '<S116>/Sum' */
      Sensors_and_actuators_ball_an_B.Sum_p[i] =
        Sensors_and_actuators_ball_an_B.Reshapey_m[i] -
        Sensors_and_actuators_ball_an_B.yhatkk1[i];
    }

    /* End of Product: '<S116>/D[k]*u[k]' */

    /* Product: '<S116>/Product3' incorporates:
     *  Product: '<S116>/C[k]*xhat[k|k-1]'
     *  Product: '<S87>/B[k]*u[k]'
     */
    tmp_3 = &Sensors_and_actuators_ball_an_B.Conversion_nb[0];
    r0Oc[0] = Sensors_and_actuators_ball_an_B.Sum_p[0];
    r0Oc[1] = Sensors_and_actuators_ball_an_B.Sum_p[1];
    r0Oc[2] = Sensors_and_actuators_ball_an_B.Sum_p[2];
    for (i_0 = 0; i_0 < 6; i_0++) {
      C1 = tmp_3[i_0] * r0Oc[0];
      C1 += tmp_3[i_0 + 6] * r0Oc[1];
      C1 += tmp_3[i_0 + 12] * r0Oc[2];
      Sensors_and_actuators_ball_an_B.Product3[i_0] = C1;
    }
  }

  /* End of Outputs for SubSystem: '<S87>/MeasurementUpdate' */

  /* Sum: '<S87>/Add' */
  for (i = 0; i < 6; i++) {
    Sensors_and_actuators_ball_an_B.Add_l[i] =
      (Sensors_and_actuators_ball_an_B.Bkuk_n[i] +
       Sensors_and_actuators_ball_an_B.Akxhatkk1_b[i]) +
      Sensors_and_actuators_ball_an_B.Product3[i];
  }

  /* End of Sum: '<S87>/Add' */

  /* Reshape: '<S87>/Reshape' */
  for (i = 0; i < 6; i++) {
    Sensors_and_actuators_ball_an_B.Reshape_h[i] =
      Sensors_and_actuators_ball_an_B.Add_l[i];
  }

  /* End of Reshape: '<S87>/Reshape' */
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
  /* Update for Integrator: '<S4>/MemoryX' */
  Sensors_and_actuators_ball_a_DW.MemoryX_IWORK = 0;

  /* Update for Integrator: '<S5>/MemoryX' */
  Sensors_and_actuators_ball_a_DW.MemoryX_IWORK_g = 0;
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
  int32_T i;
  XDot_Sensors_and_actuators_ba_T *_rtXdot;
  _rtXdot = ((XDot_Sensors_and_actuators_ba_T *)
             Sensors_and_actuators_ball_a_M->derivs);

  /* Derivatives for Integrator: '<S4>/MemoryX' */
  _rtXdot->MemoryX_CSTATE[0] = Sensors_and_actuators_ball_an_B.Reshape[0];
  _rtXdot->MemoryX_CSTATE[1] = Sensors_and_actuators_ball_an_B.Reshape[1];
  _rtXdot->MemoryX_CSTATE[2] = Sensors_and_actuators_ball_an_B.Reshape[2];
  _rtXdot->MemoryX_CSTATE[3] = Sensors_and_actuators_ball_an_B.Reshape[3];

  /* Derivatives for Integrator: '<S5>/MemoryX' */
  for (i = 0; i < 6; i++) {
    _rtXdot->MemoryX_CSTATE_l[i] = Sensors_and_actuators_ball_an_B.Reshape_h[i];
  }

  /* End of Derivatives for Integrator: '<S5>/MemoryX' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Derivatives for TransferFcn: '<S123>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_b = 0.0;
  _rtXdot->TransferFcn_CSTATE_b += Sensors_and_actuators_ball_an_P.TransferFcn_A
    * Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b;
  _rtXdot->TransferFcn_CSTATE_b +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Derivatives for TransferFcn: '<S128>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE_k = 0.0;
  _rtXdot->TransferFcn_CSTATE_k +=
    Sensors_and_actuators_ball_an_P.TransferFcn_A_b *
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k;
  _rtXdot->TransferFcn_CSTATE_k +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem_h.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement1' */

  /* Derivatives for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Derivatives for TransferFcn: '<S133>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += Sensors_and_actuators_ball_an_P.TransferFcn_A_p
    * Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE +=
    Sensors_and_actuators_ball_an_B.EnabledSubsystem_c.OutportBufferForOut1;

  /* End of Derivatives for SubSystem: '<Root>/Position Measurement2' */
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

  /* Start for Enabled SubSystem: '<S123>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem);

  /* End of Start for SubSystem: '<S123>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S123>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1);

  /* End of Start for SubSystem: '<S123>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement' */

  /* Start for Enabled SubSystem: '<S128>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem_h);

  /* End of Start for SubSystem: '<S128>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S128>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_m);

  /* End of Start for SubSystem: '<S128>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement1' */

  /* Start for Enabled SubSystem: '<S133>/Enabled Subsystem' */
  Sensors__EnabledSubsystem_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem_c);

  /* End of Start for SubSystem: '<S133>/Enabled Subsystem' */

  /* Start for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
  Sensors_EnabledSubsystem1_Start
    (&Sensors_and_actuators_ball_a_DW.EnabledSubsystem1_j);

  /* End of Start for SubSystem: '<S133>/Enabled Subsystem1' */
  /* End of Start for SubSystem: '<Root>/Position Measurement2' */

  /* Start for Enabled SubSystem: '<S36>/MeasurementUpdate' */
  Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE_e = false;

  /* End of Start for SubSystem: '<S36>/MeasurementUpdate' */

  /* Start for Enabled SubSystem: '<S87>/MeasurementUpdate' */
  Sensors_and_actuators_ball_a_DW.MeasurementUpdate_MODE = false;

  /* End of Start for SubSystem: '<S87>/MeasurementUpdate' */
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__o = POS_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig__n = POS_ZCSIG;
  Sensors_and_actuators_b_PrevZCX.EMC_ENCODER_POS_SET_BL1_Trig_ZC = POS_ZCSIG;

  {
    int32_T i;

    /* InitializeConditions for Integrator: '<S4>/MemoryX' incorporates:
     *  Integrator: '<S5>/MemoryX'
     */
    if (rtmIsFirstInitCond(Sensors_and_actuators_ball_a_M)) {
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[0] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[1] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[2] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE[3] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[0] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[1] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[2] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[3] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[4] = 0.0;
      Sensors_and_actuators_ball_an_X.MemoryX_CSTATE_l[5] = 0.0;
    }

    Sensors_and_actuators_ball_a_DW.MemoryX_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S4>/MemoryX' */

    /* InitializeConditions for Integrator: '<S5>/MemoryX' */
    Sensors_and_actuators_ball_a_DW.MemoryX_IWORK_g = 1;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement' */
    /* InitializeConditions for TransferFcn: '<S123>/Transfer Fcn' */
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_b = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S123>/Enabled Subsystem' */
    Sensors_a_EnabledSubsystem_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem);

    /* End of SystemInitialize for SubSystem: '<S123>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S123>/Enabled Subsystem1' */
    Sensors__EnabledSubsystem1_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem1);

    /* End of SystemInitialize for SubSystem: '<S123>/Enabled Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement1' */
    /* InitializeConditions for TransferFcn: '<S128>/Transfer Fcn' */
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE_k = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S128>/Enabled Subsystem' */
    Sensors_a_EnabledSubsystem_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem_h,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem_h);

    /* End of SystemInitialize for SubSystem: '<S128>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S128>/Enabled Subsystem1' */
    Sensors__EnabledSubsystem1_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1_m,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem1_m);

    /* End of SystemInitialize for SubSystem: '<S128>/Enabled Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement1' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Position Measurement2' */
    /* InitializeConditions for TransferFcn: '<S133>/Transfer Fcn' */
    Sensors_and_actuators_ball_an_X.TransferFcn_CSTATE = 0.0;

    /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem' */
    Sensors_a_EnabledSubsystem_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem_c,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem_c);

    /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S133>/Enabled Subsystem1' */
    Sensors__EnabledSubsystem1_Init
      (&Sensors_and_actuators_ball_an_B.EnabledSubsystem1_j,
       &Sensors_and_actuators_ball_an_P.EnabledSubsystem1_j);

    /* End of SystemInitialize for SubSystem: '<S133>/Enabled Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<Root>/Position Measurement2' */

    /* SystemInitialize for Enabled SubSystem: '<S36>/MeasurementUpdate' */
    /* SystemInitialize for Outport: '<S65>/L*(y[k]-yhat[k|k-1])' */
    Sensors_and_actuators_ball_an_B.Product3_h[0] =
      Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
    Sensors_and_actuators_ball_an_B.Product3_h[1] =
      Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
    Sensors_and_actuators_ball_an_B.Product3_h[2] =
      Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;
    Sensors_and_actuators_ball_an_B.Product3_h[3] =
      Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0;

    /* End of SystemInitialize for SubSystem: '<S36>/MeasurementUpdate' */

    /* SystemInitialize for Enabled SubSystem: '<S87>/MeasurementUpdate' */
    /* SystemInitialize for Outport: '<S116>/L*(y[k]-yhat[k|k-1])' */
    for (i = 0; i < 6; i++) {
      Sensors_and_actuators_ball_an_B.Product3[i] =
        Sensors_and_actuators_ball_an_P.Lykyhatkk1_Y0_k;
    }

    /* End of SystemInitialize for Outport: '<S116>/L*(y[k]-yhat[k|k-1])' */
    /* End of SystemInitialize for SubSystem: '<S87>/MeasurementUpdate' */

    /* set "at time zero" to false */
    if (rtmIsFirstInitCond(Sensors_and_actuators_ball_a_M)) {
      rtmSetFirstInitCond(Sensors_and_actuators_ball_a_M, 0);
    }
  }
}

/* Model terminate function */
void Sensors_and_actuators_ball_and_plate_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier' */
  /* Terminate for S-Function (rti_commonblock): '<S118>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 1 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_1, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_1);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier1' */
  /* Terminate for S-Function (rti_commonblock): '<S119>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier1/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 2 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_2, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_2);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier1' */

  /* Terminate for Atomic SubSystem: '<Root>/Outputs to Amplifier2' */
  /* Terminate for S-Function (rti_commonblock): '<S120>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Outputs to Amplifier2/DAC_CLASS1_BL1 --- */
  /* --- [RTI120X, DAC C1] - Channel: 3 --- */

  /* All channel outputs are set to high impedance state */
  DacCl1AnalogOut_setOutputHighZ(pRTIDacC1AnalogOut_Ch_3, DAC_CLASS1_HIGH_Z_ON);

  /* Deactivates AnalogOut functionality */
  DacCl1AnalogOut_stop(pRTIDacC1AnalogOut_Ch_3);

  /* End of Terminate for SubSystem: '<Root>/Outputs to Amplifier2' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement' */
  /* Terminate for Triggered SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S122>/S-Function1' incorporates:
   *  Constant: '<S12>/Constant'
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

  /* End of Terminate for SubSystem: '<S12>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S121>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 1 - Port: 1 - Channel: 1 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_1_DioCl_2_Port_1_Ch1);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement1' */
  /* Terminate for Triggered SubSystem: '<S13>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S127>/S-Function1' incorporates:
   *  Constant: '<S13>/Constant'
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

  /* End of Terminate for SubSystem: '<S13>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S126>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement1/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 2 - Port: 1 - Channel: 3 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_2_DioCl_2_Port_1_Ch3);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement1' */

  /* Terminate for Atomic SubSystem: '<Root>/Position Measurement2' */
  /* Terminate for Triggered SubSystem: '<S14>/EMC_ENCODER_POS_SET_BL1' */
  /* Terminate for S-Function (rti_commonblock): '<S132>/S-Function1' incorporates:
   *  Constant: '<S14>/Constant'
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

  /* End of Terminate for SubSystem: '<S14>/EMC_ENCODER_POS_SET_BL1' */

  /* Terminate for S-Function (rti_commonblock): '<S131>/S-Function1' */

  /* --- Sensors_and_actuators_ball_and_plate/Position Measurement2/EMC_ENCODER_BL1 --- */
  /* --- [RTIEMC, Encoder] - DIO class: 2 - Unit: 3 - Port: 1 - Channel: 5 --- */
  {
    /* Deactivates encoder interface functionality */
    DioCl2EncoderIn_stop(pRTIEmcEncoder_Unit_3_DioCl_2_Port_1_Ch5);
  }

  /* End of Terminate for SubSystem: '<Root>/Position Measurement2' */
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
