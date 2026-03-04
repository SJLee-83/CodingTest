#include<iostream>
#include<algorithm>

using namespace std;

int T, N, maxR, maxRc;
int rooms[1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> rooms[i][j];
            }
        }

        maxRc = 0;
        maxR = N * N + 1; // 방 번호 비교를 위해 초깃값은 올 수 있는 가장 큰 수로 설정

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                
                // [핵심 최적화] 주변에 나보다 1 작은 방이 있다면, 나는 출발점이 될 필요가 없다!
                bool isStart = true;
                for (int d = 0; d < 4; d++) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
                        if (rooms[ny][nx] == rooms[i][j] - 1) {
                            isStart = false; // 내 이전 방이 있으므로 나는 출발점이 아님
                            break;
                        }
                    }
                }

                if (!isStart) continue; // 출발점이 아니면 탐색 건너뛰기

                // 여기서부터는 진짜 출발점임이 보장됨 (경로를 쭉 따라가기)
                int cnt = 1;
                int cy = i, cx = j;
                
                while (true) {
                    bool moved = false;
                    for (int d = 0; d < 4; d++) {
                        int ny = cy + dy[d];
                        int nx = cx + dx[d];
                        if (ny >= 0 && nx >= 0 && ny < N && nx < N) {
                            if (rooms[ny][nx] == rooms[cy][cx] + 1) {
                                cy = ny;
                                cx = nx;
                                cnt++;
                                moved = true;
                                break; // +1인 방을 찾았으니 즉시 이동
                            }
                        }
                    }
                    if (!moved) break; // 더 이상 갈 수 없으면 종료
                }

                // [수정된 조건] 정답 갱신 (거리가 더 길거나, 거리는 같은데 방 번호가 더 작을 때)
                if (cnt > maxRc) {
                    maxRc = cnt;
                    maxR = rooms[i][j];
                } else if (cnt == maxRc) {
                    if (rooms[i][j] < maxR) {
                        maxR = rooms[i][j];
                    }
                }
            }
        }

        cout << "#" << test_case << " " << maxR << " " << maxRc << "\n";
    }
    return 0;
}