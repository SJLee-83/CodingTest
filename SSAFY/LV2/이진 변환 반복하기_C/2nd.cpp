#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int zero_cnt = 0;
    int change_cnt = 0;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 0){
            zero_cnt++;
        }
        else{
            answer.push_back(s[i]);
        }
    }
    change_cnt++;
    
    while(answer.size() != 1){
        int len = answer.size();
        
        
        for(int i = 0; )
    }
    
    
    
    return answer;
}