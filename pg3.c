

struct QNode{
    int data;
};

typedef struct {
    struct QNode *arr[101];
    int front;
    int rear;    
} MyStack;


MyStack* myStackCreate() {
    MyStack *q =(MyStack *)malloc(sizeof(MyStack));
    q->front=-1;
    q->rear=-1;
    return q;
}

void enqueue(MyStack* q, struct QNode* item) {
    q->arr[++q->rear] = item;
    if (q->front == -1) {
        q->front = 0;
    }
}

struct QNode* dequeue(MyStack* q) {
    
    struct QNode* item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

void myStackPush(MyStack* q, int x) {
    
  struct QNode* node = (struct QNode*) malloc(sizeof(struct QNode));
    node->data = x;
    enqueue(q, node);
    int size = q->rear - q->front + 1;
    while (size > 1) {
        struct QNode* front = dequeue(q);
        enqueue(q, front);
        size--;
    }
}

int myStackPop(MyStack* q) {

    struct QNode* front = dequeue(q);
    int item = front->data;
    free(front);
    return item;
}

int myStackTop(MyStack* q) {

     struct QNode* front = q->arr[q->front];
    return front->data;
}

bool myStackEmpty(MyStack* q) {
  return q->front == -1;
}

void myStackFree(MyStack* q) {
     while (!myStackEmpty(q)) {
        struct QNode* front = dequeue(q);
        free(front);
    }
    free(q);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/