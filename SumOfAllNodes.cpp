/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-16 14:28:05 
 * @Description: retutn the sum of all nodes in btree
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-16 14:28:30\
 */
#include<iostream>
#include<queue>
using namespace std;
#define ELEMTYPE int

typedef struct node
{
    int data;
    struct node *lnode;
    struct node *rnode;
}Btree;



void  Destory(Btree *&b)
{
    if(b != NULL)
    {
        Destory(b->lnode);
        Destory(b->rnode);
    }
    free(b);
}

Btree * CreateBtree(ELEMTYPE a[],ELEMTYPE b[],int n)
{
    int k;
    if(n <= 0) return NULL;
    ELEMTYPE start = a[0];
    Btree *bt = (Btree *)malloc(sizeof(Btree));
    bt->data = start;
    for(k = 0 ;k<n;k++)
    {
        if(b[k] == start)
            break;
    }
    bt->lnode = CreateBtree(a+1,b,k);
    bt->rnode = CreateBtree(a+k+1,b+k+1,n-k-1);
    return bt;
}/*
void Disp(Btree *bt)
{   
       queue<Btree> qu;
       qu.push(*bt);
       while(! qu.empty())
       {
           Btree f = qu.front();
           qu.pop();
           if(f.lnode != NULL )
           {
               qu.push(*f.lnode);
           }
           if(f.rnode != NULL)
           {
               qu.push(*f.rnode);
           }
       }
}
*/

int LeafSum(Btree * bt)
{
    if(bt== NULL) return 0;
    if(bt->lnode == NULL && bt->rnode == NULL)
    {
        return bt->data;
    }
    
    int lSum = LeafSum(bt->lnode);
    int rSum = LeafSum(bt->rnode);
    return lSum + rSum;
}
 
int Nodenum(Btree *bt,int k)
{
    if(bt == NULL) return 0;
    int lnum = Nodenum(bt->lnode,k);
    int rnum = Nodenum(bt->rnode,k);
    if(bt->data >= k)
    {
        return lnum + rnum +1;
    }
    else
    {
        return lnum + rnum;
    }
}

int Level(Btree *bt,int x,int l)
{
    if(bt == NULL) return 0;
    if(bt->data == x)
        return l;
    else
    {
        int level = Level(bt->lnode,x,l+1);
        if(level != 0)
            return level;//  ltree find 
        else
        {
            return (Level(bt->rnode,x,l+1));
        }   
    }   
}

int main()
{
    Btree * bt;
    ELEMTYPE a[] = {5,2,3,4,1,6};
    ELEMTYPE b[] = {2,3,5,1,4,6};
    int n  = sizeof(a) / sizeof(a[0]);
    bt =  CreateBtree(a,b,n);
    cout<<"btree: ";
    //Disp(bt);
    cout<<"All nodes' sum == "<<LeafSum(bt)<<endl;
    cout<<"High than 3  num ; "<<Nodenum(bt,3)<<endl;
    cout<<"The elem 3's level is :"<<Level(bt,3,1)<<endl;

    Destory(bt);
    return 0;
}
