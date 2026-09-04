#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    
    for(int i = 0; i < works.size(); i++){
        pq.push(works[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(pq.top() == 0) break;
        
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }
    
    long long answer = 0;
    while(!pq.empty()){
        long long work = pq.top();
        pq.pop();
        answer += work * work;
    }
    
    return answer;
}