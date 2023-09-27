#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    double w,h;
    cin >> w >> h;

    cout << fixed;
    cout.precision(1);
    cout << w*h*0.5 << endl;

    return 0;
}