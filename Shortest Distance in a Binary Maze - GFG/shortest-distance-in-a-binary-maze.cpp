//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    struct val{
    int x, y, z;
};

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValidDirection(int X, int Y, int n, int m) {return (X >= 0 && Y >= 0 && X < n && Y < m);}

  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
    set<pair<int, pair<int, int>>> q1;
    // queue<val> q1;
    // priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q1;
    vector<vector<bool>> vis(n, vector<bool> (m, 0));
    vis[source.first][source.second] = 1;
    // q1.push({source.first, source.second, 0});
    q1.insert({0, source});
    while(q1.size()){
        auto it = q1.begin();
        int x = it->second.first;
        int y = it->second.second;
        int cost = it->first;
        q1.erase(it);
        if(x == destination.first and y == destination.second)
            return cost;
        for(int i = 0; i < 4; i++){
            int dX = x + dx[i];
            int dY = y + dy[i];
            if(isValidDirection(dX, dY, n, m) and !vis[dX][dY] and grid[dX][dY]==1){
                vis[dX][dY] = 1;
                q1.insert({cost + 1, {dX, dY}});
            }
        }
    }
    return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends