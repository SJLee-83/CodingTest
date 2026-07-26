#include <vector>
using namespace std;

void dfs(int cur, int n, vector<vector<int>>& computers, vector<bool>& visit) {
    visit[cur] = true;
    
    for (int next = 0; next < n; next++) {
        if (computers[cur][next] == 1 && !visit[next]) {
            dfs(next, n, computers, visit);   // 연결된 곳으로 파고듦
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visit(n, false);
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            dfs(i, n, computers, visit);
        }
    }
    
    return answer;
}