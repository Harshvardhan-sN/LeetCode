// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

bool visited[7][7];
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
void fun(int i,int j,vector<vector<int>> &v1,int n,string help,vector<string> &ans){
    if(i==n-1 and j==n-1){
        ans.push_back(help);
        return;
    }
    string direction = "DLRU";
    for(int ind=0;ind<4;ind++){
        int X = i+dx[ind];
        int Y = j+dy[ind];
        if(X>=0 && Y>=0 && X<n && Y<n and !visited[X][Y] and v1[X][Y]){
            visited[i][j] = 1;
            fun(X,Y,v1,n,help+direction[ind],ans);
            visited[i][j] = 0;
        }
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