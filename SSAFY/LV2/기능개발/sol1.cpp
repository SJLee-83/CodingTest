#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int n = progresses.size();

    vector<int> days(n);
    for(int i = 0; i < n; i++){
        int remain = 100 - progresses[i];
        days[i] = remain / speeds[i];
        if(remain % speeds[i] != 0) days[i]++;
    }
    
    int i = 0;
    while(i < n){
        int deployDay = days[i];
        int count = 1;

        i++;
        while(i < n && days[i] <= deployDay){
            count++;
            i++;
        }

        answer.push_back(count);
    }

    return answer;
}