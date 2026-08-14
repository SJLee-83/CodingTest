#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    bool isFirst = true;    // 지금 글자가 단어의 첫 글자인가?
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            isFirst = true;             // 공백 다음은 새 단어의 시작
        } else {
            if (isFirst) s[i] = toupper(s[i]);
            else         s[i] = tolower(s[i]);
            isFirst = false;            // 이후 글자는 단어 중간
        }
    }
    
    return s;
}