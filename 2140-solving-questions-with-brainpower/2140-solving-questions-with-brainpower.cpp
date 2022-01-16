class Solution {
public:
    long long solve(int ind,vector<vector<int>> &q,vector<long long> &dp){
        int n = q.size();
        if(ind == n-1){
            return q[ind][0];
        }
        if(ind >= n)        return 0;
        if(dp[ind]!=-1)     return dp[ind];
        
        long long take = q[ind][0]+solve(ind + q[ind][1]+1,q,dp);
        long long n_take = solve(ind+1,q,dp);
        
        return dp[ind] = max(take,n_take);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,dp);
    }
};