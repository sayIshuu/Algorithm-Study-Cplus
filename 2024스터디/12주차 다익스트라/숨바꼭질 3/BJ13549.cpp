#include <iostream>
#include <queue>
using namespace std;

int n,k;
priority_queue<pair<int,int>> pq; //<ÃÊ, ÀÎµ¦½º>
int ans[100002];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> k;
     pq.push({0,n});
     for (int i = 0; i < 100001; i++)   ans[i] = 999999;
     ans[n] = 0;

     while (!pq.empty())
     {
          int spendedTime = -pq.top().first;
          int currentIndex = pq.top().second;
          pq.pop();

          if(currentIndex == k){
               cout << spendedTime;
               break;
          }

          if(currentIndex*2 <= 100000 && ans[currentIndex*2] > spendedTime){
               pq.push({-spendedTime, currentIndex*2});
               ans[currentIndex*2] = spendedTime;
          }
          if(currentIndex+1 <= 100000 && ans[currentIndex+1] > spendedTime+1){
               pq.push({-spendedTime-1, currentIndex+1});
               ans[currentIndex+1] = spendedTime+1;
          }
          if(currentIndex-1 >= 0 && ans[currentIndex-1] > spendedTime+1){
               pq.push({-spendedTime-1, currentIndex-1});
               ans[currentIndex-1] = spendedTime+1;
          }
     }
     

     return 0;
}