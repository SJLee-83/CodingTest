#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K, minAns;

int originalMap[51][51];
int tempMap[51][51];

struct Command {
	int r, c, s;
};

void rotate(int r, int c, int s) {
	for (int d = 1; d <= s; d++) {
		int temp = tempMap[r - d][c - d];
		for (int i = r - d; i < r + d; i++) {
			tempMap[i][c - d] = tempMap[i + 1][c - d];
		}
		for (int i = c - d; i < c + d; i++) {
			tempMap[r + d][i] = tempMap[r + d][i + 1];
		}
		for (int i = r + d; i > r - d; i--) {
			tempMap[i][c + d] = tempMap[i - 1][c + d];
		}
		for (int i = c + d; i > c - d + 1; i--) {
			tempMap[r - d][i] = tempMap[r - d][i - 1];
		}
		tempMap[r - d][c - d + 1] = temp;
	}
}

int getMin() {
	int val = INT_MAX;

	for (int i = 1; i <= N; i++) {
		int rowSum = 0;
		for (int j = 1; j <= M; j++) {
			rowSum += tempMap[i][j];
		}
		val = min(val, rowSum);
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M >> K;
		minAns = INT_MAX;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				cin >> originalMap[i][j];
			}
		}

		vector<Command> cmds(K);
		vector<int> order(K);

		for (int i = 0; i < K; i++) {
			cin >> cmds[i].r >> cmds[i].c >> cmds[i].s;
			order[i] = i;
		}

		do {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					tempMap[i][j] = originalMap[i][j];
				}
			}

			for (int i = 0; i < K; i++) {
				int cmdIdx = order[i];
				rotate(cmds[cmdIdx].r, cmds[cmdIdx].c, cmds[cmdIdx].s);
			}

			minAns = min(minAns, getMin());

		} while (next_permutation(order.begin(), order.end()));

		cout << "#" << t << " " << minAns << "\n";

	}
}