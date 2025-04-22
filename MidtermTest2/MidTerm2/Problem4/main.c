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
    int hCount = 0; // 'h' Ű ���� Ƚ���� �����ϴ� ����

    printAsciiArt();
    gotoxy(28, 11);

    while (done == 0)
    {
        ch = _getch();

        if (ch == 'h' || ch == 'H') {
            hCount++; // 'h' �Ǵ� 'H'�� ������ ī��Ʈ ����

            if (hCount == 2) { // 'h'�� �� �� ������
                gotoxy(19, 10);
                printf("\033[37m ");
                gotoxy(20, 11);
                printf("\033[44;37mBirthday\033[0m");
                done = 1;
            }
            else {
                gotoxy(11, 11); // ���� �޽��� ���� �Ʒ�
                printf("Happy\n");
            }
        }
    }

    return 0;
}
