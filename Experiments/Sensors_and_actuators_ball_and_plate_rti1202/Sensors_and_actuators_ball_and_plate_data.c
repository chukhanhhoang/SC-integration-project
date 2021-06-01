/*
 * Sensors_and_actuators_ball_and_plate_data.c
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

#include "Sensors_and_actuators_ball_and_plate.h"
#include "Sensors_and_actuators_ball_and_plate_private.h"

/* Block parameters (default storage) */
P_Sensors_and_actuators_ball__T Sensors_and_actuators_ball_an_P = {
  /* Variable: denc_mi
   * Referenced by:
   *   '<S4>/Transfer Fcn2'
   *   '<S5>/Transfer Fcn2'
   *   '<S6>/Transfer Fcn2'
   */
  { 1.0, 1800.0, 720000.0 },

  /* Variable: numc_mi
   * Referenced by:
   *   '<S4>/Transfer Fcn2'
   *   '<S5>/Transfer Fcn2'
   *   '<S6>/Transfer Fcn2'
   */
  { 2.9545543796228832E+6, 2.9545543796228832E+8, 6.5656763991619635E+9 },

  /* Expression: 3
   * Referenced by: '<S7>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S7>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S7>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S7>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S8>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S8>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S8>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S8>/DSPscale'
   */
  0.1,

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

  /* Expression: 10
   * Referenced by: '<S10>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S10>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S10>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S10>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S19>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S19>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S19>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S19>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S10>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S11>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S11>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S11>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S11>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S24>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S24>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_b
   * Referenced by: '<S24>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S24>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S11>/mm2m'
   */
  0.001,

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
   * Referenced by: '<S29>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S29>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_p
   * Referenced by: '<S29>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S29>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S12>/mm2m'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S4>/Integrator2'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S4>/Integrator2'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S4>/Integrator2'
   */
  -3.0,

  /* Expression: 0
   * Referenced by: '<S5>/Integrator2'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S5>/Integrator2'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S5>/Integrator2'
   */
  -3.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator2'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<S6>/Integrator2'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S6>/Integrator2'
   */
  -3.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  128U,

  /* Start of '<S29>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S31>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S29>/Enabled Subsystem1' */

  /* Start of '<S29>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S30>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S30>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S29>/Enabled Subsystem' */

  /* Start of '<S24>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S26>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S24>/Enabled Subsystem1' */

  /* Start of '<S24>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S25>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S25>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S24>/Enabled Subsystem' */

  /* Start of '<S19>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S21>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S19>/Enabled Subsystem1' */

  /* Start of '<S19>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S20>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S20>/Constant'
     */
    -1.0
  }
  /* End of '<S19>/Enabled Subsystem' */
};
