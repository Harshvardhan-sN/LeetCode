//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        string res;
        stack<string> st;
        for(int i = 0; i < exp.size(); i++){
            if(exp[i]>='a' and exp[i]<='z' || exp[i]>='A' and exp[i]<='Z'){
                string s(1, exp[i]);
                st.push(s);
            }
            else{
                string b = st.top();
                st.pop();
                string a = st.top();
                st.pop();
                st.push('(' + a + exp[i] + b + ')');
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends