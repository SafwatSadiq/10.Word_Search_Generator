#include<stdio.h>

char grid[10][10];

void gridMaking(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            grid[i][j] = '0';
        }
    }
}

void main(){
    gridMaking();
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}