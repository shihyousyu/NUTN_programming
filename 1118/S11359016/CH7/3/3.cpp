#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fget_point_mass(FILE *input, int max, double location[10][3], double mass[10]){
    int n;
    if(fscanf(input, "%d", &n) != 1 || n < 3 || n > max) return 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < 3; j ++)
            if(fscanf(input, "%lf", &location[i][j]) != 1) return 0;
    
    for(int i = 0; i < n; i ++)
        if(fscanf(input, "%lf", &mass[i]) != 1) return 0;
    return n;
}

void center_grav(double location[10][3], double mass[10], int n, double center[3]){
    double total_mass = 0;
    for(int i = 0; i < 3; i ++) center[i] = 0;
    for(int i = 0; i < n; i ++){
        total_mass += mass[i];
        for(int j = 0; j < 3; j ++) center[j] += mass[i] * location[i][j];
    }
    for(int i = 0; i < 3; i ++) center[i] /= total_mass;
}

void fwrite_point_mass(FILE *output, double location[10][3], double mass[10], int n, double center[3]){
    fprintf(output, "Location Matrix:\n");
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 3; j ++) fprintf(output, "%8.2f ", location[i][j]);
        fprintf(output, "\n");
    }
    fprintf(output, "Mass Vector:\n");
    for(int i = 0; i < n; i ++)
        fprintf(output, "%8.2f ", mass[i]);
    fprintf(output, "\n");
    fprintf(output, "Number of Points: %d\n", n);
    fprintf(output, "Center of Gravity:\n");
    for(int i = 0; i < 3; i ++)
        fprintf(output, "%8.2f ", center[i]);
    fprintf(output, "\n\n");
}

int main(){
    double location[10][3], mass[10], center[3];
    int n;

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    while((n = fget_point_mass(input, 10, location, mass)) > 0){
        center_grav(location, mass, n, center);
        fwrite_point_mass(output, location, mass, n, center);
    }
    fclose(input);
    fclose(output);
    return 0;
}