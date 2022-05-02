class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> v1(nums.size(),0);
        int even = 0;
        int odd = nums.size()-1;
        for(auto &it:nums){
            if(it&1)    v1[odd--] = it;
            else    v1[even++] = it;
        }
        return v1;
    }
};