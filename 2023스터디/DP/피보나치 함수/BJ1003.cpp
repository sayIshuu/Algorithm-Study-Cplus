#include <iostream>
using namespace std;

int t,n;

typedef struct
{
    long long a;
    long long b;
}s;

s arr[41] = {{1,0},{0,1},};

void setting()
{
    for (int i = 2; i < 41; i++)
    {
        arr[i].a = arr[i-1].a + arr[i-2].a;
        arr[i].b = arr[i-1].b + arr[i-2].b;
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    setting();

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << arr[n].a << ' ' << arr[n].b << '\n';
    }
    
    return 0;
}