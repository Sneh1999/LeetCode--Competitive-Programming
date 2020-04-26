/*622. Design Circular Queue
Medium

473

76

Add to List

Share
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.

*/

class MyCircularQueue {
    int size = 0;
    int size_copy = 0;
    struct LinkedList {
        int val;
        LinkedList *next;
        LinkedList *prev;
    } *head,*tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k;
        head = NULL;
        tail = NULL;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size != size_copy){
            if(size_copy == 0 ){
                size_copy++;
                head = new LinkedList();
                head->val = value;
                head->prev = NULL;
                head->next = new LinkedList();
                tail = head;
            }
            else{
                size_copy++;
                LinkedList* copy = tail;
                tail->next->val = value;
                tail = tail->next;
                tail->prev = copy;
                tail->next = new LinkedList();
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size_copy != 1 && head != NULL){
            LinkedList* copy = head;
            head = head->next;
            head->prev = NULL;
            size_copy--;
            return true;
        }
        else if(size_copy == 1){
            size_copy = 0;
            head = NULL;
            tail = NULL;
            return true;
        }
        else{
            return false;
        }
        
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size_copy != 0){
            return head->val;
        }
        else{
            return -1;
        }
        
    }
    
    /** Get the last item from the queue. */
    int Rear() {
         if(size_copy != 0){
        return tail->val;
         }
        else{
            return -1;
        }
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
       if(size_copy == 0){
        return true;
        }
        else{
            return false;
        }
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
      if(size_copy == size){
        return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
