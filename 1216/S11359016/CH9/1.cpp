#include<stdio.h>

int is_valid(int x, int y){
    return (x >= 0 && x < 5 && y >= 0 && y < 5);
}

int blob_check(int grid[5][5], int x, int y){
    if(!is_valid(x, y) || grid[x][y] == 0) return 0;

    grid[x][y] = 0;

    int blob_size = 1;

    int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

    for(int i = 0; i < 8; i++) blob_size += blob_check(grid, x + dx[i], y + dy[i]);

    return blob_size;
}

int main(){
    int grid[5][5] = {
        {1, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 1}
    };

    int x, y;
    printf("grid: \n");
    for(int i = 0; i < 5; i ++){
        for(int j = 0; j < 5; j ++)
            printf("%d ", grid[i][j]);
        printf("\n");
    }
    printf("\n");

    printf("x = ");
    scanf("%d", &x);
    printf("y = ");
    scanf("%d", &y);

    int blob_size = blob_check(grid, x, y);

    printf("Blob size starting at (%d, %d): %d\n", x, y, blob_size);

    return 0;
}