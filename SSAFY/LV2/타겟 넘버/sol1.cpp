#include <vector>
using namespace std;

void dfs(vector<int>& numbers, int target, int idx, int sum, int& count) {
    // 숫자를 다 썼으면 결과 확인
    if (idx == numbers.size()) {
        if (sum == target) count++;
        return;
    }
    
    dfs(numbers, target, idx + 1, sum + numbers[idx], count);  // 이번 숫자를 +로
    dfs(numbers, target, idx + 1, sum - numbers[idx], count);  // 이번 숫자를 -로
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0, answer);
    return answer;
}