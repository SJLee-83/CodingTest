#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(int i = 0; i < participant.size(); i++){
        for(int j = 0; j < completion.size(); j++){
            // 이름 간 길이 먼저 체크
            if(participant[i].size() == completion[j].size()){
                for(int k = 0; k < participant[i].size(); k++){
                    if(participant[i][k] != completion[j][k]){
                        continue;   
                    }
                }
                
            }
        }
    }
    
    return answer;
}