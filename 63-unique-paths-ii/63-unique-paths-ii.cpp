class Solution {
public:
    int dp[107][107];

    int solve(int i, int j, vector<vector<int>> &v1){
        if(i>=0 &&  j>=0 && v1[i][j]==1){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1)    return dp[i][j];
        int left = solve(i-1,j,v1);
        int up = solve(i,j-1,v1);

        return dp[i][j] = left+up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(n==1 && m==1){
            if(obstacleGrid[0][0]==1)   return 0;
            return 1;
        }
        memset(dp,-1,sizeof(dp));
        return solve(n-1,m-1,obstacleGrid);
    }
};