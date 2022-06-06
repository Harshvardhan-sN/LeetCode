class Solution {
public:
    void setZeroes(vector<vector<int>>& v1) {
        int n = v1.size();
        int m = v1[0].size();
        int arr[n][m];
        memset(arr,-1,sizeof(arr));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i][j]==0){
                    int row = i;
                    int col = j;
                    while(row<n)    arr[row++][col] = 0;
                    row = i;
                    while(row>=0)    arr[row--][col] = 0;
                    row = i;
                    while(col<m)    arr[row][col++] = 0;
                    col = j;
                    while(col>=0)    arr[row][col--] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0)    v1[i][j] = 0;
            }
        }
    }
};