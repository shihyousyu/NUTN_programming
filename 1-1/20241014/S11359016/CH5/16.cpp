#include <stdio.h>
#include <math.h>

/* NaN means an invalid real root or failure to converge. */
double newton_method(double c, int n) {
    if(n <= 0 || !isfinite(c) || (c < 0 && n % 2 == 0)) return NAN;
    if(c == 0) return 0;
    double x = c / 2.0;
    for(int trial = 0; trial < 100; ++trial){
        double derivative = n * pow(x, n - 1);
        if(derivative == 0 || !isfinite(derivative)) return NAN;
        double next = x - (pow(x, n) - c) / derivative;
        if(!isfinite(next)) return NAN;
        if(fabs(next - x) <= 0.0000005) return next;
        x = next;
    }
    return NAN;
}

int main(void) {
    int n;
    double num;
    printf("Approximating n-th root of num using Newton's Method: ");
    if(scanf("%d%lf", &n, &num) != 2) return 1;
    double result = newton_method(num, n);
    if(!isfinite(result)){
        fprintf(stderr, "No real root or failed to converge within 100 trials.\n");
        return 1;
    }
    printf("%.6f\n", result);
    return 0;
}
