class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        multiset<int> p1;
        int time = 0;
        
        for(auto &it : courses){
            int duration = it[0] , lastDay = it[1];
            if(duration <= lastDay){
                if( duration+time <= lastDay ){
                    p1.insert(duration);
                    time += duration;
                }
                else{
                    auto it = p1.rbegin();
                    if(*it > duration){
                        time -= *it;
                        p1.erase(--p1.end());
                        time += duration;
                        p1.insert(duration);
                    }
                }
            }
        }
        return p1.size();
    }
};