//
// Created by RessMatthew on 2022/5/5.
//

#include<iostream>
#include<stdlib.h>
using namespace std;
//二叉树的链式存储
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
//根据输入的数据建立二叉树
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
//前序遍历输出遍历结果
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
//中序遍历输出遍历结果
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
//后序遍历输出遍历结果
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
//计数和计算
int CountAndCalculate(BiTree root,int mod){
    BiTNode *p = root;
    BiTNode *stack[20];
    int top = 0,count;
    if(mod < 5) count = 0;
    else count = p->data;
    while(p || top!=0){
        while(p){
            switch(mod){
                case 1 : count++;break;		//计算结点个数
                case 2 : 						//计算度为1的结点个数
                    if(p->lchild == NULL ^ p->rchild == NULL)
                        count++;break;
                case 3 : 						//计算度为2的结点个数
                    if(p->lchild != NULL && p->rchild != NULL)
                        count++;break;
                case 4 : 						//计算叶子结点的个数
                    if(p->lchild == NULL && p->rchild == NULL)
                        count++;break;
                case 5 : 						//求数据的最大值
                    if(p->data > count)
                        count = p->data;break;
                case 6 : 						//求数据的最小值
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
    printf("请输入数据（用*代表空）：\n");
    BiTree root;
    createTree(root);
    printf("前序遍历结果为：");
    PreOrder(root);
    printf("中序遍历结果为：");
    InOrder(root);
    printf("后续遍历结果为：");
    PostOrder(root);
    printf("二叉树的结点个数为：%d",CountAndCalculate(root,1));
    printf("度为1的结点个数为：%d",CountAndCalculate(root,2));
    printf("度为2的结点个数为：%d",CountAndCalculate(root,3));
    printf("叶子结点个数为：%d",CountAndCalculate(root,4));
    printf("数据的最大值为：%d",CountAndCalculate(root,5));
    printf("数据的最小值为：%d",CountAndCalculate(root,6));
}
