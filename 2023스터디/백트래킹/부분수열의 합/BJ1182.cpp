#include <iostream>
using namespace std;

int n, s;
int arr[20];

int ans = 0;

void input()
{
    cin >> n >> s;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
}

void sos(int index, int sum)
{
    if(index == n)
    {
        if(sum == s)
        {
            ans++;
        }
        return;
    }
    sos(index+1, sum+arr[index]);
    sos(index+1, sum);
}

void solve()
{
    sos(0, 0);
    if(s == 0)
    {
        ans--;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return 0;
}