/*********************** dSPACE target specific file *************************

   Header file MPC_Controller_trc_ptr.h:

   Declaration of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue Jun  1 16:44:25 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/
#ifndef RTI_HEADER_MPC_Controller_trc_ptr_h_
#define RTI_HEADER_MPC_Controller_trc_ptr_h_

/* Include the model header file. */
#include "MPC_Controller.h"
#include "MPC_Controller_private.h"
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
EXTERN_C volatile real_T *p_0_MPC_Controller_real_T_0;
EXTERN_C volatile boolean_T *p_0_MPC_Controller_boolean_T_1;
EXTERN_C volatile real_T *p_2_MPC_Controller_real_T_0;
EXTERN_C volatile uint16_T *p_2_MPC_Controller_uint16_T_1;
EXTERN_C volatile boolean_T *p_2_MPC_Controller_boolean_T_2;
EXTERN_C volatile real_T *p_3_MPC_Controller_real_T_0;
EXTERN_C volatile int32_T *p_3_MPC_Controller_int32_T_1;
EXTERN_C volatile boolean_T *p_3_MPC_Controller_boolean_T_2;

/*
 *  Declare the general function for TRC pointer initialization
 */
EXTERN_C void MPC_Controller_rti_init_trc_pointers(void);

#endif                                /* RTI_HEADER_MPC_Controller_trc_ptr_h_ */
