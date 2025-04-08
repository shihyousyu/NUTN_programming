#include <stdio.h>
#include <math.h>

double g(double x){
    return x * x * sin(x);
}

double h(double x){
    return sqrt(4 - x * x);
}

double trap(double (*f)(double), double a, double b, int n){
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));

    for (int i = 1; i < n; i++){
        double x_i = a + i * h;
        sum += f(x_i);
    }

    return h * sum;
}

int main(){
    double a1 = 0, b1 = 3.14159;
    double a2 = -2, b2 = 2;
    int n_values[] = {2, 4, 8, 16, 32, 64, 128};
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("Approximations for g(x) = x^2 * sin(x):\n");
    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        double result = trap(g, a1, b1, n);
        printf("n = %d, Approximation = %.6f\n", n, result);
    }

    printf("\nApproximations for h(x) = sqrt(4 - x^2):\n");
    for (int i = 0; i < num_n_values; i++) {
        int n = n_values[i];
        double result = trap(h, a2, b2, n);
        printf("n = %d, Approximation = %.6f\n", n, result);
    }

    double actual_area = 3.14159 * 2;
    printf("\nActual area of the half-circle = %.6f\n", actual_area);

    return 0;
}
