#ifndef _TEST_H_
#define _TEST_H_
void TestDoubleCompare(const double num1, const double num2, const bool correctAnswer);
void TestSolveLinear(const double a, const double b, const int correctRootsCount, ...);
void TestSolveQuad(const double a, const double b, const double c, const int correctRootsCount, ...);
void TestAll();
#endif
