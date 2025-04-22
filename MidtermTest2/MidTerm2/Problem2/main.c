#include <stdio.h>

// 초필살기 발동 함수
int SS(int mp, int range) {
    // 조건 확인
    if (mp >= 50 && range >= 11) {
        printf("주인공 : 너는 점수를 획득했나?\n");
    }
    // 리턴값은 항상 0
    return 0;
}

int main() {
    // 주인공의 현재 mp와 range
    int mp, range;

    // 사용자로부터 mp와 range 입력 받기
    printf("mp 값을 입력하세요: ");
    scanf_s("%d", &mp);
    printf("range 값을 입력하세요: ");
    scanf_s("%d", &range);

    // 초필살기 발동 함수 호출
    SS(mp, range);

    return 0;
}
