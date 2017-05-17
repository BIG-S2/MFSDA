/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_stat_sif_mex.c
 *
 * Code generation for function '_coder_stat_sif_mex'
 *
 */

/* Include files */
#include "stat_sif.h"
#include "_coder_stat_sif_mex.h"
#include "stat_sif_terminate.h"
#include "_coder_stat_sif_api.h"
#include "stat_sif_initialize.h"
#include "stat_sif_data.h"

/* Variable Definitions */
static jmp_buf emlrtJBEnviron;

/* Function Declarations */
static void stat_sif_mexFunction(stat_sifStackData *SD, int32_T nlhs, mxArray
  *plhs[3], int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void stat_sif_mexFunction(stat_sifStackData *SD, int32_T nlhs, mxArray
  *plhs[3], int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4, 8,
                        "stat_sif");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "stat_sif");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  stat_sif_api(SD, inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  stat_sif_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  stat_sifStackData *stat_sifStackDataGlobal = NULL;
  stat_sifStackDataGlobal = (stat_sifStackData *)mxCalloc(1, 1U * sizeof
    (stat_sifStackData));
  mexAtExit(stat_sif_atexit);

  /* Initialize the memory manager. */
  omp_init_lock(&emlrtLockGlobal);
  omp_init_nest_lock(&emlrtNestLockGlobal);

  /* Module initialization. */
  stat_sif_initialize();
  st.tls = emlrtRootTLSGlobal;
  emlrtSetJmpBuf(&st, &emlrtJBEnviron);
  if (setjmp(emlrtJBEnviron) == 0) {
    /* Dispatch the entry-point. */
    stat_sif_mexFunction(stat_sifStackDataGlobal, nlhs, plhs, nrhs, prhs);
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
  } else {
    omp_destroy_lock(&emlrtLockGlobal);
    omp_destroy_nest_lock(&emlrtNestLockGlobal);
    emlrtReportParallelRunTimeError(&st);
  }

  mxFree(stat_sifStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal,
                     emlrtLockerFunction, omp_get_num_procs());
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_stat_sif_mex.c) */
