#include <iostream>
#include <queue>
using namespace std;

int cnt[1000001];
int from[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    if(n==1)
    {
        cout << 0 << '\n' << 1;
        return 0;
    }


    for (int i = 1; i <= n; i++)
    {
        if(i+1 <= n && (cnt[i+1] == 0 || cnt[i+1] > cnt[i]+1))
        {
            cnt[i+1] = cnt[i]+1;
            from[i+1] = i;
        }

        if(i*2 <= n && (cnt[i*2] == 0 || cnt[i*2] > cnt[i]+1))
        {
            cnt[i*2] = cnt[i]+1;
            from[i*2] = i;
        }

        if(i*3 <= n && (cnt[i*3] == 0 || cnt[i*3] > cnt[i]+1))
        {
            cnt[i*3] = cnt[i]+1;
            from[i*3] = i;
        }
    }

    cout << cnt[n] << '\n';
    cout << n << ' ';
    while(true)
    {
        cout << from[n] << ' ';
        n = from[n];

        if(n == 1)
            return 0;
    }
    
    return 0;
}