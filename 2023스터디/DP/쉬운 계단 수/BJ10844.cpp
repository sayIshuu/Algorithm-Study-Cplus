#include <iostream>
#define num 1000000000
using namespace std;

long long map[101][10]; //0도 고려해야해서
long long ans[101] = {0,9,};
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 10; i++)
    {
        map[1][i] = 1;
    }
    

    int n; cin >> n;
    for (int i = 2; i < n+1; i++)
    {
        map[i][0] = map[i-1][1]%num;
        ans[i] += map[i][0]%num;
        for (int j = 1; j < 9; j++)
        {
            map[i][j] = map[i-1][j-1]%num + map[i-1][j+1]%num;
            ans[i] += map[i][j]%num;
        }
        map[i][9] = map[i-1][8]%num;
        ans[i] += map[i][9]%num;
    }
    
    cout << ans[n]%num;
    return 0;
}