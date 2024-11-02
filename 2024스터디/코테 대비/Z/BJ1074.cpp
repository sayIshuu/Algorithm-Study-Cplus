#include <iostream>
#include <algorithm>
using namespace std;

long long n,r,c;
//int arr[32769][32769];
long long dan = 1;
long long ans;

void plusAns()
{
     if(r >= dan && c >= dan){
          ans += dan*dan*3;
          r -= dan;
          c -= dan;
     }
     else if(r >= dan){
          ans += dan*dan*2;
          r -= dan;
     }
     else if(c >= dan){
          ans += dan*dan*1;
          c -= dan;
     }
}

void findDan(long long maxone)
{
     //dan은 2의 지수
     if(maxone < 2)
          dan = 1;
     else if(maxone < 4)
          dan = 2;
     else if(maxone < 8)
          dan = 4;
     else if(maxone < 16)
          dan = 8;
     else if(maxone < 32)
          dan = 16;
     else if(maxone < 64)
          dan = 32;
     else if(maxone < 128)
          dan = 64;
     else if(maxone < 256)
          dan = 128;
     else if(maxone < 512)
          dan = 256;
     else if(maxone < 1024)
          dan = 512;
     else if(maxone < 2048)
          dan = 1024;
     else if(maxone < 4096)
          dan = 2048;
     else if(maxone < 8192)
          dan = 4096;
     else if(maxone < 8192*2)
          dan = 8192;
     else if(maxone < 8192*4)
          dan = 8192*2;
     else if(maxone < 8192*8)
          dan = 8192*4;
}


int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> r >> c;

     while (true)
     {
          long long maxone = max(r,c);
          findDan(maxone);
          plusAns();
          if(dan == 1){
               cout << ans;
               break;
          }
     }

     return 0;
}