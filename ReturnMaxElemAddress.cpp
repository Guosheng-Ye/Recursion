/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-15 21:03:56
 * @Description : Return the max elem address 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-15 21:31:37
 */
#include<iostream>
using namespace std;
#include<malloc.h>

typedef struct Node
{
    int data;
    struct Node  *next;
    
}ListNode;

void  CreateList(ListNode *&L,int n)
{
    cout<<"Input the "<<n<<" elems "<<endl;
    L = (ListNode*)malloc(sizeof(ListNode));
    ListNode *p;
    ListNode *t;
    int x;
    cin>>x;
    L->data  = x;
    L->next = NULL;
    t = L;
    for(int i  =  1;i< n ;i++)
    {
         p = (ListNode*)malloc(sizeof(ListNode));
         cin>>x;
         p->data =  x;
         t->next =  p;
         t = p;
    }
    t->next = NULL;
}
void Disp(ListNode *L)
{
    if(L==NULL)return;
    else
    {
        cout<<L->data<<" ";
        Disp(L->next);
    }   
}
void Destory(ListNode *&L)
{
    ListNode * pre = L;
    ListNode *p  = L->next;
    while(p !=NULL)
    {
        free(pre);
        pre  = p;
        p = p->next;
    }
    free(pre);
}

ListNode * Findmax(ListNode *L)
{
    if(L->next== NULL)return L;
    else
    {
        ListNode * maxnode;
        maxnode = Findmax(L->next);
        if(L->data > maxnode->data)
        {
            return L;
        }
        else
        {
            return maxnode;
        }
        
    }
    
}

int main()
{
    int n;
    cin>>n;
    ListNode *L;
    CreateList(L,n);
    Disp(L);
    ListNode *p = Findmax(L);
    cout<<"Max node elem is"<<p->data<<endl;
    Destory(L);
    return 0;
}
