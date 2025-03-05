#include<stdio.h>
#include<string.h>

#define GRID_ROW 10
#define GRID_COL 10

char grid[GRID_ROW][GRID_COL];

void gridMaker(){
    for(int i=0; i<GRID_ROW; i++){
        for(int j=0; j<GRID_COL; j++){
            grid[i][j] = '.';
        }
    }
}

void gridPrinter(){
    for(int i=0; i<GRID_ROW; i++){
        for(int j=0; j<GRID_COL; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int checkHorizontal(char *word, int row, int column){
    int len = strlen(word);
    if(len + column > GRID_COL) return 0; 
    for(int i = 0; i < len; i++){
        if(grid[row][column + i] != '.') return 0;
    }
    return 1;
}

void placeHorizontal(char *word, int row, int column){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        grid[row][column + i] = word[i];
    }
}

int checkVertical(char *word, int row, int column){
    int len = strlen(word);
    if(len + row > GRID_ROW) return 0; 
    for(int i = 0; i < len; i++){
        if(grid[row + i][column] != '.') return 0;
    }
    return 1;
}

void placeVertical(char *word, int row, int column){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        grid[row + i][column] = word[i];
    }
}

int checkDiagonal(char *word, int row, int column){
    int len = strlen(word);
    if(len + row > GRID_ROW && len + column > GRID_COL) return 0; 
    for(int i = 0; i < len; i++){
        if(grid[row + i][column + i] != '.') return 0;
    }
    return 1;
}

void placeDiagonal(char *word, int row, int column){
    int len = strlen(word);
    for(int i = 0; i < len; i++){
        grid[row + i][column + i] = word[i];
    }
}

void main(){
    char *word[] = {"HELLO", "WORLD", "PROJECT"};

    gridMaker();
    
    if (checkHorizontal(word[0], 8, 3)) placeHorizontal(word[0], 8, 3);
    
    if (checkVertical(word[1], 4, 2)) placeVertical(word[1], 4, 2);
    
    if (checkDiagonal(word[2], 0, 0)) placeDiagonal(word[2], 0, 0);



    gridPrinter();
}