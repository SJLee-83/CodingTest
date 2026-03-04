#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int T, N, M;
int map_type[10][10]; // 0: 농지, 1: 산

// 방향: 0(북), 1(동), 2(남), 3(서)
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

// 특정 시작 위치와 방향에서 M일 동안 얻을 수 있는 수확량을 시뮬레이션 하는 함수
int simulate(int start_y, int start_x, int start_dir) {
    int plant_day[10][10] = { 0 };     // 씨를 심은 날짜 (0이면 빈 농지)
    int harvest_count[10][10] = { 0 }; // 해당 칸에 몇 번째 싹이 났는지 (K)
    
    int cy = start_y;
    int cx = start_x;
    int cdir = start_dir;
    int harvests = 0;

    for (int day = 1; day <= M; day++) {
        // --- 1. 오전 (Morning) 작업 ---
        bool is_fruit = false;
        // 곡식이 열렸는지 판별: 씨를 심은 날 + 4 + K 일 이후면 곡식이 열림
        if (plant_day[cy][cx] > 0 && day >= plant_day[cy][cx] + 4 + harvest_count[cy][cx]) {
            is_fruit = true;
        }

        if (is_fruit) {
            // 수확
            harvests++;
            plant_day[cy][cx] = 0; // 수확 후 빈 농지가 됨
        } 
        else if (plant_day[cy][cx] == 0) {
            // 빈 농지라면, 오후에 이동할 수 있는 곳이 있는지 미리 탐색 (Peek)
            bool can_move = false;
            // 탐색 순서: 우, 앞, 좌, 뒤
            int check_dirs[4] = { (cdir + 1) % 4, cdir, (cdir + 3) % 4, (cdir + 2) % 4 };
            
            for (int i = 0; i < 4; i++) {
                int ndir = check_dirs[i];
                int ny = cy + dy[ndir];
                int nx = cx + dx[ndir];

                if (map_type[ny][nx] == 1) continue; // 산은 이동 불가

                bool target_empty = (plant_day[ny][nx] == 0);
                bool target_fruit = (plant_day[ny][nx] > 0 && day >= plant_day[ny][nx] + 4 + harvest_count[ny][nx]);

                if (target_empty || target_fruit) {
                    can_move = true; // 이동 가능한 칸을 발견!
                    break;
                }
            }

            if (can_move) {
                // 오후에 이동 가능하므로 씨를 심음
                plant_day[cy][cx] = day;
                harvest_count[cy][cx]++; // K값 증가
            }
        }

        // --- 2. 오후 (Afternoon) 작업 ---
        bool moved = false;
        int check_dirs[4] = { (cdir + 1) % 4, cdir, (cdir + 3) % 4, (cdir + 2) % 4 };
        
        for (int i = 0; i < 4; i++) {
            int ndir = check_dirs[i];
            int ny = cy + dy[ndir];
            int nx = cx + dx[ndir];

            if (map_type[ny][nx] == 1) continue;

            bool target_empty = (plant_day[ny][nx] == 0);
            bool target_fruit = (plant_day[ny][nx] > 0 && day >= plant_day[ny][nx] + 4 + harvest_count[ny][nx]);

            if (target_empty || target_fruit) {
                cy = ny;
                cx = nx;
                cdir = ndir; // ★ 이동한 방향으로 로봇의 시야(방향) 갱신!
                moved = true;
                break;
            }
        }
        // 이동 가능한 곳이 없으면 머무름 (!moved 일 때는 cy, cx, cdir 유지)
    }

    return harvests;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map_type[i][j];
            }
        }

        int maxCnt = 0;

        // 모든 빈 농지에서, 4가지 방향으로 시작하는 모든 경우의 수를 시뮬레이션
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map_type[i][j] == 0) { // 시작점은 무조건 농지여야 함
                    for (int dir = 0; dir < 4; dir++) {
                        maxCnt = max(maxCnt, simulate(i, j, dir));
                    }
                }
            }
        }

        cout << "#" << t << " " << maxCnt << "\n";
    }
    return 0;
}