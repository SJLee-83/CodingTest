#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool dfs(int total,
         unordered_map<string, vector<string>>& ap,
         unordered_map<string, vector<bool>>& visit,
         string dep, vector<string>& seq) {
    if (seq.size() == total) return true;   // 항공권 전부 사용
    
    for (int i = 0; i < ap[dep].size(); i++) {
        if (!visit[dep][i]) {
            visit[dep][i] = true;
            seq.push_back(ap[dep][i]);
            
            if (dfs(total, ap, visit, ap[dep][i], seq)) return true;  // 찾았으면 즉시 종료
            
            seq.pop_back();
            visit[dep][i] = false;
        }
    }
    return false;   // 이 경로로는 완성 불가
}

vector<string> solution(vector<vector<string>> tickets) {
    unordered_map<string, vector<string>> ap;
    unordered_map<string, vector<bool>> visit;
    
    for (int i = 0; i < tickets.size(); i++) {
        ap[tickets[i][0]].push_back(tickets[i][1]);
        visit[tickets[i][0]].push_back(false);
    }
    
    // 도착지를 알파벳순으로 정렬
    for (auto& p : ap) {
        sort(p.second.begin(), p.second.end());
    }
    
    vector<string> seq;
    seq.push_back("ICN");
    dfs(tickets.size() + 1, ap, visit, "ICN", seq);
    
    return seq;
}