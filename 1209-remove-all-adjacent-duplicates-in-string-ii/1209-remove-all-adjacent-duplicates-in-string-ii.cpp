class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.length();
        vector<int> v1(n,1);
        stack<int> st;
        string answer = "";
        st.push(0);
        for(int i=1;i<n;i++){
            if(!st.empty()){
                if(s[st.top()]==s[i]){
                    v1[i] = v1[st.top()]+1;
                }
            }
            st.push(i);
            if(v1[st.top()]==k){
                for(int i=0;i<k;i++){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            answer += s[st.top()];
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};