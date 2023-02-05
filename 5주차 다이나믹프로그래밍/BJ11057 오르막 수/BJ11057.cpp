//BJ11057 오르막 수 실1 언타멘토링6주차 다이나믹프로그래밍
#include <iostream>
using namespace std;

// 문제아이디어
// 0~9 10개의 숫자에서 중복을 허용하여 주어진 길이 N만큼 뽑고 순서는 정해져있다.
// 중복조합
// 점화식은 P(n) = (9+n)C(n)
// 문제의 10007은 뭔지 모르겠넹

int main(void)
{
    int n;  cin >> n;

    // 분자 분모
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