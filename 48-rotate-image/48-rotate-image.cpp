class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> v1(n,vector<int>(n,0));
        int row = 0,col = 0;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                v1[row++][col] = matrix[i][j];
            }
            row %= n;
            col++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = v1[i][j];
            }
        }
    }
};