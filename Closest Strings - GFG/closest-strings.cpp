// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
#define all(x) x.begin(),x.end()
class Solution{
public:	
	
	int shortestDistance(vector<string> &s, string word1, string word2){
	    vector<int> v1,v2;
	    int i = 0;
	    long ans1 = INT_MAX;
	    for(auto &it:s){
	        if(it==word1)       v1.push_back(i);
	        if(it==word2)       v2.push_back(i);
	        i++;
	    }
	    int n = v1.size();
	    int m = v2.size();
	    for(int i = 0;i<n;i++){
	        for(int j = 0;j<m;j++){
	            ans1 = min(ans1,long(abs(v1[i]-v2[j])));
	        }
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