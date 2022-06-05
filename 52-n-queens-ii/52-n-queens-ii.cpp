class Solution {
    int count = 0;
private:
    bool check(int row,int col,vector<string> &board,int n){
        int a = row;
        int b = col;
        while(row>=0 and col>=0){
            if(board[row--][col--]=='Q')    return false;
        }
        row = a;
        col = b;
        while(col>=0){
            if(board[row][col--]=='Q')      return false;
        }
        col = b;
        while(row<n and col>=0){
            if(board[row++][col--]=='Q')    return false;
        }
        return true;
    }
public:
    void solve(int col,vector<string>& board,vector<vector<string>> &ans,int n){
        if(col==n){
            count++;
            return; 
        }
        for(int row=0;row<n;row++){
            if(check(row,col,board,n)){
                board[row][col] = 'Q';
                solve(col+1,board,ans,n);
                board[row][col] = '.';
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,board,ans,n);
        return count;         
    }
};