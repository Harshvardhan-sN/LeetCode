//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	   // map<int, int> iE;
	    vector<int> iE(V, 0);
	    queue<int> q1;
	    for(int i=0; i<V; i++){
	        for(int &it: adj[i])    iE[it]++;
	    }    
	    for(int i=0; i<V; i++){
	        if(iE[i]==0)    q1.push(i);
	    }
	    vector<int> res;
	    while(!q1.empty()){
	        int S = q1.front();
	        q1.pop();
	        res.push_back(S);
	        
	        for(int &child: adj[S]){
	            iE[child]--;
	            if(iE[child]==0)    q1.push(child);
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
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
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends