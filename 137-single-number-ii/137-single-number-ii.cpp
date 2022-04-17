class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m1;
        for(auto &it:nums){
            m1[it]++;
        }
        int ans = 0;
        for(auto &it:m1){
            if(it.second==1){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};