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
        // ������ �ؽ�Ʈ

        printf("\033[31m���ؿ�\033[0m\n");



        // �ʷϻ� �ؽ�Ʈ�� ����� ���

        printf("\033[32m\033[43m��ȯ\033[0m\n");



        // ���� �ؽ�Ʈ�� �Ķ��� �ؽ�Ʈ

        printf("\033[1m\033[34m����\033[0m\n");
    }


    return 0;

}