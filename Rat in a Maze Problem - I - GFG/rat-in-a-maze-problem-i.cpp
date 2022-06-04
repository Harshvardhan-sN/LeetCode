// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

bool visited[7][7];
void fun(int i,int j,vector<vector<int>> &v1,int n,string help,vector<string> &ans){
    if(i==n-1 and j==n-1){
        ans.push_back(help);
        return;
    }
    // Downward
    if(i+1<n and !visited[i+1][j] and v1[i+1][j]){
        visited[i][j] = 1;
        fun(i+1,j,v1,n,help+'D',ans);
        visited[i][j] = 0;
    }
    // Left
    if(j-1>=0 and !visited[i][j-1] and v1[i][j-1]){
        visited[i][j] = 1;
        fun(i,j-1,v1,n,help+'L',ans);
        visited[i][j] = 0;
    }
    // Right
    if(j+1<n and !visited[i][j+1] and v1[i][j+1]){
        visited[i][j] = 1;
        fun(i,j+1,v1,n,help+'R',ans);
        visited[i][j] = 0;
    }
    // Up
    if(i-1>=0 and !visited[i-1][j] and v1[i-1][j]){
        visited[i][j] = 1;
        fun(i-1,j,v1,n,help+'U',ans);
        visited[i][j] = 0;
    }
}
class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==1)    fun(0,0,m,n,"",ans);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends