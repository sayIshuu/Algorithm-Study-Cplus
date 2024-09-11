#include <iostream>
using namespace std;

int n;
long long s;
int ans = 999999;
int arr[100001];
long long prefixSum[100001];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> s;
     cin >> arr[0]; 
     prefixSum[0] = arr[0];

     for (int i = 1; i < n; i++)
     {
          cin >> arr[i];
          prefixSum[i] = prefixSum[i-1]+arr[i];
     }
     
     int start=0, end=0;
     for (; start < n; start++)
     {
          long long temp;
          if(start == 0)
               temp = prefixSum[end];
          else
               temp = prefixSum[end] - prefixSum[start-1];

          if(temp >= s){
               if(end-start+1 < ans)
                    ans = end-start+1;
               
               if(ans == 1){
                    cout << ans;
                    return 0;
               }
          }
          else if(end < n-1){
               end++;
               start--;
          }
     }
     
     if(ans == 999999)
          cout << 0;
     else
          cout << ans;

     return 0;
}