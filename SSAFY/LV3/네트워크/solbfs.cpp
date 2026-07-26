#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (visit[i]) continue;      // 이미 어떤 네트워크에 속함
        
        answer++;                    // 새 네트워크 발견
        
        queue<int> q;
        q.push(i);
        visit[i] = true;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            // cur와 연결된 모든 컴퓨터 확인
            for (int next = 0; next < n; next++) {
                if (computers[cur][next] == 1 && !visit[next]) {
                    visit[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return answer;
}