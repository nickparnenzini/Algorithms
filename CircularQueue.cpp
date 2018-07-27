/* Coding challenge #622 from LeetCode */

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        arr = vector<int>(k,-1);
        front = rear = -1; 
        size = k;
        count = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {  //std::cout << "enQueue" << std::endl;
        if (count == size) {
            return false;
        }
        rear = (rear+1)%size;
        arr[rear] = value;
        count++;
        if (count == 1) {
            front++;
        }                     
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {  //  std::cout << "deQueue" << std::endl;
        if (count == 0) {    // queue is empty
            return false;
        }
        arr[front] = -1;
        if (count == 1) {
            front = rear = -1;
        }
        else {
            front = (front+1)%size;    
        }                
        count--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {   // std::cout << "Front" << std::endl;
        if (front > -1) {
            return arr[front];
        }
        return -1;
    }
    
    /** Get the last item from the queue. */
    int Rear() {  // std::cout << "Rear" << std::endl;
        if (rear > -1) {
            return arr[rear];
        }
        return -1; 
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {   ///std::cout << "isEmpty" << std::endl;
       return count == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {    //std::cout << "front: " << front << "; rear: " << rear << std::endl;
        return count == size;
    }
    
private:
    vector<int> arr;
    int front;
    int rear;
    int size;
    int count;
};
