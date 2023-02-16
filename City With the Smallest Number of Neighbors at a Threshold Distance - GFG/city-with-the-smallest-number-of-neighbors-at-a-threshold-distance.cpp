//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int dijkstra(int n, int S, vector<vector<int>> adj[], int thress){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        vector<int> vis(n, 1e9);
        vis[S] = 0;
        unordered_set<int> st;
        while(pq.size()){
            auto it = pq.top();
            int cost = it.first;
            int node = it.second;
            pq.pop();
            for(auto &it: adj[node]){
                if(cost + it[1] < vis[it[0]]){
                    if(cost + it[1] <= thress){
                        st.insert(it[0]);
                        vis[it[0]] = cost + it[1];
                        pq.push({cost + it[1], it[0]});
                    }
                }
            }
        }
        return st.size();
    }
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<vector<int>> adj[n];
        for(auto &it: edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        int currMin = 1e9, currCity = -1;
        for(int i = 0; i < n; i++){
            int Mini = dijkstra(n, i, adj, distanceThreshold);
            if(Mini <= currMin){
                currCity = max(currCity, i);
                currMin = Mini;
            }
        }
        return currCity;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends