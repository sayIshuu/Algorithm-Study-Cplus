#include <iostream>
using namespace std;

int n,m;
int arr[1050][1050];

long long sum[1050][1050];

void solution(int a, int b, int x, int y)
{
    cout << sum[x][y] - sum[a-1][y] - sum[x][b-1] + sum[a-1][b-1] << '\n';
}

void get_sum(int i, int j)
{
    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + arr[i][j];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
            get_sum(i, j);
        }
    }
    

    for (int i = 0; i < m; i++)
    {
        int a,b,x,y;
        cin >> a >> b >> x >> y;

        solution(a,b,x,y);
    }


    return 0;
}