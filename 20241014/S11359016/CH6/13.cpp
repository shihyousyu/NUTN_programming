#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <ctype.h>

const char build_num = 1;
const char build_id = 2;
const char number = 3;
const char identifier = 4;
const char start = 5;
const char stop = 6;

char transition(char current_state, char transition_char){
    if(current_state == start){
        if(isdigit(transition_char)) return(build_num);
        else if(isalpha(transition_char)) return(build_id);
        else if(transition_char == ' ') return(start);
        else if(transition_char == '.') return(stop);
        else if(transition_char == EOF) return(stop);
    }

    else if(current_state == build_num){
        if(transition_char == ' ') return(number);
        else if(isdigit(transition_char)) return(build_num);
        else if(transition_char == '\n') return(number);
    }
    else if(current_state == build_id){
        if(transition_char == ' ')
            return(identifier);
        else if(isalpha(transition_char) || isdigit(transition_char) || transition_char == '_'){
            return(build_id);
        }
        else if(transition_char == '\n') return(identifier);
    }
}

int main(){
    char current_state, transition_char;
    printf("Enter the data :");
    current_state = start;
    do{
        if(current_state == identifier){
            printf(" - Identifier\n");
            current_state = start;
        }
        else if(current_state == number){
            printf(" - Number\n");
            current_state = start;
        }
        scanf("%c", &transition_char);
        if(transition_char != ' ' && transition_char != '\n')
            printf("%c", transition_char);
        current_state = transition(current_state, transition_char);
    }while(current_state != stop);
    return 0;
}