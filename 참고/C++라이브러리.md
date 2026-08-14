# sort
#include<algorithm>

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end()); // 오름차순 정렬
}

# find
find는 문자열 안에서 다른 문자열을 찾아 그 시작 위치를 돌려줌. 찾으면 string::npos라는 특수값을 돌려줌

    if (phone_book[i + 1].find(phone_book[i]) == 0) {
        return false;
    }

# set vs unordered_set
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

int main() {
    set<string> s = {"119", "97674223", "1195524421", "12"};
    unordered_set<string> us = {"119", "97674223", "1195524421", "12"};
    
    for (auto& x : s)  cout << x << " ";
    cout << endl;
    
    for (auto& x : us) cout << x << " ";
    cout << endl;
}

출력 결과
set:            119 12 1195524421 97674223       ← 사전순 정렬
unordered_set:  12 1195524421 97674223 119       ← 순서 없음 (실행마다 다를 수 있음)

# stringstream
#include <sstream>

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

# to_string
#include <string>
    
string ss = to_string(mn) + " " + to_string(mx);