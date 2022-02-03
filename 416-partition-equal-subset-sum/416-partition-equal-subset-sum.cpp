class Solution {
public:
    int dp[210][20010];

    bool solve(int i,int sum,vector<int> &v1){
        if(sum==0)  return true;
        if(i<0)     return false;
        if(dp[i][sum]!=-1)  return dp[i][sum];
        // not pick
        bool ispossible = solve(i-1,sum,v1);
        // pick
        if(sum-v1[i]>=0)
            ispossible |= solve(i-1,sum-v1[i],v1);
        return dp[i][sum] = ispossible;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)    return false;
        sum = sum/2;
        return solve(n-1,sum,nums);
    }   
};