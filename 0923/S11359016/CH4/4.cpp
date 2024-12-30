#include<stdio.h>
int main(){
    char color;
    scanf("%c", &color);
    switch (color){
        case 'O':
        case 'o':
            printf("ammonia\n");
            break;
        case 'B':
        case 'b':
            printf("carbon monoxide\n");
            break;
        case 'Y':
        case 'y':
            printf("hydrogen\n");
            break;
        case 'G':
        case 'g':
            printf("oxygen");
            break;
        default:
            printf("contents unknown\n");
            break;
    }
}