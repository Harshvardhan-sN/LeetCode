// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string v1[], int n)
    {
        int ans1 = INT_MAX;
        for(int i = 0;i<n;i++){
            ans1 = min(ans1,int(v1[i].size()));
        }
        long i = 0;
	    string ans = "", k = "";
	    while (i < ans1) {
		    long j = 0;
		    while (j < n) {
			    ans += v1[j][i];
			    j++;
		    }
		    i++;
		    int l1 = ans.size();
		    if (count(ans.begin(),ans.end(), ans[0]) == j) {
			    k += ans[0];
			    ans = "";
		    }
		    else if(k=="") {
    			k = "-1";
			    break;
		    }
	    }
	    return k;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends