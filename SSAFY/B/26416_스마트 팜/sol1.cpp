#include <cstring>

const int EMPTY = -1;

int n;
int field[1001][1001];      // 작물 품종 (-1 = 빈 칸)
int growthCut[3];           // 품종별 성장 시간
int sowTime[1001][1001];    // 심은 시각 (고정)
int waterGrowth[1001][1001]; // 물로 얻은 누적 성장량

void init(int N, int mGrowthTime[]) {
    n = N;
    for (int i = 0; i < 3; i++) {
        growthCut[i] = mGrowthTime[i];
    }
    memset(field, -1, sizeof(field));
    memset(sowTime, 0, sizeof(sowTime));
    memset(waterGrowth, 0, sizeof(waterGrowth));
}

// 현재 시각 기준 (i,j) 작물의 크기
int getSize(int i, int j, int mTime) {
    return (mTime - sowTime[i][j]) / growthCut[field[i][j]] + waterGrowth[i][j];
}

int sow(int mTime, int mRow, int mCol, int mCategory) {
    if (field[mRow][mCol] != EMPTY) return 0;
    
    field[mRow][mCol] = mCategory;
    sowTime[mRow][mCol] = mTime;
    waterGrowth[mRow][mCol] = 0;
    return 1;
}

int water(int mTime, int G, int mRow, int mCol, int mHeight, int mWidth) {
    int cnt = 0;
    
    for (int i = mRow; i < mRow + mHeight; i++) {
        for (int j = mCol; j < mCol + mWidth; j++) {
            if (field[i][j] != EMPTY) {
                waterGrowth[i][j] += G;
                cnt++;
            }
        }
    }
    return cnt;
}

int harvest(int mTime, int L, int mRow, int mCol, int mHeight, int mWidth) {
    int cnt = 0;
    
    // 1차: 모든 작물이 L 이상인지 확인
    for (int i = mRow; i < mRow + mHeight; i++) {
        for (int j = mCol; j < mCol + mWidth; j++) {
            if (field[i][j] != EMPTY) {
                if (getSize(i, j, mTime) < L) return 0;
                cnt++;
            }
        }
    }
    
    // 2차: 실제 수확
    for (int i = mRow; i < mRow + mHeight; i++) {
        for (int j = mCol; j < mCol + mWidth; j++) {
            if (field[i][j] != EMPTY) {
                field[i][j] = EMPTY;
                sowTime[i][j] = 0;
                waterGrowth[i][j] = 0;
            }
        }
    }
    
    return cnt;
}