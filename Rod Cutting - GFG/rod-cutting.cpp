// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int dp[1007];

int solve(int len,vector<int> &v1){
    if(len==0)  return 0;
    int ans = 0;
    if(dp[len]!=-1)     return dp[len];
    for(int length=1;length<=len;length++){
        if(len-length>=0)
            ans = max(ans,solve(len-length,v1)+v1[length-1]);
    }

    return dp[len] = ans;
}

int cutRod(int price[], int n) {
    vector<int> v1(price,price+n);
    memset(dp,-1,sizeof dp);
    return solve(n,v1);
}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends