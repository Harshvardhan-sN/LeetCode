class Solution {
private:
    int fun(vector<int> &v1,int start,int end,int x){
        int ans = 0;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(v1[mid]>=x){
                end = mid-1;
            }
            else       start = mid+1;
        }
        return start;
    }
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        // return fun(nums,l,r,target);
        return lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    }
};