class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> v1;
        sort(nums.begin(),nums.end());
        v1.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            v1.push_back(nums);
        }
        return v1;
    }
};