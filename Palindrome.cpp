/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-17 21:34:09 
 * @Description:count the min methods the set the array to become the palindrome array 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-17 21:43:54
 */
#include<iostream>
using namespace std;
#include<vector>

int n;
vector<int >arr;

int Solve(int low,int high)
{
    int count  = 0;
    int ie = arr[low];
    int je = arr[high];
    while( ie < je && ie != je)
    {
        if(ie < je)
        {
            low ++;
            ie += arr[low];
            ++count;   
        }
        else
        {
            high--;
            je += arr[high];
            ++count;
        }
    }
    if(low >= high)
    {
        return count;
    }
    else
    {
        low++;
        high--;
        return count + Solve(low,high);
    }   
}

int main()
{
    int x;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    cout<<endl<<Solve(0,n-1);
    return 0;
}
