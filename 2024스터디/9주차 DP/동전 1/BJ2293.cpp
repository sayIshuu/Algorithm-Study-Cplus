#include <iostream>
using namespace std;

int n,k;
int arr[10003];
int brr[10003];
int coins[103];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> k;
     arr[0] = 1;
     for (int i = 1; i <= n; i++)
     {
          cin >> coins[i];
     }


     for (int i = 1; i <= n; i++)
     {
          for (int j = 0; j <= k; j++)
          {
               if(i%2 == 0){
                    if(coins[i] > k)
                         arr[j] = brr[j];
                    else if(j<coins[i])
                         arr[j] = brr[j];
                    else{
                         arr[j] = brr[j] + arr[j-coins[i]];
                    }
               }
               else{
                    if(coins[i] > k)
                         brr[j] = arr[j];
                    else if(j<coins[i])
                         brr[j] = arr[j];
                    else{
                         brr[j] = arr[j] + brr[j-coins[i]];
                    }
               }
          }
     }
     
     if(n%2 == 0)
     {
          cout << arr[k];
     }
     else
          cout << brr[k];
     

     return 0;
}