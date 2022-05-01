class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ans1 = 0;
        for(int i=0;i<=s.size();i++){
            string h = s.substr(0,i);
            int x = count(words.begin(),words.end(),h);
            if(x>0)    ans1+=x;
        }
        return ans1;
    }
};