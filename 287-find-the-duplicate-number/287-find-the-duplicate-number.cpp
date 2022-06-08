class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int> arr(n,0);
        for(auto &it:nums){
            arr[it]++;
            if(arr[it]==2){
                ans = it;
                break;
            }
        }
        return ans;
    }
};