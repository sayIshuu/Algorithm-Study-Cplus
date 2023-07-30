#include <iostream>
#include <algorithm>
using namespace std;

int arr[500][500];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        if(i==0)
        {
            cin >> arr[0][0];
            continue;
        }
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
            if(j==0)
                arr[i][j] += arr[i-1][j];
            else if(j==i)
                arr[i][j] += arr[i-1][j-1];
            else
                arr[i][j] += max(arr[i-1][j], arr[i-1][j-1]);
        }
    }
    
    cout << *max_element(arr[n-1], arr[n-1]+n);
    return 0;
}