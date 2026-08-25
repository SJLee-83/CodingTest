#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    
    bool visit[n];
    int nwCnt = n;
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(visit[i] == True || visit[j] == True) continue;
            else{          
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i] == True;
                
                while(q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    
                    for(int d = 0; d < 4; d++){
                        int ny = y + dy[d];
                        int nx = x + dx[d];
                        
                        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                        if(ny == y && visit[nx] == False){
                            visit[nx] = True;
                            nwCnt--;
                            q.push({y, nx});
                        }
                        if(nx == x && visit[ny] == False){
                            visit[ny] = True;
                            nwCnt--;
                            q.push({ny, x});
                        }
                    }
                }
            }
        }
    }
    
    int answer = nwCnt;
    return answer;
}