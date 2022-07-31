class Solution {
public:
    int solve(vector<int> &nums,int n,int &res){
        int idx = upper_bound(nums.begin(),nums.end(),0)-nums.begin();
        if(*max_element(nums.begin(),nums.end())==0){
            return 0;
        }    
        int val = nums[idx];
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                continue;
            }else{
                nums[i] = nums[i]-val;
            }
        }                       
        return 1 + solve(nums,n,res);            
    }
    int minimumOperations(vector<int>& nums) {  
        int res = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return solve(nums,n,res);
    }
};