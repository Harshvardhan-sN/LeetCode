class Solution {
private:
    bool check_Vowel(char ch){
        return (ch=='a' || ch=='A' 
                || ch=='e' || ch=='E'
                || ch=='i' || ch=='I' 
                || ch=='o' || ch=='O' 
                || ch=='u' || ch=='U' );
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i < j){
            bool b1 = check_Vowel(s[i]);
            bool b2 = check_Vowel(s[j]);
            if(b1 and b2){
                swap(s[i++], s[j--]);
            }
            else if(!b1)    i++;
            else if(!b2)    j--;
        }
        return s;
    }
};