#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;
int arr[21][1001]; // j명을 모집하는 최소 비용

int main(void) {
     int goal, n;
     cin >> goal >> n;

     for (int i = 0; i <= goal; i++)
          arr[0][i] = INF;

     for (int i = 1; i <= n; i++)
     {
          int cost, people; cin >> cost >> people;
          for (int j = 1; j <= goal; j++)
          {
               if(j-people < 1)
                    arr[i][j] = min(arr[i-1][j], cost);
               else
                    arr[i][j] = min(arr[i-1][j], cost + arr[i][j-people]);
          }
     }
     
     cout << arr[n][goal];
     return 0;
}
