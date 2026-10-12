#include <stdio.h>
#include <ctype.h>

enum State { start, sign_only, build_num, fraction, build_id, stop, invalid };

/* A standalone period ends the input. Within a number it starts a fraction. */
enum State transition(enum State state, int ch){
    if(state == start){
        if(ch == EOF || ch == '.') return stop;
        if(isspace((unsigned char)ch)) return start;
        if(ch == '+' || ch == '-') return sign_only;
        if(isdigit((unsigned char)ch)) return build_num;
        if(isalpha((unsigned char)ch) || ch == '_') return build_id;
    } else if(state == sign_only){
        if(isdigit((unsigned char)ch)) return build_num;
        if(ch == '.') return fraction;
    } else if(state == build_num){
        if(isdigit((unsigned char)ch)) return build_num;
        if(ch == '.') return fraction;
    } else if(state == fraction){
        if(isdigit((unsigned char)ch)) return fraction;
    } else if(state == build_id){
        if(isalnum((unsigned char)ch) || ch == '_') return build_id;
    }
    return invalid;
}

int main(void){
    enum State state = start;
    int ch;
    int has_digit = 0;
    printf("Enter the data :");
    while((ch = getchar()) != EOF){
        if(isspace((unsigned char)ch) && state != start){
            if(state != build_id && !has_digit){
                fprintf(stderr, "Invalid number.\n");
                return 1;
            }
            printf(state == build_id ? " - Identifier\n" : " - Number\n");
            state = start;
            has_digit = 0;
            continue;
        }
        state = transition(state, ch);
        if(state == stop) return 0;
        if(state == invalid){
            fprintf(stderr, "Invalid token.\n");
            return 1;
        }
        if(state != start) putchar(ch);
        if(isdigit((unsigned char)ch)) has_digit = 1;
    }
    if(state == build_id) puts(" - Identifier");
    else if(has_digit) puts(" - Number");
    else if(state != start){fprintf(stderr, "Incomplete number.\n"); return 1;}
    return 0;
}
