#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
int mmap[10][10];
int co[10][10];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> mmap[i][j];
				cin >> co[i][j];
			}
		}

		// M일 동안 로봇이 움직임

		int maxCnt = 0;

		for (int i = 1; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				if (mmap[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						if (k == 0) { // 북쪽 보고 시작
							// 오른쪽, 앞쪽, 왼쪽, 뒤쪽의 순서
							int y = i;
							int x = j;
							int cnt = 0;
							for (int d = 2; d <= M + 1; d++) {
								if (mmap[y][x + 1] == 0) {
									mmap[y][x] = d;
									x++;
								}
								else if (d - mmap[y][x + 1] > 3 + mmap[y][x + 1]) {
									mmap[y][x] = d;
									x++;
									cnt++;
								}
								else if (mmap[y - 1][x] == 0) {
									mmap[y][x] = d;
									y--;
								}
								else if (d - mmap[y - 1][x] > 3 + mmap[y - 1][x]) {
									mmap[y][x] = d;
									y--;
									cnt++;
								}
								else if (mmap[y][x - 1] == 0) {
									mmap[y][x] = d;
									x--;
								}
								else if (d - mmap[y][x - 1] > 3 + mmap[y][x - 1]) {
									mmap[y][x] = d;
									x--;
									cnt++;
								}
								else if (mmap[y + 1][x] == 0) {
									mmap[y][x] = d;
									y++;
								}
								else if (d - mmap[y + 1][x] > 3 + mmap[y + 1][x]) {
									mmap[y][x] = d;
									y++;
									cnt++;
								}
							}
							maxCnt = max(maxCnt, cnt);
							for (int a = 0; a < N; a++) {
								for (int b = 0; b < N; b++) {
									mmap[a][b] = co[a][b];
								}
							}
						}
						if (k == 1) { // 남쪽보고 시작
							int y = i;
							int x = j;
							int cnt = 0;
							for (int d = 2; d <= M + 1; d++) {
								if (mmap[y][x - 1] == 0) {
									mmap[y][x] = d;
									x--;
								}
								else if (d - mmap[y][x - 1] > 3 + mmap[y][x - 1]) {
									mmap[y][x] = d;
									x--;
									cnt++;
								}
								else if (mmap[y + 1][x] == 0) {
									mmap[y][x] = d;
									y++;
								}
								else if (d - mmap[y + 1][x] > 3 + mmap[y + 1][x]) {
									mmap[y][x] = d;
									y++;
									cnt++;
								}
								else if (mmap[y][x + 1] == 0) {
									mmap[y][x] = d;
									x++;
								}
								else if (d - mmap[y][x + 1] > 3 + mmap[y][x + 1]) {
									mmap[y][x] = d;
									x++;
									cnt++;
								}
								else if (mmap[y - 1][x] == 0) {
									mmap[y][x] = d;
									y--;
								}
								else if (d - mmap[y - 1][x] > 3 + mmap[y - 1][x]) {
									mmap[y][x] = d;
									y--;
									cnt++;
								}
							}
							maxCnt = max(maxCnt, cnt);
							for (int i = 0; i < N; i++) {
								for (int j = 0; j < N; j++) {
									mmap[i][j] = co[i][j];
								}
							}
						}
						if (k == 2) { // 서쪽보고 시작
							int y = i;
							int x = j;
							int cnt = 0;
							for (int d = 2; d <= M + 1; d++) { 
								if (mmap[y - 1][x] == 0) { // 우 / 북
									mmap[y][x] = d;
									y--;
								}
								else if (d - mmap[y - 1][x] > 3 + mmap[y - 1][x]) {
									mmap[y][x] = d;
									y--;
									cnt++;
								}
								else if (mmap[y][x - 1] == 0) { // 앞 / 서
									mmap[y][x] = d;
									x--;
								}
								else if (d - mmap[y][x - 1] > 3 + mmap[y][x - 1]) {
									mmap[y][x] = d;
									x--;
									cnt++;
								}
								else if (mmap[y + 1][x] == 0) { // 좌 / 남
									mmap[y][x] = d;
									y++;
								}
								else if (d - mmap[y + 1][x] > 3 + mmap[y + 1][x]) {
									mmap[y][x] = d;
									y++;
									cnt++;
								}
								else if (mmap[y][x + 1] == 0) { // 뒤 / 동
									mmap[y][x] = d;
									x++;
								}
								else if (d - mmap[y][x + 1] > 3 + mmap[y][x + 1]) {
									mmap[y][x] = d;
									x++;
									cnt++;
								}
							}
							maxCnt = max(maxCnt, cnt);
							for (int i = 0; i < N; i++) {
								for (int j = 0; j < N; j++) {
									mmap[i][j] = co[i][j];
								}
							}
						}
						if (k == 3) { // 동쪽보고 시작
							int y = i;
							int x = j;
							int cnt = 0;
							for (int d = 2; d <= M + 1; d++) { 
								if (mmap[y + 1][x] == 0) { // 우 / 남
									mmap[y][x] = d;
									y++;
								}
								else if (d - mmap[y + 1][x] > 3 + mmap[y + 1][x]) {
									mmap[y][x] = d;
									y++;
									cnt++;
								}
								else if (mmap[y][x + 1] == 0) { // 앞 / 동
									mmap[y][x] = d;
									x++;
								}
								else if (d - mmap[y][x + 1] > 3 + mmap[y][x + 1]) {
									mmap[y][x] = d;
									x++;
									cnt++;
								}
								else if (mmap[y - 1][x] == 0) { // 좌 / 북
									mmap[y][x] = d;
									y--;
								}
								else if (d - mmap[y - 1][x] > 3 + mmap[y - 1][x]) {
									mmap[y][x] = d;
									y--;
									cnt++;
								}
								else if (mmap[y][x - 1] == 0) { // 뒤 / 서
									mmap[y][x] = d;
									x--;
								}
								else if (d - mmap[y][x - 1] > 3 + mmap[y][x - 1]) {
									mmap[y][x] = d;
									x--;
									cnt++;
								}
							}
							maxCnt = max(maxCnt, cnt);
							for (int i = 0; i < N; i++) {
								for (int j = 0; j < N; j++) {
									mmap[i][j] = co[i][j];
								}
							}
						}
						
					}
				}
			}
		}
		cout << "#" << t << " " << maxCnt;
	}
}