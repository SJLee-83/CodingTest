#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> st;

    for(int i = 0; i < arr.size(); i++){
        if(st.empty || st.top() != arr[i]){
            st.push(arr[i]);
        }
    }

    vector<int> answer;
    while(!st.empty){
        answer.push_back(st.top());
        st.pop();
    }
    reverse(answer.begin(), answer.end());

    return answer;
}