class MyStack {
public:
    queue<int> q1,q2;
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int m = q2.front();
        q2.pop();
        return m;
    }
    
    int top() {
        return q2.front();
    }
    bool empty() {
        return q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// class MyStack {
// public:
//     queue<int> q1;
    
//     void push(int x) {
//         q1.push(x);
//         for(int i=1;i<q1.size();i++){
//             q1.push(q1.front());
//             q1.pop();
//         }
//     }
    
//     int pop() {
//         int front = q1.front();
//         q1.pop();
//         return front;
//     }
    
//     int top() {
//         return q1.front();
//     }
//     bool empty() {
//         return q1.empty();
//     }
// };