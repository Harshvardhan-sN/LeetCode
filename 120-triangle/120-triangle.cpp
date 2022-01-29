class Solution {
public:
    int dp[207][207];
    int solve(int start,int end,vector<vector<int>> &v1,int n){
        if(start+1 == n)  return v1[start][end];
        
        if(dp[start][end] != -1)  return dp[start][end];
        
        int up = solve(start+1,end,v1,n) + v1[start][end];
        int right = solve(start+1,end+1,v1,n) + v1[start][end];
        
        return dp[start][end] = min(up,right);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp,-1,sizeof dp);
        int n = triangle.size();
        
        return solve(0,0,triangle,n);
    }
};