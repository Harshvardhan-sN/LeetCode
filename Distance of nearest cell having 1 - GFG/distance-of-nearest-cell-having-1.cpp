//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    struct S{
        int x, y, z;  
    };
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(), m = grid[0].size();
	    vector<vector<bool>> vis(n, vector<bool>(m , 0));
	    vector<vector<int>> res(n, vector<int>(m , 0));
	    queue<S> q1;
        for (int i = 0; i < n; i++) {
		    for (int j = 0; j < m; j++) {
			    if (grid[i][j] == 1) {
                    q1.push({i, j, 0});
                    vis[i][j] = 1;
                    res[i][j] = 0;
			    }
		    }   
	    }
    
	    while (!q1.empty()) {
		    int R = q1.front().x;
		    int C = q1.front().y;
		    int V = q1.front().z + 1;
    		q1.pop();
	    	for (int i = 0; i < 4; i++) {
		    	int nRow = R + dx[i];
			    int mCol = C + dy[i];
    			if (nRow >= 0 && mCol >= 0 && nRow < n && mCol < m &&
	    		        grid[nRow][mCol] == 0 ) {
		    		if (!vis[nRow][mCol]) {
			    		q1.push({nRow, mCol, V});
				    	vis[nRow][mCol] = 1;
					    res[nRow][mCol] = V;
    				}
	    			else {
		    			res[nRow][mCol] = min(res[nRow][mCol], V);
			    	}
    			}
	    	}
	    }
	    return res;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends