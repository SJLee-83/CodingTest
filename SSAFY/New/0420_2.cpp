#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>

using namespace std;

int N, sy, sx;

int mmap[20][20];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1, 1 };

struct Monster {
	int y, x, dist;
};

bool cmp(const Monster& a, const Monster& b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == 9) {
				sy = i;
				sx = j;
				mmap[i][j] = 0;
			}
		}
	}

	int lv = 2;
	int exp = 0;
	int totalTime = 0;

	while (true) {
		vector<Monster> candidates;
		int dist[20][20];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = -1;
			}
		}

		queue<pair<int, int>> q;
		q.push({ sy, sx });
		dist[sy][sx] = 0;

		while (!q.empty()) {
			int cy = q.front().first;
			int cx = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny >= 0 && nx >= 0 && ny < N && nx < N && dist[ny][nx] == -1) {
					if (mmap[ny][nx] <= lv) {
						dist[ny][nx] = dist[cy][cx] + 1;
						q.push({ ny, nx });

						if (mmap[ny][nx] > 0 && mmap[ny][nx] < lv) {
							candidates.push_back({ ny, nx, dist[ny][nx] });
						}
					}
				}
			}

		}
		if (candidates.empty()) break;

		sort(candidates.begin(), candidates.end(), cmp);
		Monster target = candidates[0];

		totalTime += target.dist;
		sy = target.y;
		sx = target.x;
		mmap[sy][sx] = 0;
		exp++;
		if (exp == lv) {
			lv++;
			exp = 0;
		}
	}
	cout << totalTime << "\n";
}