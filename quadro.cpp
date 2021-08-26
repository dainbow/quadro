#include <stdio.h>
#include <math.h>
#include <float.h>
#include <cassert>

const int INF_ROOTS = -1;
const double presicion = 0.0001;

bool IsApproxZero(double num);
void testIsApproxZero(double num, bool correctAnswer);
int SolveLinear(double a, double b, double* x1);
void testSolveLinear(double a, double b, double* x1, int CorrectAnswer, double CorrectX1);
void testSolveLinear(double a, double b, double* x1, int CorrectAnswer);
int SolveQuad(double a, double b, double c, double* x1, double* x2);
void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer, double CorrectX1, double CorrectX2);
void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer, double CorrectX1);
void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer);
void printAnswer(int rootsCount, double* x1, double* x2);
void FlushInput();
void ReadCoeffs(double* a, double* b, double* c);
void TestAll();

int main(){

    TestAll();

    printf("Solve quadratic equation\n");
    printf("Please enter coefficients of the equation in format \"a b c\" (3 numbers) \n");

    double a = 0, b = 0, c = 0;

    ReadCoeffs(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int rootsCount = SolveQuad(a, b, c, &x1, &x2);

    printAnswer(rootsCount, &x1, &x2);

    return 0;
}

//--------------------------------------------------------------------
//! Checks if some number is near zero
//!
//! @param [in] num Number which will be checked
//!
//! @return 1 if number is near zero, 0 if isn't
//!
//! @note You can change presicion const in the beginning of file
//!       if you think it's too low or too big
//--------------------------------------------------------------------

bool IsApproxZero(double num) {
    assert(isfinite(num));

    return -presicion <= num && num <= presicion;
}

void testIsApproxZero(double num, bool correctAnswer) {
    bool answer = IsApproxZero(num);
    char* result;

    if (answer == correctAnswer) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] IsApproxZero(%lf) = %d, expected %d\n", result, num, answer, correctAnswer);
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

int SolveLinear(double a, double b, double* x1) {
    assert(isfinite(a));
    assert(isfinite(b));

    assert(x1 != nullptr);

    if (IsApproxZero(a)) {
        return IsApproxZero(b) ? INF_ROOTS : 0;
    }
    else {
        *x1 = -b/a;
        return 1;
    }
}

void testSolveLinear(double a, double b, double* x1, int CorrectAnswer, double CorrectX1) {
    int answer = SolveLinear(a, b, x1);
    char* result;

    if (answer == CorrectAnswer && *x1 == CorrectX1) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] SolveLinear(%lf, %lf, &x1) = %d; x1 = %lf, expected %d; x1 = %lf\n", result, a, b, answer, *x1, CorrectAnswer, CorrectX1);
}

void testSolveLinear(double a, double b, double* x1, int CorrectAnswer) {
    int answer = SolveLinear(a, b, x1);
    char* result;

    if (answer == CorrectAnswer) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] SolveLinear(%lf, %lf, &x1) = %d, expected %d\n", result, a, b, answer, CorrectAnswer);
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

int SolveQuad(double a, double b, double c, double* x1, double* x2) {
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    assert(x1 != nullptr);
    assert(x2 != nullptr);
    assert(x1 != x2);

    if (!IsApproxZero(a)) {
        double d = b*b - 4*a*c;

        if (IsApproxZero(d)) {
            *x1 = (-b)/(2*a);

            return 1;
        }
        else if (d > 0) {
            d = sqrt(d);
            *x1 = (-b + d)/(2*a);
            *x2 = (-b - d)/(2*a);

            return 2;
        }
        else {
            return 0;
        }
    }
    else {
        return SolveLinear(b, c, x1);
    }
}

void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer, double CorrectX1, double CorrectX2) {
    int answer = SolveQuad(a, b, c, x1, x2);
    char* result;

    if (answer == CorrectAnswer && ((*x1 == CorrectX1 && *x2 == CorrectX2) || (*x2 == CorrectX1 && *x1 == CorrectX2))) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] SolveQuad(%lf, %lf, %lf, &x1, &x2) = %d; x1 = %lf; x2 = %lf, expected %d; x1 = %lf; x2 = %lf\n", result, a, b, c, answer, *x1, *x2, CorrectAnswer, CorrectX1, CorrectX2);
}

void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer, double CorrectX1) {
    int answer = SolveQuad(a, b, c, x1, x2);
    char* result;

    if (answer == CorrectAnswer && *x1 == CorrectX1) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] SolveQuad(%lf, %lf, %lf, &x1, &x2) = %d; x1 = %lf, expected %d; x1 = %lf\n", result, a, b, c, answer, *x1, CorrectAnswer, CorrectX1);
}

void testSolveQuad(double a, double b, double c, double* x1, double* x2, int CorrectAnswer) {
    int answer = SolveQuad(a, b, c, x1, x2);
    char* result;

    if (answer == CorrectAnswer) {
        result = "correct";
    }
    else {
        result = "wrong";
    }

    printf("[%s] SolveQuad(%lf, %lf, %lf, &x1, &x2) = %d, expected %d\n", result, a, b, c, answer, CorrectAnswer);
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

void printAnswer(int rootsCount, double* x1, double* x2) {
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
            printf("Solutions of this equations are all numbers\n");
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

    assert(a != b && a != c && b != c);

    while (scanf("%lf %lf %lf", a, b, c) != 3) {
        printf("Please enter coefficients of the equation in format \"a b c\" (3 numbers) \n");
        FlushInput();
    }
}

void TestAll() {
    double x1 = 0, x2 = 0;

    testIsApproxZero(0.00001, true);
    testIsApproxZero(0, true);
    testIsApproxZero(0.001, false);
    testIsApproxZero(-1, false);

    testSolveLinear(2, -2, &x1, 1, 1);
    testSolveLinear(0, 0, &x1, INF_ROOTS);
    testSolveLinear(0, 1, &x1, 0);

    testSolveQuad(1,4,4,&x1,&x2,1,-2);
    testSolveQuad(1,-9,20,&x1,&x2,2,4,5);
    testSolveQuad(0,0,4,&x1,&x2,0);
    testSolveQuad(0,0,0,&x1,&x2,INF_ROOTS);
}


