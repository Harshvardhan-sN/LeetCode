// class Solution {
// public:
//     int maximumWealth(vector<vector<int>>& accounts) {
//         int maxi = 0;
//         for(auto &it:accounts){        
//             int sum = accumulate(it.begin(),it.end(),0);
//             maxi = max(maxi,sum);
            
//         }
//         return maxi;
//     }
// };
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(int i =0;i<accounts.size();i++){
            int temp = 0;
            for(int j = 0;j<accounts[i].size();j++){
                temp+=accounts[i][j];
            }
            res = max(res,temp);
        }
        return res;
    }
};