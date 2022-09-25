// class Solution {
// private:
//     static bool cmp(pair<string,int> p1, pair<string,int> p2){
//         return p1.second>p2.second;             // Sorting according to integer
//     }
// public:
//     vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
//         vector<pair<string,int>> v1;
//         vector<string> ans;
//         for(int i=0;i<names.size();i++)  v1.emplace_back(names[i],heights[i]);      // Store in form of pairs
//         sort(v1.begin(),v1.end(),cmp);                              // sort using comparator function
//         for(auto &it: v1)    ans.push_back(it.first);                  // Result
//         return ans;
//     }
// };


class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m1;
        vector<string> ans; 
        for(int i=0; i<names.size(); i++)                               m1[heights[i]] = names[i];      // map will sort according to heights
        for(auto it=m1.rbegin(); it!=m1.rend(); it++)                   ans.push_back(it->second);      // Reverse Traversal
        return ans;
    }
};
