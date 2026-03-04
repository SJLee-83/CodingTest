#include<iostream>
#include<algorithm>

using namespace std;

int T, N, maxS;

int ba[11];

void dfs(int cnt, int score) {
	if (cnt == 0) {
		maxS = max(maxS, score);
		//cout << score << " " << maxS << "\n";
		return;
	}

	//cout << score << " " << maxS << "\n";

	for (int i = 0; i < cnt; i++) {
		if (i == 0) {
			if (ba[1] == 0) {
				int plusS;

				plusS = ba[0];
				dfs(cnt - 1, score + plusS);
			}
			else {
				int plusS, delS;
				plusS = ba[1];
				delS = ba[0];
				for (int j = 0; j < N; j++) {
					ba[j] = ba[j + 1];
				}
				dfs(cnt - 1, score + plusS);
				for (int j = N - 1; j > 0; j--) {
					ba[j] = ba[j - 1];
				}
				ba[0] = delS;
			}
		}
		else {
			if (ba[i + 1] == 0) {
				int plusS, delS;
				plusS = ba[i - 1];
				delS = ba[i];
				ba[i] = 0;
				dfs(cnt - 1, score + plusS);
				ba[i] = delS;
			}
			else {
				int plusS, delS;
				plusS = ba[i - 1] * ba[i + 1];
				delS = ba[i];
				for (int j = i; j < N; j++) {
					ba[j] = ba[j + 1];
				}
				dfs(cnt - 1, score + plusS);
				for (int j = N - 1; j > i; j--) {
					ba[j] = ba[j - 1];
				}
				ba[i] = delS;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < 11; i++) {
			ba[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			cin >> ba[i];
		}

		maxS = 0;
		dfs(N, 0);

		cout << "#" << t << " " << maxS << "\n";
	}
}