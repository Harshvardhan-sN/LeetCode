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
            // not visited 
            if(!vis[i]){
                if(dfs(i, adj, vis, path))  return 1;
            }
            // if visited and path_visited then we have find a cycle
            else if(path[i])    return 1;
        }
        path[start] = 0;
        return 0;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // vector<bool> vis(V, 0);
        // vector<bool> path(V, 0);
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         if(dfs(i, adj, vis, path))  return 1;
        //     }
        // }
        vector<int> InDegree(V, 0);
	    queue<int> q1;
	    for(int i=0; i<V; i++){
	        for(int &it: adj[i])    InDegree[it]++;
	    }    
	    for(int i=0; i<V; i++){
	        if(InDegree[i]==0)    q1.push(i);
	    }
	    int temp = 0;
	    while(!q1.empty()){
	        int S = q1.front();
	        temp++;
	        q1.pop();
	        for(int &child: adj[S]){
	            InDegree[child]--;
	            if(InDegree[child]==0)    q1.push(child);
	        }
	    }
	    // if topological sort exict then there is no cycle
	    // .. so we return false
	    if(temp==V)     return 0;
	    return 1;
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