#include <iostream>
#include <algorithm>
using namespace std;

typedef struct BJ1946
{
     int first;
     int second;
}ranking;

int t,n;

bool compare(ranking a, ranking b)
{
     return a.first < b.first;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> t;
     for (int i = 0; i < t; i++)
     {
          cin >> n;
          ranking arr[n];
          for (int j = 0; j < n; j++)
          {
               cin >> arr[j].first >> arr[j].second;
          }
          sort(arr,arr+n,compare);

          int temp = arr[0].second;
          int cnt = 0;

          for (int j = 1; j < n; j++)
          {
               if(arr[j].second > temp)
                    cnt++;
               else
                    temp = arr[j].second;
          }
          
          cout << n-cnt << '\n';
     }

     return 0;
}