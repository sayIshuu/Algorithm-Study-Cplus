//BJ2707 �Ǻ���ġ �� ��2
#include <iostream>
using namespace std;


//Bottom-Up ����� ���̳��� ���α׷���.
long fibo[46];

int main()
{
    int n;
    cin >> n;

    fibo[0] = 0;
    fibo[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }

    cout << fibo[n];

    return 0;
}