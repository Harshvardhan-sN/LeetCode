class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> mask(n);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(auto &it:words[i]){
                mask[i] |= 1<<(it-'a');
            }
            for(int j=0;j<i;j++){
                if((mask[i] & mask[j])==0){
                    ans  = max(ans,int(words[i].size())*int(words[j].size()));
                }
            }
        }
        return ans;
    }
};