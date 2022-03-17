// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long a[], long long n) {
        // Your code here
        long long ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;
        priority_queue<long long,vector<long long>,greater<>> pq;
	for(int i=0;i<n;i++){
	    pq.push(a[i]);
	}

	while(pq.size()>1){
		long long l1 = pq.top();
		pq.pop();
		long long l2 = pq.top();
		pq.pop();
		long long sum = l1+l2;
		ans1 += sum;
		pq.emplace(sum);
	}
	return ans1;
    }
};


// { Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends