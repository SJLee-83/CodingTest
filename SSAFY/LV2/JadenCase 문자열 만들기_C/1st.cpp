#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    for(int i = 0; i < s.size(); i++){
        // 첫번째 글자가 알파벳인지?
        if(i == 0 && s[i] >= 'a' && s[i] <= 'z'){
            // 대문자로 변환
        }
        
        // 나머지
        else if(s[i-1] == ' ' && s[i] >= 'a' && s[i] <= 'z'){
            // 대문자로 변환
        }
    }
    
    string answer = s;
    return answer;
}