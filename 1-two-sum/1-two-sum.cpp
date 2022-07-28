class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++){
            auto it = find(begin(nums)+i+1,end(nums),target-nums[i]);
            if(it != nums.end())    return {i,int(it-nums.begin())};
        }
        return {};
    }
};