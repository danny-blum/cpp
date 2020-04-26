class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) : buf_(k, 0), size_(k), start_(0), len_(0) {
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (len_ == size_) return false;
        
        if (len_ == 0) {
            start_ = 0;
        }
        else {
            if (start_ == 0)
                start_ = size_ -1;
            else
                start_--;
        }
            
        buf_[start_] = value;
        len_++;
        
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (len_ == size_) return false;
        
        int end = (start_ + len_) % size_;
        buf_[end] = value;
        len_++;
        
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (len_ == 0) return false;
        
        start_ = (start_ + 1) % size_;
        len_--;
        
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (len_ == 0) return false;
        
        len_--;
        
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (len_ == 0) return -1;
        
        return buf_[start_];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (len_ == 0) return -1;
        
        int rear = (start_ + len_ - 1) % size_;
        
        return buf_[rear];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return (len_ == 0);
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (len_ == size_);
    }
private:
    int size_;
    int len_;
    int start_;
    std::vector<int> buf_;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
