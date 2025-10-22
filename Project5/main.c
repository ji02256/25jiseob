#include <stdio.h>
#include <stdlib.h>   // rand(), srand()
#include <time.h>     // time()
#include <Windows.h>  // Sleep()
#include <string.h>   // strcmp()
#include <direct.h>   // _getcwd()

struct Fish
{
    char* name;
    char* talk;   // 퀴즈
    char* answer; // 정답
    char* talk_O; // 맞았을 때
    char* talk_X; // 틀렸을 때
};

int main(void)
{
    struct Fish fishes[5] = {
        {"금붕어", "멍청한 물고기는?", "금붕어", "정답! 금붕어!", "틀렸어!"},
        {"연어",   "초밥의 인기스타!", "연어",   "정답! 연어!",   "틀렸어!"},
        {"인면어", "내 얼굴이 무서울걸?", "인면어", "정답! 인면어!", "틀렸어!"},
        {"참치",   "캔으로 자주 보이지?", "참치",   "정답! 참치!",   "틀렸어!"},
        {"광어",   "횟집 단골 메뉴!",    "광어",   "정답! 광어!",   "틀렸어~"}
    };

    // 현재 작업 디렉터리 출력
    char cwd[1024];
    if (_getcwd(cwd, sizeof(cwd)) != NULL)
        printf("현재 작업 디렉터리: %s\n\n", cwd);

    FILE* fp = NULL;
    int total_games = 0, correct_games = 0;

    // ✅ 기존 로그 읽기 (안전하게 fscanf_s 사용)
    if (fopen_s(&fp, "log.txt", "r") == 0 && fp != NULL)
    {
        char name[128], result[32];
        while (fscanf_s(fp, "%127s %31s",
            name, (unsigned)_countof(name),
            result, (unsigned)_countof(result)) == 2)
        {
            total_games++;
            if (strcmp(result, "정답") == 0)
                correct_games++;
        }
        fclose(fp);
    }

    printf("%d번째 게임입니다.\n", total_games + 1);
    if (total_games > 0)
        printf("정답률: %d/%d (%.1f%%)\n\n",
            correct_games, total_games, (correct_games * 100.0) / total_games);
    else
        printf("이번이 첫 게임입니다!\n\n");

    srand((unsigned int)time(NULL));

    char buf[64];
    while (1)
    {
        printf("찌를 던진다. (Y/N): ");
        if (fgets(buf, sizeof(buf), stdin) == NULL)
        {
            printf("입력 오류 - 종료합니다.\n");
            return 1;
        }

        char YN = buf[0];

        if (YN == 'Y' || YN == 'y')
        {
            printf("찌를 던지는 중");
            for (int k = 0; k < 6; k++)
            {
                Sleep(300);
                printf(".");
                fflush(stdout);
            }
            printf("\n");

            int idx = rand() % 5;
            printf("%s가 낚였다!\n", fishes[idx].name);
            printf("%s: %s\n", fishes[idx].name, fishes[idx].talk);

            char answer[128];
            printf("정답 입력: ");
            if (fgets(answer, sizeof(answer), stdin) == NULL)
            {
                printf("입력 오류 - 종료합니다.\n");
                return 1;
            }

            // 개행 제거
            size_t len = strlen(answer);
            if (len > 0 && answer[len - 1] == '\n')
                answer[len - 1] = '\0';

            int correct = 0;
            if (strcmp(answer, fishes[idx].answer) == 0)
            {
                printf("%s: %s\n", fishes[idx].name, fishes[idx].talk_O);
                correct = 1;
            }
            else
            {
                printf("%s: %s\n", fishes[idx].name, fishes[idx].talk_X);
            }

            // ✅ 결과 저장
            if (fopen_s(&fp, "log.txt", "a") != 0 || fp == NULL)
            {
                printf("⚠️ log.txt 파일 생성 실패!\n");
                return 1;
            }

            fprintf(fp, "%s %s\n", fishes[idx].name, correct ? "정답" : "오답");
            fclose(fp);

            printf("\n결과가 log.txt에 저장되었습니다.\n");
            printf("게임을 종료합니다.\n");
            break;
        }
        else if (YN == 'N' || YN == 'n')
        {
            Sleep(300);
            printf("집에 간다...\n");
            break;
        }
        else
        {
            printf("잘못된 입력입니다! Y 또는 N을 입력해주세요.\n\n");
        }
    }

    return 0;
}
