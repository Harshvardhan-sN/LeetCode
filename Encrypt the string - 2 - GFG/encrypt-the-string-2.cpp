// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    private:
    string fun(int count){
        string hx = "";
	    while(count!=0){
	        int rem = count%16;
            if(rem<10)  hx += ('0'+rem);
            else        hx += ('a' + (rem-10));
            count /= 16;
	        }
	    return hx;
    }
  public:
    string encryptString(string s) {
        int n = s.length();
        int count = 1;
	    char cur = s[0];
	    string ans = "";
	    for(int i=1;i<n;i++){
	        if(s[i]==s[i-1])    count++;
	        else{
	            ans += cur;
	            ans.append(fun(count));
	            cur = s[i];
	            count = 1;
	        }
	    }
	    ans += cur;
	    ans.append(fun(count));
	    reverse(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.encryptString(S)<<endl;
    }
    return 0;
}  // } Driver Code Ends