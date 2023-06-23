#include <iostream>
using namespace std;

int main(void)
{
    int n; cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i < 100)
        {
            sum++;
            continue;
        }
        int bak = i/100;
        int ten = (i%100)/10;
        int il = (i%10);

        if(bak-ten == ten-il)
            sum++;
    }
    

    cout << sum;

    return 0;
}