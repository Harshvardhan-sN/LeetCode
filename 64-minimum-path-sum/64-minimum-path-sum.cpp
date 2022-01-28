#define ll long long
class Solution {
public:
    ll dp[207][207];


    ll solve(ll start,ll end,vector<vector<int>> &v1){
        if(start==0 && end==0)  return v1[start][end];
        if(start<0 || end<0)    return INT_MAX;

        if(dp[start][end]!=-1)  return dp[start][end];


        ll up = solve(start-1,end,v1) + v1[start][end];
        ll left = solve(start,end-1,v1)  + v1[start][end];

        return dp[start][end] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        ll n = grid.size();
        ll m = grid[0].size();
        return solve(n-1,m-1,grid);
    }
};