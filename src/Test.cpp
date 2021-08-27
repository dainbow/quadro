#include <stdio.h>
#include <stdarg.h>

#include "Utilities.h"
#include "Solve.h"

//--------------------------------------------------------------------
//! Tests DoubleCompare function
//!
//! @param [in] num1 "num1" parameter of DoubleCompare function
//! @param [in] num2 "num2" parameter of DoubleCompare function
//! @param [in] correctAnswer correct return of DoubleCompare(num1,num2)
//--------------------------------------------------------------------

void TestDoubleCompare(const double num1, const double num2, const bool correctAnswer) {
    bool answer = DoubleCompare(num1, num2);
    const char* isTestOk = (answer == correctAnswer) ? "correct" : "wrong";

    printf("[%s] DoubleCompare(%lf,%lf) = %d, expected %d\n", isTestOk, num1, num2, answer, correctAnswer);
}

//--------------------------------------------------------------------
//! Tests SolveLinear function
//!
//! @param [in] a "a" parameter of SolveLinear function
//! @param [in] b "b" parameter of SolveLinear function
//! @param [in] correctRootsCount correct count of roots of equation
//! @param [in] correctX1 correct 1st root
//!
//! @note If correctAnswer = 1, you should write 4 arguments
//!		  If correctAnswer = 0 or = INF_ROOTS, you should write 3 arguments
//--------------------------------------------------------------------

void TestSolveLinear(const double a, const double b, int correctRootsCount, ...) {
    double x1 = 0;
    int rootsCount = SolveLinear(a, b, &x1);
    switch (correctRootsCount) {
        case 1: {
            va_list args;
            va_start(args, correctRootsCount);

            double correctX1 = va_arg(args, double);
            va_end(args);

            const char* isTestOk = (rootsCount == correctRootsCount && DoubleCompare(x1, correctX1)) ? "correct" : "wrong";

            printf("[%s] SolveLinear(%lf, %lf) = %d; x1 = %lf, expected %d; x1 = %g\n", isTestOk, a, b, rootsCount, x1, correctRootsCount, correctX1);
            break;
        }
        case 0:
        case INF_ROOTS: {
            const char* isTestOk = (rootsCount == correctRootsCount) ? "correct" : "wrong";

            printf("[%s] SolveLinear(%lf, %lf) = %d, expected %d\n", isTestOk, a, b, rootsCount, correctRootsCount);
            break;
        }
        default:
            printf("Invalid correctRootsCount\n");
            break;
    }
}

//--------------------------------------------------------------------
//! Tests SolveQuad function (in case of 2 roots)
//!
//! @param [in] a "a" parameter of SolveQuad function
//! @param [in] b "b" parameter of SolveQuad function
//! @param [in] c "c" parameter of SolveQuad function
//! @param [in] correctRootsCount correct count of roots of equation
//! @param [in] correctX1 correct 1st root
//! @param [in] correctX2 correct 2nd root
//!
//! @note If correctAnswer = 2, you should write 6 arguments
//!		  If correctAnswer = 1, you should write 5 arguments
//!		  If correctAnswer = 0 or = INF_ROOTS, you should write 4 arguments
//--------------------------------------------------------------------

void TestSolveQuad(const double a, const double b, const double c, const int correctRootsCount, ...) {
    double x1 = 0, x2 = 0;
    int rootsCount = SolveQuad(a, b, c, &x1, &x2);

    switch(correctRootsCount) {
        case 2: {
            va_list args;
            va_start(args, correctRootsCount);

            double correctX1 = va_arg(args,double);
            double correctX2 = va_arg(args,double);
            va_end(args);

            const char* isTestOk = (rootsCount == correctRootsCount && ((DoubleCompare(x1, correctX1) && DoubleCompare(x2, correctX2)) || (DoubleCompare(x2, correctX1) && DoubleCompare(x1, correctX2)))) ? "correct" : "wrong";
            printf("[%s] SolveQuad(%lf, %lf, %lf) = %d; x1 = %lf; x2 = %lf, expected %d; x1 = %lf; x2 = %lf\n", isTestOk, a, b, c, rootsCount, x1, x2, correctRootsCount, correctX1, correctX2);
            break;
        }
        case 1:{
            va_list args;
            va_start(args, correctRootsCount);

            double correctX1 = va_arg(args,double);
            va_end(args);

            const char* isTestOk = (rootsCount == correctRootsCount && DoubleCompare(x1, correctX1)) ? "correct" : "wrong";
            printf("[%s] SolveQuad(%lf, %lf, %lf) = %d; x1 = %lf, expected %d; x1 = %lf\n", isTestOk, a, b, c, rootsCount, x1, correctRootsCount, correctX1);
            break;
        }
        case 0:
        case INF_ROOTS: {
            const char* isTestOk = (rootsCount == correctRootsCount) ? "correct" : "wrong";
            printf("[%s] SolveQuad(%lf, %lf, %lf) = %d, expected %d\n", isTestOk, a, b, c, rootsCount, correctRootsCount);
            break;
        }
        default: {
            printf("Invalid correctRootsCount\n");
            break;
        }
    }
}

//--------------------------------------------------------------------
//! Tests IsApproxZero, SolveLinear, SolveQuad functions
//--------------------------------------------------------------------

void TestAll() {
    TestDoubleCompare(0.00001, 0, true);
    TestDoubleCompare(0, 0, true);
    TestDoubleCompare(0.00001, 0, false);
    TestDoubleCompare(-1, 0, false);

    TestSolveLinear(4, -6, 1, 1.5);
    TestSolveLinear(0, 0, INF_ROOTS);
    TestSolveLinear(0, 1, 0);
    TestSolveLinear(1, 0, 1, 0.0);

    TestSolveQuad(1, -9, 20, 2, 4.0, 5.0);
    TestSolveQuad(0, 1, 0, 1, 0.0);
    TestSolveQuad(1, 3, 2.25, 1, -1.5);
    TestSolveQuad(1, -4, 3.75, 2, 1.5, 2.5);
    TestSolveQuad(1, 2, 0, 2, 0.0, -2.0);
    TestSolveQuad(0, 0, 4, 0.0);
    TestSolveQuad(0, 0, 0, INF_ROOTS);
}

