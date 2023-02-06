//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
bool isValidDirection(int X, int Y, int n, int m) {return (X >= 0 && Y >= 0 && X < n && Y < m);}
  public:
    int MinimumEffort(vector<vector<int>>& heights){
        int n = heights.size(), m = heights[0].size(), res = INT_MAX;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    vector<vector<int>> distance(n, vector<int> (m, 1e9));
    distance[0][0] = 0;
    while(pq.size()){
        int currEffort = pq.top().first;
        int x = pq.top().second.first, y = pq.top().second.second;
        pq.pop();
        if(x == n - 1 and y == m - 1){
            res = 
        }
        for(int i = 0; i < 4; i++){
            int X = x + dx[i];
            int Y = y + dy[i];
            if(isValidDirection(X, Y, n, m)){
                int newEffort = max(currEffort, (int)abs(heights[x][y]-heights[X][Y]));
                if(distance[X][Y] > newEffort){
                    distance[X][Y] = newEffort;
                    pq.push({newEffort, {X, Y}});
                }
            }
        }
    }
    return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends