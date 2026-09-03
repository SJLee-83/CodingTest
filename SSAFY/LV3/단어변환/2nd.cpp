#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    vector<bool> visit(n, false);
    
    queue<pair<string, int>> q;
    q.push({begin, 0});
    
    while(!q.empty()){
        string fW = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(fW == target) return cnt;
        
        for(int i = 0; i < n; i++){
            if(visit[i]) continue;
            
            int sameAlphaCnt = 0;
            for(int j = 0; j < words[i].size(); j++){
                if(words[i][j] == fW[j]) sameAlphaCnt++;
            }
            if(sameAlphaCnt == fW.size() - 1){
                visit[i] = true;
                q.push({words[i], cnt + 1});
            }
        }
    }
    return 0;
}