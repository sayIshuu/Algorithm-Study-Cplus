//BJ25304 영수증 브5
#include <iostream>
using namespace std;

int main(void)
{
    long x;
    int n;
    cin >> x;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a,b;
        cin >> a >> b;

        x -= a*b;
    }
    
    if(x==0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}