class Solution {
public:
    bool arr[201][201];
    void setZeroes(vector<vector<int>>& v1) {
        int n = v1.size();
        int m = v1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i][j]==0){
                    int row = i;
                    int col = j;
                    while(row<n)    arr[row++][col] = 1;
                    row = i;
                    while(row>=0)    arr[row--][col] = 1;
                    row = i;
                    while(col<m)    arr[row][col++] = 1;
                    col = j;
                    while(col>=0)    arr[row][col--] = 1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==1)    v1[i][j] = 0;
            }
        }
    }
};