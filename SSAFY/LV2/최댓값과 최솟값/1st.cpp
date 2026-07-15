#include <string>
#include <vector>

using namespace std;

vector<string> nums;

string solution(string s) {
    int po = 0;
    
    for(int i = 0; i < s.length; i++){
        if(s[i] == " ") {
            po = i + 1;
            for(int j = 0; j < i; j++){
                // 문자열 k에 공백 이전 문자들 누적
            }
            // vector nums에 문자열 k push_back
            // vector nums에 공백 push_back
        }  
    }
    
    // string answer에 for문으로 nums 값을 누적
    
    return answer;
}