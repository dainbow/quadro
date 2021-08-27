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


