/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-17 21:18:05 
 * @Description : cout the nmatrix
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-17 21:29:23
 */
#include<iostream>
using namespace std;
#include<iomanip>
int n;
int start;
int arr[50][50];
void Solve(int x,int y ,int start,int n)
{
    int i;
    int j;
    if(n <= 0)return ;
    if(n == 1){arr[x][y] = start;return ;}
    for(i = x;i < x + n -1;i++)
    {
        arr[y][i] = start++;
    }
    for(j = y;j < y + n -1;j++)
    {
        arr[j][x+n-1] = start++;
    }
    for(i = x+n-1;i>x;i--)
    {
        arr[y+n-1][i] = start++;
    }
    for(j = y+n-1;j>y;j--)
    {
        arr[j][x] = start++;
    }
    Solve(x+1,y+1,start,n-2);
}

void Disp()
{
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cout<<setw(5)<<arr[i][j]<<" "; 
        }
        cout<<endl;
    }
}
int main()
{

    cin>>n;
    Solve(0,0,1,n);
    Disp();
    return 0;
}