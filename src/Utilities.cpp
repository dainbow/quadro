#include <math.h>
#include <assert.h>
#include <float.h>
#include <stdio.h>
#include "Utilities.h"

//--------------------------------------------------------------------
//! Compares 2 double numbers
//!
//! @param [in] num1 1st number which will be checked
//! @param [in] num2 2nd number which will be checked
//!
//! @return 1 if numbers are equal, 0 if isn't.
//--------------------------------------------------------------------

bool DoubleCompare(const double num1, const double num2) {
    assert(isfinite(num1));
    assert(isfinite(num2));

    return fabs(num1 - num2) <= DBL_EPSILON;
}

//--------------------------------------------------------------------
//! Clear stdin
//--------------------------------------------------------------------

void FlushInput() {
    while (getchar() != '\n');
}
