class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int mini = *min_element(nums.begin(),nums.end());
        int ans = 0;
        for(auto &it:nums){
            if(maxi>it && mini<it){
                ans++;
            }
        }
        return ans;
    }
};