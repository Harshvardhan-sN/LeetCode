class Solution {
public:
    int minMoves2(vector<int>& v1) {
        int n = v1.size();
        sort(begin(v1),end(v1));
        if( n<=2 )  return v1[n-1]-v1[0];
        int l1 = v1[n/2];
        int ans1 = 0;
        for(auto &it:v1){
            ans1 += abs(it-l1);
        }
        return ans1;
    }
};