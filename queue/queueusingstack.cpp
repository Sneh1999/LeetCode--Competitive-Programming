/*

232. Implement Queue using Stacks
Easy

930

135

Add to List

Share
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
Notes:

You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).



*/

class MyQueue {
    stack<int> s_push;
    stack<int> s_pop;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s_push.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(s_pop.size()==0){
            while(s_push.size() != 0){
                int e = s_push.top();
                s_push.pop();
                s_pop.push(e);
            }
            int a =  s_pop.top();
            s_pop.pop();
            return a;
        }
        else{
           
           int a =  s_pop.top();
            s_pop.pop();
            return a;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(s_pop.size()==0){
            while(s_push.size() != 0){
             int e = s_push.top();
                s_push.pop();
                s_pop.push(e);
          } 
            int a =  s_pop.top();
         
            return a;
        }
        else{ 
            int e = s_pop.top();
       
            return e;
        }
       
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(s_push.size()== 0 && s_pop.size()== 0){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

