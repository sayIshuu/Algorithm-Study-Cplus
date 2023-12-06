//memory�� ������ õ������, cost�� ������ 100������� cost�� �迭 �����ϸ��
//�ᱹ �賶������ ���� ������� n�� �÷�����, ������ �� �����ϸ� Ǯ��
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