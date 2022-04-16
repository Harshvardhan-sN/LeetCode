class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            bool x = 0,y = 0,z = 0;
        
            if(a & (1<<i))  x = 1;
            if(b & (1<<i))  y = 1;
            if(c & (1<<i))  z = 1;
            
            if(!z){
                if(x && y){
                    ans += 2;
                }
                else if(x || y){
                    ans++;
                }
            }
            else{
                if(!x && !y)    ans++;
            }
        }
        return ans;
    }
};