/*================================================================
*  @FileName: SelectSort.cpp
*  @Author  : YeGuosheng 
*  @CreateTime : 2019-03-13 22:52:26
*  @Description: 
*     SelectSort by recutsion 
*  @Last Modified time: 2019-03-13 22:52:26
================================================================*/
#include<iostream>
using namespace std;

void Swap(int &x,int &y)
{
  int temp = x;
  x = y;
  y = temp;
}

void Disp(int a[],int n)
{
  int i;
  for(i = 0;i < n;i++ )
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void SelectSort(int a[],int n,int i)
{
  
    int k;
    int j;
    if(n == i - 1)
      return;
    else
    {
      k  = i ;
      for(j = i +1;j<n;j++)
      {
        if(a[j] < a[k])
        {
          k  = j;
        }
      }
      if(k != i)
      {
        Swap(a[i],a[k]);
      }
      SelectSort(a,n,i+1);
    }
}


int main()
{
  int n;
  cout<<"Please input the size of array:";
  cin>>n;
  int arr[n];
  cout<<"Cin the elem "<<endl;
  for(int i = 0 ;i < n;i++)
  {
    cin>>arr[i];
  }
  cout<<"Before of sort:";
  Disp(arr,n);
  SelectSort(arr,n,0);
  cout<<"After of sort:";
  Disp(arr,n);
  return 0;
}






