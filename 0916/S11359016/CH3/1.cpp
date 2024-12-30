#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
    double amount, downPay, rate, sum;
    printf("Enter \"amount downPay rate totalPayment\": ");
    scanf("%lf%lf%lf%lf", &amount, &downPay, &rate, &sum);
    printf("borrow: %.2f.\nmonthPayment: %.2f", amount - downPay, ((rate / 100 / 12 * (amount - downPay)) / (1 - pow(1 + rate / 100 / 12, -sum))));
}