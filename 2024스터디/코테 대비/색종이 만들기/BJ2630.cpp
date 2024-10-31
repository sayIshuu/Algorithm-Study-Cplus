#include <iostream>
#include <vector>
using namespace std;
//확인 -> 분할의 재귀 구조. 출력은 파랑 하양 갯수. 갯수는 전역으로 선언후 단순 리턴
//n범위가 적음.

int blue;
int white;
int n;
vector<vector<int>> v;

void find_division(int _x, int _y, int _n)
{
     bool succed = true;
     int start = v[_x][_y];
     for (int i = _x; i < _x+_n; i++)
     {
          for (int ii = _y; ii < _y+_n; ii++)
               if(v[i][ii] != start){
                    succed = false;
                    _n /= 2;
                    find_division(_x, _y, _n);
                    find_division(_x+_n, _y, _n);
                    find_division(_x, _y+_n, _n);
                    find_division(_x+_n, _y+_n, _n);
                    return;
               }
     }

     if(succed){
          if(start == 1)
               blue++;
          else
               white++;
          return;
     }
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     v.resize(n,vector<int>(n));
     for (int i = 0; i < n; i++){
          for (int ii = 0; ii < n; ii++)
               cin >> v[i][ii];
     }
     
     find_division(0,0,n);
     cout << white << '\n' << blue;
     return 0;
}