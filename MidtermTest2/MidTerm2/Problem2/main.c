#include <stdio.h>

// ���ʻ�� �ߵ� �Լ�
int SS(int mp, int range) {
    // ���� Ȯ��
    if (mp >= 50 && range >= 11) {
        printf("���ΰ� : �ʴ� ������ ȹ���߳�?\n");
    }
    // ���ϰ��� �׻� 0
    return 0;
}

int main() {
    // ���ΰ��� ���� mp�� range
    int mp, range;

    // ����ڷκ��� mp�� range �Է� �ޱ�
    printf("mp ���� �Է��ϼ���: ");
    scanf_s("%d", &mp);
    printf("range ���� �Է��ϼ���: ");
    scanf_s("%d", &range);

    // ���ʻ�� �ߵ� �Լ� ȣ��
    SS(mp, range);

    return 0;
}
