#include <stdio.h>

// PassOrFail �Լ� ����
int PassOrFail(int score) {
    if (score >= 50) {
        return 1; // 50�� �̻��� ��� 1 ��ȯ
    }
    else {
        return 0; // 50�� �̸��� ��� 0 ��ȯ
    }
}

int main() {
    int score;

    // ����ڷκ��� ���� ���� �Է� �ޱ�
    printf("���� ������ �Է��ϼ���: ");
    scanf_s("%d", &score);

    // PassOrFail �Լ� ȣ�� �� ����� ���� ���
    if (PassOrFail(score) == 1) {
        printf("����� �����ϴ�!\n");
    }
    else {
        printf("����� �ֽ��ϴ�!\n");
    }

    return 0;
}
