#include <iostream>
#include <algorithm>
using namespace std;

//마지막 인덱스에 최종값이 어떻게 들어갈까가 문제풀이 쟁점
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