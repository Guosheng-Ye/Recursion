/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-14 21:16:24 
 * @Description :  n queen
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-14 21:27:23
 */
#include<iostream>
using namespace std;
#include<stdlib.h>
#define N  20
int q[N];
int count  = 0;

void Disp(int n)
{
    cout<<"The "<<++count<<" solution :";
    for(int i = 1;i <=n;i++)
    {   
        cout<<"("<<i<<","<<q[i]<<")";
    }
    cout<<endl;
}
bool Place(int i ,int j)
{
    if(i == 1 )return true; 
    int k = 1;
    while(k < i)//test the 1 ~ i queen
    {
        if((j  == q[k] )||  (abs(k -i) == abs(q[k] - j)))
        {
            return false;
        }
        k++;
    }
    return true;
}

void Solve(int i,int n)
{
    if(i > n)
    {
        Disp(n);
    }
    else
    {
        for(int j = 1;j<=n;j++)
        {
            if(Place(i,j))
            {
                q[i] = j;
                Solve(i+1,n);
            }
        }
    }
    
}

int main()
{
    int n ;
    cout<<"Input the n :";
    cin>>n;
    if(n> 20)
    {
        cout<<"Too big !"<<endl;
    }
    else
    {
        Solve(1,n);
    }
    
    return 0;
}
