/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-16 17:55:24
 * @Description:find the max path from root to leaf  
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-16 18:11:12
 */
#include<iostream>
using namespace std;
#include<malloc.h>
#include<vector>

int maxsum = 0;
vector<int>maxpath;

typedef struct node
{
    int data;
    struct node * lchild;
    struct node * rchild;
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
    if( bt != NULL)
    {
        Destory(bt->lchild);
        Destory(bt->rchild);
        free(bt);
    }
}

void Pre(BtreeNode *bt)
{
    if(bt != NULL)
    {
        cout<<bt->data<<" "; 
        Pre(bt->lchild);
        Pre(bt->rchild);
    }
}

void FindMaxPath(BtreeNode *bt,vector<int>anspath,int anssum)
{
    if(bt == NULL) return ;
    anspath.push_back(bt->data);
    anssum += bt->data;//push bt 
    if(bt->lchild == NULL && bt->rchild == NULL)
    {
        if(anssum > maxsum)
        {
            maxsum = anssum;
            maxpath.clear();
            maxpath = anspath;
        }
    }
    FindMaxPath(bt->lchild,anspath,anssum);
    FindMaxPath(bt->rchild,anspath,anssum);
}

int main()
{
    BtreeNode *bt;
    cout<<"Create Btree"<<endl;
    CreateBtree(bt);
    cout<<"Pre bt :";
    Pre(bt);

    vector<int> anspath;
    int ansnum = 0;
    cout<<"Max path:"<<endl;
    FindMaxPath(bt,anspath,ansnum);
    cout<<"Max size of path is :"<<maxsum<<endl;
    for(int i = 0;i<maxpath.size();i++ )
    {
        cout<<maxpath[i]<<" ";
    }
    Destory(bt);
    return 0;
}
