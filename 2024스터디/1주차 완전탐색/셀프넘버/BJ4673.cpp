#include <iostream>
using namespace std;

bool isChecked[10001] = {true};

void nextNumber(int n)
{
     if(n>10000) return;

     int sum = n;
    
     while (n > 0) 
     {
        sum += n % 10;
        n /= 10;
     }
     if(isChecked[sum]) return;
     isChecked[sum] = true;
     nextNumber(sum);

     return;
}


void solve()
{
    for (int i = 1; i < 10001; i++)
    {
          if(!isChecked[i])
          {
               cout << i << '\n';
               isChecked[i] = true;

               nextNumber(i);
          }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

     solve();
     
     return 0;
}