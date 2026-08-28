#include <cstring>

int n;
int field[1001][1001]; // 심는 작물 종류 입력 0, 1, 2
int growthCut[3]; // 각 식물 성장 기준
int sowTime[1001][1001]; // 심거나 성장 후 지난 시간
int growth[1001][1001]; // 성장 정도


void init(int N, int mGrowthTime[]) {
	n = N;
	for (int i = 0; i < 3; i++) {
		growthCut[i] = mGrowthTime[i];
	}
	memset(field, 10, sizeof(field));
	memset(sowTime, 0, sizeof(sowTime));
	memset(growth, 0, sizeof(growth));
}

void rotate(int mTime) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (field[i][j] != 10) {
				int growthRate = (mTime - sowTime[i][j]) / growthCut[field[i][j]];
				growth[i][j] += growthRate;
				int elseRate = (mTime - sowTime[i][j]) % growthCut[field[i][j]];
				sowTime[i][j] = mTime - elseRate;
			}
		}
	}
}

int sow(int mTime, int mRow, int mCol, int mCategory) {
	rotate(mTime);

	if (field[mRow][mCol] == 10) {
		field[mRow][mCol] = mCategory;
		sowTime[mRow][mCol] = mTime;
		return 1;
	}
	return 0;
}

int water(int mTime, int G, int mRow, int mCol, int mHeight, int mWidth) {
	rotate(mTime);
	
	int cnt = 0; // 작물 수 

	for (int i = mRow; i < mRow + mHeight; i++) {
		for (int j = mCol; j < mCol + mWidth; j++) {
			if (field[i][j] != 10) {
				cnt++;
				growth[i][j] += G;
			}
		}
	}
	return cnt;
}

int harvest(int mTime, int L, int mRow, int mCol, int mHeight, int mWidth) {
	rotate(mTime);

	int cnt = 0; // 수확한 작물 수

	for (int i = mRow; i < mRow + mHeight; i++) {
		for (int j = mCol; j < mCol + mWidth; j++) {
			if (field[i][j] != 10) {
				if (growth[i][j] < L) return 0;
				else cnt++;
			}
		}
	}

	for (int i = mRow; i < mRow + mHeight; i++) {
		for (int j = mCol; j < mCol + mWidth; j++) {
			if (field[i][j] != 10) {
				field[i][j] = 10;
				sowTime[i][j] = 0;
				growth[i][j] = 0;
			}
		}
	}
	
	return cnt;
}