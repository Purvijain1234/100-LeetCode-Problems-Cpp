/*
Problem Number: 155
Problem Name: Min Stack

LeetCode Link:
https://leetcode.com/problems/min-stack/

Difficulty: Medium

Topics:
Stack, Design

Approach:
Use two stacks:
- st stores all the elements.
- minst stores the minimum element at each relevant level.

Steps:

1. In push():
   - Push the value into st.
   - If minst is empty or the new value is smaller than
     or equal to the current minimum, push it into minst.

2. In pop():
   - If the top of st is equal to the top of minst, remove
     the top element from minst as well.
   - Then remove the top element from st.

3. In top():
   - Return the top element of st.

4. In getMin():
   - Return the top element of minst, which always represents
     the current minimum value.

This allows retrieving the minimum element in O(1) time.

Time Complexity:
O(1) for push(), pop(), top(), and getMin()

Space Complexity:
O(n)

where:
n = number of elements stored in the stack
*/

class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(minst.empty() || value <= minst.top()){
            minst.push(value);
        }
    }
    
    void pop() {

        if(st.top() == minst.top()){
            minst.pop();
        }

        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
