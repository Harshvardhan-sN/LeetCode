class Solution {
public:
//     int dp[107][107];
//     int solve(int i, int j){
//         if(i==0 && j==0){
//             return 1;
//         }
//         if(i<0 || j<0){
//             return 0;
//         }
//         if(dp[i][j]!=-1)	return dp[i][j];
//         int left = solve(i-1,j);
//         int up = solve(i,j-1);

//         return dp[i][j] = left+up;
//     }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(m-1,n-1);
        
        // Optimal Solution
        int N = n+m-2;
        int r = m-1;
        double ans = 1;
        for(int i=1;i<=r;i++){
            ans = ans*(N-r+i)/i;
        }
        return int(ans);
        
    }
};