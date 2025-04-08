#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main(){
    double min, current, percent;
    char grade;
    printf("Enter desired grade> ");
    scanf("%c", &grade);
    printf("Enter minimum average required> ");
    scanf("%lf", &min);
    printf("Enter current average in course> ");
    scanf("%lf", &current);
    printf("Enter how much the final counts as a percentage of the course grade> ");
    scanf("%lf", &percent);
    printf("You need a score of %.2f on the final to get a %c.\n", (min - current * (100 - percent) / 100) * 100 / percent, grade);
    // current * (100 - percent) / 100 + need * percent / 100 = min
    // min - current * (100 - percent) / 100 = need * percent / 100
}

// min - (cur * (100 - percent) / 100) = fin * percent / 100