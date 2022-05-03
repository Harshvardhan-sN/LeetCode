class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v1,v2;
        if(is_sorted(nums.begin(),nums.end())) return 0;
        for(auto &it:nums)  v1.push_back(it);
        sort(v1.begin(),v1.end());
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(v1[i]!=nums[i])  v2.push_back(i);
        }
        return v2[v2.size()-1]-v2[0]+1;
    }
};