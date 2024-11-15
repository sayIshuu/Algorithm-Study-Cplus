#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string A,B;
int arr[1002][1002];

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> A >> B;
     A = '0'+A;
     B = '0'+B;

     for (int i = 1; i < B.size(); i++){
          for (int j = 1; j < A.size(); j++){
               if(B[i] == A[j])
                    //하 이거 이해안되네
                    arr[i][j] = arr[i-1][j-1]+1;
               else
                    arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
          }
     }
     cout << arr[B.size()-1][A.size()-1];

     return 0;
}