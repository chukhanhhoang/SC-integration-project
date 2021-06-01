/*
 * BallAndPlateMeasurement_data.c
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

#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"

/* Model block global parameters (default storage) */
real_T rtP_UseUserDefinedBallReference = 1.0;/* Variable: UseUserDefinedBallReference
                                              * Referenced by: '<Root>/Controller'
                                              */
real_T rtP_UseUserDefinedPlateReference = 1.0;/* Variable: UseUserDefinedPlateReference
                                               * Referenced by: '<Root>/Controller'
                                               */
real_T rtP_denc_mi[3] = { 1.0, 1800.0, 720000.0 } ;/* Variable: denc_mi
                                                    * Referenced by: '<Root>/Controller'
                                                    */

real_T rtP_numc_mi[3] = { 2.9545543796228832E+6, 2.9545543796228832E+8,
  6.5656763991619635E+9 } ;            /* Variable: numc_mi
                                        * Referenced by: '<Root>/Controller'
                                        */

/* Block parameters (default storage) */
P_BallAndPlateMeasurement_T BallAndPlateMeasurement_P = {
  /* Expression: 3
   * Referenced by: '<S4>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S4>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S4>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S4>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S5>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S5>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S5>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S5>/DSPscale'
   */
  0.1,

  /* Expression: 3
   * Referenced by: '<S6>/Saturation'
   */
  3.0,

  /* Expression: -3
   * Referenced by: '<S6>/Saturation'
   */
  -3.0,

  /* Expression: 10/3
   * Referenced by: '<S6>/Current2V'
   */
  3.3333333333333335,

  /* Expression: 1/10
   * Referenced by: '<S6>/DSPscale'
   */
  0.1,

  /* Expression: 10
   * Referenced by: '<S7>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S7>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S7>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S7>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S16>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S16>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S16>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S16>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S7>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S8>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S8>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S8>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S8>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S21>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S21>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_b
   * Referenced by: '<S21>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S21>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S8>/mm2m'
   */
  0.001,

  /* Expression: 10
   * Referenced by: '<S9>/Constant'
   */
  10.0,

  /* Expression: 29
   * Referenced by: '<S9>/ZP'
   */
  29.0,

  /* Expression: 8e-3
   * Referenced by: '<S9>/Inc2Pos'
   */
  0.008,

  /* Expression: 0
   * Referenced by: '<S9>/Pos_offset'
   */
  0.0,

  /* Expression: 0.01
   * Referenced by: '<S26>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S26>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_p
   * Referenced by: '<S26>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S26>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S9>/mm2m'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Init'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant5'
   */
  0.0,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<Root>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  128U,

  /* Start of '<S26>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S28>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S26>/Enabled Subsystem1' */

  /* Start of '<S26>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S27>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S27>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S26>/Enabled Subsystem' */

  /* Start of '<S21>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S23>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S21>/Enabled Subsystem1' */

  /* Start of '<S21>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S22>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S22>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S21>/Enabled Subsystem' */

  /* Start of '<S16>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S18>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S16>/Enabled Subsystem1' */

  /* Start of '<S16>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S17>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S17>/Constant'
     */
    -1.0
  }
  /* End of '<S16>/Enabled Subsystem' */
};
