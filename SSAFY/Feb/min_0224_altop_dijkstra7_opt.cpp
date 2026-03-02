#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int N, A, B; 
string board[35];
int used[35][35];

// [수정 2] 2차원 배열 대신 전역 변수 하나로 관리합니다.
int globalMaxFuel = 0; 

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dijkstra(int startY, int startX) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            used[i][j] = INF;
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater< pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {startY, startX} });
    used[startY][startX] = 0;

    while (!pq.empty()) {
        int nowY = pq.top().second.first;
        int nowX = pq.top().second.second; // nowY, nowX 순서 명확히
        int fuel = pq.top().first;
        pq.pop();

        // [수정 1] 치명적인 오타 수정: nowY -> nowX
        if (fuel > used[nowY][nowX]) continue; 

        for (int i = 0; i < 4; i++) {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= N) continue;
            
            int nextFuel;
            if (board[nowY][nowX] != board[nextY][nextX]) nextFuel = B;
            else nextFuel = A;

            int sumFuel = fuel + nextFuel;
            if (sumFuel < used[nextY][nextX]) {
                used[nextY][nextX] = sumFuel;
                pq.push({ sumFuel, {nextY, nextX} });
            }
        }
    }

    // [수정 2] 다익스트라 1회가 끝났을 때, 이번 출발지에서 나온 최댓값으로 정답 갱신
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(used[i][j] != INF) {
                globalMaxFuel = max(globalMaxFuel, used[i][j]);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }

    // 모든 좌표를 출발점으로 삼아 다익스트라 실행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dijkstra(i, j);
        }
    }

    // 바로 전역 변수 출력
    cout << globalMaxFuel;
    
    return 0;
}