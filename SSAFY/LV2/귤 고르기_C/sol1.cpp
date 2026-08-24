#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    unordered_map<int, int> count; // 해시: 값의 범위는 넓지만 실제 등장하는 건 적을 때
    
    for(int i = 0; i < tangerine.size(); i++){
        count[tangerine[i]]++;
    }
    
    vector<int> counts;
    for(auto& p : count){
        counts.push_back(p.second); // p.second가 값
    }
    
    sort(counts.begin(), counts.end(), greater<int>()); // 내림차순
    
    int answer = 0;
    int sum = 0;
    for(int i = 0; i < counts.size(); i++){
        sum += counts[i];
        answer++;
        if(sum >= k) break;
    }
    
    return answer;
}