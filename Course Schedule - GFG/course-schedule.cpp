//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) {
        vector<int> InDegree(N, 0);
	    vector<int> adj[N];
	    // create a adjacency matrix
	    for(auto &it: prerequisites){
	        adj[it[1]].push_back(it[0]);
	    }
	    // count number of inDegrees for each node
	    for(int i=0; i<N; i++){
	        for(auto &it: adj[i])   InDegree[it]++;
	    }
	    queue<int> q1;
	    // insert node on queue with InDegree 0
	    for(int i=0; i<N; i++){
	        if(InDegree[i]==0)      q1.push(i);
	    }
	    // bfs for toposort
	    vector<int> toposort;
	    while(!q1.empty()){
	        int from = q1.front();
	        toposort.push_back(from);    // linear order of sort
	        q1.pop();
	        for(auto &it: adj[from]){
	            InDegree[it]--;
	            if(InDegree[it]==0)     q1.push(it);
	        }
	    }
	    if(toposort.size()==N)  return toposort;
	    return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends