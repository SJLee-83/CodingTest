#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n = maps.size();        // 행 개수
    int m = maps[0].size();     // 열 개수
    
    int dy[4] = {-1, 1, 0, 0};  // 상 하 좌 우
    int dx[4] = {0, 0, -1, 1};
    
    // 거리 배열 (0 = 미방문). 시작칸 거리를 1로 둠
    vector<vector<int>> dist(n, vector<int>(m, 0));
    
    queue<pair<int,int>> q;
    q.push({0, 0});             // 시작점 (행 0, 열 0)
    dist[0][0] = 1;             // 시작칸도 1칸으로 세므로 1부터
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            
            // 맵을 벗어나면 스킵
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            // 벽이거나 이미 방문했으면 스킵
            if (maps[ny][nx] == 0 || dist[ny][nx] != 0) continue;
            
            dist[ny][nx] = dist[y][x] + 1;   // 한 칸 더 온 거리
            q.push({ny, nx});
        }
    }
    
    int goal = dist[n-1][m-1];
    if (goal == 0)
        return -1;
    else
        return goal;
}