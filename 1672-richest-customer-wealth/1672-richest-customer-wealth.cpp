class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxi = 0;
        for(auto &it:accounts){        
            int sum = accumulate(it.begin(),it.end(),0);
            maxi = max(maxi,sum);
            
        }
        return maxi;
    }
};