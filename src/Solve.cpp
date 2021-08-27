#include <math.h>
#include <assert.h>

#include "Utilities.h"
#include "Solve.h"

//--------------------------------------------------------------------
//! Solves a linear equation ax + b = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [out] x1 pointer to the root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//!       return INF_ROOTS
//--------------------------------------------------------------------

int SolveLinear(const double a, const double b, double* x) {
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x != nullptr);

    if (DoubleCompare(a, 0)) {
        return DoubleCompare(b, 0) ? INF_ROOTS : 0;
    }

    double localX = -b/a;
    *x = DoubleCompare(localX, 0) ? 0 : localX; //-0 fix

    return 1;
}

//--------------------------------------------------------------------
//! Solves a square equation ax2 + bx + c = 0
//!
//! @param [in] a a-coefficient
//! @param [in] b b-coefficient
//! @param [in] c c-coefficient
//! @param [out] x1 pointer to the 1st root
//! @param [out] x2 pointer to the 2nd root
//!
//! @return Number of roots
//!
//! @note In case of infinite number of roots,
//!       return INF_ROOTS
//--------------------------------------------------------------------

int SolveQuad(const double a, const double b, const double c, double* x1, double* x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (!DoubleCompare(a, 0)) {
        double d = b*b - 4*a*c;
        double twiceA = 2*a;

        if (DoubleCompare(c, 0)) {
            *x1 = 0;
            if (!DoubleCompare(b, 0)) {
                SolveLinear(a, b, x2);

                return 2;
            }

            return 1;
        }

        if (DoubleCompare(d, 0)) {
            *x1 = (-b)/(twiceA);

            return 1;
        }
        else if (d > 0) {
            d = sqrt(d);

            *x1 = (-b + d)/(twiceA);
            *x2 = (-b - d)/(twiceA);

            return 2;
        }
        else {
            return 0;
        }
    }
    return SolveLinear(b, c, x1);
}
