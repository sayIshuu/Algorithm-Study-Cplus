#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n;
int l,r;

int day;
bool check = true;
int tempSum = 0;
int newPop = 0;

int arr[101][101];
bool visited[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

queue<pair<int,int>> q;
queue<pair<int,int>> store;
void bfs()
{
     while(!q.empty())
     {
          int x = q.front().first;
          int y = q.front().second;
          store.push({x,y});
          tempSum += arr[x][y];
          q.pop();

          for(int i = 0; i < 4; i++)
          {
               int nx = x + dx[i];
               int ny = y + dy[i];

               if(nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;
               if(!visited[nx][ny])
               {
                    int diff = abs(arr[x][y] - arr[nx][ny]);
                    if(diff >= l && diff <= r)
                    {
                         visited[nx][ny] = true;
                         q.push({nx,ny});
                    }
               }
          }
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> l >> r;
     for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     
     while(check)
     {
          tempSum = 0;
          check = false;
          day++;
          for(int i = 0; i < n; i++)
               for(int j = 0; j < n; j++)
                    visited[i][j] = false;
          q = queue<pair<int,int>>();
          store = queue<pair<int,int>>();

          for(int i = 0; i<n; i++)
          {
               for(int j = 0; j<n; j++)
               {
                    if(!visited[i][j])
                    {
                         visited[i][j] = true;
                         q.push({i,j});
                         bfs();
                         newPop = tempSum/store.size();

                         if(store.size() > 1)
                              check = true;
                         while(!store.empty())
                         {
                              int x = store.front().first;
                              int y = store.front().second;
                              store.pop();
                              arr[x][y] = newPop;
                         }

                         newPop = 0;
                         tempSum = 0;
                    }
               }
          }
     }

     cout << day-1;

     return 0;
}