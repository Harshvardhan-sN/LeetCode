// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  private:
    int fun(string s){
        int c1 = count(s.begin(),s.end(),')'),c2=0;
        int i = 0;
        for(i;i<s.length();i++){
            if(c1==c2)  return i;
            if(s[i]=='(')   c2++;
            else            c1--;
        }
        return i;
    }
  public:
    int findIndex(string s) {
        return fun(s);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.findIndex(s)<<endl;
	}
}  // } Driver Code Ends