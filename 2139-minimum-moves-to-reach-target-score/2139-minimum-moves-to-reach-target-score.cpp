class Solution {
public:
    int cc = 0;
    int solve(int i,int m){
        if(i==1)    return 0;
        if(m==0){
            cc += i-1;
            return 0;
        }
        if(i%2==0 && m>0){
            cc++;
            return solve(i/2,m-1);
        }
        cc++;
        return solve(i-1,m);
    }
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0){
            return target-1;
        }
        if(target==1)   return 0;
        solve(target,maxDoubles);
        return cc;
    }
};