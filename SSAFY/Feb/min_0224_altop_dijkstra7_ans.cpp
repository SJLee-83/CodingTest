#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int N, A, B; // 같은 지역 이동할 때 A만큼 연료 소모 / 다른 지역 이동위해 전환 시 B만큼 연료 소모
string board[35];
int used[35][35];
int maxFuel[35][35];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dijkstra(int startY, int startX) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			used[i][j] = INF;
		}
	}

	priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {startY, startX} });
	used[startY][startX] = 0;

	while (!pq.empty()) {
		int nowX = pq.top().second.second;
		int nowY = pq.top().second.first;
		int fuel = pq.top().first;
		pq.pop();

		if (fuel > used[nowY][nowX]) continue;

		for (int i = 0; i < 4; i++) {
			int nextX = nowX + dx[i];
			int nextY = nowY + dy[i];

			if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) continue;
			
			int nextFuel;
			if (board[nowY][nowX] != board[nextY][nextX]) nextFuel = B;
			else nextFuel = A;

			int sumFuel = fuel + nextFuel;
			if (sumFuel < used[nextY][nextX]) {
				used[nextY][nextX] = sumFuel;
				pq.push({ sumFuel, {nextY, nextX} });
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(used[i][j] != INF) maxFuel[i][j] = max(used[i][j], maxFuel[i][j]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> A >> B;
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dijkstra(i, j);
		}
	}

	int maxUsedFuel = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			maxUsedFuel = max(maxUsedFuel, maxFuel[i][j]);
		}
	}

	cout << maxUsedFuel;
}