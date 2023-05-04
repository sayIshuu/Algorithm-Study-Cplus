#include <iostream>
using namespace std;

int n, m;

//유클리드 호제법 => 최대공약수
int gcd(int a, int b)
{
    if(b==0)
        return a;
    
    return gcd(b,a%b);
}

int main(void)
{
    cin >> n >> m;
    int ans = gcd(n,m);
    cout << ans << '\n';
    //최소공배수 = 두수의 곱 / 최대공약수
    cout << m*n/ans;
    return 0;
}