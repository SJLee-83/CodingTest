#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int T, N, maxS;

// 배열 자체를 복사해서 받습니다. (참조 &를 쓰지 않음!)
void dfs(vector<int> ba, int score) {
    int cnt = ba.size();
    
    // 풍선을 다 터트렸을 때 최댓값 갱신
    if (cnt == 0) {
        maxS = max(maxS, score);
        return;
    }

    for (int i = 0; i < cnt; i++) {
        int plusS = 0; // 지역 변수로 선언!
        
        // 1. 점수 계산
        if (cnt == 1) { // 풍선이 하나 남았을 때
            plusS = ba[i];
        } 
        else if (i == 0) { // 맨 왼쪽 풍선일 때
            plusS = ba[i + 1];
        } 
        else if (i == cnt - 1) { // 맨 오른쪽 풍선일 때
            plusS = ba[i - 1];
        } 
        else { // 중간 풍선일 때
            plusS = ba[i - 1] * ba[i + 1];
        }

        // 2. 현재 상태를 복사해서 다음 단계로 넘김
        vector<int> next_ba = ba; 
        
        // i번째 풍선을 터트림 (자동으로 뒤에 있는 원소들이 앞으로 당겨짐)
        next_ba.erase(next_ba.begin() + i); 
        
        // 3. 재귀 호출 (원상 복구 로직이 필요 없음!)
        dfs(next_ba, score + plusS);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<int> ba(N);
        for (int i = 0; i < N; i++) {
            cin >> ba[i];
        }

        maxS = 0;
        dfs(ba, 0);

        cout << "#" << t << " " << maxS << "\n";
    }
    
    return 0;
}