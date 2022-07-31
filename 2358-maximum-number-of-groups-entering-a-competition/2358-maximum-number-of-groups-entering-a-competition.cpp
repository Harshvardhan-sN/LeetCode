class Solution {
public:
    int maximumGroups(vector<int>& g) {        
        int n = g.size(), m = 0, i = 1, ans = 0;        
        while(m < n){
            m += i++;
            ans++;
        }
        return m > n ? --ans : ans;
    }
};