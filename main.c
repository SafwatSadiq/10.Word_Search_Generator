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

void placeDiagonal(char *word, int row, int column){
    int len = strlen(word);
    if(len + row < GRID_ROW && len + column < GRID_COL){
        for(int i = 0; i < len; i++){
            grid[row + i][column + i] = word[i];
        }
    }
}

void main(){
    char word1[10] = "Hello", word2[10] = "World", word3[10] = "Project";
    gridMaker();

    if (checkHorizontal(word1, 8, 3)) placeHorizontal(word1, 8, 3);

    if (checkVertical(word2, 4, 2)) placeVertical(word2, 4, 2);


    int column_num = 0, row_num = 0;
    placeDiagonal(word3, row_num, column_num);



    gridPrinter();
}