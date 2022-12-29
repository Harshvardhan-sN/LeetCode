//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<int> InDegree(N, 0);
	    vector<int> adj[N];
	    // create a adjacency matrix
	    for(auto &it: prerequisites){
	        // it.first ---> it.second
	        //    u     --->    v
	        adj[it.second].push_back(it.first);
	    }
	    // count number of inDegrees for each node
	    for(int i=0; i<N; i++){
	        for(auto &it: adj[i])   InDegree[it]++;
	    }
	    queue<int> q1;
	    // insert node on queue with InDegree 0
	    for(int i=0; i<N; i++){
	        if(InDegree[i]==0)      q1.push(i);
	    }
	    // bfs for toposort
	    vector<int> toposort;
	    while(!q1.empty()){
	        int from = q1.front();
	        toposort.push_back(from);    // linear order of sort
	        q1.pop();
	        for(auto &it: adj[from]){
	            InDegree[it]--;
	            if(InDegree[it]==0)     q1.push(it);
	        }
	    }
	    // if toposort exist then 
	    // there is a schedule to complete the task in orders
	    if(toposort.size()==N)      return 1;
	    return 0;
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