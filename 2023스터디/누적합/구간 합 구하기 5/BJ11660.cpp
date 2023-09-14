#include <iostream>
using namespace std;

int n,m;
int arr[1050][1050];

long long sum[1050][1050];

void solution(int a, int b, int x, int y)
{
    if(a == x)
    {
        cout << sum[x][y] - sum[a][b-1] << '\n';
    }
    else if (a == 1){
        cout << sum[x][y] - sum[a][b-1] << '\n';
    }
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
            sum[i][j] = arr[i][j] + sum[i][j-1];
        }
        sum[i+1][0] = sum[i][n];
    }
    
    for (int i = 0; i < m; i++)
    {
        int a,b,x,y;
        cin >> a >> b >> x >> y;

        solution(a,b,x,y);
    }


    return 0;
}