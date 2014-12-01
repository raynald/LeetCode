//Good problem
//I tried vector instead of stack, returns MLE
//I tried double linked-list, with a pointer min points to min node, but still MLE
//Learned: pointer can waste a lot of momery, also vector. 
class MinStack {
private:
    stack<int> st;
    stack<int> min_st;
public:
    MinStack(){
        while(!st.empty()) st.pop();
        while(!min_st.empty()) min_st.pop();
    }
    void push(int x) {
        st.push(x);
        if(min_st.empty() || min_st.top()>=x) {
            min_st.push(x);
        }
    }

    void pop() {
        if(st.empty()) return;
        if(st.top()==min_st.top()) {
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        if(st.empty()) return -1;
        return st.top();
    }

    int getMin() {
        if(min_st.empty()) return -1;
        return min_st.top();
    }
};
