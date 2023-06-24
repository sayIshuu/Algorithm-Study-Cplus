#include <iostream>
using namespace std;

int arr[101][101];

int main(void)
{
    int n, m;   cin >>n >>m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a; cin >> a;
            arr[i][j] += a;
        }    
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int a; cin >> a;
            arr[i][j] += a;
        }    
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << ' ';
        }    
        cout << '\n';
    }
    
    

    return 0;
}