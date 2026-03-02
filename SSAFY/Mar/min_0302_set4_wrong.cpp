#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int T, N, M, maxPrice;
int honeyComb[20][20];
bool visited[20][20];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void fy(int y, int x) {
	int p = 0;
	for (int i = 0; i < 4; i++) {
		if (i == 0 && y > 0 && x > 0 && x < M - 1) { // 상
			p = honeyComb[y][x] + honeyComb[y - 1][x] + honeyComb[y][x - 1] + honeyComb[y][x + 1];
		}
		else if (i == 1 && y < N - 1 && x > 0 && x < M - 1) { // 하
			p = honeyComb[y][x] + honeyComb[y + 1][x] + honeyComb[y][x - 1] + honeyComb[y][x + 1];
		}
		else if (i == 2 && y < N - 1 && y > 0 && x > 0) {
			p = honeyComb[y][x] + honeyComb[y + 1][x] + honeyComb[y - 1][x] + honeyComb[y][x - 1];
		}
		else if (i == 3 && y < N - 1 && y > 0 && x < M - 1) {
			p = honeyComb[y][x] + honeyComb[y + 1][x] + honeyComb[y - 1][x] + honeyComb[y][x + 1];
		}

		maxPrice = max(maxPrice, p);
	}
}

void dfs(int lv, int y, int x, int price) {
	if (lv == 4) {
		maxPrice = max(maxPrice, price);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
		if (!visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(lv + 1, ny, nx, price + honeyComb[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		memset(visited, false, sizeof(visited));
		maxPrice = 0;
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> honeyComb[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = true;
				dfs(1, i, j, honeyComb[i][j]);
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				fy(i, j);
			}
		}

		cout << "#" << t << " " << maxPrice << "\n";
	}
}