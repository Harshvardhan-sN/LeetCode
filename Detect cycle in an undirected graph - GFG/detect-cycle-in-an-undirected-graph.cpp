//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool bfs(int V, int source, vector<int> adj[]){
        bool vis[V] = {};
        queue<pair<int,int>> que;
        que.push({source, -1});
        vis[source] = 1;
        while(!que.empty()){
            int curr = que.front().first;
            int prev = que.front().second;
            que.pop();
            for(int it: adj[curr]){
                if(prev!=it){
                    if(!vis[it]){
                        que.push({it, curr});
                        vis[it] = 1;
                    }
                    else            return 1;
                }
            }
        }
        return 0;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        for(int i=0; i<V; i++){
            if(bfs(V, i, adj))      return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends