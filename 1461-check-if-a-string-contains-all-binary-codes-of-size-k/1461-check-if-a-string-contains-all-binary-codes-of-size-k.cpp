class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if(k>n)     return false;
        unordered_set<string> s1;
        for(int i=0;i<=n-k;i++){
            s1.insert(s.substr(i,k));
        }
        return s1.size()==(1<<k);
    }
};