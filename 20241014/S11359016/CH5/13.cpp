#include <stdio.h>
#include <string.h>

float calc_avg(char record[]){
    int hits = 0;
    int at_bats = 0;

    for(int i = 0; record[i] != '\0'; i++){
        if(record[i] == 'H'){
            hits++;
            at_bats++;
        }
        else if(record[i] == 'O') at_bats++;
    }
    if(at_bats == 0) return 0.0;
    else return (float)hits / at_bats;
}

int main(){
    FILE *file = fopen("input.txt", "r");
    int player_number;
    char record[100];

    while(fscanf(file, "%d %s", &player_number, record) == 2){
        printf("Player %d's record: %s\n", player_number, record);
        float avg = calc_avg(record);
        printf("Player %d's batting average: %.3f\n\n", player_number, avg);
    }
    fclose(file);
    return 0;
}