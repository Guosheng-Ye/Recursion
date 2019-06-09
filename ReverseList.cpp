/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-16 16:20:55
 * @Description : reverse the list  
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-16 17:10:26
 */
#include<iostream>
using namespace std;
#include<malloc.h>
#define ELEMTYPE int 

typedef struct  list
{
    ELEMTYPE data;
    struct  list *next;
}SqList;

void CreateList(SqList *&L,int n)
{
    cout<<"Input the "<<n<<"elements :";
    int x;
    L = (SqList * )malloc(sizeof(SqList));
    cin>>x;
    L->data = x;
    L->next = NULL;
    SqList *r = L;
    SqList *t;
    for(int i = 1;i<n;i++)
    {
        cin>>x;
        t = (SqList*)malloc(sizeof(SqList));\
        t->data = x;
        r->next = t;
        r = t;
    }
    r->next = NULL;
}

void Disp(SqList *L)
{
    if( L == NULL)
    {
        return ;
    }
    else
    {
        cout<<L->data<<" ";
        Disp(L->next); 
    }
}

void Destory(SqList *&L)
{
    SqList * pre = L;
    SqList * p = L->next;
    while(p != NULL)
    {
        free(pre);
        pre  = p;
        p = p->next;
    }
    free(p);
}

SqList * Reverse(SqList *&L)
{
     SqList *p;
     if( L == NULL  || L ->next == NULL)
     {
         return L;
     }
     p = Reverse(L->next);
     L->next->next = L;
     L->next = NULL;
     return p;
}

int main()
{
    SqList *L;
    int n;
    cout<<"Input the size of lisr :";
    cin>>n;
    CreateList(L,n);
    cout<<"Before reverse :";
    Disp(L);
    cout<<endl;
    L = Reverse(L);
    cout<<"Afrer reverse :";
    Disp(L);

    Destory(L);
    return 0;
}
