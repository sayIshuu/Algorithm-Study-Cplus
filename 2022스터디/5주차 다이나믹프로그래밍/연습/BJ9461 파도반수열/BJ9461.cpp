//BJ9461 �ĵ��ݼ��� ��3 ���̳������α׷���
#include <iostream>
using namespace std;

int main(void)
{
    int t;  cin >> t;
    long long p[101] = {0,1,1,1,2,2,};    //�ε����� 100������

    for (int i = 6; i < 101; i++)
    {
        p[i] = p[i-1]+p[i-5];
    }

    while(t--)
    {
        int n; cin >> n;
        cout << p[n] << endl;
    }

    return 0;
}