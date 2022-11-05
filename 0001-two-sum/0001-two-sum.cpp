class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            auto it = find(nums.begin() + i + 1, nums.end(), target-nums[i]);
            if(it != end(nums)){
                int ind = it - nums.begin();
                return {i, ind};
            }
        }
        return {};
    }
};