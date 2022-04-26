// { Driver Code Starts
// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        if(s1.length()!=s2.length())    return false;
        int N = s1.length();
        int v1[26] = {0};
        int v2[26] = {0};
        
        for(int i = 0;i<N;i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
        }
        
        for(int i = 0;i<N;i++){
            if(v1[s1[i]-'a']!=v2[s2[i]-'a'])    return false;
        }
        return true;
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends