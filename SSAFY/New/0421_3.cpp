#include<iostream>
#include<algorithm>

using namespace std;

int N, maxScore;

int bals[10];

void dfs(int lv, int score) {
	if (lv == N) {
		maxScore = max(maxScore, score);
		return;
	}

	for (int i = 0; i < N - lv; i++) {
		if (N - lv == 1) {
			dfs(lv + 1, score + bals[0]);
		}

		else {
			if (i == 0) {
				int temp = bals[0];
				for (int j = 0; j < N - lv - 1; j++) bals[j] = bals[j + 1];
				bals[N - lv - 1] = 0;
				dfs(lv + 1, score + bals[0]);
				for (int k = N - lv - 1; k > 0; k--) bals[k] = bals[k - 1];
				bals[0] = temp;
			}
			else if (i == N - lv - 1) {
				int temp = bals[N - lv - 1];
				bals[N - lv - 1] = 0;
				dfs(lv + 1, score + bals[N - lv - 2]);
				bals[N - lv - 1] = temp;
			}
			else {
				int temp = bals[i];
				for (int j = i; j < N - lv - 1; j++) bals[j] = bals[j + 1];
				bals[N - lv - 1] = 0;
				dfs(lv + 1, score + bals[i - 1] * bals[i]);
				for (int k = N - lv - 1; k > i; k--) bals[k] = bals[k - 1];
				bals[i] = temp;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		maxScore = 0;

		for (int i = 0; i < N; i++) {
			cin >> bals[i];
		}

		dfs(0, 0);

		cout << "#" << t << " " << maxScore << "\n";
	}
}