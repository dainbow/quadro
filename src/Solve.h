#ifndef _SOLVE_H_
#define _SOLVE_H_
const int INF_ROOTS = -1;

int SolveLinear(const double a, const double b, double* x1);
int SolveQuad(const double a, const double b, const double c, double* x1, double* x2);
#endif
