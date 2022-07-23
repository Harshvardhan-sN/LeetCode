class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        map<int,int> m1;
        int mn1 = INT_MIN;
        int S = count(begin(suits), end(suits), suits[0]);
        int n = ranks.size();
        for(int i=0;i<n;i++){
            m1[ranks[i]]++;
            mn1 = max(mn1,m1[ranks[i]]);
        }
        if(S==n)     return "Flush";
        if(mn1>=3)      return "Three of a Kind";
        if(mn1==2)      return "Pair";
        return "High Card";
    }
};