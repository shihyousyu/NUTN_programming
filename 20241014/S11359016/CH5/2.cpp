#include <stdio.h>
#include <string.h>

int main() {
    char num[100];
    int sum = 0;
    scanf("%s", num);
    for(int i = strlen(num) - 1; i >= 0; i--)
        sum += (int)num[i] - (int)'0';
    if(sum % 9) printf("No\n");
    else printf("Yes\n");
    return 0;
}