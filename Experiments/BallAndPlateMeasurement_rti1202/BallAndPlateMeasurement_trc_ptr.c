/***************************************************************************

   Source file BallAndPlateMeasurement_trc_ptr.c:

   Definition of function that initializes the global TRC pointers

   RTI1202 7.15 (02-Nov-2020)
   Tue Jun  1 19:38:40 2021

   Copyright 2021, dSPACE GmbH. All rights reserved.

 *****************************************************************************/

/* Include header file. */
#include "BallAndPlateMeasurement_trc_ptr.h"
#include "BallAndPlateMeasurement.h"
#include "BallAndPlateMeasurement_private.h"

/* Compiler options to turn off optimization. */
#if !defined(DS_OPTIMIZE_INIT_TRC_POINTERS)
#ifdef _MCCPPC

#pragma options -nOt -nOr -nOi -nOx

#endif

#ifdef __GNUC__

#pragma GCC optimize ("O0")

#endif

#ifdef _MSC_VER

#pragma optimize ("", off)

#endif
#endif

/* Definition of Global pointers to data type transitions (for TRC-file access) */
volatile real_T *p_0_BallAndPlateMeasurement_real_T_0 = NULL;
volatile uint32_T *p_0_BallAndPlateMeasurement_uint32_T_1 = NULL;
volatile uint16_T *p_0_BallAndPlateMeasurement_uint16_T_2 = NULL;
volatile uint8_T *p_0_BallAndPlateMeasurement_uint8_T_3 = NULL;
volatile boolean_T *p_0_BallAndPlateMeasurement_boolean_T_4 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_5 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_6 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_7 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_8 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_9 = NULL;
volatile real_T *p_0_BallAndPlateMeasurement_real_T_10 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_0 = NULL;
volatile uint8_T *p_1_BallAndPlateMeasurement_uint8_T_1 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_2 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_3 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_4 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_5 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_6 = NULL;
volatile real_T *p_1_BallAndPlateMeasurement_real_T_7 = NULL;
volatile real_T *p_2_BallAndPlateMeasurement_real_T_0 = NULL;
volatile uint32_T *p_2_BallAndPlateMeasurement_uint32_T_1 = NULL;
volatile uint16_T *p_2_BallAndPlateMeasurement_uint16_T_2 = NULL;
volatile int8_T *p_2_BallAndPlateMeasurement_int8_T_3 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_5 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_6 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_7 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_8 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_9 = NULL;
volatile boolean_T *p_2_BallAndPlateMeasurement_boolean_T_10 = NULL;
volatile uint32_T *p_3_BallAndPlateMeasurement_uint32_T_0 = NULL;
volatile real_T *p_3_BallAndPlateMeasurement_real_T_1 = NULL;
volatile uint16_T *p_3_BallAndPlateMeasurement_uint16_T_2 = NULL;
volatile real_T *p_3_BallAndPlateMeasurement_real_T_3 = NULL;

/*
 *  Declare the functions, that initially assign TRC pointers
 */
static void rti_init_trc_pointers_0(void);

/* Global pointers to data type transitions are separated in different functions to avoid overloading */
static void rti_init_trc_pointers_0(void)
{
  p_0_BallAndPlateMeasurement_real_T_0 = &BallAndPlateMeasurement_B.Delay;
  p_0_BallAndPlateMeasurement_uint32_T_1 =
    &BallAndPlateMeasurement_B.SFunction1_o4;
  p_0_BallAndPlateMeasurement_uint16_T_2 =
    &BallAndPlateMeasurement_B.SFunction1_o6;
  p_0_BallAndPlateMeasurement_uint8_T_3 =
    &BallAndPlateMeasurement_B.SFunction1_o1_n[0];
  p_0_BallAndPlateMeasurement_boolean_T_4 =
    &BallAndPlateMeasurement_B.DataTypeConversion;
  p_0_BallAndPlateMeasurement_real_T_5 =
    &BallAndPlateMeasurement_B.EnabledSubsystem1_j.In1;
  p_0_BallAndPlateMeasurement_real_T_6 =
    &BallAndPlateMeasurement_B.EnabledSubsystem_c.OutportBufferForOut1;
  p_0_BallAndPlateMeasurement_real_T_7 =
    &BallAndPlateMeasurement_B.EnabledSubsystem1_m.In1;
  p_0_BallAndPlateMeasurement_real_T_8 =
    &BallAndPlateMeasurement_B.EnabledSubsystem_h.OutportBufferForOut1;
  p_0_BallAndPlateMeasurement_real_T_9 =
    &BallAndPlateMeasurement_B.EnabledSubsystem1.In1;
  p_0_BallAndPlateMeasurement_real_T_10 =
    &BallAndPlateMeasurement_B.EnabledSubsystem.OutportBufferForOut1;
  p_1_BallAndPlateMeasurement_real_T_0 =
    &BallAndPlateMeasurement_P.Saturation_UpperSat;
  p_1_BallAndPlateMeasurement_uint8_T_1 = &BallAndPlateMeasurement_P.Gain2_Gain;
  p_1_BallAndPlateMeasurement_real_T_2 =
    &BallAndPlateMeasurement_P.EnabledSubsystem1_j.Out1_Y0;
  p_1_BallAndPlateMeasurement_real_T_3 =
    &BallAndPlateMeasurement_P.EnabledSubsystem_c.Out1_Y0;
  p_1_BallAndPlateMeasurement_real_T_4 =
    &BallAndPlateMeasurement_P.EnabledSubsystem1_m.Out1_Y0;
  p_1_BallAndPlateMeasurement_real_T_5 =
    &BallAndPlateMeasurement_P.EnabledSubsystem_h.Out1_Y0;
  p_1_BallAndPlateMeasurement_real_T_6 =
    &BallAndPlateMeasurement_P.EnabledSubsystem1.Out1_Y0;
  p_1_BallAndPlateMeasurement_real_T_7 =
    &BallAndPlateMeasurement_P.EnabledSubsystem.Out1_Y0;
  p_2_BallAndPlateMeasurement_real_T_0 =
    &BallAndPlateMeasurement_DW.Delay_DSTATE;
  p_2_BallAndPlateMeasurement_uint32_T_1 =
    &BallAndPlateMeasurement_DW.Add1_DWORK1;
  p_2_BallAndPlateMeasurement_uint16_T_2 =
    &BallAndPlateMeasurement_DW.Add_DWORK1;
  p_2_BallAndPlateMeasurement_int8_T_3 =
    &BallAndPlateMeasurement_DW.SwitchCase_ActiveSubsystem;
  p_2_BallAndPlateMeasurement_boolean_T_5 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_j.EnabledSubsystem1_MODE;
  p_2_BallAndPlateMeasurement_boolean_T_6 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem_c.EnabledSubsystem_MODE;
  p_2_BallAndPlateMeasurement_boolean_T_7 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem1_m.EnabledSubsystem1_MODE;
  p_2_BallAndPlateMeasurement_boolean_T_8 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem_h.EnabledSubsystem_MODE;
  p_2_BallAndPlateMeasurement_boolean_T_9 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem1.EnabledSubsystem1_MODE;
  p_2_BallAndPlateMeasurement_boolean_T_10 =
    &BallAndPlateMeasurement_DW.EnabledSubsystem.EnabledSubsystem_MODE;
  p_3_BallAndPlateMeasurement_uint32_T_0 = &BallAndPlateMeasurement_Y.Status;
  p_3_BallAndPlateMeasurement_real_T_1 = &BallAndPlateMeasurement_Y.Frames;
  p_3_BallAndPlateMeasurement_uint16_T_2 = &BallAndPlateMeasurement_Y.Pb_X;
  p_3_BallAndPlateMeasurement_real_T_3 = &BallAndPlateMeasurement_Y.I_A;
}

void BallAndPlateMeasurement_rti_init_trc_pointers(void)
{
  rti_init_trc_pointers_0();
}
