class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1,v2,ans;
        
        for(auto &it:nums){
            if(it>=0){
                v1.emplace_back(it);
            }
            else{
                v2.emplace_back(it);
            }
        }
        
        for(int i=0;i<nums.size()/2;i++){
            ans.emplace_back(v1[i]);
            ans.emplace_back(v2[i]);
        }
        return ans;
    }
};