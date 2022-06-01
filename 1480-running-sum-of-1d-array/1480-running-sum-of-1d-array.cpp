class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n,0);
        arr[0] = nums[0];
        for(int i=1;i<n;i++){
            arr[i] = arr[i-1]+nums[i];
        }
        return arr;
    }
};