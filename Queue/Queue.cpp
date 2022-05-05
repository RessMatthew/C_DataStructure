/*队列练习题*/
/*基础操作*/
/*t
#include "iostream"

using namespace std;

typedef struct node{
    int data;
    struct node *next;
}Node;
typedef struc queue{
    node *front;
    node *rear;
}Queue;

// 初始化队列
Queue *createQueue(){
    Queue *pQueue=new Queue();
        // 建立失败，退出(省略)
    // 头尾结点均赋值NULL
    pQueue->front=NULL;
    pQueue->rear=NULL;
    return pQueue;
}

// 入队列
void push_queue(Queue *queue,int data){
    Node *tempNode = new Node();
    tempNode->data=data;
    tempNode->next=NULL;

    //如果队列为空的话，需要将头指针和尾指针一同指向第一个结点，即front=n;rear=n
    if(queue->front==NULL){
        queue->front=tempNode;
        queue->rear=tempNode;
    }
    //当如果队列不为空的时候，我们只需要将尾结点向后移动，通过不断移动next指针指向新的结点构成队列即可
    else{
        queue->rear->next=tempNode;
        queue->rear=tempNode;
    }
}

// 出队列
int pop_queue(Queue *queue){\
    int tempInt;
    //队列为空
    if(queue->front==NULL){
        cout<<"error：队列为空";
        return 0;
    }
    //只有一个元素，直接将头尾两指针制空（NULL）并释放这一个结点即可
    else if(queue->front==queue->rear){
        delete queue->front;
        queue->front=NULL;
        queue->rear=NULL;
    }
    //有二以上个元素，将队列的头指针指向头指针当前指向的下一个元素并释放掉当前元素即可
    else{
        Node *tempNode=queue->front;
        queue->front=queue->front->next;
        tempInt=tempNode->data;
        delete tempNode;
    }
    return tempInt;
}

//  遍历打印队列
void printQueue(Queue *queue){
    Queue *currentQueue=queue;
    //在队列不为空的情况下，通过结点的next指向依次遍历并输出元素既可以
    while (currentQueue->front!=NULL){
        cout<<currentQueue->front->data<<endl;
        currentQueue->front=currentQueue->front->next;
    }
}


int main(){

    Queue *p=createQueue();
    push_queue(p,1);
    push_queue(p,2);
    printQueue(p);


    return 0;
}*/