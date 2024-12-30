#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct{
    int xx, yy, zz, mm;
    char nickname[11];
} address_t;

void scan_address(address_t* addr){
    printf("input \"xx.yy.zz.mm nickname\": ");
    scanf("%d.%d.%d.%d %s", &addr->xx, &addr->yy, &addr->zz, &addr->mm, addr->nickname);
}

void print_address(address_t addr){
    printf("%d.%d.%d.%d %s\n", addr.xx, addr.yy, addr.zz, addr.mm, addr.nickname);
}

int local_address(address_t* addr1, address_t* addr2){
    return (addr1->xx == addr2->xx && addr1->yy == addr2->yy);
}

int main(){
    address_t addresses[100];
    int count = 0;
    
    while(1){
        address_t addr;
        scan_address(&addr);
    
        if(addr.xx == 0 && addr.yy == 0 && addr.zz == 0 && addr.mm == 0 && strcmp(addr.nickname, "none") == 0) break;
        addresses[count++] = addr;
    
        if(count >= 100){
            printf("Have reached the maximum 100.\n");
            break;
        }
    }
    printf("\nThe same location pairing: ");
    int found = 0;
    for(int i = 0; i < count; i++)
        for(int j = i + 1; j < count; j++)
            if(local_address(&addresses[i], &addresses[j])){
                printf("Machines %s and %s are on the same local network.\n", addresses[i].nickname, addresses[j].nickname);
                found = 1;
            }
    if (!found) printf("Not found computers from the same location.\n");
    printf("\nThe full list of addresses and nicknames:\n");
    for(int i = 0; i < count; i++) print_address(addresses[i]);

    return 0;
}