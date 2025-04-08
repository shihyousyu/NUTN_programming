#include <stdio.h>
#include <math.h>

double newton_method(double c, int n) {
    double tolerance = 0.000001;
    double x = c / 2.0;
    double diff;

    do{
        double fx = pow(x, n) - c;
        double f_prime_x = n * pow(x, n - 1);
        double x_next = x - fx / f_prime_x;

        diff = fabs(x_next - x);
        x = x_next;
    }while(diff > tolerance);

    return x;
}

int main() {
    int n;
    double num;
    printf("Approximating n-th root of num using Newton's Method:");
    scanf("%d%lf", &n, &num);
    printf("%.6f", newton_method(num, n));
    return 0;
}