#include <iostream>
#include <algorithm>
using namespace std;

int n; int k;
int arr[1001];

int main(void)
{
     cin >> n; cin >> k;
     for (int i = 0; i < n; i++)
          cin >> arr[i];
     sort(arr, arr+n);

     cout << arr[n-k];
     return 0;
}