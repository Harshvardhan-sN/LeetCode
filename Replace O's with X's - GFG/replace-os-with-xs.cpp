//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    int dis[5] = {0, -1, 0, 1, 0};
public:
void dfs(int r, int c, int n, int m, vector<vector<char>> &mat, vector<vector<char>> &res, vector<vector<bool>> &vis){
    vis[r][c] = 1;
    for(int i=0; i<4; i++){
        int nR = r + dis[i];
        int nC = c + dis[i+1];
        if(nR>=0 and nC>=0 and nR<n and nC<m and !vis[nR][nC] and mat[nR][nC]=='O'){
            res[nR][nC] = 'O';
            dfs(nR, nC, n, m, mat, res, vis);
        }
    }
}
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
    vector<vector<char>> res(n, vector<char>(m, 'X'));
    queue<pair<int, int>> q1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if((i==0 || i==n-1) || (i>0 and i<n-1 and (j==0 || j==m-1))){
                if(mat[i][j]=='O'){
                    // q1.push({i, j});
                    // vis[i][j] = 1;
                    res[i][j] = 'O';
                    dfs(i, j, n, m, mat, res, vis);
                }
            }
        }
    }
    // while(!q1.empty()){
    //     int r = q1.front().first;
    //     int c = q1.front().second;
    //     q1.pop();
    //     for(int i=0; i<4; i++){
    //         int nR = r + dis[i];
    //         int nC = c + dis[i+1];
    //         if(nR>=0 and nC>=0 and nR<n and nC<m and !vis[nR][nC] and mat[nR][nC]=='O'){
    //             res[nR][nC] = 'O';
    //             vis[nR][nC] = 1;
    //             q1.push({nR, nC});
    //         }
    //     }
    // }
    return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends