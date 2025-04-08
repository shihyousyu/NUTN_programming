#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>

void charges(double hours_used, double *ptr_total_charge, double *ptr_charge_per_hour, double *ptr_average_cost){
    if(hours_used <= 10) *ptr_total_charge = 7.99;
    else{
        *ptr_total_charge = 7.99 + (int)(hours_used - 10) * 1.99;
        if(hours_used - 10 - (int)(hours_used - 10) != 0) *ptr_total_charge = *ptr_total_charge + 1.99;
    }

    *ptr_charge_per_hour = round(*ptr_total_charge * 100) / 100;
    *ptr_average_cost = round(*ptr_total_charge / hours_used * 100) / 100;
}

int main(){
    FILE *input_file, *output_file;
    input_file = fopen("usage.txt", "r");
    output_file = fopen("charges.txt", "w");

    if(input_file == NULL){
        printf("無法開啟 usage.txt\n");
        return 1;
    }
    if(output_file == NULL){
        printf("無法開啟 charges.txt\n");
        return 1;
    }

    int month, year;
    fscanf(input_file, "%d%d", &month, &year);
    fprintf(output_file, "Charges for %d/%d\n", month, year);
    
    fprintf(output_file, "        \t\t        Charge\n");
    fprintf(output_file, "Customer\tHours used\tper hour\tAverage cost\n\n");

    int customer_number;
    double hours_used, total_charge, charge_per_hour, average_cost;
    double *ptr_total_charge, *ptr_hours_used, *ptr_charge_per_hour, *ptr_average_cost;

    ptr_total_charge = &total_charge;
    ptr_hours_used = &hours_used;
    ptr_charge_per_hour = &charge_per_hour;
    ptr_average_cost = &average_cost;

    while(fscanf(input_file, "%d%lf", &customer_number, &hours_used) != EOF){
        charges(hours_used, ptr_total_charge, ptr_charge_per_hour, ptr_average_cost);
        fprintf(output_file, "%d\t\t%.1f\t\t%.2f\t\t%.2f\n", customer_number, hours_used, charge_per_hour, average_cost);
    }
    fclose(input_file);
    return 0;
}