#include <iostream>
#include <cmath>
using namespace std;

int t;
int x1, yy1, r1, x2, y2, r2;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> x1 >> yy1 >> r1 >> x2 >> y2 >> r2;
        if(x1==x2 && yy1==y2 )
        {
            if(r1==r2){
                cout << -1 << '\n';
                continue;
            }
            else{
                cout << 0 << '\n';
                continue;
            }
        }
        
        long long d = (x1-x2)*(x1-x2) + (yy1-y2)*(yy1-y2);
        long long r = (r1+r2)*(r1+r2);

        if(d>r)
            cout << 0 << '\n';
        else if(d==r)
            cout << 1 << '\n';
        else{
            if(sqrt(d)+r1 == r2 || sqrt(d)+r2 == r1)
                cout << 1 << '\n';
            else if(sqrt(d)+r1 < r2 || sqrt(d)+r2 < r1)
                cout << 0 << '\n';
            else if(sqrt(d)+r1 > r2 || sqrt(d)+r2 > r1)
                cout << 2 << '\n';
        }
    }

    return 0;
}