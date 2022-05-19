class Solution {
    int dX[4] = {0,0,1,-1};
    int dY[4] = {1,-1,0,0};
    int dp[207][207];
private:
    int find(vector<vector<int>> &m1,int x,int y){
        if(dp[x][y])    return dp[x][y];
        int ans = 1;
        for(int i=0;i<4;i++){
            int dx = x + dX[i];
            int dy = y + dY[i];
            if(dx>=0 and dy>=0 and dx<m1.size() and dy<m1[0].size()){
                if(m1[dx][dy]>m1[x][y]){
                    ans = max(ans,1+find(m1,dx,dy));
                }
            }
        }
        return dp[x][y] = ans;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                ans = max(ans,find(matrix,i,j));
            }
        }
        return ans;
    }
};