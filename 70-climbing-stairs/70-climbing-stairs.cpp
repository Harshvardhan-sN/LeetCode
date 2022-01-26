class Solution {
public:
    int dp[51];
    int solve(int i){
        if(i==0)    return 1;
        if(dp[i]!=-1)   return dp[i];
        int take = solve(i-1);
        int notTake = 0;
        if(i>1){
            notTake = solve(i-2);
        }
        return dp[i] = take+notTake;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};