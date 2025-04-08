#include<stdio.h>
#include<math.h>

int main(){
    double weight, height, BMI;
    printf("weight: ");
    scanf("%lf", &weight);
    printf("height", &height);

    BMI = 703 * weight / pow(height, 2);

    if(BMI < 18.5)
        printf("Underweight\n");
    else if(18.5 <= BMI && BMI <= 24.9)
        printf("Normal");
    else if(25.0 <= BMI && BMI <= 29.9)
        printf("Overweight");
    else
        printf("Obese");
}