//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool isVal(int x, int y, int n, int m){
        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        // code here
        vector<vector<bool>> vis(N, vector<bool>(M, 0));
        queue<pair<int, int>> q1;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < M; ++j){
                if(grid[i][j] == 'X'){
                    q1.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        int cost = 0;
        while(q1.size()){
            int k = q1.size();
            bool found = 0;
            while(k--){
                auto it = q1.front();
                q1.pop();
                int a = it.first, b = it.second;
                if(grid[a][b] == 'Y'){
                    found = 1;
                    break;
                }
                for(int l = 0; l < 4; ++l){
                    int X = a + dx[l], Y = b + dy[l];
                    if(isVal(X, Y, N, M) && !vis[X][Y]){
                        vis[X][Y] = 1;
                        q1.push({X, Y});
                    }
                }
            }
            if(found)   break;
            cost++;
        }
        return cost;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        char ch;
        cin >> N >> M;

        vector<vector<char>> grid;

        for (int i = 0; i < N; i++) {
            vector<char> col;
            for (int i = 0; i < M; i++) {
                cin >> ch;
                col.push_back(ch);
            }
            grid.push_back(col);
        }

        Solution ob;
        cout << ob.shortestXYDist(grid, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends