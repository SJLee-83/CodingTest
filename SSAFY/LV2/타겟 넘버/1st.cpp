#include <string>
#include <vector>

using namespace std;

int howCnt = 0;

void dfs(vector<int> numbers, int target, int sum, int cnt){
    if(cnt == numbers.size()){
        if(sum == target){
            howCnt++;
            return;
        }
        else return;
    }
    
    for(int i = 0; i < numbers.size(); i++){
        dfs(numbers, target, sum + numbers[i], cnt+1);
    }
    
    for(int i = 0; i < numbers.size(); i++){
        dfs(numbers, target, sum - numbers[i], cnt+1);
    }    
    
}

int solution(vector<int> numbers, int target) {
    
    int answer = 0;
    answer = dfs(numbers, target, 0, 0);
    return answer;
}