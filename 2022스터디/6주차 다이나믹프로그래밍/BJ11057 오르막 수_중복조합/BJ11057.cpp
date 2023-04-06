//BJ11057 ������ �� ��1 ��Ÿ���丵6���� ���̳������α׷���
#include <iostream>
using namespace std;

// �������̵��
// 0~9 10���� ���ڿ��� �ߺ��� ����Ͽ� �־��� ���� N��ŭ �̰� ������ �������ִ�.
// �ߺ�����
// ��ȭ���� P(n) = (9+n)C(n)
// ������ 10007�� ���� �𸣰ڳ�

int main(void)
{
    int n;  cin >> n;

    // ���� �и�
    unsigned long long qnswk = 1;
    unsigned long long qnsah = 1;

    for (int i = 0; i < n; i++)
    {
        qnswk *= (9+n-i);
        qnsah *= (i+1);
    }
    
    cout << (qnswk/qnsah)%10007 << endl;

    return 0;   
}