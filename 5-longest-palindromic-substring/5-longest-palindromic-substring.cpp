class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 0;
        int L = 0, R = 0;
        int n = s.length();
        
        // Odd
        for(int mid = 0; mid<n; mid++){
            for(int x = 0; mid-x>=0 and mid+x<n; x++){
                if(s[mid-x]!=s[mid+x])  break;
                int len = (x<<1) + 1;
                if(len > maxLen){
                    maxLen = len;
                    L = mid - x;
                    R = len;
                }
            }
        }
        // Even
        for(int mid = 0; mid<n-1; mid++){
            for(int x = 1; mid-x+1>=0 and mid+x<n; x++){
                if(s[mid-x+1]!=s[mid+x])    break;
                int len = (x<<1);
                if(len > maxLen){
                    maxLen = len;
                    L = mid - x + 1;
                    R = len;
                }
            }
        }
        return s.substr(L,R);
    }
};