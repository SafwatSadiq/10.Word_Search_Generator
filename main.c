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

void capitalize(char *word){
    for(int i = 0; i < strlen(word); i++){
        if(word[i] >= 'a' && word[i] <= 'z') word[i] -= 32;
    }
}

void removeHorizontally(char *word){
    int found;
    int len = strlen(word);
    for(int i = 0; i < GRID_ROW; i++){
        for(int j = 0; j < GRID_COL; j++){
            found = 1;
            for(int k = 0; k < len; k++){
                if(grid[i][j + k] != word[k]){
                    found = 0;
                    break;
                }
            }
            if(found){
                for(int k = 0; k < len; k++){
                    grid[i][j + k] = '.';
                }
            }
        }
    }
}

void removeVertically(char *word){
    int found;
    int len = strlen(word);
    for(int i = 0; i < GRID_ROW; i++){
        for(int j = 0; j < GRID_COL; j++){
            found = 1;
            for(int k = 0; k < len; k++){
                if(grid[i + k][j] != word[k]){
                    found = 0;
                    break;
                }
            }
            if(found){
                for(int k = 0; k < len; k++){
                    grid[i + k][j] = '.';
                }
            }
        }
    }
}

void main(){
    gridMaker();
    placeWords();
    randomCharacterPlacement();
    gridPrinter();

    int found;
    int word_found_count = 0;
    int word_found[TOTAL_WORDS] = {0};
    while(word_found_count != TOTAL_WORDS){
        found = 0;
        char word[20];
        printf("Enter a word(%d/%d): ", word_found_count, TOTAL_WORDS);
        scanf("%s", word);
        capitalize(word);

        for(int i = 0; i < TOTAL_WORDS; i++){
            if(strcmp(word, words[i]) == 0 && word_found[i] == 0){
                word_found[i] = 1;
                word_found_count++;
                found = 1;
                removeHorizontally(words[i]);
                removeVertically(words[i]);
                break;
            }
        }
        gridPrinter();
        if(found) printf("Word Found!\n");
        else printf("Word Not Found\n");
    }
    printf("All words found!\nCongratulations!\n");
}