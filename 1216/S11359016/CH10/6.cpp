#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct{
    char language[20];
    int word_count;
    char words[100][20];
} wordlist_t;

void load_word_list(wordlist_t* list){
    list->word_count = 0;

    FILE* file = fopen("wordlist.txt", "r");
    fscanf(file, "%s", list->language);
    while(fscanf(file, "%s", list->words[list->word_count]) == 1){
        list->word_count++;
        if(list->word_count >= 100){
            printf("The list is full.\n");
            break;
        }
    }
}

int contains(char* word, wordlist_t* list){
    for(int i = 0; i < list->word_count; i++)
        if(strcmp(list->words[i], word) == 0) return 1;
    return 0;
}

void add_word(char* word, wordlist_t* list){
    if(list->word_count >= 100){
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
    wordlist_t list1 = {"", 0};
    wordlist_t list2 = {"", 0};
    load_word_list(&list1);

    printf("Enter the language: ");
    scanf("%s", list2.language);
    printf("Enter 12 words:\n");
    for(int i = 0; i < 12; i++){
        char word[20];
        scanf("%s", word);
        add_word(word, &list2);
    }

    printf("\nEnter the word you want to search (type \"exit\" to stop):\n");
    while(1){
        char word[20];
        scanf("%s", word);
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