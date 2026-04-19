#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

int N, minDiff;

int mmap[8][8];
int ppop[8];
bool isA[8];

bool canConnect(const vector<int>& team) {
	bool visited[8] = { false };
	queue<int> q;

	q.push(team[0]);
	visited[team[0]] = true;

	int count = 1;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < team.size(); i++) {
			int next = team[i];

			if (!visited[next] && mmap[curr][next] == 1) {
				visited[next] = true;
				q.push(next);
				count++;
			}
		}
	}
	if (team.size() == count) return true;
	else return false;
}

void dfs(int idx) {
	//기저
	if (idx == N) {
		vector<int> teamA, teamB;
		int sumA = 0, sumB = 0;

		for (int i = 0; i < N; i++) {
			if (isA[i]) {
				teamA.push_back(i);
				sumA += ppop[i];
			}
			else {
				teamB.push_back(i);
				sumB += ppop[i];
			}
		}

		if (teamA.empty() || teamB.empty()) return;

		if (canConnect(teamA) && canConnect(teamB)) {
			minDiff = min(minDiff, abs(sumA - sumB));
		}
		return;
	}

	// 모든 A, B 경우의 수
	isA[idx] = true;
	dfs(idx + 1);

	isA[idx] = false;
	dfs(idx + 1);
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		minDiff = INT_MAX;	

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mmap[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			cin >> ppop[i];
		}

		dfs(0);
		cout << "#" << t << " " << minDiff << "\n";
	}
}