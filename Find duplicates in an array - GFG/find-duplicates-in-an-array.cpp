// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        sort(arr,arr+n);
        vector<int> v1;
        int count = 1;
        bool h = true;
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                count++;
            }
            if(count>1 and h == true){
                v1.emplace_back(arr[i-1]);
                h = false;
            }
            if(arr[i]!=arr[i-1]){
                count = 1;
                h = true;
            }
        }
        if(v1.size()==0)    return {-1};
        return v1;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends