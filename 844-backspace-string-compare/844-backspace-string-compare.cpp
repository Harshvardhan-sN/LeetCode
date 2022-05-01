class Solution {
public:
    string fun(string &s){
        stack<char> s1;
        for(auto &it:s){
            if(it!='#')     s1.push(it);
            else if(!s1.empty())     s1.pop();
        }
        string h = "";
        while(!s1.empty()){
            h += s1.top();
            s1.pop();
        }
        return h;
    }
    bool backspaceCompare(string s, string t) {
        if(fun(s)==fun(t))  return true;
        return false;
    }
};