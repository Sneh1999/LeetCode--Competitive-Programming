/**
 * initialize your data structure here.
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

 */
var MinStack = function() {
    this.topp = null;
   this.size = 0;
 };
 
 var Node = function(data){
   this.data = data;
   this.previous = null;
 };
 /** 
  * @param {number} x
  * @return {void}
  */
 MinStack.prototype.push = function(x) {
     var node = new Node(x);
     node.previous = this.topp;
     this.topp = node;
     this.size += 1;
     
 };
 
 /**
  * @return {void}
  */
 MinStack.prototype.pop = function() {
   var  temp = this.topp;
   this.topp = this.topp.previous;
   this.size -= 1;
   return temp;
 };
 
 /**
  * @return {number}
  */
 MinStack.prototype.top = function() {
     return this.topp.data
 };
 
 /**
  * @return {number}
  */
 MinStack.prototype.getMin = function() {
     var min = this.topp.data
     var loop = this.topp
     while(loop.previous !== null){
         if(this.topp.previous.data<min){
             min = this.topp.previous.data
             }
         loop = loop.previous
         }
     return min
 };
 
 /** 
  * Your MinStack object will be instantiated and called as such:
  * var obj = new MinStack()
  * obj.push(x)
  * obj.pop()
  * var param_3 = obj.top()
  * var param_4 = obj.getMin()
  */