class Solution {
    unordered_map<char,char> m1 = { {'(',')'}, {'{','}'}, {'[',']'} };
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto &it:s){
            if(m1.count(it))    st.push(it);
            else{
                if(!st.empty() and m1[st.top()]==it)    st.pop();
                else                return false;
            }
        }
        if(!st.empty())     return false;
        return true;
    }
};