class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0)    return 0;
        unordered_map<char,int> m1;
        int maxi = 0;
        for(int i=0, j=0; i<n; i++){
            if(m1.count(s[i])>0){
                j = max(m1[s[i]]+1,j);
            }
            m1[s[i]] = i;
            maxi = max(maxi,i-j+1);
        }
        return maxi;
    }
};