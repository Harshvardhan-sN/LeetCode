class Solution {
public:
    int g1[310][10010];

    int solve(int ind, int amount, vector<int> &v1){
        if(amount==0)   return 1;
        if(ind<0)   return 0;
        if(g1[ind][amount]!=-1)     return g1[ind][amount];

        int ways = 0;
        for(int i=0;i<=amount;i+=v1[ind]){
            ways+=solve(ind -1 ,amount-i,v1);
        }
        return g1[ind][amount] = ways;
    }

    int change(int amount, vector<int> &coins){
        memset(g1,-1,sizeof(g1));
        return solve(coins.size()-1,amount,coins);
    }
};