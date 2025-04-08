#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
    double VBTI, min;
    printf("Volume to be infused (ml) => ");
    scanf("%lf", &VBTI);
    printf("Minutes over which to infuse => ");
    scanf("%lf", &min);
    printf("VBTI: %.0f ml\nRate: %.0f ml/hr", VBTI, VBTI / min * 60);
}