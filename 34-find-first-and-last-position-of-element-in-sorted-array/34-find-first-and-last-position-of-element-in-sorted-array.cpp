class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto l1 = lower_bound(nums.begin(),nums.end(),target);
        auto l2 = upper_bound(nums.begin(),nums.end(),target);
        if(!binary_search(nums.begin(),nums.end(),target))    return {-1,-1};
        int ind1 = l1-nums.begin();
        int ind2 = l2-nums.begin()-1;
        return {ind1,ind2};
    }
};