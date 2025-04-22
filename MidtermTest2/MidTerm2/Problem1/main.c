#include <stdio.h>

// PassOrFail 함수 정의
int PassOrFail(int score) {
    if (score >= 50) {
        return 1; // 50점 이상일 경우 1 반환
    }
    else {
        return 0; // 50점 미만일 경우 0 반환
    }
}

int main() {
    int score;

    // 사용자로부터 예상 점수 입력 받기
    printf("예상 점수를 입력하세요: ");
    scanf_s("%d", &score);

    // PassOrFail 함수 호출 및 결과에 따라 출력
    if (PassOrFail(score) == 1) {
        printf("재시험 없습니다!\n");
    }
    else {
        printf("재시험 있습니다!\n");
    }

    return 0;
}
