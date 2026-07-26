#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    vector<bool> visit(n, false);
    
    queue<pair<string,int>> q;   // {현재 단어, 여기까지 온 단계 수}
    q.push({begin, 0});
    
    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();
        
        if (cur == target) return step;   // 목적지 도달 → 그때의 단계 수가 최단
        
        // words 전체를 훑어 "이웃"을 찾음
        for (int i = 0; i < n; i++) {
            if (visit[i]) continue;
            
            // cur와 words[i]가 한 글자만 다른가?
            int diff = 0;
            for (int j = 0; j < cur.size(); j++) {
                if (cur[j] != words[i][j]) diff++;
            }
            
            if (diff == 1) {
                visit[i] = true;
                q.push({words[i], step + 1});
            }
        }
    }
    
    return 0;   // 큐가 다 비도록 target에 못 감 → 변환 불가
}