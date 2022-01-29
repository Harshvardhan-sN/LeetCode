class Solution {
public:
//     int dp[207][207];
//     int solve(int start,int end,vector<vector<int>> &v1,int n){
//         if(start+1 == n)  return v1[start][end];
        
//         if(dp[start][end] != -1)  return dp[start][end];
        
//         int up = solve(start+1,end,v1,n) + v1[start][end];
//         int right = solve(start+1,end+1,v1,n) + v1[start][end];
        
//         return dp[start][end] = min(up,right);
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
        // memset(dp,-1,sizeof dp);
        int n = triangle.size();
        vector<vector<int>> v1(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++)    v1[n-1][i] = triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + v1[i+1][j];
                int diagonal = triangle[i][j] + v1[i+1][j+1];
                v1[i][j] = min(down,diagonal);
            }
        }
        return v1[0][0];
    }
};