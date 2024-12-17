#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][10001];

int main(void)
{
     int n; int t;
     cin >> n >> t;
     
     for(int i=1; i<=n; i++){
          int k, s;
          cin >> k >> s;
          for(int j=0; j<=t; j++){
               if(j < k)
                    arr[i][j] = arr[i-1][j];
               else
                    arr[i][j] = max(arr[i-1][j], arr[i-1][j-k] + s);
          }
     }

     cout << arr[n][t];
     return 0;
}