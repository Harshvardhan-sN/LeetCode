class Solution {
public:
    void fun(int i, string &s, int k){
        if(i==k)    return;
        int n = s.size();
        int count = 1;
        char ch = s[0];
        string help = "";
        for(int i=1; i<n; i++){
            if(s[i]==ch)    count++;
            else{
                help += to_string(count) + ch;
                ch = s[i];
                count = 1;
            }
        }
        if(n==1){
            s = "11";
        }
        else if(count>=1){
            s = help + to_string(count) + ch;
        }
        else{
            s = help;
        }
        fun(i+1, s, k);
    }
    string countAndSay(int n) {
        string ans = "1";
        fun(1, ans, n);
        return ans;
    }
};