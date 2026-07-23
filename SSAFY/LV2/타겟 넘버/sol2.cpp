#include <vector>
using namespace std;

int dfs(vector<int>& numbers, int target, int idx, int sum) {
    if (idx == numbers.size()) {
        return (sum == target) ? 1 : 0;
    }
    
    return dfs(numbers, target, idx + 1, sum + numbers[idx])
         + dfs(numbers, target, idx + 1, sum - numbers[idx]);
}

int solution(vector<int> numbers, int target) {
    return dfs(numbers, target, 0, 0);
}