#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    gotoxy(6, 10);
    {
        // 빨간색 텍스트

        printf("\033[31m윤준영\033[0m\n");



        // 초록색 텍스트와 노란색 배경

        printf("\033[32m\033[43m규환\033[0m\n");



        // 굵은 텍스트와 파란색 텍스트

        printf("\033[1m\033[34m성훈\033[0m\n");
    }


    return 0;

}