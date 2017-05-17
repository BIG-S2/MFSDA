/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * permute.h
 *
 * Code generation for function 'permute'
 *
 */

#ifndef PERMUTE_H
#define PERMUTE_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "stat_lpks_wob_types.h"

/* Function Declarations */
extern void permute(const emlrtStack *sp, const emxArray_real_T *a,
                    emxArray_real_T *b);

#endif

/* End of code generation (permute.h) */
