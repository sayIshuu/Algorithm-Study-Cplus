#include <iostream>
using namespace std;

int n,h;
int suk[500001];
int jong[500001];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> h;
     for (int i = 0; i < n; i++)
     {
          int temp; cin >> temp;
          if(i%2 == 0){
               jong[h-temp]++;
          }
          else{
               suk[temp-1]++;
          }
     }
     
     for (int i = 1; i < h; i++)
     {
          jong[i] += jong[i-1];
          suk[h-i-1] += suk[h-i];
     }
     
     int ans = 999999;
     for (int i = 0; i < h; i++)
     {
          suk[i] += jong[i];
          if(suk[i] < ans)
               ans = suk[i];
     }
     
     cout << ans << ' ';

     int num = 0;
     for (int i = 0; i < h; i++)
     {
          if(suk[i] == ans)
               num++;
     }
     
     cout << num;

     return 0;
}