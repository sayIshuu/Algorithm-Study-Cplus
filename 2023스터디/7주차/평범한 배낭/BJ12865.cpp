#include <iostream>
using namespace std;

int bag[102][100020];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;

    int stuff[n][2];
    for (int i = 0; i < n; i++)
        cin >> stuff[i][0] >> stuff[i][1];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if(stuff[i-1][0] <= j)
            {
                //안넣은게 더 클때
                if(bag[i-1][j] > stuff[i-1][1]+bag[i-1][j-stuff[i-1][0]])
                    bag[i][j] = bag[i-1][j];
                else
                    bag[i][j] = stuff[i-1][1]+bag[i-1][j-stuff[i-1][0]];
            }
            else
                bag[i][j] = bag[i-1][j];
        }   
    }

    cout << bag[n][k];
    return 0;
}