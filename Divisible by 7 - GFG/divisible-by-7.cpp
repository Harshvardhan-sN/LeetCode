// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int isdivisible7(string num){
        int v1[] = {1,3,2,-1,-3,-2};
        int sum = 0, i = num.size()-1, j = 0;
        while(i>=0){
            sum += (num[i--]-'0')*(v1[(j++)%6]);
        }
        return sum%7==0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}  // } Driver Code Ends