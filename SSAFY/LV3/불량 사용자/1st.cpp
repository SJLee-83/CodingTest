#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

vector<int> combi;

void dfs(int len, int n, vector<string>& user_id, vector<string>& banned_id, vector<bool>& c, int& result){ // ban 목록 길이, 회전 수, 유저 목록, 밴 목록
    if(len == n) {
        
        vector<int> p;
        
        for(int i = 0; i < c.size(); i++){
            if(c[i] == true){
                p.push_back(i);
            }
        }
        
        sort(p.begin(), p.end());
        
        int num = 0;
        for(int i = 0; i < p.size(); i++){
            num *= 10;
            num += p[i];
        }
        
        if(combi.size() == 0){
            combi.push_back(num);
            result++;
        }
        else{
            for(int i = 0; i < combi.size(); i++){
                if(num == combi[i]) return;
            }
            combi.push_back(num);
            result++;
        }
        
        return;
    }
    
    for(int i = 0; i < user_id.size(); i++){ // 밴 기준 유저 하나씩 매칭
        
        bool isSame = true;
        // 길이 같은지
        if(user_id[i].size() == banned_id[n].size() && c[i] == false){
            for(int j = 0; j < user_id[i].size(); j++){ // 아이디 스펠링 매칭
                if(banned_id[n][j] == '*') continue;
                if(banned_id[n][j] != user_id[i][j]){
                    isSame = false;
                    break;
                } 
            }
            if(isSame){
                c[i] = true;
                dfs(len, n+1, user_id, banned_id, c, result);
                c[i] = false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    int result = 0;
    int l = user_id.size();
    int len = banned_id.size();
    
    vector<bool> c(l, false);
    
    dfs(len, 0, user_id, banned_id, c, result);
    
    return result;
}