class Solution {
public:
    int dp[10010];
    int solve(int amount, vector<int> &v1){
        if(amount==0)   return 0;
        if(dp[amount]!=-1)  return dp[amount];
        
        int ans = INT_MAX;
        for(auto &it:v1){
            if((amount-it)>=0)
                ans = min(ans+ 0LL,solve(amount-it,v1)+1LL);
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int ans = solve(amount,coins);
        return ans == INT_MAX?-1:ans;
    }
};