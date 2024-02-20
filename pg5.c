

#define MAX_CALL 100
typedef struct {
    int *in;
    int *out;
    int lstin;
    int lstout;    
} MyQueue;


MyQueue* myQueueCreate() {
     MyQueue *queue = (MyQueue *)malloc(sizeof(MyQueue));
    if (queue == NULL) {
        return NULL;
     }
    queue->in = (int *)malloc(MAX_CALL * sizeof(int));
    queue->out = (int *)malloc(MAX_CALL * sizeof(int));
    queue->lstin = -1;
    queue->lstout = -1;

    return queue;
    
}

void myQueuePush(MyQueue* obj, int x) {
    obj->in[++obj->lstin] = x;

    
}

int myQueuePop(MyQueue* obj) {
    int front = myQueuePeek(obj);

    if (front != -1) {
        obj->lstout--;
    }

    return front;
    
}

int myQueuePeek(MyQueue* obj) {
    if (obj->lstout < 0) {
        while (obj->lstin >= 0) {
            obj->out[++obj->lstout] = obj->in[obj->lstin--];
        }
    }

    return obj->lstout < 0 ? -1 : obj->out[obj->lstout];


    
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->lstin == -1 && obj->lstout == -1;
    
}

void myQueueFree(MyQueue* obj) {
    free(obj->in);
    free(obj->out);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/