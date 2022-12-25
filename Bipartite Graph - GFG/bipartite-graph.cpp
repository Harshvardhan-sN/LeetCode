//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int start, vector<int> adj[], vector<int> &vis){
	    queue<int> q1;
	    q1.push(start);
	    vis[start] = 1;
	    while(!q1.empty()){
	        int tr = q1.front();
	        q1.pop();
	        for(int i: adj[tr]){
	            if(vis[i]==-1){
	                vis[i] = !vis[tr];
	                q1.push(i);
	            }
	            else if(vis[i]==vis[tr])  
	                return 0;
	        }
	    }
	    return 1;
    }
    bool dfs(int start, int color, vector<int> adj[], vector<int> &vis){
        for(int i: adj[start]){
            if(vis[i]==-1){
                vis[i] = !vis[start];
                if(!dfs(i, vis[i], adj, vis))   return 0;
            }
            else if(vis[i]==vis[start]) return 0;
        }
        return 1;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> vis(V, -1);
	    for(int i=0; i<V; i++){
	        if(vis[i]==-1){
	           // // for -> BFS
	           // if(!bfs(i, adj, vis))    return 0;
	           
	           // // for -> DFS
	           vis[i] = 0;
	           if(!dfs(i, 0, adj, vis))    return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends