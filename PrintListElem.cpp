/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-14 22:17:17 
 * @Description: A list without the head  .design an algorithm to print the elem
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-14 22:53:59
 */
#include<iostream>
using namespace std;
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}ListNode;

void CreateList(ListNode *&L,int n)
{   
    ListNode *p;
    ListNode * r;
    int x;
    cin>>x;
    L = (ListNode*)malloc(sizeof(ListNode));
    L->data = x;
    L->next = NULL;
    r = L;
    for(int i =1;i<n;i++)
    {
        cin>>x;
        ListNode *t;
        t = (ListNode*)malloc(sizeof(ListNode));
        t->data = x;
        r->next = t;
        r = t; 
    }
    r->next = NULL;
}

void SeqDisp(ListNode *L)
{
    if(L == NULL) return ;
    else
    {
        cout<<L->data<<" ";
        SeqDisp(L->next);
    }
    
}

void ReDisp(ListNode *L)
{
    if(L == NULL)return ;
    else
    {
        ReDisp(L->next);
        cout<<L->data<<" ";
    }
}

void Destory(ListNode *&L)
{
    ListNode *pre = L;
    ListNode *p = L->next;
    while(p != NULL)
    {
        free(pre);
        pre = p;
        p = p->next;
    }
    free(pre);
}

int main()
{
    ListNode *L;
    int n;
    cout<<"Please input the size of list:";
    cin>>n;
    CreateList(L,n);
    cout<<"Seq Disp:"<<endl;
    SeqDisp(L);
    cout<<endl;
    cout<<"Rev Disp:"<<endl;
    ReDisp(L);
    Destory(L);
    return 0;
}