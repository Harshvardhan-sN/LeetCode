class Solution {
public:
    int rob(vector<int>& v1) {
        int n = v1.size();
        int prev = v1[0];
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int take = v1[i];
            if(i>1) take+=prev2;
            int notTake = prev;
            int current = max(take,notTake);
            prev2 = prev;
            prev = current;
        }
        return prev;
    }
};