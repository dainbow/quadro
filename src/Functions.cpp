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
//! Tests DoubleCompare function
//!
//! @param [in] num1 "num1" parameter of DoubleCompare function
//! @param [in] num2 "num2" parameter of DoubleCompare function
//! @param [in] correctAnswer correct return of DoubleCompare(num1,num2)
//--------------------------------------------------------------------

void TestDoubleCompare(const double num1, const double num2, const bool correctAnswer) {
    bool answer = DoubleCompare(num1, num2);
    const char* isTestOk = (answer == correctAnswer) ? "correct" : "wrong";

    printf("[%s] IsApproxZero(%lf,%lf) = %d, expected %d\n", isTestOk, num1, num2, answer, correctAnswer);
}

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
    *x = DoubleCompare(localX, -0) ? 0 : localX;

    return 1;
}

//--------------------------------------------------------------------
//! Tests SolveLinear function (in case of 1 root)
//!
//! @param [in] a "a" parameter of SolveLinear function
//! @param [in] b "b" parameter of SolveLinear function
//! @param [in] correctRootsCount correct count of roots of equation
//! @param [in] correctX1 correct 1st root
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

//--------------------------------------------------------------------
//! Tests SolveQuad function (in case of 2 roots)
//!
//! @param [in] a "a" parameter of SolveQuad function
//! @param [in] b "b" parameter of SolveQuad function
//! @param [in] c "c" parameter of SolveQuad function
//! @param [in] correctRootsCount correct count of roots of equation
//! @param [in] correctX1 correct 1st root
//! @param [in] correctX2 correct 2nd root
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
//! Prints an answer to square equation
//!
//! @param [in] rootsCount How many roots
//! @param [out] x1 Pointer to the 1st root
//! @param [out] x2 Pointer to the 2nd root
//!
//! @note In case of irrelevant value of rootsCount
//!       prints "Error"
//--------------------------------------------------------------------

void PrintAnswer(const int rootsCount, double* x1, double* x2) {
    assert(isfinite(rootsCount));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    switch (rootsCount) {
        case 0:
            printf("The equation does not have any solution.\n");
            break;
        case 1:
            printf("The equation has 1 solution: %3f\n", *x1);
            break;
        case 2:
            printf("The equation has 2 solutions: %3f and %3f\n", *x1, *x2);
            break;
        case INF_ROOTS:
            printf("Solutions of this equation are all numbers\n");
            break;
        default:
            printf("Error\n");
            break;
    }
}

//--------------------------------------------------------------------
//! Clear stdin
//--------------------------------------------------------------------

void FlushInput() {
    while (getchar() != '\n');
}

//--------------------------------------------------------------------
//! Asks for 3 numbers - coefficients of square equation
//!
//! @param [in] a Pointer to the 1st coefficient
//! @param [in] b Pointer to the 2nd coefficient
//! @param [in] c Pointer to the 3d coefficient
//!
//! @note In case of wrong input will ask user for numbers again
//--------------------------------------------------------------------

void ReadCoeffs(double* a, double* b, double* c) {
    assert(a != nullptr);
    assert(b != nullptr);
    assert(c != nullptr);

    assert(a != b);
    assert(a != c);
    assert(b != c);

    while (scanf("%lf %lf %lf", a, b, c) != 3) {
        printf("Please enter coefficients of the equation in format \"a b c\" (3 numbers) \n");
        FlushInput();
    }
}

//--------------------------------------------------------------------
//! Tests IsApproxZero, SolveLinear, SolveQuad functions
//--------------------------------------------------------------------

void TestAll() {
    TestDoubleCompare(0.00001, 0, true);
    TestDoubleCompare(0, 0, true);
    TestDoubleCompare(0.001, 0, false);
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
