#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int Y, X, N;
int village[1001][1001];
int fatigue[1001][1001];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void dijkstra(int y, int x) {
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	int startFatigue = village[y][x];
	pq.push({ startFatigue, {y, x} });
	fatigue[y][x] = startFatigue;

	while (!pq.empty()) {
		int nowFatigue = pq.top().first;
		int nowY = pq.top().second.first;
		int nowX = pq.top().second.second;
		pq.pop();

		if (nowFatigue > fatigue[nowY][nowX]) continue;

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextX < 0 || nextY < 0 || nextX >= N || nextY >= N) continue;
			if (village[nextY][nextX] == -1) continue;
			int nextFatigue = village[nextY][nextX];
			int sumFatigue = nextFatigue + nowFatigue;

			if (sumFatigue < fatigue[nextY][nextX]) {
				fatigue[nextY][nextX] = sumFatigue;
				pq.push({ sumFatigue, { nextY, nextX } });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Y >> X >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> village[i][j];
			fatigue[i][j] = INF;
		}
	}

	dijkstra(Y, X);

	int maxFatigue = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (village[i][j] != -1 && fatigue[i][j] != INF) maxFatigue = max(maxFatigue, fatigue[i][j]);
		}
	}

	cout << maxFatigue;
}