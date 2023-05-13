#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <conio.h>

#define BOARD_WIDTH 3
#define BOARD_HEIGHT 3

enum
{
    DIRECTION_UP,
    DIRECTION_LEFT,
    DIRECTION_DOWN,
    DIRECTION_RIGHT,
    DIRECTION_MAX
};


int directions[][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

int cells[BOARD_HEIGHT][BOARD_WIDTH];
int cursorX=-1, cursorY=1;

void drawBoard(){
    system("cls");
    for (int y = 0; y < BOARD_HEIGHT; y++){
        for (int x = 0; x < BOARD_WIDTH; x++){
            switch (cells[y][x])
            {
                case 1:
                printf("1");
                break;
                case 2:
                printf("2");
                break;
                case 3:
                printf("3");
                break;
                case 4:
                printf("4");
                break;
                case 5:
                printf("5");
                break;
                case 6:
                printf("6");
                break;
                case 7:
                printf("7");
                break;
                case 8:
                printf("8");
                break;
                case 9:
                printf("9");
                break;
                case -1:
                printf("+");
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

void shuffle(int *array, int size){
    int i, j;
    int tmp;

    i = size - 1;
    srand((unsigned int)time(NULL));
    while (i>0){
        j = rand() % (i + 1);
        tmp = array[j];
        array[j] = array[i];
        array[i] = tmp;
        i--;
    }
}

void swap(int i, int j, int p, int q){
    int temp;
    temp =cells[i][j];
   cells[i][j] =cells[p][q];
   cells[p][q] = temp;
}

bool check(){
   int end[3][3] = {
       {1, 2, 3},
       {8, -1, 4},
       {7, 6, 5}};

   for (int y = 0; y < BOARD_HEIGHT; y++)
   {
        for (int x = 0; x < BOARD_WIDTH; x++){
            if(cells[y][x] != end[y][x]){
                return false;
            }
        }
    }

    return true;
}

bool possible(int *array){
    int start[9];
    int end[] = {1, 2, 3, 8, -1, 4, 7, 6, 5};

    for (int i = 0; i < 9; i++){
        start[i] = array[i];
    }

    int dis_empty = 0;
    int dis = 0;

    for (int i = 0; i < 9; i++){
        if(start[i]==-1){
            if (start[i]==end[i]){
                continue;
            }
            dis_empty = abs((i / 3) - 1) + abs((i % 3) - 1);
        }
        else{
            if (start[i] = end[i]){
                continue;
            }
            for (int j = i + 1; j < 9;j++){
                if (start[j] = end[i]){
                    int temp = start[j];
                    start[j] = start[i];
                    start[i] = temp;
                    dis += 1;
                    break;
                }
            }
        }
    }
    return dis_empty % 2 == dis % 2;
}

int solve_puzzle()
{
    int cnt = 0;
    int start = time(NULL);
    while(1){
        int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, -1};
        shuffle(array, 9);
        for (int y = 0; y < BOARD_HEIGHT;y++){
            for (int x = 0; x < BOARD_WIDTH;x++){
                if (array[y*3+x]==-1){
                    cursorY = y;
                    cursorX = x;
                    }
                cells[y][x] = array[y * 3 + x];
            }
        }

        if(possible(array)){
            break;
        }
    }

    while (1){
        drawBoard();

        if (check()){
            printf("YOU COMEPLETE");
            break;
        }
        else{
            while (1){
                bool flag = false;
                switch((_getch())){
                    case 'u':
                    if (cursorY < 2){
                        swap(cursorY + 1, cursorX, cursorY, cursorX);
                        cursorY += 1;
                        flag = true;
                    }
                    break;
                    case 'd':
                    if(cursorY>0){
                        swap(cursorY, cursorX, cursorY - 1, cursorX);
                        cursorY -= 1;
                        flag = true;
                    }
                    break;
                    case 'l':
                    if (cursorX < 2){
                        swap(cursorY, cursorX + 1, cursorY, cursorX);
                        cursorX += 1;
                        flag = true;
                    }
                    break;
                    case 'r':
                    if(cursorX > 0){
                        swap(cursorY, cursorX - 1, cursorY, cursorX);
                        cursorX -= 1;
                        flag = true;
                    }
                    break;
                    default:
                    break;
                }
                cnt += 1;
                _getch();
                if(flag)
                    break;
            }
        }
    }
    int finish = time(NULL);
    return cnt, finish - start;
}

int main(int argc, char const *argv[]){

    for (int i = 0; i < 10000;i++){
        int *start;
        int cnt, time = solve_puzzle();
        int *end;
        int memory = end - start;
        print(cnt, time, memory);
    }

        return 0;
}

void IDS() {
    int *a = (int)(malloc(sizeof(int)));
        
}