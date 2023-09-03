#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int sum;
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void solution()
{
    sort(arr, arr+n);

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        sum += temp;
        sum += arr[i];
        temp += arr[i];
    }

    cout << sum;
}

void solve()
{
    input();
    solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}