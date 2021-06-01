/*
 * BallAndPlateMeasurement_data.c
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

#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"

/* Model block global parameters (default storage) */
real_T rtP_UseUserDefinedBallReference = 1.0;/* Variable: UseUserDefinedBallReference
                                              * Referenced by: '<S14>/Controller'
                                              */
real_T rtP_UseUserDefinedPlateReference = 1.0;/* Variable: UseUserDefinedPlateReference
                                               * Referenced by: '<S14>/Controller'
                                               */

/* Block parameters (default storage) */
P_BallAndPlateMeasurement_T BallAndPlateMeasurement_P = {
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
   * Referenced by: '<S20>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S20>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A
   * Referenced by: '<S20>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C
   * Referenced by: '<S20>/Transfer Fcn'
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
   * Referenced by: '<S25>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S25>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_b
   * Referenced by: '<S25>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_j
   * Referenced by: '<S25>/Transfer Fcn'
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
   * Referenced by: '<S30>/Const'
   */
  0.01,

  /* Expression: -0.98
   * Referenced by: '<S30>/Const1'
   */
  -0.98,

  /* Computed Parameter: TransferFcn_A_p
   * Referenced by: '<S30>/Transfer Fcn'
   */
  -1.0,

  /* Computed Parameter: TransferFcn_C_m
   * Referenced by: '<S30>/Transfer Fcn'
   */
  1.0,

  /* Expression: 0.001
   * Referenced by: '<S12>/mm2m'
   */
  0.001,

  /* Computed Parameter: Pp_Aref_Y0
   * Referenced by: '<S14>/Pp_Aref'
   */
  0.0,

  /* Computed Parameter: Pp_Bref_Y0
   * Referenced by: '<S14>/Pp_Bref'
   */
  0.0,

  /* Computed Parameter: Pp_Cref_Y0
   * Referenced by: '<S14>/Pp_Cref'
   */
  0.0,

  /* Computed Parameter: Pb_Xref_Y0
   * Referenced by: '<S14>/Pb_Xref'
   */
  0.0,

  /* Computed Parameter: Pb_Yref_Y0
   * Referenced by: '<S14>/Pb_Yref'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S14>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Init'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/State'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<Root>/Delay'
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
   * Referenced by: '<Root>/Switch'
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

  /* Start of '<S30>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S32>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S30>/Enabled Subsystem1' */

  /* Start of '<S30>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S31>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S31>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S30>/Enabled Subsystem' */

  /* Start of '<S25>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S27>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S25>/Enabled Subsystem1' */

  /* Start of '<S25>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S26>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S26>/Constant'
     */
    -1.0
  }
  ,

  /* End of '<S25>/Enabled Subsystem' */

  /* Start of '<S20>/Enabled Subsystem1' */
  {
    /* Expression: [0]
     * Referenced by: '<S22>/Out1'
     */
    0.0
  }
  ,

  /* End of '<S20>/Enabled Subsystem1' */

  /* Start of '<S20>/Enabled Subsystem' */
  {
    /* Expression: [0]
     * Referenced by: '<S21>/Out1'
     */
    0.0,

    /* Expression: -1
     * Referenced by: '<S21>/Constant'
     */
    -1.0
  }
  /* End of '<S20>/Enabled Subsystem' */
};
