#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    double beginning, ending;
    printf("Enter beginning odometer reading=> ");
    scanf("%lf", &beginning);
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &ending);
    printf("You traveled a distance of %.1f miles. At $1.50 per mile, your fare is %.2f.\n", ending - beginning, (ending - beginning) * 1.5);
}