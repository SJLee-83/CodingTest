#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int INF = 2e9;

int N, M, sx, sy, minLim;
int mmap[55][55];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct snowMan {
	int y, x;
	int lim;
	int maxLim;
};

void ff(int y, int x) {
	priority_queue < pair<int, pair<int, pair<int, int>>>, vector< pair<int, pair<int, pair<int, int>>>>, greater< pair<int, pair<int, pair<int, int>>>>> pq;
	pq.push({ 0, { 0, { y, x }} });

	while (!pq.empty()) {
		int nowX = pq.top().second.second.second;
		int nowY = pq.top().second.second.first;
		int nowL = pq.top().second.first;
		int nowML = pq.top().first;
		pq.pop();

		nowML = max(nowL, nowML);

		if (minLim < nowML) continue;

		if (mmap[nowY][nowX] == 3) {
			minLim = min(minLim, nowML);
			break;
		}

		if (mmap[nowY][nowX] == 0) {
			for (int i = 0; i < 2; i++) {
				int ny = nowY + dy[i];
			
				if (ny < 0 || ny >= N) continue;
				pq.push({ nowML, {nowL + 1, {ny, nowX}} });
			}
		}

		else {
			nowL = 0;
			for (int i = 0; i < 4; i++) {
				int ny = nowY + dy[i];
				int nx = nowX + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

				if (i == 0 || i == 1) pq.push({ nowML, {nowL + 1, {ny, nx}} });
				else {
					if (mmap[ny][nx] != 0) pq.push({ nowML, {nowL, {ny, nowX}} });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int p;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> p;
			if (p == 2) {
				sy = i;
				sx = j;
			}
			mmap[i][j] = p;
		}
	}

	minLim = INF;
	ff(sy, sx);
	cout << minLim;
}