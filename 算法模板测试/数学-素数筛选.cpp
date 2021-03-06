/*
*素数筛选-判断小于MAXN的是不是素数
*notprime是一张表，true则不是素数
*
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int MAXN = 1000010;
bool notprime[MAXN];
void init()
{
    memset(notprime,0,sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for(int i = 2; i < MAXN ; i++)
    {
        if(i > MAXN/i)continue;//防止后边的i*i 溢出
        for(int j = i*i; j < MAXN; j+=i)
        {
            notprime[j] =  true;
        }
    }
}

int main()
{
    init();
    int n;
    while(cin >> n)
    {
        for(int i = 0; i < n ;i++)
        {
            if(!notprime[i])
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
