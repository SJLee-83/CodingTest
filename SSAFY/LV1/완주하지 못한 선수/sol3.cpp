#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];   // 어긋나는 순간이 답
        }
    }
    
    return participant.back();   // 끝까지 같으면 마지막 사람이 답
}