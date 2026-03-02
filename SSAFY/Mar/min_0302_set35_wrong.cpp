#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int INF = 2e9;

int N, score, minDiff, maxSum;
int imgs[101];
int arr[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> imgs[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			arr[i][j] = imgs[i] * imgs[j];
		}
	}

	int sum, diff, a, b;
	minDiff = INF;
	maxSum = -INF;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			a = arr[i][j];
			for (int k = i; k < N; k++) {
				for (int l = k + 1; l < N; l++) {
					b = arr[k][l];
					diff = abs(a - b);
					if (diff < minDiff) {
						maxSum = a + b;
						minDiff = diff;
					}
					else if (diff == minDiff) {
						sum = a + b;
						if (sum > maxSum) {
							maxSum = sum;
						}
					}
				}
			}
		}
	}
	
	cout << maxSum;
}