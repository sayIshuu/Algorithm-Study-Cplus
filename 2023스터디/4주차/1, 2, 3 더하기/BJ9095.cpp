#include <iostream>
using namespace std;

int arr[12] = {0,1,2,4,};
int main(void)
{
    for (int i = 4; i < 12; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        cout << arr[n] << '\n';
    }
    return 0;
}