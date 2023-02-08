//BJ11057 오르막 수 실1 언타알고멘토링6주차 다이나믹 프로그래밍
#include <iostream>
using namespace std;

// dp푸는법 구체화 된듯. 배낭처럼 조건들 뽑아내서 표 만들면 돼. 값은 보통 문제답으로 설정

int graph[10][1001];    // 행은 숫자 종류. 열은 자리수. 첫열은 버릴거임 직관을 위해 0자리수는 없음

int main(void)
{
    int n; cin >> n;


    for (int i = 0; i <= n; i++)
    {
        graph[0][i] = 1;
    }
    for (int i = 1; i < 10; i++)
    {
        graph[i][1] = i+1;
        for (int j = 2; j <= n; j++)
        {
            graph[i][j] = graph[i-1][j]%10007 + graph[i][j-1]%10007;
            graph[i][j]%=10007;
        }    
    }

    cout << graph[9][n] << endl;

    return 0;
}