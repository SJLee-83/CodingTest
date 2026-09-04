#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    
    for (int i = 0; i < operations.size(); i++) {
        // 명령어와 숫자 분리
        char cmd = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if (cmd == 'I') {
            ms.insert(num);
        }
        else {  // 'D'
            if (ms.empty()) continue;
            
            if (num == 1) {
                ms.erase(--ms.end());   // 최댓값 삭제
            } else {
                ms.erase(ms.begin());   // 최솟값 삭제
            }
        }
    }
    
    if (ms.empty()) return {0, 0};
    return {*(--ms.end()), *ms.begin()};   // [최댓값, 최솟값]
}