#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[8];
bool check[8];
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int ans;
int sum;
int cnt;
int temp;
void back()
{
    if(cnt == n)
    {
        ans = max(ans,sum);
        return;
    }
    int t = temp;
    for (int i = 0; i < n; i++)
    {
        if(!check[i])
        {
            check[i] = true;
            sum += abs(t - arr[i]);
            cnt++;
            temp = arr[i];
            back();
            check[i] = false;
            sum -= abs(t - arr[i]);
            cnt--;
        }
    }
}


void solve()
{
    input();
    for (int i = 0; i < n; i++)
    {
        temp = arr[i];
        check[i] = true;
        cnt++;
        back();
        check[i] = false;
        cnt--;
    }

    cout << ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}