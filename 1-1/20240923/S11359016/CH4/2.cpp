#include<stdio.h>
#include<math.h>

int main(){
    double weight, height, BMI;
    printf("weight: ");
    scanf("%lf", &weight);
    printf("height: ");
    scanf("%lf", &height);

    if(weight <= 0 || height <= 0) return 1;
    BMI = 703 * weight / pow(height, 2);

    printf("BMI: %.1f\n", BMI);
    if(BMI < 18.5)
        printf("Underweight\n");
    else if(BMI < 25)
        printf("Normal");
    else if(BMI < 30)
        printf("Overweight");
    else
        printf("Obese");
}
