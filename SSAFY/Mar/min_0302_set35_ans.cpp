#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int INF = 2e9;

int N;
int imgs[101];
vector<int> ai_scores; // 생성 가능한 모든 인공지능의 점수를 담을 1차원 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> imgs[i];
    }

    // 1. 만들 수 있는 모든 인공지능의 성능 점수를 vector에 저장
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ai_scores.push_back(imgs[i] * imgs[j]);
        }
    }

    int minDiff = INF;
    int maxSum = -INF; // 점수가 음수일 수 있으므로 아주 작은 값으로 초기화 필수!

    // 2. vector 안에서 2개의 인공지능을 선택하여 비교 (깔끔한 2중 for문)
    int total_ai_count = ai_scores.size();
    for (int i = 0; i < total_ai_count; i++) {
        for (int j = i + 1; j < total_ai_count; j++) {
            int a = ai_scores[i];
            int b = ai_scores[j];
            int diff = abs(a - b);
            int sum = a + b;

            if (diff < minDiff) {
                minDiff = diff;
                maxSum = sum;
            }
            else if (diff == minDiff) {
                if (sum > maxSum) {
                    maxSum = sum;
                }
            }
        }
    }
    
    cout << maxSum << "\n";
    return 0;
}