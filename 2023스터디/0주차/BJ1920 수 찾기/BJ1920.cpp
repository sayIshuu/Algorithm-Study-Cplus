#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[100001];
int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);

    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a;  cin >> a;
        if(!binary_search(arr,arr+n,a)){
            cout << 0 << '\n';
        }
        else
            cout << 1 << '\n';
    }
    
    
    return 0;
}