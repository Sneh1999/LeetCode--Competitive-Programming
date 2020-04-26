/*
155. Min Stack
Easy

3035

297

Add to List

Share
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

Methods pop, top and getMin operations will always be called on non-empty stacks.

*/

class MinStack {
    stack<int> s1;
    stack<pair<int,int>> s2;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(s1.size()== 0){
             s1.push(x);
            s2.push(make_pair(x,1));
        }
        else{
            s1.push(x);
            if(x < s2.top().first){
                s2.push(make_pair(x,1));
            }
            else{
                s2.top().second++;
            }
        }
    }
    
    void pop() {
        s1.pop();
        s2.top().second--;
        if(s2.top().second == 0){
            s2.pop();
        }
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
       return s2.top().first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
