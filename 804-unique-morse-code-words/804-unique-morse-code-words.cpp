class Solution {
private:
    map<char,string> m1 = {{'a',".-"} , {'b',"-..."}, {'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"},{'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."}};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> s1;
        for(auto &it: words){
            string ans = "";
            for(char &ch: it){
                ans += m1[ch];
            }
            s1.insert(ans);
        }
        return s1.size();
    }
};