//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int res = 0, minCost = -1, mod = 1e9 + 7;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> adj[n];
        for(auto &it: roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        pq.push({0, 0});
        vector<int> vis(n, 1e9);
        vector<int> ways(n, 0);
        ways[0] = 1;
        vis[0] = 0;
        while(pq.size()){
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &child: adj[node]){
                int newCost = cost + child[1];
                if(newCost < vis[child[0]]){
                    vis[child[0]] = newCost;
                    ways[child[0]] = ways[node];
                    pq.push({newCost, child[0]});
                }
                else if(newCost == vis[child[0]]){
                    ways[child[0]] += ways[node];
                    ways[child[0]] %= mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends