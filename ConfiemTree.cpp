/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-16 17:16:17
 * @Description: Confirm the btree is similar or not  
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-16 17:46:32
 */
#include<iostream>
using namespace std;
#include<malloc.h>

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}BtreeNode;

void CreateBtree(BtreeNode *&bt)
{
    bt = NULL;
    char ch;
    ch = getchar();
    if(ch == '#')
    {
        bt = NULL;
    }
    else
    {
        bt = (BtreeNode*)malloc(sizeof(BtreeNode));
        bt->data = ch;
        CreateBtree(bt->lchild);
        CreateBtree(bt->rchild);
    }   
}

void Destory(BtreeNode *&bt)
{
    if(bt != NULL)
    {
        Destory(bt->lchild);
        Destory(bt->rchild);
        free(bt);
    }
}

void PreOrder(BtreeNode *bt)
{
    if(bt != NULL)
    {
        cout<<bt->data<<" ";
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}

bool IsSame(BtreeNode *b1,BtreeNode * b2)
{
    if(b1 == NULL && b1 == NULL)
    {
        return true;
    }
    if((b1 == NULL && b2 != NULL) ||(b1 != NULL && b2 == NULL) )
    {
        return false;
    }
   
    bool lnode = IsSame(b1->lchild,b1->rchild);
    bool rnode = IsSame(b1->rchild,b1->rchild);
    return lnode & rnode;
}

int main()
{
    BtreeNode *b1;
 
    cout<<"Create b1:";
    CreateBtree(b1);
    cout<<"Preorder b1: ";
    PreOrder(b1);
    cout<<endl;
    
    BtreeNode *b2;
    cout<<"Create b2:";
    CreateBtree(b2);
    cout<<"Preorder b2: ";
    PreOrder(b2);
    cout<<endl;
    
    if(IsSame(b1,b2))
    {
        cout<<"b1 and b2 is same "<<endl;
    }
    else
    {
        cout<<"b1 and b2 is not same "<<endl;
    }

    Destory(b1);
    Destory(b2);
    return 0;
}
