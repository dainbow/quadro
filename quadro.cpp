#include <stdio.h>
#include <cmath>

int main(){
    double a = 0, b = 0, c = 0, d = 0;
    printf("Solve quadratic equation \n");
    printf("Please enter coefficients of the equation \"a b c \" \n");
    scanf("%lf %lf %lf",&a,&b,&c);
    d = b*b - 4*a*c;
    if (d > 0)
        printf("The equation has 2 solutions: %3f è %3f",(-b + sqrt(d))/(2*a),(-b - sqrt(d))/(2*a));
    else if (d == 0)
        printf("The equation has 1 solution: %3f",(-b)/(2*a));
    else
        printf("The equation does not have any solution.");
    return 0;
}
