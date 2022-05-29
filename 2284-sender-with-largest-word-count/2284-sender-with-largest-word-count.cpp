class Solution {
public:
string largestWordCount(vector<string> & m, vector<string> & sd) {
        int msz= m.size();
        map<string, int> mp;
        set<string> st;
        set<string> st2;
        for(int i=0; i<msz; i++){
            int sz= m[i].length();
            int ct=1;
            for(int j=0; j<sz; j++)
            {
                if(m[i][j]==' ')
                    ct++;
            }    
            mp[sd[i]] += ct;
        }    
        int mx=0;
        for(auto it= mp.begin(); it!=mp.end(); it++){
            if(it->second > mx)
                mx = it->second;
        }
        for(auto it= mp.begin(); it!=mp.end(); it++){
            if(it->second==mx){
                st.insert(it->first);
            }    
        }
        return *(--st.end());
    }
};