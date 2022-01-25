class Solution {
public:
    int dp[107][107];
    int solve(int i, int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)	return dp[i][j];
        int left = solve(i-1,j);
        int up = solve(i,j-1);

        return dp[i][j] = left+up;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1);
    }
};