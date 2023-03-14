//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	   void dfs1(int S, stack<int> &st, vector<vector<int>>& adj, vector<bool> &vis){
	       vis[S] = 1;
	       for(auto &it: adj[S]){
	           if(!vis[it])
	            dfs1(it, st, adj, vis);
	       }
	       st.push(S);
	   }
	   void dfs2(int S, vector<int> adj[], vector<bool> &vis){
	       vis[S] = 1;
	       for(auto &it: adj[S])
	            if(!vis[it])
	                dfs2(it, adj, vis);
	   }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<bool> vis(V, 0);
        stack<int> st;
        for(int i = 0; i < V; ++i){
            if(!vis[i]){
                dfs1(i, st, adj, vis);
            }
        }
        vector<int> transpose[V];
        for(int i = 0; i < V; ++i){
            vis[i] = 0;
            for(auto &it: adj[i])
                transpose[it].push_back(i);
        }
        int res = 0;
        while(st.size()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                ++res;
                dfs2(node, transpose, vis);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends