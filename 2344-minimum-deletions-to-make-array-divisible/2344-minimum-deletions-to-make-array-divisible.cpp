class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        set<int> s1;
        for(auto &it:nums)      s1.insert(it);
        int ans = 0;
        for(auto &it:s1){
            bool b1 = true;
            for(auto &i:numsDivide){
                if(i%it!=0){
                    b1 = false;
                    ans += count(nums.begin(),nums.end(),it);
                    break;
                }
            }
            if(b1)  break;
        }
        return ans==nums.size()?-1:ans;
    }
};