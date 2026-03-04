#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int N, maxC, maxR, maxRc;
int rooms[1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct spot {
	int y, x;
	int cnt;
};

void ff(int y, int x) {
	queue<spot> q;
	q.push({ y, x, 1 });

	while (!q.empty()) {
		int sy = q.front().y;
		int sx = q.front().x;
		int sCnt = q.front().cnt;
		q.pop();

		maxC = max(maxC, sCnt);

		for (int i = 0; i < 4; i++) {
			int ny = sy + dy[i];
			int nx = sx + dx[i];
			
			if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
			if (rooms[ny][nx] - rooms[sy][sx] == 1) {
				q.push({ ny, nx, sCnt + 1 });
			}
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> rooms[i][j];
			}
		}

		maxRc = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				maxC = 0;
				if (N * N - rooms[i][j] + 1 > maxRc) {
					ff(i, j);
					if (maxRc < maxC) {
						maxR = rooms[i][j];
						maxRc = maxC;
					}
				}
			}
		}

		cout << "#" << test_case << " " << maxR << " " << maxRc << "\n";
	}
	return 0;
}