#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    const int MOD = 1000000007;
    
    // dp[행][열], 1-based로 사용
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // 물웅덩이 표시 (-1)
    for (int i = 0; i < puddles.size(); i++) {
        int col = puddles[i][0];
        int row = puddles[i][1];
        dp[row][col] = -1;
    }
    
    dp[1][1] = 1;   // 출발점
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (dp[i][j] == -1) {
                dp[i][j] = 0;      // 물웅덩이는 0으로
                continue;
            }
            if (i == 1 && j == 1) continue;   // 출발점은 건너뜀
            
            int fromUp = (i > 1) ? dp[i-1][j] : 0;
            int fromLeft = (j > 1) ? dp[i][j-1] : 0;
            
            dp[i][j] = (fromUp + fromLeft) % MOD;
        }
    }
    
    return dp[n][m];
}