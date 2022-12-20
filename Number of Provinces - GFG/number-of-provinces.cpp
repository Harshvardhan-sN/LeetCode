//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int N){
        vis[N] = 1;
        for(auto &it: adj[N]) {
            if(!vis[it])    dfs(adj, vis, it);
        }   
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<bool> vis(V+1, 0);
        vector<vector<int>> v1;
        v1.push_back({});
        for(auto &it: adj){
            vector<int> a;
            for(int i=0; i<it.size(); i++){
                if(it[i]==1)    a.push_back(i+1);
            }
            v1.push_back(a);
        }
        int ans = 0;
        for(int i=1; i<=V; i++){
            if(!vis[i]){
                dfs(v1, vis, i);
                ans++;
            }     
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends