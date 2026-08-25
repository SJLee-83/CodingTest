#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == 0){
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            else if(j == i){
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }
    for(int i = 0; i < n; i++){
        answer = max(answer, dp[n-1][i]);
    }
    
    return answer;
}