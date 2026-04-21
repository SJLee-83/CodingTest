#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, maxScore;

int stas[20];
vector<int> candis;

bool canSelect(int sta) {
	if (candis.size() == 0) return true;
	else {
		for (int i = 0; i < candis.size(); i++) {
			if (candis[i] == sta) return false;

			if (sta == 0) {
				if (candis[i] == N - 1 || candis[i] == 1) return false;
			}
			else if (sta == N - 1) {
				if (candis[i] == 0 || candis[i] == N - 2) return false;
			}
			else {
				if (candis[i] == sta - 1 || candis[i] == sta + 1) return false;
			}
		}
	} return true;
}

int calScore() {
	int arr[4];
	for (int i = 0; i < 4; i++) {
		arr[i] = candis[i];
	}

	sort(arr, arr + 4);
	int sc1 = (stas[arr[0]] + stas[arr[1]]) * (stas[arr[0]] + stas[arr[1]]) + (stas[arr[2]] + stas[arr[3]]) * (stas[arr[2]] + stas[arr[3]]);
	int sc2 = (stas[arr[0]] + stas[arr[3]]) * (stas[arr[0]] + stas[arr[3]]) + (stas[arr[1]] + stas[arr[2]]) * (stas[arr[1]] + stas[arr[2]]);
	int score = max(sc1, sc2);
	return score;
}

void selectCandi(int lv) {
	if (lv == 4) {
		maxScore = max(maxScore, calScore());
		return;
	}

	for (int i = 0; i < N; i++) {
		if (canSelect(i)) {
			candis.push_back(i);
			selectCandi(lv + 1);
			candis.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		maxScore = 0;

		for (int i = 0; i < N; i++) {
			cin >> stas[i];
		}

		selectCandi(0);

		cout << "#" << t << " " << maxScore << "\n";
	}
}