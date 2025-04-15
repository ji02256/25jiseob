#include <stdio.h>
#include <windows.h>

void createPopup() {
    // 팝업 창을 생성
    MessageBoxA(NULL, "팝업 메시지입니다.", "제목", MB_OK);
}

int main() {
    char input;

    // 그림 출력
    printf("                          (   )\n");
    printf("                          (    )\n");
    printf("                           (    )\n");
    printf("                          (    )\n");
    printf("                            )  )\n");
    printf("                           (  (                  /\\\n");
    printf("                            (_)                 /  \\  /\\\n");
    printf("                    ________[_]________      /\\/    \\/  \\\n");
    printf("           /\\      /\\        ______    \\    /   /\\/\\  /\\/\\\n");
    printf("          /  \\    //_\\   \033[41m \\    /\\    \\  /\\/\\/    \\/    \\\n");
    printf("   /\\    / /\\/\\  //___\\       \\__/  \\    \\/\n");
    printf("  /  \\  /\\/    \\\\//_____\\       \\ |[]|     \\\n");
    printf(" /\\/\\/\\/       //_______\\       \\|__|      \\\n");
    printf("/      \\      /XXXXXXXXXX\\    “나는 잘 시험을 보고있나? \\\n");
    printf("        \\    /_I_II  I__I_\\__________________\\\n");
    printf("               I_I|  I__I_____[]_|_[]_____I\n");
    printf("               I_II  I__I_____[]_|_[]_____I\n");
    printf("  \033[0m      I II__I  I     XXXXXXX     I\n");
    printf("            ~~~~~\"   \"~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // 사용자 입력 대기
    printf("종료하려면 'n'을, 팝업을 보려면 'y'를 누르세요: ");
    scanf_s(" %c", &input);

    // 'n' 입력 시 종료 메시지 출력
    if (input == 'n' || input == 'N') {
        printf("프로그램이 종료됩니다.\n");
    }
    // 'y' 입력 시 팝업 창 생성
    else if (input == 'y' || input == 'Y') {
        // 팝업 창을 (30, 10) 위치에 생성
        HWND hwnd = GetConsoleWindow();
        SetWindowPos(hwnd, NULL, 30 * 10, 10 * 20, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        createPopup();
    }

    return 0;
}
