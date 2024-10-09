#include <iostream>
using namespace std;

int main(void)
{
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;

        int coinType[n+1] = {0,};
        for (int i = 1; i <= n; i++)
            cin >> coinType[i];
        
        int finalMoney; cin >> finalMoney;
        
        int coin[n+1][10001] = {1,0,};

        for (int c = 1; c <= n; c++)
        {
            for (int m = 0; m <= finalMoney; m++)
            {
                if(coinType[c] > m)
                    coin[c][m] = coin[c-1][m];
                else{
                    for (int i = 0; i <= m/coinType[c]; i++)
                        coin[c][m] += coin[c-1][m - (coinType[c]*i)];
                }
            }    
        }

        cout << coin[n][finalMoney] << '\n';
    }

    return 0;
}