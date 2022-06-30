class Solution {
public:
    int minMoves2(vector<int>& v1) {
        sort(begin(v1),end(v1));
        int l1 = v1[ v1.size()>>1];
        int ans1 = 0;
        for(auto &it:v1){
            ans1 += abs(it-l1);
        }
        return ans1;
    }
};