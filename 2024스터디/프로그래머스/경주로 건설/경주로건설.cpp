#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct
{
     int px,py;
     int x,y;
     int value;
}node;

int arr[26][26];
int value[26][26];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
queue<node> q;

int solution(vector<vector<int>> board) {
     int answer = 0;

     int n = board.size();

     for (int i = 0; i < n; i++)
          for (int ii = 0; ii < n; ii++){
               arr[i][ii] = board[i][ii];
               value[i][ii] = 9999999;
          }

     q.push({0,0,0,0,0});
     value[0][0] = 0;

     while(!q.empty())
     {
          int px = q.front().px;
          int py = q.front().py;
          int x = q.front().x;
          int y = q.front().y;
          int v = q.front().value;
          q.pop();

          for (int i = 0; i < 4; i++)
          {
               int nx = x+dx[i];
               int ny = y+dy[i];
               int tempValue = v;

               if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
               if(arr[nx][ny] == 1) continue;

               if(nx != px && ny != py)
                    tempValue += 600;
               else
                    tempValue += 100;
               
               if(tempValue <= value[nx][ny]+500){
                    q.push({x,y,nx,ny,tempValue});
                    value[nx][ny] = min(tempValue,value[nx][ny]);
               }
          }
     }
     answer = value[n-1][n-1];
     return answer;
}