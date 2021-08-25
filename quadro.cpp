#include <stdio.h>
#include <cmath>

void solvequadeq(double a, double b, double c, double* x1, double* x2,int* err) {
    if (a != 0) {
        double d = 0;
        d = b*b - 4*a*c;

        if (d > 0) {
            *x1 = (-b + sqrt(d))/(2*a);
            *x2 = (-b - sqrt(d))/(2*a);
        }
        else if (d == 0)
            *x1 = *x2 = (-b)/(2*a);
        else
            *err = 1;
    }
    else if (a == 0 && b == 0) {
        if (c != 0)
            *err = 1;
        else
            *x1 = *x2 = *err = 1;
    }
    else
        *x1 = *x2 = (-c/b);
}

int main(){
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int err = 0;
    printf("Solve quadratic equation \n");
    printf("Please enter coefficients of the equation \"a b c \" \n");
    scanf("%lf %lf %lf",&a,&b,&c);
    solvequadeq(a,b,c,&x1,&x2,&err);
    if (err == 0) {
        if (x1 == x2)
            printf("The equation has 1 solution: %3f",x1);
        else
            printf("The equation has 2 solutions: %3f and %3f",x1,x2);

    }
    else if (x1 == 0)
        printf("The equation does not have any solution.");
    else
        printf("Solutions of this equations are all numbers");ы
    return 0;
}
