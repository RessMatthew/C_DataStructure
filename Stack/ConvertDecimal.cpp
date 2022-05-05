/*栈练习题*/
/*将10进制转换为2进制*/
/*
#include "iostream"
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}Node;
typedef struct{
    Node *top;
    int count;
}Link_Stack;


Link_Stack* push_stack(Link_Stack *p,int elem){
    //p==NULL
    if(p==NULL){
        cout<<"输入Link_Stack错误"<<endl;
        return NULL;
    }
    //p!=NULL
    else{
        Node* temp = new Node();
        temp->data=elem;
        temp->next=p->top;
        p->top=temp;
        p->count++;
        return p;
    }
}

void printStack(Link_Stack *p){
    //p==NULL
    if(p==NULL){
        cout<<"输入Link_Stack错误"<<endl;
        return;
    }
    //p!=NULL
    else{
        Node* current=p->top;
        while(current!=NULL){
            cout<<current->data;
            current=current->next;
        }
        cout<<endl;
    }
}

Link_Stack* creatStack(){
    //创建头指针结点
    Link_Stack* p = new Link_Stack();
    p->top=NULL;
    p->count=0;
    return p;
}

void convertDecimalToBinary(int x){
    Link_Stack *stack = creatStack();
    if(x>0){
        do{
            push_stack(stack,x%2);
            x=x/2;
        }while(x!=0);
    }
    else if(x<0){
        x=-x;
        do{
            push_stack(stack,x%2);
            x=x/2;
        }while(x!=0);
        cout<<'-';
    }
    else{
        push_stack(stack,0);
    }
    printStack(stack);

}

int main(){

    int x;
    while(cin>>x){
        convertDecimalToBinary(x);
    }
    return  0;

}*/
