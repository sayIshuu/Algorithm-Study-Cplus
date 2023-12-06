//memory의 범위는 천만단위, cost의 범위는 100단위라고 cost로 배열 구성하면됨
//결국 배낭문제는 기준 상관없이 n을 늘려가며, 최적의 답 유지하면 풀림
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int memory[101];
int cost[101];
int dp[101][10001];

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> memory[i];
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
}

void solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 10001; j++)
        {
            if(j >= cost[i])
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]] + memory[i]);
            else
                dp[i][j] = dp[i-1][j];


            if(dp[i][j] >= m)
                break;
        }
    }
    
    for (int i = 0; i < 10001; i++)
    {
        if(dp[n][i] >= m)
        {
            cout << i;
            break;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();
    solution();
    return 0;
}