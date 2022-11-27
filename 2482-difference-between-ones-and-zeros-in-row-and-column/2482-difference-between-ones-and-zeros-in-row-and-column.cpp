class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<int> row(n, 0), col(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                row[i] += (g[i][j]==1);
                col[j] += (g[i][j]==1);
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = row[i] + col[j] - (n-row[i]) - (m-col[j]); 
            }
        }
        return ans;
    }
};