//BJ11021 A+B -7 ��5
#include <iostream>
using namespace std;

int main(void)
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int a,b;
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << a+b << endl;
    }

    return 0;
}