// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
    bool areKAnagrams(string s1, string s2, int k) {
        unordered_map<char, int> m1;
    int n = s1.size();
    int m = s2.size();
    long c1 = 0;
    if (n != m)    return false;

    for (auto &it : s1)    m1[it]++;
    for (auto &it : s2) {
        if (!m1[it]){
            if(k==0)    return false;
            k--;
        }
        else    m1[it]--;
    }
    
    return true;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str1,str2;
		cin>>str1>>str2;
		int k;
		cin>>k;
		Solution ob;
		if(ob.areKAnagrams(str1, str2, k) == true)
			cout<<"1\n";
		else
			cout<<"0\n";
	}
}  // } Driver Code Ends