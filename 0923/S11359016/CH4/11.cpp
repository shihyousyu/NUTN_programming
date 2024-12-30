#include<stdio.h>

double within_x_percent(double ref, double data, double percent){
    if((ref - ref * (percent / 100)) <= data && data <= (ref + ref * (percent / 100)))
        return 1;
    else
        return 0;
}

int main(void) {
    double boiling_point;
    printf("Enter the observed boiling point of a substance (in Celsius) :");
    scanf("%lf", &boiling_point);

    if(within_x_percent(100, boiling_point, 5))
        printf("The substance is water.\n");
    else if(within_x_percent( 357, boiling_point, 5))
        printf("The substance is mercury.\n");
    else if(within_x_percent(1187, boiling_point, 5))
        printf("The substance is copper.\n");
    else if(within_x_percent(2193, boiling_point, 5))
        printf("The substance is silver.\n");
    else if(within_x_percent(2660, boiling_point, 5))
        printf("The substance is gold.\n");
    else
        printf("Substance unknown.\n");
}