#include <iostream>
#include <algorithm>
using namespace std;

void f(int a, int b, int c)
{
    if(a%2 == 0 && b%2 == 1)
    {
        a = a/2;
        b = (b+1)/2;
    }
    else if(a%2 == 1 && b%2 == 0)
    {
        b /= 2;
        a = (a+1)/2;
    }
    else if(a%2 == 0 && b%2 == 0)
    {
        a /= 2;
        b /= 2;
    }
    else
    {
        a = (a+1)/2;
        b = (b+1)/2;
    }

    if(a==b)
    {
        cout << c;
        return;
    }
    else
        c++;

    f(a,b,c);
}





int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y; cin >> n >> x >> y;
     
    f(max(x,y), min(x,y), 1);

    //È¦Â¦ÀÌ Áß¿ä
    return 0;
}