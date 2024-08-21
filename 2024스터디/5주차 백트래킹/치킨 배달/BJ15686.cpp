#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int n, m;

int distance(int x1, int y1, int x2, int y2)
{
     return abs(x1 - x2) + abs(y1 - y2);
}

typedef struct
{
     int x; int y;
}location;

vector<location> house;
vector<location> chicken;
int chickenDistance[14];
int chickenNum;
int houseNum;

void input()
{
     cin >> n >> m;
     for (int i = 0; i < n; i++)
     {
          for (int j = 0; j < n; j++)
          {
               int a; cin >> a;
               if(a==1)
                    house.push_back({i,j});
               else if (a==2)
                    chicken.push_back({i,j});
          }
     }
     chickenNum = chicken.size();
     houseNum = house.size();
}

vector<int> temp;
int ansSum = 9999999;
void backtracking(int check)
{
     if(temp.size() == m)
     {
          int tempSum = 0;
          for (int i = 0; i < houseNum; i++)
          {
               int tempDistance = 9999999;
               for (int j = 0; j < m; j++)
               {    
                    int d = distance(house[i].x, house[i].y, chicken[temp[j]].x, chicken[temp[j]].y);
                    if(d < tempDistance) tempDistance = d;
               }
               tempSum += tempDistance;
          }
          if(tempSum < ansSum) ansSum = tempSum;
          return;
     }
     if(check >= chickenNum) return;
     for (int i = check; i < chickenNum; i++)
     {
          temp.push_back(i);
          backtracking(i+1);
          temp.pop_back();
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     input();
     
     backtracking(0);
     cout << ansSum;

     return 0;
}