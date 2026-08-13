#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    stack<int> st;
    
    for(int i = 0; i < progresses.size(); i++){
        int endDate = (100 - progresses[i]) / speeds[i] + 1;
        if(i == 0 || endDate > st.top()){
            st.push(endDate);   
        }
        else{
            st.push(st.top());
        }
    }
    
    int cnt = 0;
    int num = 0;
    while(!st.empty()){
        
    }
    
    return answer;
}