class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        set<int> s1;
        for(int i=0;i<n;i++){
            s1.insert(nums[i]);
            string h = to_string(nums[i]);
            reverse(h.begin(), h.end());
            s1.insert(stoi(h));
        }
        return  s1.size();
    }
};