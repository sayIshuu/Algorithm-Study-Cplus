#include <iostream>
#include <queue>
using namespace std;

int n;
int sharkSize = 2;
int eatenFish;

int sea[21][21];
bool visited[21][21];
int sumTime;

int lastTime;
int lastX;
int lastY;
bool isEaten;
int minX = 999;
int minY = 999;

typedef struct
{
     int x, y, time;
}pos;
queue<pos> q;
int dx[] = {-1,0,0,1}; //순서 중요하다!
int dy[] = {0,-1,1,0};

void visitedClear()
{
     for (int i = 0; i < n; i++){
          for (int j = 0; j < n; j++)
               visited[i][j] = false;
     }
     //cout << "clear" << endl;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     for (int i = 0; i < n; i++){
          for (int j = 0; j < n; j++){
               cin >> sea[i][j];
               if(sea[i][j] == 9){
                    sea[i][j] = 0;
                    lastX = i;
                    lastY = j;
               }
          }
     }

     while(true)
     {
          q = queue<pos>();
          visitedClear();
          sumTime += lastTime;
          lastTime == 0;
          q.push({lastX,lastY,0});
          visited[lastX][lastY] = true;
          isEaten = false;
          minX = 999;
          minY = 999;
          
          while(!q.empty())
          {
               int x = q.front().x;
               int y = q.front().y;
               int time = q.front().time;
               q.pop();

               if((isEaten && lastTime == time) || (isEaten && time == 999)){
                    sea[lastX][lastY] = 0;
                    //cout << lastX << ' ' << lastY << endl;
                    q.push({0,0,0});
                    eatenFish++;
                    if(eatenFish == sharkSize){
                         sharkSize++;
                         eatenFish = 0;
                    }
                    break;
               }

               for (int i = 0; i < 4; i++)
               {
                    int nx = x+dx[i];
                    int ny = y+dy[i];

                    if(nx < 0 || ny < 0 || nx > n-1 || ny > n-1)
                         continue;

                    if(visited[nx][ny])
                         continue;

                    if(sea[nx][ny] == 0){
                         q.push({nx,ny,time+1});
                         visited[nx][ny] = true;
                         continue;
                    }
                    else if(sea[nx][ny] > sharkSize)
                         continue;
                    else if(sea[nx][ny] == sharkSize){
                         q.push({nx,ny,time+1});
                         visited[nx][ny] = true;
                         continue;
                    }
                    else if(sea[nx][ny] < sharkSize){
                         //cout << nx << ' ' << ny << 'a' << endl;
                         if(minX > nx){
                              lastX = nx;
                              lastY = ny;
                              lastTime = time+1;
                              minX = nx;
                              minY = ny;
                         }
                         else if(minX == nx){
                              if(minY > ny){
                                   lastX = nx;
                                   lastY = ny;
                                   lastTime = time+1;
                                   minY = ny;
                              }
                         }
                         visited[nx][ny] = true;
                         isEaten = true;
                         q.push({0,0,999});
                         continue;
                    }
               }
          }

          if(q.empty() && !isEaten)
               break;
     }

     cout << sumTime;

     return 0;
}