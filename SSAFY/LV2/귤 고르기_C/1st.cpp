#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    int arr[10000000];
    int maxNum = 0;
    
    for(int i = 0; i < tangerine.size(); i++){
        arr[tangerine[i]]++;
        maxNum = max(maxNum, tangerine[i]);
    }
    
    sort(arr + 1, arr + maxNum + 1);
    
    queue<int> q;
    q.push()
    
    while(!q.empty()){
        
    }
    
    return answer;
}