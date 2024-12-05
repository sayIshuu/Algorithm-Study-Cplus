#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int>> pq;
int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     int n; cin >> n;
     while(n--){
          int a, b;
          cin >> a >> b;
          pq.push({-a,-b});
     }

     priority_queue<int> last;
     last.push(0);

     while(!pq.empty()){
          int s = -pq.top().first;
          int e = -pq.top().second;
          pq.pop();
          
          //시작 기준으로 집어넣어야했던 이유!!!!
          if(s >= -last.top())
               last.pop();

          last.push(-e);
     }

     cout << last.size();
     return 0;
}