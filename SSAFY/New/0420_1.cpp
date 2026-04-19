#include<iostream>
#include<algorithm>

using namespace std;

int N, K, maxR;

int mmap[100][100];

int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

void ff(int cy, int cx) {
	int sum = 0;

	for (int i = 0; i < 8; i++) {
		for (int j = 1; j <= K; j++) {
			int ny = cy + j * dy[i];
			int nx = cx + j * dx[i];

			if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
				sum += mmap[ny][nx];
			}
		}
	}

	maxR = max(maxR, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mmap[i][j];
		}
	}

	cin >> K;

	maxR = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ff(i, j);
		}
	}

	cout << maxR;
}