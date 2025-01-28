#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,c;
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> c;
     vector<int> arr(n);
     for(int i = 0; i<n; i++)
          cin >> arr[i];
     sort(arr.begin(), arr.end());

     //구해야하는 값은 거리. 거리의 최선값을 찾아간다.
     int start = 1;
     int end = arr[n-1] - arr[0];

     int ans = 0;
     while(start <= end){
          int mid = (start + end) / 2;
          int cnt = 1;
          int prev = arr[0];

          //거리와 인덱스는 별개개
          for(int i = 1; i < n; i++){
               if(arr[i] - prev >= mid){
                    cnt++;
                    prev = arr[i];
               }
          }

          if(cnt >= c){
               ans = mid;
               start = mid + 1;
          }
          else
               end = mid - 1;
     }
     cout << ans;
     return 0;
}