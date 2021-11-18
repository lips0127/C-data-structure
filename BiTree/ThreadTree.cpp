#include <stdio.h>

//宏定义
#define Elemtype int

//线索二叉树
//tag为0,child指示孩子；tag为1，child指向前缀（左子树）或者后继（右子树）.
typedef struct ThreadNode{
    Elemtype data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode,*ThreadTree;

//中序遍历对二叉树线索化
void InThread(ThreadTree &p,ThreadTree &pre){
    if(p!=NULL){
        InThread(p->lchild,pre);
        if(p->lchild==NULL){//建立前驱结点
            p->lchild=pre;
            p->ltag=1;
        }
        if(pre!=NULL&&pre->rchild==NULL){//建立前驱结点的后继线索
            pre->rchild=p;
            pre->rtag=1;
        }
        pre=p;
        InThread(p->rchild,pre);
    }
}

//中序遍历建立中序线索二叉树的主过程算法
void CreateInThread(ThreadTree T){
    ThreadTree pre = NULL;
    if(T!=NULL){
        InThread(T,pre);
        pre->rchild=NULL;
        pre->rtag=1;
    }
}