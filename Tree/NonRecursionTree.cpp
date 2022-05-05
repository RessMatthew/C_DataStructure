//
// Created by RessMatthew on 2022/5/5.
//

#include<iostream>
#include<stdlib.h>
using namespace std;
//����������ʽ�洢
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//������������ݽ���������
void createTree(BiTree &root){
    BiTNode **stack[20];
    int top = 0;
    int temp;
    root = (BiTNode *) malloc (sizeof(BiTNode));
    stack[top++] = &root;
    BiTNode *p = root;
    while(top != 0){
        if(cin >> temp){
            root = *stack[--top];
            root->data = temp;
            root->rchild = (BiTree) malloc (sizeof(BiTNode));
            stack[top++] = &root->rchild;
            root->lchild = (BiTree) malloc (sizeof(BiTNode));
            stack[top++] = &root->lchild;
        }
        else{
            cin.clear();
            cin.ignore();
            *stack[--top] = NULL;
        }
    }
    root = p;
}
//ǰ���������������
void PreOrder(BiTree root){
    BiTNode *p = root;
    BiTNode *stack[20];
    int top = 0;
    while(p || top!=0){
        while(p){
            printf("%d ",p->data);
            if(p->rchild) stack[top++] = p->rchild;
            p = p->lchild;
        }
        if(top != 0) p = stack[--top];
    }
    cout << endl;
}
//�����������������
void InOrder(BiTree root){
    BiTNode *p = root;
    BiTNode *stack[20];
    int top=0;
    p=root;
    while(p||top!=0){
        while(p){
            stack[top++]=p;
            p=p->lchild ;
        }
        p=stack[--top];
        printf("%d ",p->data );
        p=p->rchild ;
    }
    cout << endl;
}
//�����������������
void PostOrder(BiTree root){
    BiTNode *p;
    BiTNode *stack[20];
    int status[20];
    int top = 0;
    int tempstatus;
    p = root;
    if(p){
        stack[top] = p;
        status[top] = 1;
        top++;
    }
    while(top!=0){
        top = top -1;
        p = stack[top];
        tempstatus = status[top];
        switch(tempstatus){
            case 1: {
                stack[top] = p;
                status[top] = 2;
                top++;
                if(p->lchild){
                    stack[top] = p->lchild;
                    status[top] = 1;
                    top++;
                }
                break;
            }
            case 2: {
                stack[top] = p;
                status[top] = 3;
                top++;
                if(p->rchild != NULL){
                    stack[top] = p->rchild;
                    status[top] = 1;
                    top++;
                }
                break;
            }
            case 3 : printf("%d ",p->data);break;
        }
    }
    cout << endl;
}
//�����ͼ���
int CountAndCalculate(BiTree root,int mod){
    BiTNode *p = root;
    BiTNode *stack[20];
    int top = 0,count;
    if(mod < 5) count = 0;
    else count = p->data;
    while(p || top!=0){
        while(p){
            switch(mod){
                case 1 : count++;break;		//���������
                case 2 : 						//�����Ϊ1�Ľ�����
                    if(p->lchild == NULL ^ p->rchild == NULL)
                        count++;break;
                case 3 : 						//�����Ϊ2�Ľ�����
                    if(p->lchild != NULL && p->rchild != NULL)
                        count++;break;
                case 4 : 						//����Ҷ�ӽ��ĸ���
                    if(p->lchild == NULL && p->rchild == NULL)
                        count++;break;
                case 5 : 						//�����ݵ����ֵ
                    if(p->data > count)
                        count = p->data;break;
                case 6 : 						//�����ݵ���Сֵ
                    if(p->data < count)
                        count = p->data;break;
            }
            if(p->rchild) stack[top++] = p->rchild;
            p = p->lchild;
        }
        if(top != 0) p = stack[--top];
    }
    cout << endl;
    return count;
}

int main()
{
    printf("���������ݣ���*����գ���\n");
    BiTree root;
    createTree(root);
    printf("ǰ��������Ϊ��");
    PreOrder(root);
    printf("����������Ϊ��");
    InOrder(root);
    printf("�����������Ϊ��");
    PostOrder(root);
    printf("�������Ľ�����Ϊ��%d",CountAndCalculate(root,1));
    printf("��Ϊ1�Ľ�����Ϊ��%d",CountAndCalculate(root,2));
    printf("��Ϊ2�Ľ�����Ϊ��%d",CountAndCalculate(root,3));
    printf("Ҷ�ӽ�����Ϊ��%d",CountAndCalculate(root,4));
    printf("���ݵ����ֵΪ��%d",CountAndCalculate(root,5));
    printf("���ݵ���СֵΪ��%d",CountAndCalculate(root,6));
}
