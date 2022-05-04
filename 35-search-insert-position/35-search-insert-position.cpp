class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it=find(begin(nums),end(nums),target);
        int ans=it-nums.begin();
        auto low=lower_bound(begin(nums),end(nums),target);
        int ind=low-nums.begin();
        
        if(it!=nums.end()){
            return ans;
        }
        return ind;
        
    }
};