//BJ2707 �Ǻ���ġ �� ��2
#include <iostream>
using namespace std;

//����Լ��� �̿��� �Ǻ���ġdp ž�ٿ� Ǯ��


//�ߴ��۾� ���ϱ����� ����!������ �迭
int dp[46];

//����Լ����� �ߴ��۾��� �� ���ϰ� �����س���.
int fibo(int n)
{
    if (n == 1 || n == 2)
				return 1;

		if (dp[n] != 0)
				return dp[n];

		return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);

    return 0;
}
