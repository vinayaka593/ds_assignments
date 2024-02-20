//Design Circular Queue

typedef struct {
    int head;
    int tail;
    int max;
    int* buffer;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue * rb = malloc(sizeof(MyCircularQueue));
    rb->head = 0;
    rb->tail = 0;
    rb->max = k+1;
    rb->buffer = (int*) malloc((k+1) * sizeof(int));

    return rb;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->head + 1) % obj->max == obj->tail;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    obj->buffer[obj->head] = value;
    obj->head = (obj->head + 1) % obj->max;
    return true;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->tail == obj->head);
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(myCircularQueueIsEmpty(obj))
        return false;

    obj->tail = (obj->tail + 1) % obj->max;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->buffer[obj->tail];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    return myCircularQueueIsEmpty(obj) ? -1 : obj->buffer[obj->head == 0 ? obj->max-1 : obj->head-1];
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->buffer);
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
