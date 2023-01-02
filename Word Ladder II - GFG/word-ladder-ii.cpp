//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> path;
        queue<vector<string>> q1;
        q1.push({beginWord});
        unordered_set<string> st(wordList.begin(), wordList.end());
        int level = 0;
        vector<string> del;
        del.push_back(beginWord);
        while(!q1.empty()){
            vector<string> sequence = q1.front();
            q1.pop();
            if(sequence.size() > level){
                level++;
                for(auto &it: del)      st.erase(it);
                del.clear();
            }
            string child = sequence.back();
            if(child==endWord) {
                if(path.size()==0 || path[0].size()==sequence.size()){
                    path.push_back(sequence);
                }
            }
            for(int i=0; i<child.size(); i++){
                string tp = child;
                for(char ch='a'; ch<='z'; ch++){
                    tp[i] = ch;
                    if(st.find(tp)!=st.end()){
                        sequence.push_back(tp);
                        q1.push(sequence);
                        sequence.pop_back();
                        del.push_back(tp);
                    }
                }
            }
        }
        return path;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends