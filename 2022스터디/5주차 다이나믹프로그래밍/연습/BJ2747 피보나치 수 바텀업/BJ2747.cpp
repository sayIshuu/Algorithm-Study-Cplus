//BJ2707 피보나치 수 브2
#include <iostream>
using namespace std;


//Bottom-Up 방식의 다이나믹 프로그래밍.
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