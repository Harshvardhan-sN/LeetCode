//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    int dis[5] = {0, -1, 0, 1, 0};
    
  public:
    void dfs(int r, int c, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &vis){
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nR = r + dis[i];
            int nC = c + dis[i+1];
            if(nR>=0 and nC>=0 and nR<n and nC<m and !vis[nR][nC] and grid[nR][nC]){
                grid[nR][nC] = 0;
                dfs(nR, nC, n, m, grid, vis);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if( (i==0 || i==n-1) || (i>0 and i<n-1 and (j==0 || j==m-1)) ){
                    if(!vis[i][j] and grid[i][j]){
                        grid[i][j] = 0;
                        dfs(i, j, n, m, grid, vis);
                    }
                }
            }
        }
        for(auto arr: grid){
            for(auto it: arr)      res += it;
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends