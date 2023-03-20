//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    long long int mod = 1e9 + 7;
  public:
    long long int fun(long long int n, vector<long long int> &dp){
        if(dp[n] != -1)  
            return dp[n];
        long long int last = fun(n - 1, dp) % mod;
        long long int sLast = fun(n - 2, dp) % mod;
        return dp[n] = (last + sLast) % mod;
    }
    long long int nthFibonacci(long long int n){
        vector<long long int> dp(n + 3, -1);
        dp[0] = 0, dp[1] = 1, dp[2] = 1;
        return fun(n, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends