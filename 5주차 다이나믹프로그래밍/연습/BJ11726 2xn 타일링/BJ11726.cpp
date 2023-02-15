//BJ11726 2xn 타일링 실3 다이나믹프로그래밍
#include <iostream>
using namespace std;

// 전 타일에서 세로타일 하나 추가한거 + 전전 타일에서 가로 타일 두개 추가한거
// 따라서 피보나치
// 1 2 3 5 8 13 21 ...
// 나머지 끼리 더한값 = 더한 값의 나머지

int main(void)
{
    int tile[1001] = {0,1,2,};

    int n;  cin >> n;

    for (int i = 3; i <= n; i++)
    {
        tile[i] = tile[i-1]%10007 + tile[i-2]%10007;
    }
    
    cout << tile[n]%10007;

    return 0;
}