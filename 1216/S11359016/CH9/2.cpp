#include<stdio.h>
#include<ctype.h>
#include<string.h>

int is_palindrome(char str[], int start, int end){
    if(start >= end) return 1;
    if(tolower(str[start]) != tolower(str[end])) return 0;

    if(!isalnum(str[start])) return is_palindrome(str, start + 1, end);
    if(!isalnum(str[end])) return is_palindrome(str, start, end - 1);

    return is_palindrome(str, start + 1, end - 1);
}

int main(){
    char str[10000];

    fgets(str, sizeof(str) / sizeof(str[0]), stdin);

    if(is_palindrome(str, 0, strlen(str) - 1)) printf("is a palindrome.\n");
    else printf("is not a palindrome.\n");

    return 0;
}