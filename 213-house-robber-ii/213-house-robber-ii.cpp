class Solution {
public:
    int solve(int i,vector<int> &v1,vector<int> &dp){
        if(i == 0)    return v1[i];
        if(i < 0)     return 0;
        
        if(dp[i]!=-1)	return dp[i];
        
        int left = INT_MIN;
        int right = INT_MIN;

        left = solve(i-2,v1,dp)+v1[i];
        right = solve(i-1,v1,dp);

        return dp[i] = max(left,right);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)    return nums[0];
        
        vector<int> dp1(n,-1),dp2(n,-1);
        // before reverse excluding last element
        int ans1 = solve(n-2,nums,dp1);
        
        reverse(nums.begin(),nums.end());
        // after reverse excluding 1st element 
        return max( ans1,solve(n-2,nums,dp2) );
    }
};