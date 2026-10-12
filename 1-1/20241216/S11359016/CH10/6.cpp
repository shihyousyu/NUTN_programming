#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct{
    char language[20];
    int word_count;
    char words[MAX_WORDS][21];
} wordlist_t;

int load_word_list(const char* filename, wordlist_t* list){
    list->word_count = 0;

    FILE* file = fopen(filename, "r");
    if(file == NULL) return 0;
    if(fscanf(file, "%19s", list->language) != 1){fclose(file); return 0;}
    while(fscanf(file, "%20s", list->words[list->word_count]) == 1){
        list->word_count++;
        if(list->word_count >= MAX_WORDS){
            printf("The list is full.\n");
            break;
        }
    }
    fclose(file);
    return 1;
}

int contains(char* word, wordlist_t* list){
    for(int i = 0; i < list->word_count; i++)
        if(strcmp(list->words[i], word) == 0) return 1;
    return 0;
}

void add_word(char* word, wordlist_t* list){
    if(list->word_count >= MAX_WORDS){
        printf("The list is full. Could not add word %s.\n", word);
        return;
    }
    if(contains(word, list)){
        printf("Word %s is already in the list.\n", word);
        return;
    }
    strcpy(list->words[list->word_count], word);
    list->word_count++;
}

int equal_lists(wordlist_t* list1, wordlist_t* list2){
    if(strcmp(list1->language, list2->language) != 0 || list1->word_count != list2->word_count)
        return 0;
    for(int i = 0; i < list1->word_count; i++)
        if (contains(list1->words[i], list2) == 0) return 0;
    return 1;
}

void display_word_list(const wordlist_t* list){
    printf("Language: %s\n", list->language);
    printf("Word count: %d\n", list->word_count);

    for(int i = 0; i < list->word_count; i++){
        printf("%-20s", list->words[i]);
        if((i + 1) % 4 == 0) printf("\n");
    }
    if (list->word_count % 4 != 0) printf("\n");
}

int main(){
    wordlist_t list1 = {0};
    wordlist_t list2 = {0};
    if(!load_word_list("wordlist.txt", &list1)){perror("wordlist.txt"); return 1;}

    printf("Enter the language: ");
    scanf("%19s", list2.language);
    printf("Enter 12 words:\n");
    for(int i = 0; i < 12; i++){
        char word[21];
        if(scanf("%20s", word) != 1) return 1;
        add_word(word, &list2);
    }

    printf("\nEnter the word you want to search (type \"exit\" to stop):\n");
    while(1){
        char word[21];
        if(scanf("%20s", word) != 1) return 1;
        if(strcmp(word, "exit") == 0) break;
        if(contains(word, &list1)) printf("Word %s exists in list1.\n", word);
        else printf("Word %s does not exist in list1.\n", word);
    }

    if(equal_lists(&list1, &list2)) printf("\nList1 is the same as list2.\n");
    else printf("\nList1 is not the same as list2.\n");

    printf("\nList1:\n");
    display_word_list(&list1);
    printf("\nList2:\n");
    display_word_list(&list2);

    return 0;
}
