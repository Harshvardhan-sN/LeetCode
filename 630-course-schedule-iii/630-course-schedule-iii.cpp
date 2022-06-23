class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        priority_queue<int> p1;
        int time = 0;
        
        for(auto &it : courses){
            int duration = it[0] , lastDay = it[1];
            if(duration <= lastDay){
                if( duration+time <= lastDay ){
                    p1.push(duration);
                    time += duration;
                }
                else{
                    if(p1.top() > duration){
                        time -= p1.top();
                        p1.pop();
                        time += duration;
                        p1.push(duration);
                    }
                }
            }
        }
        return p1.size();
    }
};