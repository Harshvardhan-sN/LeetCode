//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k){
	    int sum = 0, res = 0;
	    vector<int> vis(k, -2);
	    vis[0] = -1;
	    for(int i=0; i<n; i++){
	        sum += arr[i];
	        int remd = sum % k;
	        if(remd < 0)    remd += k;
	        if(vis[remd]==-2)   vis[remd] = i;
	        else{
	            res = max(res, i - vis[remd]);
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends