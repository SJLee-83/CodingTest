#include <string>
#include <cctype>
using namespace std;

string solution(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i-1] == ' ')    // 단어 첫 글자
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);
    }
    return s;
}

// i=0이면 s[i-1]을 검사하지 않기 때문에 큰 문제가 없음
// toupper, tolower은 알파벳일때만 적용됨