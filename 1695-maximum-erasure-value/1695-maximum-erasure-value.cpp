class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, maxi = 0;
        unordered_set<int> m1;
        
        for(int i=0, j=0; j<nums.size(); j++){
            while(m1.count(nums[j])){
                m1.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            m1.insert(nums[j]);
            sum += nums[j];
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};