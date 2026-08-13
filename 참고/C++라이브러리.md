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