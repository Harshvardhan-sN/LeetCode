//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    void dfs(int S, int E, vector<int> &path, vector<int> &res){
        if(S == E)      return;
        dfs(path[S], E, path, res);
        res.push_back(S);
    }
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        set<pair<int, int>> st;
        vector<vector<int>> adj[n+1];
        for(auto &it: edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<int> initialCost(n+1, 1e9);
        initialCost[1] = 0;
        st.emplace(0, 1);
        // unordered_map<int, int> path;
        vector<int> path(n+1, 0);
        path[1] = 1;
        while(st.size()){
            auto it = st.begin();
            int cost = it->first;
            int node = it->second;
            st.erase(it);
            for(auto &neighbour: adj[node]){
                int newCost = cost + neighbour[1];
                int goToNode = neighbour[0];
                if(newCost < initialCost[goToNode]){
                    if(initialCost[goToNode] != 1e9)    st.erase({initialCost[goToNode], goToNode});
                    initialCost[goToNode] = newCost;
                    path[goToNode] = node;
                    st.emplace(newCost, goToNode);
                }
            }
        }
        if(path[n]==0)    return {-1};
        vector<int> res;
        res.push_back(1);
        dfs(n, 1, path, res);
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends