//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,int newColor) {
        int n = image.size(), m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, 0));
        dfs(sr, sc, n, m, newColor, image[sr][sc], image, vis);
        image[sr][sc] = newColor;
        return image;
    }
private:
    void dfs(int i, int j, int n, int m, int color, int ini, 
    vector<vector<int>> &img, vector<vector<bool>> &vis){
        vis[i][j] = 1;
        for(int D = 0; D < 4; D++){
            int nRow = i + dx[D];
            int nCol = j + dy[D];
            if(nRow>=0 and nCol>=0 &&
            nRow<n and nCol<m &&
            img[nRow][nCol]==ini and !vis[nRow][nCol] ){
                dfs(nRow, nCol, n, m, color, ini, img, vis);
                img[nRow][nCol] = color;
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends