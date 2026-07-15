#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
using namespace std;

string solution(string s) {
    stringstream ss(s);
    int num;
    int mn = INT_MAX;   // 가장 큰 값으로 시작 → 어떤 입력이든 갱신됨
    int mx = INT_MIN;   // 가장 작은 값으로 시작
    
    while (ss >> num) {          // 공백 단위로 하나씩 int로 읽음
        mn = min(mn, num);
        mx = max(mx, num);
    }
    
    return to_string(mn) + " " + to_string(mx);
}