#include <iostream>
using namespace std;

int arr[31][31];

int f(int _m, int _n)
{
    if(_n == 0 || _m == _n)
    {
        return 1;
    }
    if(arr[_m][_n] != 0)
    {
        return arr[_m][_n];
    }
    else{
        arr[_m][_n] = f(_m-1, _n-1) + f(_m-1,_n);
        return arr[_m][_n];
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n,m; cin >> t;
    while (t--)
    {
        cin >> n >>m;

        if(n==m)
        {
            cout << 1 << '\n';
            continue;
        }

        cout << f(m,n) << '\n';
    }
    return 0;
}