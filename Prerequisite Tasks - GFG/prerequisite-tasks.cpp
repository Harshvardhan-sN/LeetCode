//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> inDegree(N, 0);
	    vector<int> adj[N];
	    for(auto &it: prerequisites){
	        adj[it.first].push_back(it.second);
	    }
	    for(int i=0; i<N; i++){
	        for(auto &it: adj[i]){
	            inDegree[it]++;
	        }
	    }
	    queue<int> q1;
	    for(int it=0; it<N; it++){
	        if(inDegree[it]==0)    q1.push(it);
	    }
	    vector<int> res;
	    while(!q1.empty()){
	        int child = q1.front();
	        q1.pop();
	        res.push_back(child);
	        for(auto &it: adj[child]){
	            inDegree[it]--;
	            if(inDegree[it]==0)     q1.push(it);
	        }
	    }
	    return (res.size()==N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends