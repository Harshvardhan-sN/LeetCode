//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] and grid[row][col]=='1'){
                    ans++;
                    dfs(row, col, n, m, vis, grid);
                    // bfs(row, col, n, m, vis, grid);
                }
            }
        }
        return ans;
    }
private:
    void dfs(int r, int c, int n, int m, vector<vector<bool>> &vis, vector<vector<char>> &grid){
        vis[r][c] = 1;
        for(auto &it: grid){
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int Row = r + i;
                    int Col = c + j;
                    if(Row>=0 and Col>=0 and
                        Row<n and Col<m and
                        !vis[Row][Col] and grid[Row][Col]=='1'){
                            dfs(Row, Col, n, m, vis, grid);
                        }
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends