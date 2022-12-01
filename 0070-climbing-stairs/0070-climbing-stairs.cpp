class Solution {
public:
    int step(int i, int n, vector<int> &dp){
        if(i==n)    return 1;
        if(i>n)     return 0;
        if(dp[i]!=-1)   return dp[i];
        int l = step(i+1, n, dp);
        int r = step(i+2, n, dp);
        return dp[i] = l + r;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return step(0, n, dp);
    }
};