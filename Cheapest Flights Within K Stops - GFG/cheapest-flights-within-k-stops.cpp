//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int, int>> adj[n];
        for(auto &it: flights)
            adj[it[0]].push_back({it[1], it[2]});
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q1;
        q1.push({0, {src, -1}});
        int res = 1e9;
        set<pair<pair<int, int>, int>> st;
        while(q1.size()){
            int node = q1.top().second.first;
            int step = q1.top().second.second;
            int cost = q1.top().first;
            q1.pop();
            if(step <= k and node == dst){
                res = min(res, cost);
            }
            if(step >= k and node != dst){
                continue;
            }
            for(auto &it: adj[node]){
                if(!st.count({{node, it.first}, step})){
                    st.insert({{node, it.first}, step});
                    q1.push({cost + it.second, {it.first, step + 1}});
                }
            }
        }
        return res == 1e9 ? -1 : res;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends