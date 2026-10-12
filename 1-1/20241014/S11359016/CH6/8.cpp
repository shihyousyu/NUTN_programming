#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>

double round_money(double value){return round(value * 100) / 100;}

void charges(double hours_used, double *total_charge, double *average_cost){
    *total_charge = round_money(7.99 + 1.99 * ceil(fmax(0, hours_used - 10)));
    *average_cost = hours_used > 0 ? round_money(*total_charge / hours_used) : 0;
}

int main(){
    FILE *input_file, *output_file;
    input_file = fopen("usage.txt", "r");
    output_file = fopen("charges.txt", "w");

    if(input_file == NULL){
        printf("無法開啟 usage.txt\n");
        if(output_file) fclose(output_file);
        return 1;
    }
    if(output_file == NULL){
        printf("無法開啟 charges.txt\n");
        fclose(input_file);
        return 1;
    }

    int month, year;
    if(fscanf(input_file, "%d%d", &month, &year) != 2){
        fclose(input_file); fclose(output_file); return 1;
    }
    fprintf(output_file, "Charges for %d/%d\n", month, year);

    fprintf(output_file, "        \t\t        Charge\n");
    fprintf(output_file, "Customer\tHours used\tTotal charge\tAverage cost\n\n");

    int customer_number;
    double hours_used, total_charge, average_cost;
    while(fscanf(input_file, "%d%lf", &customer_number, &hours_used) == 2){
        if(hours_used < 0 || !isfinite(hours_used)){
            fprintf(stderr, "Invalid hours for customer %d.\n", customer_number);
            fclose(input_file);
            fclose(output_file);
            return 1;
        }
        charges(hours_used, &total_charge, &average_cost);
        fprintf(output_file, "%d\t\t%.1f\t\t%.2f\t\t%.2f\n", customer_number, hours_used, total_charge, average_cost);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}
