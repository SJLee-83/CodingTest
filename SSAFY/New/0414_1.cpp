#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int board[10][10];
int cnt[6];
int ans;

bool canPlace(int r, int c, int k) {
	if (r + k > 10 || c + k > 10) return false;
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			if (board[i][j] != 1) return false;
		}
	}
	return true;
}

void place(int r, int c, int k, int val) {
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			board[i][j] += val;
		}
	}
}

void bt(int lv) {
	if (lv >= ans) return;

	int r = -1, c = -1;
	for (int i = 0; i < 10 && r == -1; i++) {
		for (int j = 0; j < 10 && r == -1; j++) {
			if (board[i][j] == 1) {
				r = i;
				c = j;
			}
		}
	}

	if (r == -1) {
		ans = min(ans, lv);
		return;
	}

	for (int k = 5; k >= 1; k--) {
		if (cnt[k] == 0) continue;
		if (canPlace(r, c, k)) {
			place(r, c, k, 1);
			cnt[k]--;
			bt(lv + 1);
			cnt[k]++;
			place(r, c, k, -1);
		}

	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> board[i][j];
			}
		}

		for (int k = 1; k <= 5; k++) cnt[k] = 5;
		ans = INT_MAX;

		bt(0);

		cout << "#" << test_case << " ";
		if (ans == INT_MAX) cout << -1 << "\n";
		else cout << ans << "\n";
	}
}