#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setting1(int (*ptr)[16]) {
    int x, y;

    // 4개의 지뢰(100) 배치
    for (int i = 0; i < 4; i++) {
        x = rand() % 16;
        y = rand() % 16;
        if (ptr[x][y] == 100) {
            i--;  // 중복 방지
            continue;
        }
        ptr[x][y] = 100;
    }

    // 지뢰 주변 숫자 증가 (기존: 숫자가 감소하는 오류 수정)
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (ptr[i][j] == 100) continue;
            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x < 0 || x > 15 || y < 0 || y > 15) continue;
                    if (ptr[x][y] == 100) ptr[i][j]++;  // 숫자 증가
                }
            }
        }
    }
}

void setting2(int x, int y, int(*ptr)[16]) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i < 0 || i > 15 || j < 0 || j > 15 || ptr[i][j] < 0) continue;
            if (ptr[i][j] == 100) break;
            if (ptr[i][j] == 0) {
                ptr[i][j] = -9;
                setting2(i, j, ptr);
            }
            else {
                ptr[i][j] = ptr[i][j] * (-1);
            }
        }
    }
}

int input(int(*ptr)[16]) {
    int x, y;
    printf("좌표를 입력하세요 (0~15 0~15): ");
    scanf_s("%d %d", &x, &y);  // scanf_s 사용

    if (x < 0 || x > 15 || y < 0 || y > 15) {
        printf("잘못된 입력입니다. 다시 입력하세요.\n");
        return 1;  // 다시 입력받도록 1 반환
    }

    if (ptr[x][y] == 100) {
        printf("지뢰를 밟았습니다! 게임 종료 💥\n");
        return 0;  // 게임 종료
    }

    if (ptr[x][y] == 0) {
        ptr[x][y] = -9;
        setting2(x, y, ptr);
    }
    else {
        ptr[x][y] = ptr[x][y] * (-1);
    }

    return 1;
}

void output(int(*ptr)[16]) {
    printf("\n  ");
    for (int i = 0; i < 16; i++) printf("%2d", i);
    printf("\n");

    for (int i = 0; i < 16; i++) {
        printf("%2d ", i);
        for (int j = 0; j < 16; j++) {
            if (ptr[i][j] == -9) {
                printf(" 0");
            }
            else if (ptr[i][j] == -100) {
                printf(" X");
            }
            else if (ptr[i][j] < 0) {
                printf(" %d", -ptr[i][j]);
            }
            else {
                printf(" L");
            }
        }
        printf("\n");
    }
}

int result(int(*ptr)[16]) {
    int unrevealed = 0, revealedSafeCells = 0;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (ptr[i][j] == -100) {
                printf("----------게임 종료!!!!----------\n\n");
                return 0;  // 게임 종료
            }

            if (ptr[i][j] > 0) unrevealed++;  // 아직 열리지 않은 안전 칸 카운트
            if (ptr[i][j] < 0 && ptr[i][j] != -100) revealedSafeCells++; // 열린 안전 칸
        }
    }

    if (revealedSafeCells == (16 * 16 - 4)) {
        printf("--------게임 클리어!!!!--------\n\n");
        return 0;  // 게임 클리어
    }

    return 1;
}

void main() {
    int a[16][16] = { 0 };
    srand((unsigned int)time(NULL));  // time_t를 unsigned int로 변환

    printf("지뢰찾기 게임 시작! 지뢰 4개가 무작위로 배치됩니다.\n");
    setting1(a);

    while (1) {
        output(a);
        if (!input(a)) break;  // 지뢰를 밟으면 게임 종료
        if (!result(a)) break; // 게임 클리어 또는 종료 조건 확인
    }
}