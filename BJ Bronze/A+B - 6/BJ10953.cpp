#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    while (n--)
    {
        int a,b;
        char c;
        cin >> a >> c >> b;

        cout << a+b << '\n';
    }
    

    return 0;
}