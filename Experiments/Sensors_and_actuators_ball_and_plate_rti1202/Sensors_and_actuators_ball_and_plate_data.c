/*
 * Sensors_and_actuators_ball_and_plate_data.c
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

#include "Sensors_and_actuators_ball_and_plate.h"
#include "Sensors_and_actuators_ball_and_plate_private.h"

/* Block parameters (default storage) */
P_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_P = {
  /* Variable: I_0
   * Referenced by: '<Root>/Constant9'
   */
  0.37278,

  /* Variable: ballLQRgain
   * Referenced by: '<Root>/Gain4'
   */
  { 1.3441226883421604E-15, 3.1622776601683791, 5.8042812222043912E-16,
    1.1355218409352279, -3.1622776601683809, 5.2911548939603954E-16,
    -1.1355218409352277, 1.27694503421296E-16 },

  /* Variable: plateLQRgain
   * Referenced by: '<Root>/Gain3'
   */
  { 7.62031544639005E-16, 1.2909944487358038, -1.2909944487358047,
    -1.4907119849998565, 0.7453559924999289, 0.74535599249992646,
    0.33333333333340787, 0.333333333333406, 0.33333333333340676,
    3.923279978294025E-17, 0.009409459115295532, -0.00940945911529556,
    -0.01086510750628986, 0.0054325537531449888, 0.0054325537531449567,
    0.0084456499628654241, 0.0084456499628650147, 0.0084456499628650147 },

  /* Expression: 0
   * Referenced by: '<S65>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S116>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S9>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S9>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S9>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S9>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S10>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S10>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S10>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S10>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S11>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S11>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S11>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S11>/DSPscale'
   */
  0.1,

  /* Expression: 10
   * Referenced by: '<S12>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S12>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S12>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S12>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S123>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S123>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S123>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S123>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S12>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S13>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S13>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S13>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S13>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S128>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S128>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_b
   * Referenced by: '<S128>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S128>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S13>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S14>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S14>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S14>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S14>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S133>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S133>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_p
   * Referenced by: '<S133>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S133>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S14>/mm2m'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S4>/X0'
   */
  { 0.1, 0.0, 0.0, 0.0 },

  /* Expression: 0.1
   * Referenced by: '<Root>/Sine Wave'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: pi/5
   * Referenced by: '<Root>/Sine Wave'
   */
  0.62831853071795862,

  /* Expression: pi/2
   * Referenced by: '<Root>/Sine Wave'
   */
  1.5707963267948966,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: pi/5
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.62831853071795862,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant13'
   */
  0.0,

  /* Expression: 0.32
   * Referenced by: '<Root>/Constant14'
   */
  0.32,

  /* Expression: 0
   * Referenced by: '<Root>/Constant8'
   */
  0.0,

  /* Expression: pInitialization.X0
   * Referenced by: '<S5>/X0'
   */
  { 0.0, 0.0, 0.32, 0.0, 0.0, 0.0 },

  /* Expression: 1
   * Referenced by: '<Root>/Gain6'
   */
  1.0,

  /* Expression: 295
   * Referenced by: '<Root>/Constant2'
   */
  295.0,

  /* Expression: -1/(515-70)*0.4
   * Referenced by: '<Root>/Gain'
   */
  -0.00089887640449438217,

  /* Expression: 227
   * Referenced by: '<Root>/Constant10'
   */
  227.0,

  /* Expression: 1/(463-25)*0.4
   * Referenced by: '<Root>/Gain5'
   */
  0.00091324200913242006,

  /* Expression: 0.32
   * Referenced by: '<Root>/Constant7'
   */
  0.32,

  /* Expression: pInitialization.A
   * Referenced by: '<S4>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S4>/B'
   */
  { 0.0, 0.0, 0.0, -4.905, 0.0, 4.905, 0.0, 0.0 },

  /* Expression: pInitialization.C
   * Referenced by: '<S4>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S16>/CovarianceZ'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S16>/KalmanGainL'
   */
  { 0.7051337429877812, 0.22360679774997896, -7.7878179131015826E-17,
    7.5298631443597475E-18, -1.3062378790115902E-18, 6.1500968242291616E-18,
    0.7051337429877812, 0.22360679774997916 },

  /* Expression: pInitialization.M
   * Referenced by: '<S16>/KalmanGainM'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.D
   * Referenced by: '<S4>/D'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.P0
   * Referenced by: '<S4>/P0'
   */
  { 0.70513374298778131, 0.22360679774997916, 5.8752462726133123E-17,
    1.0473093582432821E-17, 0.22360679774997916, 0.15767269825495428,
    -1.1320203405397979E-17, 1.0428066493353506E-17, 5.8752462726133123E-17,
    -1.1320203405397979E-17, 0.70513374298778064, 0.22360679774997916,
    1.0473093582432821E-17, 1.0428066493353506E-17, 0.22360679774997916,
    0.15767269825495445 },

  /* Expression: pInitialization.G
   * Referenced by: '<S4>/G'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: pInitialization.H
   * Referenced by: '<S4>/H'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.N
   * Referenced by: '<S4>/N'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Q
   * Referenced by: '<S4>/Q'
   */
  { 0.05, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0,
    0.05 },

  /* Expression: pInitialization.R
   * Referenced by: '<S4>/R'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /* Expression: pInitialization.A
   * Referenced by: '<S5>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -139.83050847457628, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, -139.83050847457628, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, -39.473684210526315
  },

  /* Expression: pInitialization.B
   * Referenced by: '<S5>/B'
   */
  { 0.0, 0.0, 0.0, 0.0, -365.56995679627784, 0.79744816586921852, 0.0, 0.0, 0.0,
    316.5928694459563, 182.78497839813892, 0.79744816586921852, 0.0, 0.0, 0.0,
    -316.5928694459563, 182.78497839813892, 0.79744816586921852 },

  /* Expression: pInitialization.C
   * Referenced by: '<S5>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S67>/CovarianceZ'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S67>/KalmanGainL'
   */
  { 0.22361250663943213, -2.4299166250887359E-18, 3.2924057932272796E-23,
    1.2765627853604121E-6, -1.6190304391990938E-23, 2.456337880965676E-27, 0.0,
    0.22361250663943213, -0.0, 0.0, 1.2765627853604121E-6, 0.0, -0.0, 0.0,
    0.22367813500916159, 0.0, 0.0, 1.5954040588321149E-5 },

  /* Expression: pInitialization.M
   * Referenced by: '<S67>/KalmanGainM'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /* Expression: pInitialization.D
   * Referenced by: '<S5>/D'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.P0
   * Referenced by: '<S5>/P0'
   */
  { 0.22361250663943213, 0.0, 0.0, 1.2765627853657956E-6, 0.0, 0.0, 0.0,
    0.22361250663943213, 0.0, 0.0, 1.2765627853657956E-6, 0.0, 0.0, 0.0,
    0.22367813500916164, 0.0, 0.0, 1.5954040588312588E-5, 1.2765627853657956E-6,
    0.0, 0.0, 0.00017878787878205165, 0.0, 0.0, 0.0, 1.2765627853657956E-6, 0.0,
    0.0, 0.00017878787878205165, 0.0, 0.0, 0.0, 1.5954040588312588E-5, 0.0, 0.0,
    0.000633333330109269 },

  /* Expression: pInitialization.G
   * Referenced by: '<S5>/G'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: pInitialization.H
   * Referenced by: '<S5>/H'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /* Expression: pInitialization.N
   * Referenced by: '<S5>/N'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Q
   * Referenced by: '<S5>/Q'
   */
  { 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.05, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.05 },

  /* Expression: pInitialization.R
   * Referenced by: '<S5>/R'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: true()
   * Referenced by: '<S4>/Enable'
   */
  1,

  /* Expression: true()
   * Referenced by: '<S5>/Enable'
   */
  1,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  128U,

  /* Start of '<S133>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S135>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S133>/Enabled Subsystem1' */

  /* Start of '<S133>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S134>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S134>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S133>/Enabled Subsystem' */

  /* Start of '<S128>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S130>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S128>/Enabled Subsystem1' */

  /* Start of '<S128>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S129>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S129>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S128>/Enabled Subsystem' */

  /* Start of '<S123>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S125>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S123>/Enabled Subsystem1' */

  /* Start of '<S123>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S124>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S124>/Constant'
     */
    -1.0
  }
  /* End of '<S123>/Enabled Subsystem' */
};
