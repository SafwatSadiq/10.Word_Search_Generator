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

void main(){
    char word1[10] = "Hello", word2[10] = "World";
    gridMaker();

    for(int i=0; i<1; i++){
        for(int j=0; j<5; j++){
            grid[i][j] = word1[j];
        }
    }
    for(int i=1; i<6; i++){
        for(int j=0; j<1; j++){
            grid[i][j] = word2[i-1];
        }
    }



    gridPrinter();
}