//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int start, vector<int> adj[], vector<bool> &vis, vector<bool> &path){
        vis[start] = 1;
        path[start] = 1;
        for(int &i: adj[start]){
            if(!vis[i]){
                if(dfs(i, adj, vis, path))  return 1;
            }
            else if(path[i])    return 1;
        }
        path[start] = 0;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V, 0);
        vector<bool> path(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path))  return 1;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends