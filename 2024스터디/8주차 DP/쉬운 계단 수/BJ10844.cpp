#include <iostream>
#define num 1000000000
using namespace std;

long long n, sum;
long long arr[101][10];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     for (int i = 1; i < 10; i++)
          arr[0][i] = 1;
     
     for (int i = 1; i < n; i++){
          for (int j = 0; j < 10; j++){
               if(j==0)
                    arr[i][j] = arr[i-1][j+1];
               else if(j==9)
                    arr[i][j] = arr[i-1][j-1];
               else
                    arr[i][j] = arr[i-1][j-1]%num + arr[i-1][j+1]%num;
          }
     }
     
     for (int i = 0; i < 10; i++)
          sum += (arr[n-1][i]%num);
     
     cout << sum%num;
     return 0;
}