//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord,
            vector<string>& wordList) {
        set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q1;
        q1.emplace(startWord, 1);
        while(!q1.empty()){
            string from = q1.front().first;
            int path = q1.front().second;
            q1.pop();
            if(from == targetWord)  return path;
            for(int i=0; i<from.size(); i++){
                string temp = from;
                for(char ch='a'; ch<='z'; ch++){
                    temp[i] = ch;
                    if(words.find(temp)!=words.end()){
                        q1.emplace(temp, path+1);
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends