//딱봐도 최소공배수죠? -> 유클리드 호제법
#include <iostream>
using namespace std;

//최대공약수
int gcd(int a, int b)
{
    if(b==0)
        return a;
    
    return gcd(b,a%b);
}

int main(void)
{
    int n; cin >> n;
    
    int a; cin >> a;

    for (int i = 1; i < n; i++)
    {
        int t; cin >> t;

        int temp = a*t/gcd(a,t); //최소공배수
        cout << temp/t << '/' << temp/a << '\n';
    }

    return 0;    
}