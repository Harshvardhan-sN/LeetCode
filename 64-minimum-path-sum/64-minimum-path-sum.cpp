#define ll long long
class Solution {
public:
//     ll dp[207][207];

//     ll solve(ll start,ll end,vector<vector<int>> &v1){
//         if(start==0 && end==0)  return v1[start][end];
//         if(start<0 || end<0)    return INT_MAX;

//         if(dp[start][end]!=-1)  return dp[start][end];


//         ll up = solve(start-1,end,v1) + v1[start][end];
//         ll left = solve(start,end-1,v1)  + v1[start][end];

//         return dp[start][end] = min(up,left);
//     }

    int minPathSum(vector<vector<int>>& grid) {
        // memset(dp,-1,sizeof(dp));
        ll n = grid.size();
        ll m = grid[0].size();
        // return solve(n-1,m-1,grid);
        int arr[n][m];
        memset(arr,0,sizeof(arr));
    
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)	arr[i][j] = grid[i][j];
                else{
                
                    int up = 0;
                    if(i>0)		up+=grid[i][j] + arr[i-1][j];
                    else	up+=1e7;
                
                    int left = 0;
                    if(j>0)		left+=grid[i][j] + arr[i][j-1];
                    else 	left+=1e7;
                
                    arr[i][j] = min(up,left);
                }
            }
        }
        return arr[n-1][m-1];
    }
};