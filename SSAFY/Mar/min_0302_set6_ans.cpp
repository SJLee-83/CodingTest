#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;

int T, N, ans;
int mmap[31][31];
int dist[31][31];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void ff() {
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {0, 0} });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int fuel = pq.top().first;
		int y = pq.top().second.first;
		int x = pq.top().second.second;
		pq.pop();

		if (y == N - 1 && x == N - 1) {
			ans = fuel;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			int nf;

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			if (mmap[y][x] < mmap[ny][nx]) {
				int diff = mmap[ny][nx] - mmap[y][x];
				nf = fuel + diff * 2;
			}
			else if (mmap[y][x] == mmap[ny][nx]) nf = fuel + 1;
			else nf = fuel;

			if (dist[ny][nx] > nf) {
				dist[ny][nx] = nf;
				pq.push({ nf, { ny, nx } });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;

		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mmap[i][j];
				dist[i][j] = 9999;
			}
		}

		ff();
		cout << "#" << t << " " << ans << "\n";
	}
}