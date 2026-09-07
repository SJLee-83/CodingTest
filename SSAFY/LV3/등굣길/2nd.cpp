#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for(int i = 0; i < puddles.size(); i++){
        int col = puddles[i][0];
        int row = puddles[i][1];
        dp[row][col] = -1;
    }

    dp[1][1] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == -1){
                dp[i][j] = 0;
                continue;
            }

            if(i == 1 && j == 1) continue;

            int fromUp = 0;
            int fromLeft = 0;

            if(i > 1){
                fromUp = dp[i-1][j];
            }
            if(j > 1){
                fromLeft = dp[i][j-1];
            }


            dp[i][j] = (fromUp + fromLeft) % MOD;
        }
    }
    return dp[n][m];
}