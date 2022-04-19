// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int value(char roman) {
	switch (roman) {
	case 'I':	return 1;
	case 'V':	return 5;
	case 'X':	return 10;
	case 'L': 	return 50;
	case 'C':	return 100;
	case 'D':	return 500;
	case 'M':	return 1000;
	}
	return 0;
}

    int romanToDecimal(string &s) {

	int ans = 0, p = 0;
	int n = s.size();
    
	for (int i = n - 1; i >= 0; i--) {
		int val = value(s[i]);
		if (val >= p) {
			ans += val;
		}
		else {
			ans -= val;
		}
		p = val;
	}
	return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}  // } Driver Code Ends