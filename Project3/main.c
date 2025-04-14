#include <stdio.h>

#include <conio.h>  // _getch() ����� ���� ���



void gotoxy(int x, int y) {

    // �ֿܼ��� Ŀ���� (x, y) ��ġ�� �̵��ϴ� �Լ�

    printf("\033[%d;%dH", y, x);

}



int main() {

    char c;



    // (2,2) ��ġ�� �̵��Ͽ� "input>" ���

    gotoxy(2, 2);

    printf("input>");



    int isLoop = 1;

    // ���ڸ� �Է¹��� ������ �ݺ�

    while (isLoop) {

        c = _getch();  // �� ���� �Է� �ޱ�



        // �Է��� �������� Ȯ��

        if (c >= '0')

            if (c <= '9')

            {

                printf("\033[2;8H %c", c);  // (8,2)�� ���� ���

                isLoop = 0;  // ���������� ���ڰ� �ԷµǾ����� �ݺ� ����

            }

            else

            {

                printf("\033[3;2HInvalid input. Please enter a number.\n");

            }

        else {

            printf("\033[3;2Invalid input. Please enter a number.\n");

        }

    }



    return 0;

}

