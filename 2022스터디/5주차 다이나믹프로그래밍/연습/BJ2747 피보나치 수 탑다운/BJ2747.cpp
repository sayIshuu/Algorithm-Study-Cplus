//BJ2707 피보나치 수 브2
#include <iostream>
using namespace std;

//재귀함수를 이용한 피보나치dp 탑다운 풀이


//했던작업 안하기위한 저장!을위한 배열
int dp[46];

//재귀함수지만 했던작업은 또 안하게 설정해놨다.
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
