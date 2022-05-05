////
//// Created by RessMatthew on 2022/5/5.
////
//
//
//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//typedef struct BiTNode{
//    int data;
//    struct BiTNode *lchild,*rchild;
//}BiTNode,*BiTree;
////递归建立二叉树
//BiTNode *createTree(BiTree root){
//    int temp;
//    if(cin >> temp){
//        root = (BiTree) malloc (sizeof(BiTNode));
//        root->data = temp;
//        root->lchild = createTree(root->lchild);
//        root->rchild = createTree(root->rchild);
//    }
//    else{
//        cin.clear();
//        cin.ignore();
//        root = NULL;
//    }
//    return root;
//}
////前序遍历结果
//void PreOrder(BiTree root){
//    if(root!= NULL){
//        cout << root->data <<' ';
//        PreOrder(root->lchild);
//        PreOrder(root->rchild);
//    }
//}
////中序遍历结果
//void InOrder(BiTree root){
//    if(root!= NULL){
//        InOrder(root->lchild);
//        cout << root->data << ' ';
//        InOrder(root->rchild);
//    }
//}
////后序遍历结果
//void PostOrder(BiTree root){
//    if(root!= NULL){
//        PostOrder(root->lchild);
//        PostOrder(root->rchild);
//        cout << root->data << ' ';
//    }
//}
//int main(){
//    printf("请输入数据（用*代表空）：\n");
//    BiTree root = createTree(root);
//    printf("前序遍历结果为：");
//    PreOrder(root);
//    cout << endl;
//    printf("中序遍历结果为：");
//    InOrder(root);
//    cout << endl;
//    printf("后续遍历结果为：");
//    PostOrder(root);
//}