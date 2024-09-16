#include <iostream>
#include <algorithm>
using namespace std;

int n;
int rgb[1001][3];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     for (int i = 0; i < n; i++)
     {
          cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
     }
     
     for (int i = 1; i < n; i++)
     {
          rgb[i][0] += min(rgb[i-1][1], rgb[i-1][2]);
          rgb[i][1] += min(rgb[i-1][0], rgb[i-1][2]);
          rgb[i][2] += min(rgb[i-1][0], rgb[i-1][1]);
     }
     
     cout << min({rgb[n-1][0], rgb[n-1][1], rgb[n-1][2]});

     return 0;
}