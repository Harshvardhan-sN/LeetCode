class Solution {
// private:
//     bool check(string &s1,string &s2){
//         map<char,int> m1,m2;
//         for(auto &it:s1)    m1[it]++;
//         for(auto &it:s2)    m2[it]++;
//         return m1==m2;
//     }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // for(int i=0;i<words.size()-1;i++){
        //     if(check(words[i],words[i+1])){
        //         words.erase(words.begin()+1+i--);
        //     }
        // }
        for(int i=0;i<words.size()-1;i++){
            if(multiset<char>(begin(words[i]),end(words[i]))==multiset<char>(begin(words[i+1]),end(words[i+1]))){
                words.erase(words.begin()+1+i--);
            }
        }
        return words;
    }
};