#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define GRID_ROW 10
#define GRID_COL 10

char grid[GRID_ROW][GRID_COL];
char *words[] = {"HELLO", "WORLD", "PROJECT"};

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

void placeWords(){
    int row, column;
    srand(time(0));

    row = rand() % GRID_ROW;
    column = rand() % GRID_COL;

    if (checkHorizontal(words[0], row, column)) placeHorizontal(words[0], row, column);
    if (checkVertical(words[1], row, column)) placeVertical(words[1], row, column);
    if (checkDiagonal(words[2], row, column)) placeDiagonal(words[2], row, column);


}

void main(){

    gridMaker();
    
    placeWords();


    gridPrinter();
}