#include <iostream>
using namespace std;

int n;
int arr[20];
int ans[2000001];

void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
}

void sos(int index, int sum)
{
    if(index == n)
    {
        ans[sum] = 1;
        return;
    }

    sos(index+1, sum+arr[index]);
    sos(index+1, sum);
}

void solve()
{
    sos(0, 0);
    for(int i=1; i<2000001; i++)
    {
        if(ans[i] == 0)
        {
            cout << i;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return 0;
}
