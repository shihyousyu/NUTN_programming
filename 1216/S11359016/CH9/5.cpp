#include <stdio.h>

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int dfs(char maze[8][8], int x, int y, int visited[8][8], int path[][2], int *pathLength){
    if(x == 7 && y == 7){
        path[*pathLength][0] = x;
        path[*pathLength][1] = y;
        (*pathLength)++;
        return 1;
    }

    visited[x][y] = 1;
    path[*pathLength][0] = x;
    path[*pathLength][1] = y;
    (*pathLength)++;

    for(int i = 0; i < 4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && maze[newX][newY] == ' ' && !visited[newX][newY])
            if(dfs(maze, newX, newY, visited, path, pathLength))
                return 1;
    }

    (*pathLength)--;
    visited[x][y] = 0;
    return 0;
}

int main(){
    char maze[8][8] = {
        {' ', ' ', 'X', 'X', 'X', 'X', 'X', 'X'},
        {'X', ' ', 'X', ' ', ' ', ' ', 'X', 'X'},
        {'X', ' ', 'X', ' ', 'X', 'X', 'X', 'X'},
        {'X', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'X', 'X', 'X', 'X', 'X', 'X', 'X', ' '},
        {'X', ' ', ' ', ' ', 'X', ' ', 'X', ' '},
        {'X', 'X', 'X', 'X', 'X', ' ', 'X', ' '},
        {'X', 'X', 'X', 'X', 'X', ' ', ' ', ' '}
    };
    int visited[8][8] = {0};
    int path[8 * 8][2];
    int pathLength = 0;

    if(dfs(maze, 0, 0, visited, path, &pathLength)){
        printf("find a route:\n");
        for(int i = 0; i < pathLength; i++) printf("(%d, %d)\n", path[i][0], path[i][1]);
    }
    else printf("not found\n");
    return 0;
}
