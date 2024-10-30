#include <iostream>
using namespace std;

int n;
int arr[101][101];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     for (int i = 1; i <= n; i++)
          for (int j = 1; j <= n; j++)
               cin >> arr[i][j];
     
     for (int k = 1; k <= n; k++)
          for (int i = 1; i <= n; i++)
               for (int j = 1; j <= n; j++)
                    // k한테 올수 있는가 k에서 갈수 있는가
                    if(arr[i][k]==1 && arr[k][j]==1)
                         arr[i][j] = 1;

     for (int i = 1; i <= n; i++){
          for (int j = 1; j <= n; j++)
               cout << arr[i][j] << ' ';
          cout << '\n';
     }
     return 0;
}