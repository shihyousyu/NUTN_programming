#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int A[12], oddsum = 0, evensum = 0;
    printf("Enter the 12 digits of a barcode separated by spaces:\n");
    for(int i = 0; i < 12; i ++) scanf("%d", &A[i]);
    for(int i = 0; i < 12; i += 2) oddsum += A[i];
    for(int i = 1; i < 10; i += 2) evensum += A[i];
    printf("The result of step 1 is %d.\n", oddsum * 3);
    printf("The result of step 2 is %d.\n", oddsum * 3 + evensum);
    if(A[11] == 0 && (oddsum * 3 + evensum) % 10 == 0) printf("validated.");
    else if(A[11] != 0 && (oddsum * 3 + evensum) % 10 == 10 - A[11]) printf("validated.");
    else printf("error in baecode.");
    return 0;
}
