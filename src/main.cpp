#include <stdio.h>
#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdarg.h>
#include "globals.h"
#include "funcs.cpp"


int main() {
#ifdef _USE_TESTS_
    TestAll();
#endif

    printf("Solve quadratic equation\n");
    printf("Please enter coefficients of the equation in format \"a b c\" (3 numbers)\n");

    double a = NAN, b = NAN, c = NAN;
    ReadCoeffs(&a, &b, &c);

    double x1 = NAN, x2 = NAN;
    int rootsCount = SolveQuad(a, b, c, &x1, &x2);

    PrintAnswer(rootsCount, &x1, &x2);

    return 0;
}

