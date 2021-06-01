/*********************** dSPACE target specific file *************************

   Header file BallAndPlateMeasurement_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue Jun  1 17:08:16 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_BallAndPlateMeasurement_trc_ptr_h_
#define RTI_HEADER_BallAndPlateMeasurement_trc_ptr_h_

/* Include the model header file. */
#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"
#ifdef EXTERN_C
#undef EXTERN_C
#endif

#ifdef __cplusplus
#define EXTERN_C                       extern "C"
#else
#define EXTERN_C                       extern
#endif

/*
 *  Declare the global TRC pointers
 */
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_0;
EXTERN_C volatile uint32_T *p_0_BallAndPlateMeasurement_uint32_T_1;
EXTERN_C volatile uint16_T *p_0_BallAndPlateMeasurement_uint16_T_2;
EXTERN_C volatile uint8_T *p_0_BallAndPlateMeasurement_uint8_T_3;
EXTERN_C volatile boolean_T *p_0_BallAndPlateMeasurement_boolean_T_4;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_5;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_6;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_7;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_8;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_9;
EXTERN_C volatile real_T *p_0_BallAndPlateMeasurement_real_T_10;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_0;
EXTERN_C volatile uint8_T *p_1_BallAndPlateMeasurement_uint8_T_1;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_2;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_3;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_4;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_5;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_6;
EXTERN_C volatile real_T *p_1_BallAndPlateMeasurement_real_T_7;
EXTERN_C volatile real_T *p_2_BallAndPlateMeasurement_real_T_0;
EXTERN_C volatile uint32_T *p_2_BallAndPlateMeasurement_uint32_T_1;
EXTERN_C volatile uint16_T *p_2_BallAndPlateMeasurement_uint16_T_2;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_3;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_4;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_5;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_6;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_7;
EXTERN_C volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_8;
EXTERN_C volatile uint32_T *p_3_BallAndPlateMeasurement_uint32_T_0;
EXTERN_C volatile real_T *p_3_BallAndPlateMeasurement_real_T_1;
EXTERN_C volatile uint16_T *p_3_BallAndPlateMeasurement_uint16_T_2;
EXTERN_C volatile real_T *p_3_BallAndPlateMeasurement_real_T_3;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void BallAndPlateMeasurement_rti_init_trc_pointers(void);

#endif                       /* RTI_HEADER_BallAndPlateMeasurement_trc_ptr_h_ */
