#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt, tempEndTime;
typedef struct BJ1931
{
     int start;
     int end;
}time;
time arr[100002];

void input()
{
     cin >> n;
     for (int i = 0; i < n; i++)
     {
          cin >> arr[i].start >> arr[i].end;
     }
}

//true 반환되면 ab순서가 안바뀜
bool compare(time a, time b)
{
     if(a.end == b.end)
          return a.start < b.start; //그냥 부등호 방향대로 작은게 앞으로 오겠다는 뜻
     else
          return a.end < b.end;
}
void solution()
{
     for (int i = 0; i < n; i++)
     {
          if(tempEndTime <= arr[i].start)
          {
               tempEndTime = arr[i].end;
               cnt++;
          }
     }
     cout << cnt;
}

void solve()
{
     input();
     sort(arr,arr+n,compare);
     solution();
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}