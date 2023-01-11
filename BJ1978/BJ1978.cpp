//BJ1978 소수 찾기 실4 언타멘토링 1주차
#include <iostream>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    int a; // 소수인지 판별할 숫자
    int count = 0; // 찾은 소수 갯수

    // 입력한 n만큼의 숫자를 판별하는 반복문
    while(n>0)
    {
        int b = 0; // 판별수 0이 유지되면 소수
        cin >> a;

        if(a == 1) b = 1;   // 1은 예외 수라 따로 처리
        // 실제로 그 숫자 a가 소수인지 판별하는 반복문
        for (int i = 2; i < a; i++)
        {
            if(a%i == 0) // 소수는 1과 자기자신뺀 약수가 존재하면 안됌.
                b = 1;
        }
        
        if(b == 0)
            count++;

        n--;
    }
    
    cout << count << endl;
    return 0;
}


// 시간복잡도 O(n^2) 판별할 숫자의 범위가 작아서 그냥 구현하였습니다.
// 구현 자체는 쉬웠습니다. 안좋은 알고리즘이다 보니,
// 풀고 나서 동빈나씨의 에라토스테네스의 체 영상 정독하였습니다.