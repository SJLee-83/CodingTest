#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool dfs(int total,
         unordered_map<string, vector<string>>& ap,
         unordered_map<string, vector<bool>>& visit,
         string dep, vector<string>& seq){
    if(seq.size() == total) return true;
    
    for(int i = 0; i < ap[dep].size(); i++){
        if(visit[dep][i] == false){
            visit[dep][i] = true;
            seq.push_back(ap[dep][i]);
            if(dfs(total, ap, visit, ap[dep][i], seq)) return true;
            seq.pop_back();
            visit[dep][i] = false;
        }
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    
    unordered_map<string, vector<string>> ap;
    unordered_map<string, vector<bool>> visit;
    
    for(int i = 0; i < tickets.size(); i++){
        ap[tickets[i][0]].push_back(tickets[i][1]);
        visit[tickets[i][0]].push_back(false);
    }

    for(auto& p : ap){
        sort(p.second.begin(), p.second.end());
    }

    vector<string> seq;
    seq.push_back("ICN");
    dfs(tickets.size() + 1, ap, visit, "ICN", seq);

    return seq;
}