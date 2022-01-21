class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int x) {
        int n = f.size();
        if(x==0)    return true;
        for(int i=0;i<n;i++){
            if( f[i]==0 
               && (i==0 || f[i-1]==0) 
               && (i==n-1 || f[i+1]==0)){
                x--;
                f[i]=1;
            }
            if(x==0)    return true;
        }
        return false;
    }
};