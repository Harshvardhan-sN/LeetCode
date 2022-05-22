class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int ans = 0;
        multiset<int> v1;
        int n = rocks.size();
        
        for(int i=0;i<n;i++){
            int diff = capacity[i]-rocks[i];
            if(diff==0)     ans++;
            else    v1.insert(diff);
        }
        
        for(auto &it:v1){
            if(it<=k and k>0){
                k -= it;
                ans++;
            }
        }
        
        return ans;
    }
};