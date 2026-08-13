#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;

    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];
        if (remain % speeds[i] != 0) day++;
        q.push(day);
    }    

    while (!q.empty()) {
        int deployDay = q.front();   // 맨 앞이 이번 배포일
        q.pop();
        int count = 1;
        
        // 뒤 작업들 중 함께 배포될 것들 꺼내기
        while (!q.empty() && q.front() <= deployDay) {
            q.pop();
            count++;
        }
        
        answer.push_back(count);
    }

    return answer;
}