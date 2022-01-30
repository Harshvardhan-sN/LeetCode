class Solution {
public:
    int findFinalValue(vector<int>& v1, int x) {
        int ans = x;
        while( find(v1.begin(),v1.end(),ans)!=v1.end() ){
            ans = ans * 2;
        }
        return ans;
    }
};