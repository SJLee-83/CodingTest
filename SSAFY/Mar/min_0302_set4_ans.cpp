#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int T, N, M, maxPrice;
int honeyComb[20][20];
bool visited[20][20];

// 1. 벌집 구조에 맞춘 6방향 배열 (짝수 열, 홀수 열 분리)
// 순서: 상, 하, 좌상, 좌하, 우상, 우하
int evenDy[6] = { -1, 1, -1, 0, -1, 0 }; // 짝수 열 (x % 2 == 0)
int evenDx[6] = { 0, 0, -1, -1, 1, 1 };

int oddDy[6] = { -1, 1, 0, 1, 0, 1 };    // 홀수 열 (x % 2 == 1)
int oddDx[6] = { 0, 0, -1, -1, 1, 1 };

void dfs(int lv, int y, int x, int price) {
    if (lv == 4) {
        maxPrice = max(maxPrice, price);
        return;
    }

    for (int i = 0; i < 6; i++) {
        // 현재 열(x)이 짝수인지 홀수인지에 따라 다른 방향 배열 사용
        int ny = y + (x % 2 == 0 ? evenDy[i] : oddDy[i]);
        int nx = x + (x % 2 == 0 ? evenDx[i] : oddDx[i]);

        if (ny >= N || ny < 0 || nx >= M || nx < 0) continue;
        
        if (!visited[ny][nx]) {
            visited[ny][nx] = true;
            
            // 2. [마법의 트릭] 별 모양(Y자) 탐색을 위해 2번째 칸에서 제자리 탐색 진행
            if (lv == 2) {
                // 다음 좌표의 값을 더하되, 위치는 현재 좌표(y, x)에서 다음 탐색을 이어감
                dfs(lv + 1, y, x, price + honeyComb[ny][nx]); 
            }
            
            // 일반적인 꼬리를 무는 경로 탐색
            dfs(lv + 1, ny, nx, price + honeyComb[ny][nx]);
            
            visited[ny][nx] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        memset(visited, false, sizeof(visited));
        maxPrice = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> honeyComb[i][j];
            }
        }
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                visited[i][j] = true;
                dfs(1, i, j, honeyComb[i][j]);
                visited[i][j] = false;
            }
        }
        // fy() 함수는 이제 필요 없으므로 삭제했습니다!

        cout << "#" << t << " " << maxPrice << "\n";
    }
    return 0;
}