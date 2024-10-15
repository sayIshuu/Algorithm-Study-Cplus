#include <iostream>
#include <deque>
using namespace std;

int n,k;
deque<pair<int,int>> dq;
int ans[100002];
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> k;
     dq.push_front({0,n});
     for (int i = 0; i < 100001; i++)   ans[i] = 999999;
     ans[n] = 0;

     while (!dq.empty())
     {
          int spendedTime = dq.front().first;
          int currentIndex = dq.front().second;
          dq.pop_front();

          if(currentIndex == k){
               cout << spendedTime;
               break;
          }

          if(currentIndex*2 <= 100000 && ans[currentIndex*2] > spendedTime){
               dq.push_front({spendedTime, currentIndex*2});
               ans[currentIndex*2] = spendedTime;
          }
          if(currentIndex+1 <= 100000 && ans[currentIndex+1] > spendedTime+1){
               dq.push_back({spendedTime+1, currentIndex+1});
               ans[currentIndex+1] = spendedTime+1;
          }
          if(currentIndex-1 >= 0 && ans[currentIndex-1] > spendedTime+1){
               dq.push_back({spendedTime+1, currentIndex-1});
               ans[currentIndex-1] = spendedTime+1;
          }
     }
     

     return 0;
}