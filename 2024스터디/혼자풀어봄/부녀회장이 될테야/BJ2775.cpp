#include <iostream>
using namespace std;

int n,k,t;
int arr[15][15];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> t;
     for (int i = 1; i < 15; i++){
          arr[0][i] = i;
          arr[i][1] = 1;
     }
     
     for (int i = 1; i < 15; i++){
          for (int ii = 2; ii < 15; ii++)
               arr[i][ii] = arr[i][ii-1] + arr[i-1][ii];
     }
     
     while (t--)
     {
          cin >> k >> n;
          cout << arr[k][n] << '\n';
     }

     return 0;
}