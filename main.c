#include<stdio.h>

#define GRID_ROW 10
#define GRID_COL 10

char grid[GRID_ROW][GRID_COL];

void gridMaker(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            grid[i][j] = '.';
        }
    }
}

void gridPrinter(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

void main(){
    gridMaker();
    gridPrinter();
}