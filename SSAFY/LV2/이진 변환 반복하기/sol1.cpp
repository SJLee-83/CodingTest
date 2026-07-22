#include <string>
#include <vector>
using namespace std;

string toBinary(int n) {
    string result = "";
    while (n > 0) {
        result = char('0' + n % 2) + result;
        n /= 2;
    }
    return result;
}

vector<int> solution(string s) {
    int count = 0;    // 이진 변환 횟수
    int zeros = 0;    // 제거된 0의 총 개수
    
    while (s != "1") {
        count++;
        
        int ones = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') ones++;
            else zeros++;          // 제거되는 0을 그때그때 누적
        }
        
        s = toBinary(ones);        // 1의 개수를 이진수 문자열로
    }
    
    return {count, zeros};
}