#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];
int maxP[1001];

int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
        maxP[i] = p[i];

        for (int j = 1; j <= i/2; j++)
        {
            maxP[i] = max(maxP[i], maxP[j] + maxP[i-j]);
        }
    }
    cout << maxP[n];
    return 0;
}