#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int reverse(int n){
    int reversed = 0;
    while(n > 0){
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int is_prime(int n){
    if(n <= 1)
        return 0;
    for(int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int is_palindrome(int n){
    return n == reverse(n);
}

int main() {
    int number;
    while(scanf("%d", &number) != EOF) {
        printf("reversed %d: %d\n", number, reverse(number));
        if(is_prime) printf("%d is a prime\n", number);
        else printf("%d is not a prime\n", number);
        if(is_palindrome) printf("%d is palindrome\n", number);
        else printf("%d is not a palindrome\n", number);
    }
    return 0;
}