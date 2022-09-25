
   class MyCircularQueue {
    vector<int>v;
    int front;
    int rear;
public:
    MyCircularQueue(int k) {
        for(int i=0;i<k;i++)
            v.push_back(-1);
        front=0,rear=0;
    }
    
    bool enQueue(int value) {
        if(v[rear]!=-1)
            return false;
        v[rear]=value;
        rear=(rear+1)%v.size();
        return true;
    }
    
    bool deQueue() {
        if(v[front]==-1)
            return false;
        v[front]=-1;
        front=(front+1)%v.size();
        return true;
    }
    
    int Front() {
        return v[front];
    }
    
    int Rear() {
        int x=(rear-1+v.size())%v.size();
        return v[x];
    }
    
    bool isEmpty() {
        if(rear==front && v[front]==-1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(rear==front && v[front]!=-1)
            return true;
        return false;
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