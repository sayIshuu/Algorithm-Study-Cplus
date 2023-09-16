#include <iostream>
#define E 1000000007
using namespace std;

int n;
int a[500101];
long long sum[500101];
long long ans[500101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        ans[i] = ans[i-1]%E + (sum[i-1]*a[i])%E;
    }

    cout << ans[n]%E;

    return 0;
}