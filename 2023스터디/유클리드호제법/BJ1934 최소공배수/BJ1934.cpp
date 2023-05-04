#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;

    return gcd(b,a%b);
}
int n;
int main(void)
{
    cin >> n;
    while (n--)
    {
        int a, b; cin >> a >> b;
        cout << a*b/gcd(a,b) << '\n';
    }
    
    return 0;
}