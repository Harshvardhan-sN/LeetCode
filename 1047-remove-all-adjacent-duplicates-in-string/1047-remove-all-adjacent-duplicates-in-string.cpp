class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.size();
        st.push(s[0]);
        for(int i=1;i<n;i++){
            if(!st.empty() and st.top()==s[i])  st.pop();
            else    st.push(s[i]);
        }
        string ans = "";
        while(!st.empty())  ans += st.top(), st.pop();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};