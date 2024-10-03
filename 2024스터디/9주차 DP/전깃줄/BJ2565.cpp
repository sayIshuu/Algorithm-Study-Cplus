#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
typedef struct{
     int a;
     int b;
}line;
vector<line> v;
int ans[501];

bool compare(line a, line b)
{
     if(a.a < b.a)
          return true;
     else
          return false;
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n;
     int a,b;
     for (int i = 0; i < n; i++){
          cin >> a >> b;
          v.push_back({a,b});
     }
     sort(v.begin(), v.end(), compare);

     for (int i = 0; i < n; i++){
          int temp = 0;
          for (int j = 0; j <= i; j++){
               if(v[j].b < v[i].b && ans[j] > temp)
                    temp = ans[j];
          }
          ans[i] = temp+1;
     }

     cout << n-(*max_element(ans,ans+n));

     return 0;
}