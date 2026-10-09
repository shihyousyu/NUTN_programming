#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void display(int A[4][5]){
    printf("Precinct\tCandidate A\tCandidate B\tCandidate C\tCandidate D\n");
    for(int i = 0; i < 5; i ++){
        printf("%d\t\t", i + 1);
        for(int j = 0; j < 4; j ++) printf("%d\t\t", A[j][i]);
        printf("\n");
    }
}

void compute(int A[4][5], double t[4], double* grandtotal){
    printf("\nTotal votes:\n");
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 5; j ++){
                t[i] += A[i][j];
                *grandtotal += A[i][j];
            }
        }
    for(int i=0; i<4; i++)
        printf("Candidate %c: %.f (%.2lf%%)\n", 'A'+i, t[i], (t[i] / *grandtotal) * 100);
}

void compare(double t[4], double *grandtotal){
    int max = 0, secMax = 0;
    int id_max = -1, id_secMax = -1;
    for(int i = 0; i < 4; i ++){
        if(t[i] > max){
            secMax = max;
            id_secMax = id_max;
            max = t[i];
            id_max = i;
        }
        else if(t[i] > secMax){
            secMax = t[i];
            id_secMax = i;
        }
    }
    if(max / *grandtotal > 0.5) printf("candidate %c is the winner.\n", 'A' + id_max);
    else printf("Runoff required between Candidate %c and Candidate %c.\n", 'A' + id_max, 'A' + id_secMax);
}

int main(){
    double t[4] = {0, 0, 0, 0};
    double grandtotal = 0;
    int A[4][5] = {{192, 147, 186, 114, 267}, 
                   {48, 90, 12, 21, 13},
                   {206, 312, 121, 408, 382},
                   {37, 21, 38, 39, 29}};
    int B[4][5] = {{192, 147, 186, 114, 267}, 
                  {48, 90, 12, 21, 13},
                  {206, 312, 121, 108, 382},
                  {37, 21, 38, 39, 29}};
    display(A);
    compute(A, t, &grandtotal);
    compare(t, &grandtotal);
    
    printf("\n");
    grandtotal = 0;
    for(int i = 0; i < 4; i ++) t[i] = 0;
    
    display(B);
    compute(B, t, &grandtotal);
    compare(t, &grandtotal);
    
    return 0;
}