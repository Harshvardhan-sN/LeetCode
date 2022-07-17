class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums[0].size();
        for(auto &q:queries){
            vector<pair<string,int>> m1;
            int i = 0;
            for(auto &it:nums){
                m1.emplace_back(it.substr(n-q[1]),i++);
            }
            sort(m1.begin(),m1.end());
            ans.push_back(m1[q[0]-1].second);
        }
        return ans;
    }
};