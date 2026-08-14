#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    vector<int> nums;
    string token = "";
    s += ' ';                    // 마지막 숫자도 처리되도록 공백 하나 추가
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            nums.push_back(stoi(token));  // 조각을 int로 변환해 저장
            token = "";                   // 조각 비우기
        } else {
            token += s[i];                // 공백 전까지 문자 누적
        }
    }
    
    int mn = *min_element(nums.begin(), nums.end());
    int mx = *max_element(nums.begin(), nums.end());
    // 반환값은 "값"이 아니라 "위치(반복자)"
    // int mn = min_element(nums.begin(), nums.end());   // ❌ 위치를 int에 넣으려 함
    // int mn = *min_element(nums.begin(), nums.end());   // ✅ 위치 → 실제 값
//       ↑ 여기 별표가 "가리키는 값을 꺼내라"
    
    return to_string(mn) + " " + to_string(mx);
}