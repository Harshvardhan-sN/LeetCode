class Solution {
public:
    int dp[2515];
    int solve(int i,vector<int> &it){
        if(dp[i]!=-1)   return dp[i];
        int ans = 1;
        
        for(int j=0;j<i;++j){
            if( it[i] > it[j] ){
                ans = max(ans,solve(j,it)+1);
            }
        }
        return dp[i] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int ans = 0;
        
        for(int i=0;i<nums.size();++i){
            ans = max(ans,solve(i,nums));
        }
        return ans;
    }
};