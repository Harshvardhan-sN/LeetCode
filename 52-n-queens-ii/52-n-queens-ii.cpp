class Solution {
    int count = 0;
private:
    bool check(int row,int col,vector<vector<bool>> &board,int n){
        int a = row;
        int b = col;
        while(row>=0 and col>=0){
            if(board[row--][col--]==1)    return false;
        }
        row = a;
        col = b;
        while(col>=0){
            if(board[row][col--]==1)      return false;
        }
        col = b;
        while(row<n and col>=0){
            if(board[row++][col--]==1)    return false;
        }
        return true;
    }
public:
    void solve(int col,vector<vector<bool>> &v1 ,int n){
        if(col==n){
            count++;
            return; 
        }
        for(int row=0;row<n;row++){
            if(check(row,col,v1,n)){
                v1[row][col] = 1;
                solve(col+1,v1,n);
                v1[row][col] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<bool>> arr(n,vector<bool>(n,0));
        solve(0,arr,n);
        return count;         
    }
};