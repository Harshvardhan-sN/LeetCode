class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> v1;
        for(auto &it: matrix){
            v1.insert(v1.end(), it.begin(), it.end());
        }
        sort(v1.begin(), v1.end());
        return v1[k-1];
    }
};