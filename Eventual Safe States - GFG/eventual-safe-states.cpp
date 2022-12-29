//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool dfs(int start, vector<int> adj[], vector<bool> &vis, vector<bool> &path) {
	    vis[start] = 1;
	    path[start] = 1;
    	for (int &i : adj[start]) {
	    	if (!vis[i]) {
    			if (dfs(i, adj, vis, path))  return 1;
		    }
		    else if (path[i])    return 1;
	    }
	    path[start] = 0;
    	return 0;
    }
    vector<int> DoDfs(int V, vector<int> adj[]){
        vector<bool> vis(V, 0);
        vector<bool> path(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, path);
            }
        }
        vector<int> res;
        for(int i=0; i<V; i++){
            if(!path[i])     res.push_back(i);
        }
        return res;
    }
    vector<int> bfs(int V, vector<int> adj[]){
        vector<int> revAdj[V];
        vector<int> InDegree(V, 0);
        for(int i=0; i<V; i++){
            for(int &it: adj[i]){
                revAdj[it].push_back(i);
                InDegree[i]++;
            }    
        }
        queue<int> q1;
        for(int i=0; i<V; i++){
            if(InDegree[i]==0)      q1.push(i);
        }
        vector<int> res;
        while(!q1.empty()){
            int from = q1.front();
            res.push_back(from);
            q1.pop();
            for(int &it: revAdj[from]){
                InDegree[it]--;
                if(InDegree[it]==0)     q1.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // return DoDfs(V, adj);
        return bfs(V, adj);
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends