class Solution {
public:
    int check(string &s){
        int l = 0;
        int r = s.length() - 1;
        while(l <= r){
            if(s[l++] != s[r--])  return 2;
        }
        return 1;
    }
    int removePalindromeSub(string s) {
        return check(s);
    }
};