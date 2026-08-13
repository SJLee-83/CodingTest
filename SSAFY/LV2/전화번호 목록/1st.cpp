#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_map<string, int> cnt;
    
    for(int i = 0; i < phone_book.size(); i++){
        cnt[phone_book[i]] += phone_book[i].size();
    }
    
    // 번호 길이로 오름차순 정렬 후, 길이가 더 큰 값들 앞에 해당 숫자가 있는지 확인하다가 있으면 false return, 없으면 true return
    
    
    
    bool answer = true;
    return answer;
}