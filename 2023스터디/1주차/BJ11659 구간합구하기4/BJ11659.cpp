#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n,m; cin >> n >> m;

    int arr[n];
    long sum[n+1] = {}; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[i+1] = sum[i] + arr[i];
    }

    while (m--)
    {
        int a,b; cin >> a >> b;
        cout << sum[b] - sum[a-1] << '\n';
    }
    
    
    return 0;
}