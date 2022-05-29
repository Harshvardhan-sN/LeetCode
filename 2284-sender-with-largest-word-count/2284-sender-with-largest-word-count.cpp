class Solution {
public:
string largestWordCount(vector<string> & m, vector<string> & sd) {
        int msz= m.size();
int i, j, ct;
map<string, int> mp;
set<string> st;
set<string> st2;


for(i=0; i<msz; i++)
{
    int sz= m[i].length();
    ct=1;
    //cout<<"sz:"<<sz;
    for(j=0; j<sz; j++)
    {
        if(m[i][j]==' ')
           ct++;
    }    
     mp[sd[i]]+=ct;
    
}    

int mx=0;
for(auto it= mp.begin(); it!=mp.end(); it++)
{
    //cout<<"sender: "<<it->first<<endl;
    //cout<<"count: "<<it->second;
    // cout<<endl;
    if(it->second >=mx)
        mx= it->second;
}
for(auto it= mp.begin(); it!=mp.end(); it++)
{
    string send= it->first;
    if(mp[it->first]==mx)
    {
        //cout<<"\nsender: "<<it->first<<endl;
        
        st.insert(it->first);
    }    
}
// if(st2.size()>0)
//     return *st2.rbegin();


return *(st.rbegin());
}
};