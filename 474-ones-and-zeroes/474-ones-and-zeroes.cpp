// // DP RECURSIVE
// class Solution {
//     int dp[607][107][107];
// private:
//     int solve(int i,int m,int n,vector<string> &s){
//         if(i==s.size() || !(m+n))     return 0;
        
//         if(dp[i][m][n]!=0)    return dp[i][m][n];
//         int zero = count(s[i].begin(),s[i].end(),'0');
//         int one = count(s[i].begin(),s[i].end(),'1');
        
//         int take = 0;
//         if(zero<=m and one<=n){
//             take = 1 + solve(i+1,m-zero,n-one,s);
//         }
//         int noTake = solve(i+1,m,n,s);
        
//         return dp[i][m][n] = max(noTake,take);
//     }
// public:
//     int findMaxForm(vector<string>& strs, int m, int n) {
//         return solve(0,m,n,strs);        
//     }
// };

// // DP ITRATIVE:
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];
        memset(dp,0,sizeof dp);
        for(auto &it:strs){
            int zero = count(it.begin(),it.end(),'0');
            int one = count(it.begin(),it.end(),'1');
            for(int i=m;i>=zero;i--){        // ZERO
                for(int j=n;j>=one;j--){    // ONE
                    dp[i][j] = max(dp[i-zero][j-one] + 1,dp[i][j]);
                }
            }
        }
        return dp[m][n];
    }
};