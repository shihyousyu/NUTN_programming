#include<stdio.h>

int main() {
    int num, sum = 0;
    scanf("%d", &num);
    while(num >= 1){
        sum += num % 10;
        num /= 10;
    }
    if(sum % 9) printf("No\n");
    else printf("Yes\n");
    return 0;
}