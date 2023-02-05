//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> st;
        st.emplace(0, S);
        vector<int> paths(V, 1e9);
        paths[S] = 0;
        while(st.size()){
            int cost = st.top().first;
            int node = st.top().second;
            st.pop();
            for(auto &it: adj[node]){
                int newCost = cost + it[1];
                if(newCost < paths[it[0]]){
                    paths[it[0]] = newCost;
                    st.emplace(newCost, it[0]);
                }
            }
        }
        return paths;
        // set<pair<int, int>> st;
        // st.emplace(0, S);
        // vector<int> paths(V, 1e9);
        // paths[S] = 0;
        // while(st.size()){
        //     auto it = st.begin();
        //     int cost = it->first;
        //     int node = it->second;
        //     st.erase(it);
        //     for(auto &it: adj[node]){
        //         int newCost = cost + it[1];
        //         if(newCost < paths[it[0]]){
        //             paths[it[0]] = newCost;
        //             st.emplace(newCost, it[0]);
        //         }
        //     }
        // }
        // return paths;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends