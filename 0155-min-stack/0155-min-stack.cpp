class MinStack {
public:
    stack<int> st;
    stack<int> minSt;

    MinStack() {
    }
    
    void push(int val) {
        st.push(val); // push 
        
        if(minSt.empty() || val <= minSt.top()) {
            minSt.push(val); // push only if the smallest number is coming
        }
    }
    
    void pop() {
        if(st.top() == minSt.top()) {
            minSt.pop(); //pop when both have same ele
        }
        st.pop(); // pop 
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};