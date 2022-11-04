class Solution {
public:
    string reverseVowels(string s) {
        string vowel = "", check = "aeiouAEIOU";
        for(auto &it: s){
            if(count(begin(check), end(check), it)>0)     vowel += it;
        }
        reverse(begin(vowel), end(vowel));
        for(int i=0,j=0; i<s.size(); i++){
            if(count(begin(check), end(check), s[i])>0)     
                s[i] = vowel[j++];
        }
        return s;
    }
};