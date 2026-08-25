#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>& computers, vector<bool>& visit, int cur, int n){
    visit[cur] = true;
    
    for(int next = 0; next < n; next++){
        if(visit[next] == false && computers[cur][next] == 1){
            dfs(computers, visit, next, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<bool> visit(n, false);
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            answer++;
            dfs(computers, visit, i, n);
        }
    }
    
    return answer;
}