#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;

    for(int i = 0; i < operations.size(); i++){
        char cmd = operations[i][0];
        int num = stoi(operations[i].substr(2));

        if(cmd == 'I'){
            ms.insert(num);
        }
        else{
            if(ms.empty()) continue;

            if(num == 1){
                ms.erase(--ms.end());
            }
            else{
                ms.erase(ms.begin());
            }
        }
    }
    
    if(ms.empty()) return {0, 0};
    return {*(--ms.end()), *ms.begin()};
}