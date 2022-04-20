// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#define all(x) x.begin(),x.end()
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2){
	    long start = -1,end = -1;
	    
	    long ans1 = INT_MAX;
	    for(int i=0;i<s.size();i++){
	        if(s[i]==word1)     start = i;
	        if(s[i]==word2)     end = i;
	        if(start!=-1 and end!=-1)   ans1 = min(ans1,abs(start-end));
	    }
	    
	    return  ans1;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;

   		vector<string> s(n);
   		for(int i = 0; i < n; i++)
   			cin >> s[i];

   		string word1, word2;

   		cin >> word1 >> word2;
   		
   		Solution ob;

   		cout << ob.shortestDistance(s, word1, word2) << "\n";
   	}

    return 0;
}  // } Driver Code Ends