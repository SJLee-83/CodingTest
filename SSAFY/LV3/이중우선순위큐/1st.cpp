#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> pq;
    vector<int> answer;
    
    for(int i = 0; i < operations.size(); i++){
        if(operations[i][0] == 'I'){
            string ip = ""
            for(int j = 0; j < operations[i].size(); i++){
                ip += operations[i][j];
                stoi(ip);
                pq.push(ip);
            }
        }
        else{
            if(operations[i][2] == '-'){
                if(pq.empty()) continue;
                
                // pq 제일 뒷 값 삭제
            }
            else{
                pq.pop();
            }
        }
        
        
        
    }
    
    return answer;
}