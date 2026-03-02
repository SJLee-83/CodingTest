#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int INF = 2e9;

int N, M, sx, sy;
int mmap[55][55];
int dist[55][55]; // [수정 1] 메모리 초과 방지 및 최적값 저장을 위한 배열

void dijkstra() {
    // 큐에는 {지금까지의 최대 수직 이동 거리, {y, x}} 만 넣습니다.
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // 거리 배열 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dist[i][j] = INF;
        }
    }

    pq.push({ 0, {sy, sx} });
    dist[sy][sx] = 0;

    while (!pq.empty()) {
        int maxLim = pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        // [가지치기] 이미 더 작은 한계치로 이곳에 도달한 적이 있다면 스킵
        if (dist[y][x] < maxLim) continue;

        // 보석에 도달하면 즉시 종료 (우선순위 큐이므로 무조건 최솟값 보장)
        if (mmap[y][x] == 3) {
            cout << maxLim << "\n";
            return;
        }

        // 1. 좌/우 이동 (땅이 있을 때만, 비용 증가 없음)
        int dx[] = { -1, 1 };
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            if (nx >= 0 && nx < M && mmap[y][nx] != 0) {
                if (maxLim < dist[y][nx]) {
                    dist[y][nx] = maxLim;
                    pq.push({ maxLim, {y, nx} });
                }
            }
        }

        // 2. 상/하 이동 (다음 땅을 만날 때까지 점프)
        // 위로 쏘기
        for (int ny = y - 1; ny >= 0; ny--) {
            if (mmap[ny][x] != 0) { // 땅을 만나면
                int jump = y - ny; // 점프한 칸 수 (이번 수직 이동의 게이지)
                int nextLim = max(maxLim, jump); // 기존 최대치와 이번 점프 중 큰 것 유지
                
                if (nextLim < dist[ny][x]) {
                    dist[ny][x] = nextLim;
                    pq.push({ nextLim, {ny, x} });
                }
                break; // 땅을 만났으므로 더 위로 허공을 뚫고 갈 필요 없음
            }
        }

        // 아래로 쏘기
        for (int ny = y + 1; ny < N; ny++) {
            if (mmap[ny][x] != 0) {
                int jump = ny - y;
                int nextLim = max(maxLim, jump);
                
                if (nextLim < dist[ny][x]) {
                    dist[ny][x] = nextLim;
                    pq.push({ nextLim, {ny, x} });
                }
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 2) {
                sy = i;
                sx = j;
            }
        }
    }

    dijkstra();
    return 0;
}