/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-16 22:03:15
 * @Description:find the x and y 's GCD 
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-18 19:14:20
 */
#include<iostream>
using namespace std;

int Gcd(int x,int y)
{
    if(y == 0)
    {
        return x;
    }
    return Gcd(y,x % y);    
}
int Gcd2(int x,int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x ;
}

int main()
{
    int a,b;
    cout<<"Cin a and b:";
    cin>>a>>b;
    cout<<"GCD "<<a<<" and "<<b<<" is "<<Gcd(a,b)<<" (by recursion)"<<endl;
    cout<<"GCD "<<a<<" and "<<b<<" is "<<Gcd(a,b)<<" (by inrecursion)"<<endl;
    return 0;
}
