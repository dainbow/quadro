#define ZERO "The equation does not have any solution."
#define ONE "The equation has 1 solution: %3f"
#include <stdio.h>
#include <cmath>
void solve(double a, double b, double c){
    double d = 0;
    if (a != 0){
            d = b*b - 4*a*c;
            if (d > 0)
                printf("The equation has 2 solutions: %3f and %3f",(-b + sqrt(d))/(2*a),(-b - sqrt(d))/(2*a));
            else if (d == 0)
                printf(ONE,(-b)/(2*a));
            else
                printf(ZERO);
        }
        else if (a == 0 && b == 0){
            if (c != 0)
                printf(ZERO);
            else
                printf("Solutions of this equations are all numbers");
            }
        else 
            printf(ONE,-c/b);
}

int main(){
    double a = 0, b = 0, c = 0;
    printf("Solve quadratic equation \n");
    printf("Please enter coefficients of the equation \"a b c \" \n");
    scanf("%lf %lf %lf",&a,&b,&c);
    solve(a,b,c);
    return 0;
}
