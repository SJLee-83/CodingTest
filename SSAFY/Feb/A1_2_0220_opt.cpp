#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node {
	int y, x;
};

const int INF = 2e9;

int T, N, num, minTime;
int arr[11][11]; // 맵
vector<Node> mAndN[10]; // 몬스터, 이웃이 있는 좌표 저장 배열, p + 4
bool catched[5]; // 몬스터 잡혔는지 여부, p 
bool visited[10]; // 몬스터, 주민에게 갔는지 여부 p + 4

void dfs(int cnt, int time, int y, int x) {
	// ★ 가지치기: 이미 최소 시간을 넘겼다면 과감히 탐색 포기
  if (time >= minTime) return;

	if (cnt == 2 * num) {
		minTime = min(minTime, time);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (mAndN[i].size() > 0) { // 몬스터 또는 주민
			if (i < 4) {
				if(!catched[abs(i - 4)]) continue;
				if(!visited[i]) {
					visited[i] = true;
					int ny = mAndN[i][0].y;
					int nx = mAndN[i][0].x;
					dfs(cnt + 1, time + abs(ny - y) + abs(nx - x), ny, nx);
					visited[i] = false;
				}
			}
			else if (i > 4) {
				if (!visited[i]) {
					visited[i] = true;
					catched[i - 4] = true;
					int ny = mAndN[i][0].y;
					int nx = mAndN[i][0].x;
					dfs(cnt + 1, time + abs(ny - y) + abs(nx - x), ny, nx);
					visited[i] = false;
					catched[i - 4] = false;
				}
			}
		}
	}
}

int main() {
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;

		for (int i = 0; i < 10; i++) {
			mAndN[i].clear();
		}
		memset(catched, false, sizeof(catched));
		memset(visited, false, sizeof(visited));
		num = 0;
		minTime = INF;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int p;
				cin >> p;
				if (abs(p) > 0) {
					mAndN[p + 4].push_back({ i, j }); // 몬스터, 주민 위치 저장, p = -4 -> mAndN[0]
					if (p > 0) num++; // 양수(몬스터)가 들어올 때마다 개수를 +1
				}
				arr[i][j] = p;
			}
		}

		dfs(0, 0, 1, 1);
		cout << "#" << t << " " << minTime << "\n";
	}
}