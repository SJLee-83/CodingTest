#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> count;
    
    for (int i = 0; i < participant.size(); i++) {
        count[participant[i]]++;      // 참가자: 개수 +1
    }
    for (int i = 0; i < completion.size(); i++) {
        count[completion[i]]--;       // 완주자: 개수 -1
    }
    
    // 개수가 0이 아닌(=1인) 이름이 답
    for (auto& pair : count) {
        if (pair.second != 0) {
            return pair.first;
        }
    }
    
    return "";
}