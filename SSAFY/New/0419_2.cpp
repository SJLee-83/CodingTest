#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M, maxP;

int mmap[15][15];

bool visited[15][15] = { false };

int dy[2][6] = {
	{ -1, -1, 0, 1, 0, -1 },
	{ -1, 0, 1, 1, 1, 0 }
};

int dx[2][6] = {
	{ 0, 1, 1, 0, -1, -1 },
	{ 0, 1, 1, 0, -1, -1 }
};

void dfs(int cy, int cx, int depth, int sumP) {
	if (depth == 4) {
		maxP = max(maxP, sumP);
		return;
	}
	
	int type = cx % 2;
	
	for (int i = 0; i < 6; i++) {
		int ny = cy + dy[type][i];
		int nx = cx + dx[type][i];

		if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visited[ny][nx]) {
			visited[ny][nx] = true;
			dfs(ny, nx, depth + 1, sumP + mmap[ny][nx]);
			visited[ny][nx] = false;
		}
	}
}

void star(int cy, int cx) {
	int type = cx % 2;
	vector<int> neigh;

	for (int i = 0; i < 6; i++) {
		int ny = cy + dy[type][i];
		int nx = cx + dx[type][i];

		if (ny >= 0 && nx >= 0 && ny < N && nx < M) {
			neigh.push_back(mmap[ny][nx]);
		}
	}
	if (neigh.size() >= 3) {
		sort(neigh.rbegin(), neigh.rend());
		int sum = mmap[cy][cx] + neigh[0] + neigh[1] + neigh[2];
		maxP = max(maxP, sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		maxP = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> mmap[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				visited[i][j] = true;
				dfs(i, j, 1, mmap[i][j]);
				visited[i][j] = false;

				star(i, j);
			}
		}

		cout << "#" << t << " " << maxP << "\n";
	}
}