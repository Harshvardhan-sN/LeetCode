//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> bfs(int N, vector<pair<int, int>> adj[]){
        vector<int> InDegree(N, 0);
	    queue<int> q1;
	    vector<int> path(N, 101);
    	for(int i=0; i<N; i++){
		    for(auto &it: adj[i]){
			    InDegree[it.first]++;
		    }
	    }
    	for(int i=0; i<N; i++){
	    	if(InDegree[i]==0)		q1.push(i);
    	}
	    path[0] = 0;
    	while(!q1.empty()){
		    int from = q1.front();
	    	q1.pop();
    		int currDist = path[from];
		    for(auto &it: adj[from]){
		    	path[it.first] = min(path[it.first], currDist + it.second);
	    		InDegree[it.first]--;
    			if(InDegree[it.first]==0)	q1.push(it.first);
		    }
	    }
    	for (auto &it : path) {
		    if (it == 101)     it = -1;     // if node is not reachable
	    }
	    return path;
    }
    void dfs(int S, vector<int> &vis, vector<pair<int, int>> adj[], stack<int> &st){
        vis[S] = 1;
        for(auto &it: adj[S]){
            if(!vis[it.first]){
                dfs(it.first, vis, adj, st);
            }
        }
        st.push(S);
    }
    vector<int> DoDfs(int N, vector<pair<int, int>> adj[]){
        stack<int> st;
        vector<int> vis(N, 0), path(N, 101);
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        path[0] = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            int currDistance = path[top];
            for(auto &it: adj[top]){
                path[it.first] = min(path[it.first], currDistance+it.second);
            }
        }
        for(auto &it: path){
            if(it==101)     it = -1;
        }
        return path;
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[N];
        for(auto &it: edges){
            adj[it[0]].push_back({it[1],it[2]});
        }
        return bfs(N, adj);
        return DoDfs(N, adj);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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