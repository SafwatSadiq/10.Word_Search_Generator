#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

#define GRID_ROW 10
#define GRID_COL 10
#define TOTAL_WORDS 5

char grid[GRID_ROW][GRID_COL];
char *words[] = {"HELLO", "WORLD", "PROJECT", "PROGRAM", "GAME"};

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
    if(len + row > GRID_ROW || len + column > GRID_COL) return 0; 
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
    int isPlaced, direction, row, column;
    srand(time(0));
    for(int i = 0; i < TOTAL_WORDS; i++){
        isPlaced = 0;
        while(!isPlaced){
            direction = rand() % 3;
            row = rand() % GRID_ROW;
            column = rand() % GRID_COL;
            if(direction == 0 && checkHorizontal(words[i], row, column)){
                placeHorizontal(words[i], row, column);
                isPlaced = 1;
            } else if(direction == 1 && checkVertical(words[i], row, column)){
                placeVertical(words[i], row, column);
                isPlaced = 1;
            } else if(direction == 2 && checkDiagonal(words[i], row, column)){
                placeDiagonal(words[i], row, column);
                isPlaced = 1;
            }
        }
    }
}

void randomCharacterPlacement(){
    for(int i = 0; i < GRID_ROW; i++){
        for(int j = 0; j < GRID_COL; j++){
            if(grid[i][j] == '.') grid[i][j] = 'A' + rand() % 26;
        }
    }
}

void main(){
    gridMaker();
    placeWords();
    randomCharacterPlacement();
    gridPrinter();

    char word[20];
    printf("Enter a word: ");
    scanf("%s", word);
}