#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    double hour, min;
    scanf("%lf%lf", &hour, &min);
    hour = hour + (min / 60);
    printf("%.1f", ((4 * hour * hour) / (hour + 2)) - 20);
}