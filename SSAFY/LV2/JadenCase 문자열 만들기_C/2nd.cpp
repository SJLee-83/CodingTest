#include <string>
using namespace std;

string solution(string s) {
    int l = 0;
    int len = s.size();
    
    while(l < len){
        if(s[l] == ' '){
            l++;
        }
        // 첫 글자가 알파벳이 아님 (숫자)
        else if((s[l] < 'a' || s[l] > 'z') && (s[l] < 'A' || s[l] > 'Z')){
            while(l < len && s[l] != ' '){
                if(s[l] >= 'A' && s[l] <= 'Z'){
                    s[l] += 32;
                }
                l++;
            }
        }
        // 첫 글자가 알파벳
        else{
            if(s[l] >= 'a' && s[l] <= 'z'){
                s[l] -= 32;
            }
            l++;
            while(l < len && s[l] != ' '){
                if(s[l] >= 'A' && s[l] <= 'Z'){
                    s[l] += 32;
                }
                l++;
            }
        }
    }
    
    return s;
}