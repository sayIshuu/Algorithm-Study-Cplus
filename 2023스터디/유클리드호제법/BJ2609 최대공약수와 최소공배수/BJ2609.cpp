#include <iostream>
using namespace std;

int n, m;

//��Ŭ���� ȣ���� => �ִ�����
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
    //�ּҰ���� = �μ��� �� / �ִ�����
    cout << m*n/ans;
    return 0;
}