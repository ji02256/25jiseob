#include <Windows.h>
#include <stdio.h>
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void printAsciiArt()
{
    printf("               \033[40m\033[33mo\033[0m         \033[40m\033[33mo\033[0m   \n");
    printf("               |         |       \n");
    printf("       \033[37m---------------------------\033[0m  \n");
    printf("       |\033[45m\033[37m\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\033[0m\033[37m|\033[0m   \n");
    printf("       |\033[47m                         \033[0m\033[37m|\033[0m \n");
    printf("       \033[37m---------------------------\033[0m  ");
    printf("     \n");
    printf("     \n");
    printf("   \033[37m-----------------------------------\033[0m    \n");
    printf("   \033[37m|\033[0m\033[45m\033[37m\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\033[0m\033[37m|\033[0m    \n");
    printf("   \033[37m|\033[0m\033[47m                                 \033[0m\033[37m|\033[0m \n");
    printf("   \033[37m-----------------------------------\033[0m   \n");
}

int main()
{
    char ch = '0';
    int done = 0;
    int hCount = 0; // 'h' 키 누른 횟수를 추적하는 변수

    printAsciiArt();
    gotoxy(28, 11);

    while (done == 0)
    {
        ch = _getch();

        if (ch == 'h' || ch == 'H') {
            hCount++; // 'h' 또는 'H'를 누르면 카운트 증가

            if (hCount == 2) { // 'h'를 두 번 누르면
                gotoxy(19, 10);
                printf("\033[37m ");
                gotoxy(20, 11);
                printf("\033[44;37mBirthday\033[0m");
                done = 1;
            }
            else {
                gotoxy(11, 11); // 종료 메시지 가장 아래
                printf("Happy\n");
            }
        }
    }

    return 0;
}
