//������ �ּҰ������? -> ��Ŭ���� ȣ����
#include <iostream>
using namespace std;

//�ִ�����
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

        int temp = a*t/gcd(a,t); //�ּҰ����
        cout << temp/t << '/' << temp/a << '\n';
    }

    return 0;    
}