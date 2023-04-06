//BJ2502 ���Դ�ȣ���� ��1 ��Ÿ���丵 5���� ���̳��� ���α׷���
#include <iostream>
using namespace std;

//ù�������� A, ��°�������� B�� ���� D��°
//�Ǻ���ġ������ D-1��°, D��° ��ŭ �������ִ�.
//�Ǻ���ġ���� 0 1 1 2 3 5 8 13 ...

long fibo[31];

int main()
{
    fibo[1] = 0;
    fibo[2] = 1;

    for (int i = 3; i < 32; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    int d, k;
    cin >> d >> k;

    for (int a = 1; a < k; a++)
    {
        for (int b = 2; b < k; b++)
        {
            if(fibo[d-1]*a + fibo[d]*b == k)
            {
                cout << a << endl;
                cout << b << endl;
                return 0;
            }
            else if(fibo[d-1]*a + fibo[d]*b > k)
                break;
        }  
    }
    
    return 0;
}

//�ð����⵵ o(n^2) �� ��������� «