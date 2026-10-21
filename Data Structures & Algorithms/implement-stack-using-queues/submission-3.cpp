class MyStack {
public:

    queue<int> q1;
    queue<int> q2;

    MyStack() {
        // invariant: q1 holds the data in "stack order"
    }
    
    void push(int x) {
        
        // two q's lets us emulate a push to front
        q2.push(x);
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    
    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }
    
    int top() {
        int res = q1.front();
        return res;
    }
    
    bool empty() {
        return q1.empty();
        
    }
};