/*
 * @Author: YeGuoSheng 
 * @Date: 2019-03-14 21:32:08 
 * @Description : count the length of string by use recursion
 * @Last Modified by: YeGuoSheng
 * @Last Modified time: 2019-03-14 21:32:49
 */
#include<iostream>
using namespace std;

int num = 0;

int  Count(char * str)
{
    if( *str == '\0')
    {
        return 0;
    }
    else
    {
        return Count(str + 1) + 1;
    }
    
}

int main()
{
    char str1[] = {'a','b','a','c','e','g','h'};
    cout<<str1<<"length is "<<Count(str1)<<endl;
   
    
    return 0;
}
