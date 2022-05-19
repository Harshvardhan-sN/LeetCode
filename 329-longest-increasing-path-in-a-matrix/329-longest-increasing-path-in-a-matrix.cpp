class Solution {
    // Possible directions
    int dX[4] = {0,0,1,-1};
    int dY[4] = {1,-1,0,0};
    // DP array   // Globaly declared array are intialized with ZEROs
    int dp[207][207];
    
private:
    int find(vector<vector<int>> &m1,int x,int y,int row,int col){
        if(dp[x][y])    return dp[x][y];
        int ans = 1;
        for(int i=0;i<4;i++){
            // New_Points
            int dx = x + dX[i];
            int dy = y + dY[i];
            
            // Checking out_of_bound and valid_move   (Next > Current)
            if(dx>=0 and dy>=0 and dx<row and dy<col){
                if(m1[dx][dy]>m1[x][y]){
                    ans = max(ans,1+find(m1,dx,dy,row,col));
                }
            }
        }
        return dp[x][y] = ans;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        int n = matrix.size() , m = matrix[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,find(matrix,i,j,n,m));
            }
        }
        return ans;
    }
};