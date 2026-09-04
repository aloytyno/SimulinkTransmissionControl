/*
 * File: RollAxisAutopilot.h
 *
 * Code generated for Simulink model 'RollAxisAutopilot'.
 *
 * Model version                  : 13.1
 * Simulink Coder version         : 26.1 (R2026a) 20-Nov-2025
 * C/C++ source code generated on : Fri Sep  4 12:52:27 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. Traceability
 *    3. Safety precaution
 *    4. RAM efficiency
 * Validation result: Not run
 */

#ifndef RollAxisAutopilot_h_
#define RollAxisAutopilot_h_
#ifndef RollAxisAutopilot_COMMON_INCLUDES_
#define RollAxisAutopilot_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* RollAxisAutopilot_COMMON_INCLUDES_ */

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  real32_T FixPtUnitDelay1_DSTATE;     /* '<S4>/FixPt Unit Delay1' */
  real32_T Integrator_DSTATE;          /* '<S1>/Integrator' */
  int8_T Integrator_PrevResetState;    /* '<S1>/Integrator' */
} DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real32_T Phi;                        /* '<Root>/Phi' */
  real32_T Psi;                        /* '<Root>/Psi' */
  real32_T Rate_FB;                    /* '<Root>/Rate_FB' */
  real32_T TAS;                        /* '<Root>/TAS' */
  boolean_T AP_Eng;                    /* '<Root>/AP_Eng' */
  boolean_T HDG_Mode;                  /* '<Root>/HDG_Mode' */
  real32_T HDG_Ref;                    /* '<Root>/HDG_Ref' */
  real32_T Turn_Knob;                  /* '<Root>/Turn_Knob' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real32_T Ail_Cmd;                    /* '<Root>/Ail_Cmd' */
} ExtY;

/* Block signals and states (default storage) */
extern DW rtDW;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void RollAxisAutopilot_initialize(void);
extern void RollAxisAutopilot_step(void);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination
 */

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
 * '<Root>' : 'RollAxisAutopilot'
 * '<S1>'   : 'RollAxisAutopilot/BasicRollMode'
 * '<S2>'   : 'RollAxisAutopilot/HeadingMode'
 * '<S3>'   : 'RollAxisAutopilot/RollAngleReference'
 * '<S4>'   : 'RollAxisAutopilot/RollAngleReference/LatchPhi'
 */

/*-
 * Requirements for '<Root>': RollAxisAutopilot

 */
#endif                                 /* RollAxisAutopilot_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
