class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> v1(101,0);
        for(auto &it:nums){
            v1[it]++;
        }
        int couple = 0, single = 0;        
        // Traverse trough frequncy
        for(auto &r:v1){
            if(r&1){
                single++;
            }
            couple += r/2;
        }
        return {couple,single};
    }
};