class Solution {
public:
    bool isPalindrome(int x) {
        string h = to_string(x);
        string g = h;
        reverse(begin(h), end(h));
        return h==g;
    }
};