class Solution {
    vector<string> ans;
    vector<string> v1 = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void fun(int ind,string &help,string k){
        if(ind==help.length()){
            ans.push_back(k);
            return;
        }
        int curr = help[ind] - '2';
        string val = v1[curr];
        
        for(int i=0;i<val.length();i++){
            k.push_back(val[i]);
            fun(ind+1,help,k);
            k.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")      return {};
        string s = "";
        fun(0,digits,s);
        return ans;
    }
};  