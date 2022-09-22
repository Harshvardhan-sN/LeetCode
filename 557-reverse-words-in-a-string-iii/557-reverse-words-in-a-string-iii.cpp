class Solution {
public:
    string reverseWords(string s) {
        int j = INT_MAX;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
            else{
                j = min(i,j);
            }
        }
        reverse(s.begin()+j,s.end());
        return s;
    }
};