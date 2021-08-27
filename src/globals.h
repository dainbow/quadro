const int INF_ROOTS = -1;

bool DoubleCompare(const double num1, const double num2);
void TestDoubleCompare(const double num1, const double num2, const bool correctAnswer);
int SolveLinear(const double a, const double b, double* x1);
void TestSolveLinear(const double a, const double b, const int correctRootsCount, ...);
int SolveQuad(const double a, const double b, const double c, double* x1, double* x2);
void TestSolveQuad(const double a, const double b, const double c, const int correctRootsCount, ...);
void PrintAnswer(const int rootsCount, double* x1, double* x2);
void FlushInput();
void ReadCoeffs(double* a, double* b, double* c);
void TestAll();