#include <iostream>
#include <algorithm>
using namespace std;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long a,b;
    cin >> a >> b;

    cout << abs(a-b);
    return 0;
}