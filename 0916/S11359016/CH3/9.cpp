#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main(){
    int day;
    printf("FLU EPIDEMIC PREDICTIONS BASED ON ELAPSED DAYS SINCE FIRST CASE REPORT\n");
    for(int i = 0; i <= 2; i ++){
        printf("Enter day number>> ");
        scanf("%d", &day);
        printf("by day %d, model predicts %d cases total.\n", day, (int)(40000 / (1 + 39999 * exp(-0.24681 * day))));
    }
}