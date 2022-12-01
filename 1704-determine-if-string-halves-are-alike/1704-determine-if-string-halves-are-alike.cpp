class Solution {
public:
    bool halvesAreAlike(string s) {
        int l1 = 0, l2 = 0;
        string vo = "aeiouAEIOU";
        for(int i=0; i<s.size(); i++){
            if(count(vo.begin(), vo.end(), s[i])){
                if(i<s.size()/2)  l1++;
                else                    l2++;
            }
        }
        return l1==l2;
    }
};