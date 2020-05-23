class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int size;
    const int head=0;
    int tail=0;
    int mydeque[1001];
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(tail-head+1>size) return false;
        for(int i=tail;i>head;i--){
            mydeque[i]=mydeque[i-1];
        }
        tail++;
        mydeque[head]=value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(tail-head+1>size) return false;
        mydeque[tail++]=value;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(head==tail) return false;
        for(int i=head;i<tail;i++)
            mydeque[i]=mydeque[i+1];
        tail--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(head==tail) return false;
        tail--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return head==tail ? -1 : mydeque[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return head == tail ? -1 : mydeque[tail-1];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return head == tail;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return tail==size;
    }
};
