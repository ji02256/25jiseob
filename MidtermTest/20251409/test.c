#include <stdio.h>
#include <windows.h>

void createPopup() {
    // �˾� â�� ����
    MessageBoxA(NULL, "�˾� �޽����Դϴ�.", "����", MB_OK);
}

int main() {
    char input;

    // �׸� ���
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
    printf("/      \\      /XXXXXXXXXX\\    ������ �� ������ �����ֳ�? \\\n");
    printf("        \\    /_I_II  I__I_\\__________________\\\n");
    printf("               I_I|  I__I_____[]_|_[]_____I\n");
    printf("               I_II  I__I_____[]_|_[]_____I\n");
    printf("  \033[0m      I II__I  I     XXXXXXX     I\n");
    printf("            ~~~~~\"   \"~~~~~~~~~~~~~~~~~~~~~~~~\n");

    // ����� �Է� ���
    printf("�����Ϸ��� 'n'��, �˾��� ������ 'y'�� ��������: ");
    scanf_s(" %c", &input);

    // 'n' �Է� �� ���� �޽��� ���
    if (input == 'n' || input == 'N') {
        printf("���α׷��� ����˴ϴ�.\n");
    }
    // 'y' �Է� �� �˾� â ����
    else if (input == 'y' || input == 'Y') {
        // �˾� â�� (30, 10) ��ġ�� ����
        HWND hwnd = GetConsoleWindow();
        SetWindowPos(hwnd, NULL, 30 * 10, 10 * 20, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        createPopup();
    }

    return 0;
}
