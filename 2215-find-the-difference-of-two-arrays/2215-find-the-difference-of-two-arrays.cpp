class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1,s2;
        vector<int> a,b;
        
        for(auto &i:nums1){
            auto it = find(nums2.begin(),nums2.end(),i);
            if(it==nums2.end())     s1.insert(i);
        }
        
        for(auto &i:nums2){
            auto it = find(nums1.begin(),nums1.end(),i);
            if(it==nums1.end())     s2.insert(i);
        }
        
        for(auto &i:s1)     a.push_back(i);
        for(auto &i:s2)     b.push_back(i);
        
        return {a,b};
    }
};