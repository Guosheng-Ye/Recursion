/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-14 21:44:41 
 * @Description : Confirm string is Palindrome??
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-14 21:57:15
 */
#include<iostream>
using namespace std;
#include<string.h>

bool Ispal(char * str,int n)
{
    if(n == 0 || n == 1)
    {
        return true;
    }
    if(str[0] != str[n-1])
    {
        return false;
    }
    return Ispal(str+1,n-2);
}

void Disp(char *str)
{
    int n  = strlen(str);
    if(Ispal(str,n))
    {
        cout<<str<<"is Palindrome."<<endl;
    }
}
int main()
{
    Disp("ABBA");
    Disp("abcd");
    Disp("A");
    
    return 0;
}
