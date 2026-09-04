/*
 * File: RollAxisAutopilot.c
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

#include "RollAxisAutopilot.h"
#include <math.h>
#include "rtwtypes.h"

/* Block signals and states (default storage) */
DW rtDW;

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void RollAxisAutopilot_step(void)
{
  real32_T rtb_Sum1;
  boolean_T tmp;

  /* Outputs for Atomic SubSystem: '<Root>/RollAngleReference' */
  /* UnitDelay: '<S4>/FixPt Unit Delay1' */
  rtb_Sum1 = rtDW.FixPtUnitDelay1_DSTATE;

  /* Outputs for Atomic SubSystem: '<Root>/BasicRollMode' */
  /* Logic: '<S3>/NotEngaged' incorporates:
   *  Inport: '<Root>/AP_Eng'
   *  Logic: '<S1>/NotEngaged'
   */
  tmp = !rtU.AP_Eng;

  /* End of Outputs for SubSystem: '<Root>/BasicRollMode' */

  /* Switch: '<S4>/Enable' incorporates:
   *  Logic: '<S3>/NotEngaged'
   */
  if (tmp) {
    /* Switch: '<S3>/RefSwitch' incorporates:
     *  Constant: '<S3>/LoThr'
     *  Constant: '<S3>/UpThr'
     *  Constant: '<S3>/Zero'
     *  Inport: '<Root>/Phi'
     *  Logic: '<S3>/Or'
     *  RelationalOperator: '<S3>/RefThreshold1'
     *  RelationalOperator: '<S3>/RefThreshold2'
     *  UnitDelay: '<S4>/FixPt Unit Delay1'
     */
    if ((rtU.Phi >= 6.0F) || (rtU.Phi <= -6.0F)) {
      rtDW.FixPtUnitDelay1_DSTATE = rtU.Phi;
    } else {
      rtDW.FixPtUnitDelay1_DSTATE = 0.0F;
    }

    /* End of Switch: '<S3>/RefSwitch' */
  }

  /* End of Switch: '<S4>/Enable' */
  /* End of Outputs for SubSystem: '<Root>/RollAngleReference' */

  /* Switch: '<Root>/ModeSwitch' incorporates:
   *  Abs: '<S3>/Abs'
   *  Constant: '<S3>/Three'
   *  Gain: '<S2>/DispGain'
   *  Inport: '<Root>/HDG_Mode'
   *  Inport: '<Root>/HDG_Ref'
   *  Inport: '<Root>/Psi'
   *  Inport: '<Root>/TAS'
   *  Inport: '<Root>/Turn_Knob'
   *  Product: '<S2>/Product'
   *  RelationalOperator: '<S3>/TKThreshold'
   *  Sum: '<S2>/Sum'
   *  Switch: '<S3>/TKSwitch'
   */
  if (rtU.HDG_Mode) {
    /* Outputs for Atomic SubSystem: '<Root>/HeadingMode' */
    rtb_Sum1 = (rtU.HDG_Ref - rtU.Psi) * 0.015F * rtU.TAS;

    /* End of Outputs for SubSystem: '<Root>/HeadingMode' */

    /* Outputs for Atomic SubSystem: '<Root>/RollAngleReference' */
  } else if ((real32_T)fabs(rtU.Turn_Knob) >= 3.0F) {
    rtb_Sum1 = rtU.Turn_Knob;

    /* End of Outputs for SubSystem: '<Root>/RollAngleReference' */
  }

  /* End of Switch: '<Root>/ModeSwitch' */

  /* Outputs for Atomic SubSystem: '<Root>/BasicRollMode' */
  /* DiscreteIntegrator: '<S1>/Integrator' */
  if (tmp || (rtDW.Integrator_PrevResetState != 0)) {
    rtDW.Integrator_DSTATE = 0.0F;
  }

  /* Saturate: '<S1>/DispLimit' */
  if (rtb_Sum1 > 30.0F) {
    rtb_Sum1 = 30.0F;
  } else if (rtb_Sum1 < -30.0F) {
    rtb_Sum1 = -30.0F;
  }

  /* Gain: '<S1>/DispGain' incorporates:
   *  Inport: '<Root>/Phi'
   *  Saturate: '<S1>/DispLimit'
   *  Sum: '<S1>/Sum'
   */
  rtb_Sum1 = (rtb_Sum1 - rtU.Phi) * 0.75F;

  /* Saturate: '<S1>/RateLimit' */
  if (rtb_Sum1 > 6.0F) {
    rtb_Sum1 = 6.0F;
  } else if (rtb_Sum1 < -6.0F) {
    rtb_Sum1 = -6.0F;
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Inport: '<Root>/Rate_FB'
   *  Saturate: '<S1>/RateLimit'
   */
  rtb_Sum1 -= rtU.Rate_FB;

  /* Sum: '<S1>/Sum2' incorporates:
   *  DiscreteIntegrator: '<S1>/Integrator'
   *  Gain: '<S1>/RateGain'
   */
  rtY.Ail_Cmd = 2.0F * rtb_Sum1 + rtDW.Integrator_DSTATE;

  /* Update for DiscreteIntegrator: '<S1>/Integrator' incorporates:
   *  Gain: '<S1>/IntGain'
   */
  rtDW.Integrator_DSTATE += 0.5F * rtb_Sum1 * 0.025F;
  if (rtDW.Integrator_DSTATE > 5.0F) {
    rtDW.Integrator_DSTATE = 5.0F;
  } else if (rtDW.Integrator_DSTATE < -5.0F) {
    rtDW.Integrator_DSTATE = -5.0F;
  }

  rtDW.Integrator_PrevResetState = (int8_T)tmp;

  /* End of Update for DiscreteIntegrator: '<S1>/Integrator' */
  /* End of Outputs for SubSystem: '<Root>/BasicRollMode' */

  /* Switch: '<Root>/EngSwitch' incorporates:
   *  Inport: '<Root>/AP_Eng'
   */
  if (rtU.AP_Eng) {
    /* Outputs for Atomic SubSystem: '<Root>/BasicRollMode' */
    /* Saturate: '<S1>/CmdLimit' */
    if (rtY.Ail_Cmd > 15.0F) {
      /* Sum: '<S1>/Sum2' incorporates:
       *  Outport: '<Root>/Ail_Cmd'
       */
      rtY.Ail_Cmd = 15.0F;
    } else if (rtY.Ail_Cmd < -15.0F) {
      /* Sum: '<S1>/Sum2' incorporates:
       *  Outport: '<Root>/Ail_Cmd'
       */
      rtY.Ail_Cmd = -15.0F;
    }

    /* End of Saturate: '<S1>/CmdLimit' */
    /* End of Outputs for SubSystem: '<Root>/BasicRollMode' */
  } else {
    /* Sum: '<S1>/Sum2' incorporates:
     *  Constant: '<Root>/Zero'
     *  Outport: '<Root>/Ail_Cmd'
     */
    rtY.Ail_Cmd = 0.0F;
  }

  /* End of Switch: '<Root>/EngSwitch' */
}

/* Model initialize function */
void RollAxisAutopilot_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
