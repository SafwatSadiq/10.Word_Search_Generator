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
void placeHorizontal(char *word, int row, int column){
    int len = strlen(word);
    if(len + column < GRID_COL){
        for(int i = 0; i < len; i++){
            grid[row][column + i] = word[i];
        }
    }
}

void placeVertical(char *word, int row, int column){
    int len = strlen(word);
    if(len + row < GRID_ROW){
        for(int i = 0; i < len; i++){
            grid[row + i][column] = word[i];
        }
    }
}

void main(){
    char word1[10] = "Hello", word2[10] = "World", word3[10] = "Project";
    gridMaker();

    int column_num = 3, row_num = 8;
    placeHorizontal(word1, row_num, column_num);

    column_num = 2, row_num = 4;
    placeVertical(word2, row_num, column_num);


    // column_num = 0, row_num = 0;
    // len = strlen(word3);
    // if(len + row_num < GRID_ROW && len + column_num < GRID_COL){
    //     for(int i = 0; i < len; i++){
    //         grid[row_num + i][column_num + i] = word3[i];
    //     }
    // }



    gridPrinter();
}