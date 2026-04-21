#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>

using namespace std;

int N, M, sy, sx, ey, ex;

int mmap[50][50];
int limMin[50][50];

struct State {
	int y, x, maxLim;

	bool operator<(const State& other) const {
		return maxLim > other.maxLim;
	}
};

void di(int sy, int sx) {
	priority_queue<State> pq;
	pq.push({ sy, sx, 0 });
	limMin[sy][sx] = 0;

	while (!pq.empty()) {
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cMaxLim = pq.top().maxLim;
		pq.pop();

		if (cy == ey && cx == ex) {
			cout << cMaxLim << "\n";
			return;
		}

		int dx[2] = { -1, 1 };
		for (int i = 0; i < 2; i++) {
			int nx = cx + dx[i];

			if (nx >= 0 && nx < M && mmap[cy][nx] != 0) {
				if (cMaxLim < limMin[cy][nx]) {
					limMin[cy][nx] = cMaxLim;
					pq.push({ cy, nx, cMaxLim });
				}
			}
		}

		for (int ny = 0; ny < N; ny++) {
			if (ny == cy) continue;

			if (mmap[ny][cx] != 0) {
				int jumpLim = abs(ny - cy);
				int nMaxLim = max(cMaxLim, jumpLim);

				if (nMaxLim < limMin[ny][cx]) {
					limMin[ny][cx] = nMaxLim;
					pq.push({ ny, cx, nMaxLim });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> mmap[i][j];
			limMin[i][j] = 2e9;
			if (mmap[i][j] == 2) {
				sy = i;
				sx = j;
			}
			if (mmap[i][j] == 3) {
				ey = i;
				ex = j;
			}
		}
	}

	di(sy, sx);
}