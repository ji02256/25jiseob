#include <stdio.h>

#include <conio.h>  // _getch() 사용을 위한 헤더



void gotoxy(int x, int y) {

    // 콘솔에서 커서를 (x, y) 위치로 이동하는 함수

    printf("\033[%d;%dH", y, x);

}



int main() {

    char c;



    // (2,2) 위치로 이동하여 "input>" 출력

    gotoxy(2, 2);

    printf("input>");



    int isLoop = 1;

    // 숫자만 입력받을 때까지 반복

    while (isLoop) {

        c = _getch();  // 한 글자 입력 받기



        // 입력이 숫자인지 확인

        if (c >= '0')

            if (c <= '9')

            {

                printf("\033[2;8H %c", c);  // (8,2)에 숫자 출력

                isLoop = 0;  // 성공적으로 숫자가 입력되었으면 반복 종료

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

