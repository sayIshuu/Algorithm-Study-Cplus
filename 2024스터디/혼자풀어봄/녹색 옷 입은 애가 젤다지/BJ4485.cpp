#include <iostream>
#include <queue>
#define INF 999999
using namespace std;

int n;

int miro[127][127];

// 방문체크 대신
int oneToN[127][127];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int cnt;

priority_queue<pair<int,pair<int,int>>> pq; //가중치, x,y

void clear()
{
     pq = priority_queue<pair<int,pair<int,int>>>();
     for (int i = 0; i < n; i++){
          for (int ii = 0; ii < n; ii++){
               miro[i][ii] = 0;
               oneToN[i][ii] = 0;
          }
     }
}


int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     while (true){
          cin >> n;
          cnt++;
          if(n==0) break;

          for (int i = 0; i < n; i++){
               for (int ii = 0; ii < n; ii++){
                    cin >> miro[i][ii];
                    oneToN[i][ii] = INF;
               }
          }
          pq.push({-miro[0][0],{0,0}});
          oneToN[0][0] = miro[0][0];

          while(!pq.empty()){
               int x = pq.top().second.first;
               int y = pq.top().second.second;
               int sumOfValue = -pq.top().first;
               pq.pop();

               if(x==n-1 && y==n-1){
                    cout << "Problem " << cnt << ": " << sumOfValue << '\n';
                    break;
               }

               for (int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    int nextSum = sumOfValue + miro[nx][ny];

                    if(nx > n-1 || nx < 0 || ny > n-1 || ny < 0) continue;

                    if(nextSum < oneToN[nx][ny]){
                         oneToN[nx][ny] = nextSum;
                         pq.push({-nextSum,{nx,ny}});
                    }
               }
          }

          clear();
     }
     

     return 0;
}