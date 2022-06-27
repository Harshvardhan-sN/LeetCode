class Solution {
public:
    int minPartitions(string n) {
        set<char> s1;
        for(char &ch:n)  s1.insert(ch);
        return *s1.rbegin() - '0';
    }
};