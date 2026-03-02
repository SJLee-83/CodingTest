#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>

using namespace std;

const int INF = 2e9; // [수정 2] 안전한 무한대 값 사용

int T, N, ans;
int mmap[31][31];
int dist[31][31];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void ff() {
    priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {0, 0} });
    dist[0][0] = 0;

    while (!pq.empty()) {
        int fuel = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        // 1. [핵심 최적화] 이미 더 적은 연료로 도착한 적이 있다면 스킵
        if (dist[y][x] < fuel) continue;

        // 도착지 도달 시 즉시 종료 (아주 잘 작성하신 부분!)
        if (y == N - 1 && x == N - 1) {
            ans = fuel;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

            // 연료 계산 로직 간소화
            int nf = fuel;
            if (mmap[y][x] < mmap[ny][nx]) {
                nf += (mmap[ny][nx] - mmap[y][x]) * 2; // 오르막
            }
            else if (mmap[y][x] == mmap[ny][nx]) {
                nf += 1; // 평지
            }
            // 내리막은 추가 비용 0이므로 nf 유지

            if (nf < dist[ny][nx]) {
                dist[ny][nx] = nf;
                pq.push({ nf, { ny, nx } });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;
        ans = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> mmap[i][j];
                dist[i][j] = INF; // INF로 초기화
            }
        }

        ff();
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}