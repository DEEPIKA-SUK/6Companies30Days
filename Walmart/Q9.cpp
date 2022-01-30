class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int l=2;l<=n;l++){
            for(int s=0;s<=n-l;s++){
                int e = s+l;
                for(int i=s; i<e; ++i){
                    int x = i+1;
                    if(i==s){
                        dp[s][e] = x+ dp[s+1][e];
                    }else{
                        dp[s][e] = min(dp[s][e], max(dp[s][i], dp[i+1][e]) + x);
                    }
                }
            }
        }
        return dp[0][n];
    }
};