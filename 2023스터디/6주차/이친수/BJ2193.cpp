#include <iostream>
using namespace std;

long long arr[91] = {0,1,1,};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    if(n == 0 || n == 1 || n == 2)
    {
        cout << arr[n];
        return 0;
    }
    for (int i = 3; i < 10001; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
        if(i == n)
        {
            cout << arr[i];
            return 0;
        }
    }
    return 0;
}