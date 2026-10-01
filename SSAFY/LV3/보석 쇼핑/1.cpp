#include <string>
#include <unordered_map>
#include <vector>

#include <iostream>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    ////
    
    int len = gems.size();
    
    int minsptr = 0;
    int mineptr = 0;
    int maxgem = 0;
    
    int sptr = 0;
    int eptr = 0;
    
    unordered_map<string, int> cnt;
    int cnt_gem_types = 0;
    
    while (eptr < len) {
        cnt[gems[eptr]]++;
        
        if (cnt[gems[eptr]] == 1) {
            cnt_gem_types++;
        }
        
        while (cnt[gems[sptr]] > 1) {
            cnt[gems[sptr]]--;
            sptr++;
        }
        
        if (
            cnt_gem_types > maxgem
            || (
                cnt_gem_types == maxgem
                && eptr - sptr < mineptr - minsptr
            )
        ) {
            maxgem = cnt_gem_types;
            minsptr = sptr;
            mineptr = eptr;
        }
        
        eptr++;
    }
    
    answer.emplace_back(minsptr + 1);
    answer.emplace_back(mineptr + 1);
    
    ////
    
    return answer;
}