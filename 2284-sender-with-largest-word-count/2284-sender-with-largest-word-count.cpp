class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int> m1;
        int maxi = 0;
        for(int i=0;i<senders.size();i++){
            int req = 1;
            for(auto &it:messages[i])   if(it==' ') req++;
            m1[senders[i]] += req;
            maxi = max(maxi,m1[senders[i]]);
        }
        set<string> v1;
        for(auto &it:m1){
            if(it.second==maxi){
                v1.insert(it.first);
            }
        }
        return *(--v1.end());
    }
};