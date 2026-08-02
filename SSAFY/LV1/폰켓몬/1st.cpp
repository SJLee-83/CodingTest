#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> nums)
{
    unordered_map<int, int> count;
    int answer = 0;
    for(int i = 0; i < nums.size(); i++){
        count[nums[i]]++;
    }
    
    if(count.size() < nums.size()/2){
        answer = count.size();
    }else{
        answer = nums.size()/2;
    }
    
    return answer;
}