#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int N, M, sy, sx;
int mmap[55][55];
bool visited[55][55];

// LIMIT이 주어졌을 때, 보석에 도달할 수 있는지 확인하는 BFS 함수
bool canReach(int limit) {
    memset(visited, false, sizeof(visited)); // 매 탐색마다 방문 배열 초기화
    queue<pair<int, int>> q;
    
    q.push({sy, sx});
    visited[sy][sx] = true;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        if (mmap[y][x] == 3) return true; // 보석 도달 성공!

        // 1. 좌/우 이동 (땅이 있는 곳으로만 이동, 게이지 소모 없음)
        int dx[2] = { -1, 1 };
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i];
            if (nx >= 0 && nx < M && mmap[y][nx] != 0 && !visited[y][nx]) {
                visited[y][nx] = true;
                q.push({y, nx});
            }
        }

        // 2. 상/하 이동 (현재 주어진 limit 이내의 점프만 허용)
        // 위로 탐색
        for (int jump = 1; jump <= limit; jump++) {
            int ny = y - jump;
            if (ny < 0) break; // 맵 밖으로 나가면 중단
            
            if (mmap[ny][x] != 0) { // 위로 가다가 첫 번째 땅을 만나면
                if (!visited[ny][x]) {
                    visited[ny][x] = true;
                    q.push({ny, x});
                }
                break; // 땅을 뚫고 지나갈 순 없으므로 첫 땅에서 중단!
            }
        }

        // 아래로 탐색
        for (int jump = 1; jump <= limit; jump++) {
            int ny = y + jump;
            if (ny >= N) break; // 맵 밖으로 나가면 중단
            
            if (mmap[ny][x] != 0) { // 아래로 가다가 첫 번째 땅을 만나면
                if (!visited[ny][x]) {
                    visited[ny][x] = true;
                    q.push({ny, x});
                }
                break; // 땅을 뚫고 지나갈 순 없으므로 첫 땅에서 중단!
            }
        }
    }

    return false; // 큐를 다 비웠는데도 보석을 못 찾았으면 도달 실패
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

    // 이분 탐색 시작 (LIMIT의 최소 가능 범위 0 ~ 최대 가능 범위 N)
    int left = 0;
    int right = N;
    int answer = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canReach(mid)) { // 도달 가능하다면
            answer = mid;    // 일단 정답 후보로 저장
            right = mid - 1; // 더 작은 LIMIT으로도 가능한지 쪼여본다!
        }
        else {               // 도달 불가능하다면
            left = mid + 1;  // LIMIT을 높여서 다시 시도
        }
    }

    cout << answer << "\n";
    return 0;
}