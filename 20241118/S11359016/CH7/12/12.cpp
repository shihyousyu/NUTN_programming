#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int binary_srch(int arr[], int size, int target, int* cnt1) {
    int bottom = 0, top = size - 1;
    while(bottom <= top){
        cnt1 += 1;
        int mid = (bottom + top) / 2;
        if(arr[mid] == target) return mid;
        else if(arr[mid] > target) top = mid - 1;
        else bottom = mid + 1;
    }
    return -1;
}

int linear_srch(int arr[], int size, int target, int* cnt2){
    for(int i = 0; i < size; i ++){
        *cnt2 += 1;
        if(arr[i] == target) return i;
    }
    return -1;
}

int main(){
    int cnt1 = 0, cnt2 = 0;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10, target, index;
    scanf("%d", &target);
    index = linear_srch(arr, size, target, &cnt2);
    index = binary_srch(arr, size, target, &cnt1);
    if(index != -1) printf("%d is found in %d.\n", target, index);
    else printf("Not found.\n");
    if(cnt1 > cnt2) printf("binary search is faster\n");
    else printf("linear search is faster\n");
}