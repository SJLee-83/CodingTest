#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int board[102][102];   // 좌표 2배 → 최대 100까지 → 여유롭게 102
int dist[102][102];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    // 1단계: 직사각형 내부를 1로 칠하기 (좌표 2배)
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        for (int x = x1; x <= x2; x++) {
            for (int y = y1; y <= y2; y++) {
                board[x][y] = 1;
            }
        }
    }
    
    // 2단계: 사방이 모두 1로 둘러싸인 '내부' 칸을 2로 덮기
    for (int i = 0; i < rectangle.size(); i++) {
        int x1 = rectangle[i][0] * 2;
        int y1 = rectangle[i][1] * 2;
        int x2 = rectangle[i][2] * 2;
        int y2 = rectangle[i][3] * 2;
        
        // 테두리 바로 안쪽만 검사하면 되므로 +1 ~ -1 범위
        for (int x = x1 + 1; x < x2; x++) {
            for (int y = y1 + 1; y < y2; y++) {
                board[x][y] = 2;   // 확실한 내부
            }
        }
    }
    
    // 3단계: 값이 1인 테두리 위에서 BFS
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    int sx = characterX * 2, sy = characterY * 2;
    int ex = itemX * 2, ey = itemY * 2;
    
    queue<pair<int,int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx < 0 || nx > 100 || ny < 0 || ny > 100) continue;
            if (board[nx][ny] != 1) continue;      // 테두리(1)만 밟음
            if (dist[nx][ny] != 0) continue;       // 이미 방문
            
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    
    // 2배로 늘린 거리이므로 2로 나눔. dist는 시작을 1로 뒀으니 -1 보정
    return (dist[ex][ey] - 1) / 2;
}