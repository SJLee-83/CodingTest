#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[2] = {1,0};
int dx[2] = {0,1};

struct kin{
    int y;
    int x;
    int cnt;
};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    queue<kin> q;
    q.push({1, 1, 0});
    
    while(!q.empty()){
        int cy = q.front().y;
        int cx = q.front().x;
        int cCnt = q.front().cnt;
        q.pop();
        
        if(cCnt == (m + n - 2)){
            answer++;
            continue;
        } 
        for(int i = 0; i < 2; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if(ny > n && nx > m) continue;
            
            for(int j = 0; j < puddles.size(); j++){
                if(nx == puddles[j][0] && ny == puddles[j][1]) continue;
            }
            q.push({ny, nx, cCnt + 1});
        }
    }
    
    answer %= 1000000007;
    
    return answer;
}