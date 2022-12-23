//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    public:
    struct Val{
        int x, y, t;  
    };
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = INT_MIN, before = 0, after = 0;
        queue<Val> q1;
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                    q1.push({i, j, 0});
                    vis[i][j] = 1;
                }   
                if(grid[i][j]==1)   before++;
            }
        }
        while(!q1.empty()){
            int I = q1.front().x;
            int J = q1.front().y;
            int T = q1.front().t;
            res = max(res, T);
            q1.pop();
            for(int i=0; i<4; i++){
                int ROW = I + dx[i];
                int COL = J + dy[i];
                if(ROW>=0 && COL>=0 &&
                    ROW<n && COL<m && 
                    grid[ROW][COL]==1 && !vis[ROW][COL] ){
                        q1.push({ROW, COL, T+1});
                        vis[ROW][COL] = 1;
                        after++;
                    }
            }
        }
        return after==before ? res : -1;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends