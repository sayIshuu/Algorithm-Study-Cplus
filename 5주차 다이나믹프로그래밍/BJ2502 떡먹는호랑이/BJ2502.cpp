//BJ2502 떡먹는호랑이 실1 언타멘토링 5주차 다이나믹 프로그래밍
#include <iostream>
using namespace std;

//첫날떡개수 A, 둘째날떡개수 B는 각각 D일째
//피보나치수열의 D-1번째, D번째 만큼 더해져있다.
//피보나치수열 0 1 1 2 3 5 8 13 ...

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