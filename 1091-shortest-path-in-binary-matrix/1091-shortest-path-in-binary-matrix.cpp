// For current Point and Count
struct Node{
    int x,y,count;  
};
class Solution {
    // All 8 possible directions
    int dx[8] = {-1,-1,-1,1,1,1,0,0};
    int dy[8] = {0,-1,1,0,1,-1,1,-1};

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // if start or end is blocked
        if(grid[0][0] || grid.back().back())    return -1;
        
        int row = grid.size();
        int column = grid[0].size();
        
        // Queue for BFS
        queue<Node> q;
        q.push({0,0,1});
        // for marking visited , We can use same grid and mark the point as -1;
        grid[0][0] = -1;
        
        while(!q.empty()){
            Node temp = q.front();
            q.pop();
            
            // Checking for last point ,as it will give count because we are doing bfs
            if(temp.x==row-1 and temp.y==column-1)      return temp.count;
            
            // Checking in all 8 directtions
            for(int i=0;i<8;i++){
                // new coordinates
                int x = temp.x + dx[i];
                int y = temp.y + dy[i];
                
                // cheching out of bound and not blocked
                if(x>=0 and y>=0 and x<row and y<column and !grid[x][y]){
                    // can move
                    q.push({x,y,temp.count+1});
                    // visited
                    grid[x][y] = -1;
                }
            }
        }
        return -1;
    }
};