#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int search(char COLOR_CODES[][7], int size, char* target) {
    for (int i = 0; i < size; i++) 
        if (strcmp(COLOR_CODES[i], target) == 0) return i;
    return -1;
}

int main() {
    char COLOR_CODES[10][7] = {
    "black", "brown", "red", "orange", "yellow",
    "green", "blue", "violet", "gray", "white"};
    char band1[10], band2[10], band3[10];
    char choice;

    do {
        printf("Enter the colors of the resistor's three bands, beginning with the band nearest the end.\n");
        printf("Type the colors in lowercase letters only, NO CAPS.\n");
        printf("Band 1 => ");
        scanf("%s", band1);
        printf("Band 2 => ");
        scanf("%s", band2);
        printf("Band 3 => ");
        scanf("%s", band3);

        int index1 = search(COLOR_CODES, 10, band1);
        int index2 = search(COLOR_CODES, 10, band2);
        int index3 = search(COLOR_CODES, 10, band3);

        if (index1 == -1) printf("Invalid color: %s\n", band1);
        else if (index2 == -1) printf("Invalid color: %s\n", band2);
        else if (index3 == -1) printf("Invalid color: %s\n", band3);
        else printf("Resistance value: %.f kilo-ohms\n", (index1 * 10 + index2) * pow(10, index3));

        printf("Do you want to decode another resistor? (y/n)\n=> ");
        scanf(" %c", &choice);
    } while (choice == 'y');

    return 0;
}