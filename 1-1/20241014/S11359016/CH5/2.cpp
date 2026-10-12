#include <stdio.h>
#include <string.h>

int main() {
    char num[100];
    int sum = 0;
    if(scanf("%99s", num) != 1) return 1;
    for(int i = (int)strlen(num) - 1; i >= 0; i--){
        if(num[i] < '0' || num[i] > '9') return 1;
        printf("%c\n", num[i]);
        sum += num[i] - '0';
    }
    if(sum % 9) printf("No\n");
    else printf("Yes\n");
    return 0;
}
