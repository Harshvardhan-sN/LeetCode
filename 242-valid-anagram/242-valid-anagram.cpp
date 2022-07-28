class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26,0);
        int n = t.size(), m = s.size();
        if(n != m)      return false;
        for(int i = 0; i < n; i++){
            v1[s[i]-'a']++;
            v1[t[i]-'a']--;
        }
        return count(begin(v1),end(v1),0)==26;
    }
};