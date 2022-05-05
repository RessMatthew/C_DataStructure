/*链表练习题*/
/*双链表按顺序混合*/
/*
#include<iostream>
using namespace std;
typedef struct Node{
    int sNum;
    int grade;
    struct Node* next;
}Node,*LinkedList;

LinkedList createLinkedList(int num){
    Node *L=new Node();
    Node *tail = L;

    int i=0;
    for(;i<=num-1;i++){
        Node *p=new Node();
        p->next=NULL;
        cin>>p->sNum>>p->grade;

        tail->next = p;
        tail = tail->next;
    }
    return L->next;
}

LinkedList sortLinkedList(LinkedList L){
    Node *p1 =L;
    Node *p2 =L;
    for(;p1->next!=NULL;p1=p1->next){
        for(p2 =L;p2->next!=NULL;p2=p2->next){
            if(p2->sNum>p2->next->sNum){
                int sNumTemporary = p2->sNum;
                p2->sNum = p2->next->sNum;
                p2->next->sNum=sNumTemporary;

                int sNumGrade = p2->grade;
                p2->grade = p2->next->grade;
                p2->next->grade=sNumGrade;
            }
        }
    }
    return L;
}

LinkedList mergeLinkedListsBySNum(LinkedList l1,LinkedList l2){
    l1=sortLinkedList(l1);
    l2=sortLinkedList(l2);
    LinkedList L;
    Node *tail=L;

    Node* currentL1 = l1;
    Node* currentL2 = l2;
    while(currentL1!=NULL&&currentL2!=NULL){
        if(currentL1->sNum<=currentL2->sNum){
            tail->next=currentL1;
            tail = tail->next;
            currentL1 = currentL1->next;
        } else{
            tail->next=currentL2;
            tail = tail->next;
            currentL2 = currentL2->next;
        }
    }
    if(currentL1!=NULL){
        tail->next = currentL1;
    } else{
        tail->next = currentL2;
    }
    return L->next;
}

void printLinkedList(LinkedList L){
    Node* current = L;
    while(current!=NULL){
        cout<<current->sNum<<" "<<current->grade<<endl;
        current = current->next;
    }
}


int main()
{
    int N,M;
    cin>>N>>M;
    LinkedList a = createLinkedList(N);
    LinkedList b = createLinkedList(M);
    printLinkedList(a);
    printLinkedList(b);


    cout<<endl;
    LinkedList L = mergeLinkedListsBySNum(a,b);
    printLinkedList(L);
    return 0;
}
*/
