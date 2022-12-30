//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(vector<int> adj[], vector<int> &path, int src){
        queue<pair<int, int>> q1;
        q1.push({src, 0});
        while(!q1.empty()){
            int node = q1.front().first;
            int cost = q1.front().second;
            q1.pop();
            for(auto &child: adj[node]){
                if(path[child]==103){
                    int ChildCost = cost + 1;
                    path[child] = min(path[child], ChildCost);
                    q1.push({child, path[child]});   
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> adj[N];
        for(auto &it: edges){
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> path(N, 103);
        path[src] = 0;
        bfs(adj, path, src);
        for(auto &it: path){
            if(it==103)     it = -1;
        }
        return path;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends