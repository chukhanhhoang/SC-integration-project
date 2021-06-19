/*********************** dSPACE target specific file *************************

   Header file Sensors_and_actuators_ball_and_plate_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue Jun  8 16:23:11 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_Sensors_and_actuators_ball_and_plate_trc_ptr_h_
#define RTI_HEADER_Sensors_and_actuators_ball_and_plate_trc_ptr_h_

/* Include the model header file. */
#include "Sensors_and_actuators_ball_and_plate.h"
#include "Sensors_and_actuators_ball_and_plate_private.h"
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
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_0;
EXTERN_C volatile uint32_T *p_0_Sensors_and_actuators_ball_and_plate_uint32_T_1;
EXTERN_C volatile real32_T *p_0_Sensors_and_actuators_ball_and_plate_real32_T_2;
EXTERN_C volatile uint16_T *p_0_Sensors_and_actuators_ball_and_plate_uint16_T_3;
EXTERN_C volatile uint8_T *p_0_Sensors_and_actuators_ball_and_plate_uint8_T_4;
EXTERN_C volatile boolean_T
  *p_0_Sensors_and_actuators_ball_and_plate_boolean_T_5;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_6;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_7;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_8;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_9;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_10;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_11;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_12;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_13;
EXTERN_C volatile real_T *p_0_Sensors_and_actuators_ball_and_plate_real_T_14;
EXTERN_C volatile boolean_T
  *p_1_Sensors_and_actuators_ball_and_plate_boolean_T_0;
EXTERN_C volatile real_T *p_1_Sensors_and_actuators_ball_and_plate_real_T_1;
EXTERN_C volatile boolean_T
  *p_1_Sensors_and_actuators_ball_and_plate_boolean_T_2;
EXTERN_C volatile real_T *p_1_Sensors_and_actuators_ball_and_plate_real_T_3;
EXTERN_C volatile boolean_T
  *p_1_Sensors_and_actuators_ball_and_plate_boolean_T_4;
EXTERN_C volatile real_T *p_1_Sensors_and_actuators_ball_and_plate_real_T_5;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_0;
EXTERN_C volatile boolean_T
  *p_2_Sensors_and_actuators_ball_and_plate_boolean_T_1;
EXTERN_C volatile uint8_T *p_2_Sensors_and_actuators_ball_and_plate_uint8_T_2;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_3;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_4;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_5;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_6;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_7;
EXTERN_C volatile real_T *p_2_Sensors_and_actuators_ball_and_plate_real_T_8;
EXTERN_C volatile real_T *p_3_Sensors_and_actuators_ball_and_plate_real_T_0;
EXTERN_C volatile uint32_T *p_3_Sensors_and_actuators_ball_and_plate_uint32_T_1;
EXTERN_C volatile int_T *p_3_Sensors_and_actuators_ball_and_plate_int_T_2;
EXTERN_C volatile uint16_T *p_3_Sensors_and_actuators_ball_and_plate_uint16_T_3;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_4;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_5;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_6;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_7;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_8;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_9;
EXTERN_C volatile boolean_T
  *p_3_Sensors_and_actuators_ball_and_plate_boolean_T_10;
EXTERN_C volatile real_T *p_4_Sensors_and_actuators_ball_and_plate_real_T_0;
EXTERN_C volatile real_T *p_6_Sensors_and_actuators_ball_and_plate_real_T_0;
EXTERN_C volatile uint16_T *p_6_Sensors_and_actuators_ball_and_plate_uint16_T_1;
EXTERN_C volatile uint32_T *p_6_Sensors_and_actuators_ball_and_plate_uint32_T_2;
EXTERN_C volatile real_T *p_6_Sensors_and_actuators_ball_and_plate_real_T_3;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void Sensors_and_actuators_ball_and_plate_rti_init_trc_pointers(void);

#endif          /* RTI_HEADER_Sensors_and_actuators_ball_and_plate_trc_ptr_h_ */
