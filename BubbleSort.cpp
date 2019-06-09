/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-14 21:03:00 
 * @Description: Bubble by Recursion
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-14 21:14:51
 */

#include<iostream>
using namespace std;

void Swap(int &x,int &y)
{
    int temp = x;
    x  = y;
    y  = temp;
}
void Disp(int a[],int n)
{   
    for(int i = 0 ;i< n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void BubbleSort(int a[],int n,int i)
{
    int j ;
    bool exchange;
    if(i == n - 1)
    {
        return ;
    }
    else
    {
        exchange  = false;
        for(int j  = n - 1;j>i;j--)
        {
            if(a[j] < a[j-1])
            {
                Swap(a[j],a[j-1]);
                exchange = true;
            }
        }
        if(!exchange)
            return ;
        else
        {
            BubbleSort(a,n,i+1);
        }
    }
}

int main()
{
    int n ;
    cout<<"Please input the size of array:";
    cin>>n;
    int a[n];
    cout<<"Input the elem:";
    for(int i =0;i < n;i++)
    {
        cin>>a[i];
    }
    cout<<"Before sort :";
    Disp(a,n);
    BubbleSort(a,n,0);
    cout<<"After sort:";
    Disp(a,n);
    
    return 0;
}