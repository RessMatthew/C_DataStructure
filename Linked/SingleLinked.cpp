/*实验一：链表的基本操作*/
/*
#include "iostream"
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;
}Node,*LinkedList;
//Node表示结点的类型，LinkedList表示指向Node结点类型的指针类型

//初始化:申请头结点空间，返回一个头结点指针
LinkedList initLinkedList(){
//    Node *L;
//    L = new Node();
//    L->next=NULL;

//    LinkedList L = new Node();


    Node* p = new Node();
    p->next = NULL;
    p->data = 0;
    LinkedList L;
    L = p;
    return L;
}

//初始化一、头插法：逆序
LinkedList creatHeadLinkedList(){
    //初始化空链表
    LinkedList L = initLinkedList();

    //头插
    int data;
    cout<<"输入下一结点data：";
    cin>>data;
    while(data!=-1){
        Node *p = new Node();
        p->data=data;
        p->next=L;
        L=p;
        cout<<"输入下一结点data：";
        cin>>data;
    }
    return L;
}

LinkedList creatTailLinkedList(){
    //初始化空链表
    LinkedList L = initLinkedList();
    Node *tail = L;    //每次尾插后，r指向尾结点
    //尾插
    int data;
    std::cout<<"输入下一结点data：";
    std::cin>>data;
    while(data!=-1){
        Node *p = new Node();
        p->data=data;
        p->next=NULL;
        tail->next=p;
        tail=tail->next;

        cout<<"输入下一结点data：";
        cin>>data;
    }
    return L;
}

void printLinkedList(LinkedList L){
    Node *current = L;
    int i=0;
    while(current){
        cout<<"第"<<i<<"个元素"<<current->data<<"  ";
        i++;
        current=current->next;
    }
    cout<<endl;
}

//将链表L第k个元素的data修改为x
LinkedList replaceLinkedList(LinkedList L,int k,int x){
    Node *current = L->next;
    int i=0;
    while(current){
        if(i==k){
            current->data =x;
            cout<<"修改成功"<<endl;
            return L;
        }
        i++;
        current = current->next;
    }
    cout<<"输入错误，返回NULL"<<endl;
    return NULL;
}

//在链表的第i个位置插入元素,data为x
LinkedList insertNode(LinkedList L,int k,int x){
    Node* current=L;
    int i=0;
    while(current){
        if(i==k){
            Node* p = new Node();
            p->data=x;
            p->next=current->next;
            current->next=p;
            cout<<"插入成功"<<endl;
            return L;
        }
        i++;
        current = current->next;
    }
    cout<<"输入错误"<<endl;
    return L;
}

LinkedList deleteNode(LinkedList L,int k){
    Node* current=L->next;
    Node* preCurrent;
    int i=1;
    while(current!=NULL){
        preCurrent=current;
        current=current->next;

        //判断k=i时，删除
        if(k==i){
            preCurrent->next=current->next;
            delete current;
            cout<<"删除成功"<<endl;
            return L;
        }
        i++;
        //current = current->next;
    }
    return L;
}


//int main(){
//
////    LinkedList L = creatTailLinkedList();
////    printLinkedList(L);
//
////    LinkedList L = creatHeadLinkedList();
////    printLinkedList(L);
//
////    LinkedList L = creatTailLinkedList();
////    printLinkedList(L);
////    insertNode(L,2,5);
////    printLinkedList(L);
////    replaceLinkedList(L,2,3);
////    printLinkedList(L);
////    deleteNode(L,1);
////    printLinkedList(L);
//
//    return 0;
//}*/
