#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> gems) {
    
    int se = 0; // 순서
    int shortestLen = 0;
    
    unordered_map<string, int> li;
    unordered_map<string, int> last;
    
    for(int i = 0; i < gems.size(); i++){
        // 최초
        if(li[gems[i]] == 0){
            se++;
            shortestLen++;
            li[gems[i]] = se;
            last[gems[i]] = i;
        }
        // 중복
        else{
            // 종류 수는 그대로
            // 순서는 변동
            if(li[gems[i]] == 1){
                if(gems[i-1] == gems[i]){
                    last[gems[i]] = i;
                }
                else{
                    int newLen = i - last[gems[i]];
                    if(newLen < shortestLen){
                        shortestLen = newLen;
                        for(auto& p : li){
                            if(p.second != 1){
                                li[p.first]--;
                            }
                        }
                        li[gems[i]] = se;
                        last[gems[i]] = i;
                    }
                }
            }
            else{
                if(gems[i-1] == gems[i]){
                    last[gems[i]] = i;
                }
            }
        }
    }
    int a, b;
    
    for(auto& p : li){
        if(p.second == 1) a = last[p.first];
        else if(p.second == se) b = last[p.first];
    }
    
    return {a+1, b+1};
}