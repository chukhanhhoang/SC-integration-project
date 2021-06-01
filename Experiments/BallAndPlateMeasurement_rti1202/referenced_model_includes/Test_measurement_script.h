/*
 * Code generation for system model 'Test_measurement_script'
 * For more details, see corresponding source file Test_measurement_script.c
 *
 */

#ifndef RTW_HEADER_Test_measurement_script_h_
#define RTW_HEADER_Test_measurement_script_h_
#ifndef Test_measurement_script_COMMON_INCLUDES_
# define Test_measurement_script_COMMON_INCLUDES_
#include <rti_assert.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                            /* Test_measurement_script_COMMON_INCLUDES_ */

#include "Test_measurement_script_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Parameters (default storage) */
struct P_Test_measurement_script_T_ {
  real_T Switch2_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */
  real_T Switch3_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch3'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch4'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_measurement_scri_T {
  const char_T **errorStatus;
};

typedef struct {
  RT_MODEL_Test_measurement_scr_T rtm;
} MdlrefDW_Test_measurement_scr_T;

/* Model block global parameters (default storage) */
extern real_T rtP_UseUserDefinedBallReference;/* Variable: UseUserDefinedBallReference
                                               * Referenced by: '<Root>/Constant'
                                               */
extern real_T rtP_UseUserDefinedPlateReference;/* Variable: UseUserDefinedPlateReference
                                                * Referenced by: '<Root>/Constant1'
                                                */

/* Model reference registration function */
extern void Test_measurement_scr_initialize(const char_T **rt_errorStatus,
  RT_MODEL_Test_measurement_scr_T *const Test_measurement_script_M);
extern void Test_measurement_script_Init(real_T *rty_I_A, real_T *rty_I_B,
  real_T *rty_I_C);
extern void Test_measurement_script(const real_T *rtu_Pp_Aref_in, const real_T
  *rtu_Pp_Bref_in, const real_T *rtu_Pp_Cref_in, const real_T *rtu_Pb_Xref_in,
  const real_T *rtu_Pb_Yref_in, real_T *rty_I_A, real_T *rty_I_B, real_T
  *rty_I_C, real_T *rty_Pp_Aref, real_T *rty_Pp_Bref, real_T *rty_Pp_Cref,
  real_T *rty_Pb_Xref, real_T *rty_Pb_Yref);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Test_measurement_script'
 * '<S1>'   : 'Test_measurement_script/RTI Data'
 * '<S2>'   : 'Test_measurement_script/RTI Data/RTI Data Store'
 * '<S3>'   : 'Test_measurement_script/RTI Data/RTI Data Store/RTI Data Store'
 * '<S4>'   : 'Test_measurement_script/RTI Data/RTI Data Store/RTI Data Store/RTI Data Store'
 */
#endif                               /* RTW_HEADER_Test_measurement_script_h_ */
