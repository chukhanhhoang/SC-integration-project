/*
 * Sensors_and_actuators_ball_and_plate_data.c
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

#include "Sensors_and_actuators_ball_and_plate.h"
#include "Sensors_and_actuators_ball_and_plate_private.h"

/* Block parameters (default storage) */
P_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_P = {
  /* Variable: ballLQRgain
   * Referenced by: '<Root>/Gain3'
   */
  { 1.2707120681244419E-15, 4.4721359549995876, 2.158789341731688E-17,
    1.8132103328222406, -4.4721359549995778, 1.2874049511538502E-15,
    -1.8132103328222398, 5.9942487436205844E-16 },

  /* Variable: denc_mi
   * Referenced by:
   *   '<Root>/Transfer Fcn1'
   *   '<Root>/Transfer Fcn2'
   *   '<Root>/Transfer Fcn3'
   */
  { 1.0, 1800.0, 720000.0 },

  /* Variable: numc_mi
   * Referenced by:
   *   '<Root>/Transfer Fcn1'
   *   '<Root>/Transfer Fcn2'
   *   '<Root>/Transfer Fcn3'
   */
  { 2.9545543796228832E+6, 2.9545543796228832E+8, 6.5656763991619635E+9 },

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch5'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch2'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S69>/L*(y[k]-yhat[k|k-1])'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S13>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S13>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S13>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S13>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S14>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S14>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S14>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S14>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S15>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S15>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S15>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S15>/DSPscale'
   */
  0.1,

  /* Expression: 10
   * Referenced by: '<S16>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S16>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S16>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S16>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S76>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S76>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S76>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S76>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S16>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S17>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S17>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S17>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S17>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S81>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S81>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_b
   * Referenced by: '<S81>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S81>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S17>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S18>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S18>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S18>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S18>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S86>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S86>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_p
   * Referenced by: '<S86>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S86>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S18>/mm2m'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 227
   * Referenced by: '<Root>/Constant10'
   */
  227.0,

  /* Expression: 1/(463-25)*0.4
   * Referenced by: '<Root>/Gain5'
   */
  0.00091324200913242006,

  /* Expression: 295
   * Referenced by: '<Root>/Constant4'
   */
  295.0,

  /* Expression: 1/(515-70)*0.4
   * Referenced by: '<Root>/Gain'
   */
  0.00089887640449438217,

  /* Expression: pInitialization.X0
   * Referenced by: '<S7>/X0'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0.32
   * Referenced by: '<Root>/Constant9'
   */
  0.32,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
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

  /* Expression: pi/4
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.78539816339744828,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/Sine Wave'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: pi/4
   * Referenced by: '<Root>/Sine Wave'
   */
  0.78539816339744828,

  /* Expression: pi/2
   * Referenced by: '<Root>/Sine Wave'
   */
  1.5707963267948966,

  /* Expression: 0
   * Referenced by: '<Root>/Constant13'
   */
  0.0,

  /* Expression: 0.32
   * Referenced by: '<Root>/Constant14'
   */
  0.32,

  /* Expression: 0.1
   * Referenced by: '<Root>/GainA'
   */
  0.1,

  /* Expression: 1000
   * Referenced by: '<S4>/Gain'
   */
  1000.0,

  /* Computed Parameter: LeadlagFilter_A
   * Referenced by: '<S4>/LeadlagFilter'
   */
  -3769.9111843077512,

  /* Computed Parameter: LeadlagFilter_C
   * Referenced by: '<S4>/LeadlagFilter'
   */
  -30159.289474462003,

  /* Computed Parameter: LeadlagFilter_D
   * Referenced by: '<S4>/LeadlagFilter'
   */
  8.9999999999999982,

  /* Computed Parameter: LeadlagFilter2_A
   * Referenced by: '<S4>/LeadlagFilter2'
   */
  -376.99111843077515,

  /* Computed Parameter: LeadlagFilter2_C
   * Referenced by: '<S4>/LeadlagFilter2'
   */
  -6408.8490133231762,

  /* Computed Parameter: LeadlagFilter2_D
   * Referenced by: '<S4>/LeadlagFilter2'
   */
  17.999999999999996,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S4>/Integrator1'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S4>/Integrator1'
   */
  -3.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch3'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<Root>/Integrator1'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<Root>/Integrator1'
   */
  -3.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch4'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 0.1
   * Referenced by: '<Root>/GainC'
   */
  0.1,

  /* Expression: 1000
   * Referenced by: '<S6>/Gain'
   */
  1000.0,

  /* Computed Parameter: LeadlagFilter_A_k
   * Referenced by: '<S6>/LeadlagFilter'
   */
  -3769.9111843077512,

  /* Computed Parameter: LeadlagFilter_C_d
   * Referenced by: '<S6>/LeadlagFilter'
   */
  -30159.289474462003,

  /* Computed Parameter: LeadlagFilter_D_j
   * Referenced by: '<S6>/LeadlagFilter'
   */
  8.9999999999999982,

  /* Computed Parameter: LeadlagFilter2_A_l
   * Referenced by: '<S6>/LeadlagFilter2'
   */
  -376.99111843077515,

  /* Computed Parameter: LeadlagFilter2_C_j
   * Referenced by: '<S6>/LeadlagFilter2'
   */
  -6408.8490133231762,

  /* Computed Parameter: LeadlagFilter2_D_b
   * Referenced by: '<S6>/LeadlagFilter2'
   */
  17.999999999999996,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S6>/Integrator1'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S6>/Integrator1'
   */
  -3.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Switch6'
   */
  0.5,

  /* Expression: 0.1
   * Referenced by: '<Root>/GainB'
   */
  0.1,

  /* Expression: 2*pi*10
   * Referenced by: '<S4>/Integrator Gain'
   */
  62.831853071795862,

  /* Expression: 2*pi*10
   * Referenced by: '<S6>/Integrator Gain'
   */
  62.831853071795862,

  /* Expression: pInitialization.A
   * Referenced by: '<S7>/A'
   */
  { 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    0.0 },

  /* Expression: pInitialization.B
   * Referenced by: '<S7>/B'
   */
  { 0.0, 0.0, 0.0, -2.7204993278279241, 0.0, 2.7204993278279241, 0.0, 0.0 },

  /* Expression: pInitialization.C
   * Referenced by: '<S7>/C'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0 },

  /* Expression: pInitialization.Z
   * Referenced by: '<S20>/CovarianceZ'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0 },

  /* Expression: pInitialization.L
   * Referenced by: '<S20>/KalmanGainL'
   */
  { 0.74999999999999878, 0.25000000000000006, -4.1488295014682325E-17,
    -1.2514628494325258E-16, 5.57874081837508E-16, 1.3073113514107436E-16, 0.75,
    0.24999999999999989 },

  /* Expression: pInitialization.M
   * Referenced by: '<S20>/KalmanGainM'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.D
   * Referenced by: '<S7>/D'
   */
  { 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.P0
   * Referenced by: '<S7>/P0'
   */
  { 1.1999999999999975E-5, 3.9999999999999905E-6, 3.7597772112438397E-22,
    -1.3315926518900046E-21, 3.9999999999999905E-6, 2.9999999999999984E-6,
    1.3236631593148067E-21, 8.4635538471429593E-23, 3.7597772112438397E-22,
    1.3236631593148067E-21, 1.2000000000000007E-5, 3.9999999999999973E-6,
    -1.3315926518900046E-21, 8.4635538471429593E-23, 3.9999999999999973E-6,
    2.9999999999999992E-6 },

  /* Expression: pInitialization.G
   * Referenced by: '<S7>/G'
   */
  { 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0 },

  /* Expression: pInitialization.H
   * Referenced by: '<S7>/H'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.N
   * Referenced by: '<S7>/N'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: pInitialization.Q
   * Referenced by: '<S7>/Q'
   */
  { 1.0E-6, 0.0, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0, 0.0, 0.0, 1.0E-6, 0.0, 0.0,
    0.0, 0.0, 1.0E-6 },

  /* Expression: pInitialization.R
   * Referenced by: '<S7>/R'
   */
  { 1.6E-5, 0.0, 0.0, 1.6E-5 },

  /* Expression: 0
   * Referenced by: '<Root>/Integrator2'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<Root>/Integrator2'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<Root>/Integrator2'
   */
  -3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Integrator3'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<Root>/Integrator3'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<Root>/Integrator3'
   */
  -3.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<S5>/Gain'
   */
  1000.0,

  /* Computed Parameter: LeadlagFilter_A_g
   * Referenced by: '<S5>/LeadlagFilter'
   */
  -3769.9111843077512,

  /* Computed Parameter: LeadlagFilter_C_e
   * Referenced by: '<S5>/LeadlagFilter'
   */
  -30159.289474462003,

  /* Computed Parameter: LeadlagFilter_D_k
   * Referenced by: '<S5>/LeadlagFilter'
   */
  8.9999999999999982,

  /* Computed Parameter: LeadlagFilter2_A_k
   * Referenced by: '<S5>/LeadlagFilter2'
   */
  -376.99111843077515,

  /* Computed Parameter: LeadlagFilter2_C_h
   * Referenced by: '<S5>/LeadlagFilter2'
   */
  -6408.8490133231762,

  /* Computed Parameter: LeadlagFilter2_D_i
   * Referenced by: '<S5>/LeadlagFilter2'
   */
  17.999999999999996,

  /* Expression: 2*pi*10
   * Referenced by: '<S5>/Integrator Gain'
   */
  62.831853071795862,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S5>/Integrator1'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S5>/Integrator1'
   */
  -3.0,

  /* Expression: true()
   * Referenced by: '<S7>/Enable'
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

  /* Start of '<S86>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S88>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S86>/Enabled Subsystem1' */

  /* Start of '<S86>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S87>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S87>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S86>/Enabled Subsystem' */

  /* Start of '<S81>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S83>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S81>/Enabled Subsystem1' */

  /* Start of '<S81>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S82>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S82>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S81>/Enabled Subsystem' */

  /* Start of '<S76>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S78>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S76>/Enabled Subsystem1' */

  /* Start of '<S76>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S77>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S77>/Constant'
     */
    -1.0
  }
  /* End of '<S76>/Enabled Subsystem' */
};
