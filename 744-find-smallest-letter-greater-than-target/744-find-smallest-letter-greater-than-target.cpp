class Solution {
public:
    char nextGreatestLetter(vector<char>& v1, char target) {
        if(upper_bound(v1.begin(),v1.end(),target)==v1.end())   return v1[0];
        return v1[upper_bound(v1.begin(),v1.end(),target)-v1.begin()];        
    }
};