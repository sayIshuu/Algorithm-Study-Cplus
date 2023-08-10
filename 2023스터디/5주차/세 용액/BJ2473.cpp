#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long arr[5001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    long long min = 3000000000;
    int ansf = 0;   int anse = 0;   int ansm = 0;

    //탐색의 포인트는 브루트포스가 아니라, 포인터를 옮기는 정답이 정해져 잇다는점
    //합이 음수냐, 양수냐에 따라 f,e포인터중 뭘 옮겨야되는지가 다르다
    
    for (int f = 0; f < n-1; f++)
    {
        int m = f+1; int e = n-1;
        while(m<e)
        {
            long long sum = arr[m]+arr[e]+arr[f];
            if(abs(sum) < min)
            {
                min = abs(sum);
                ansf = arr[f];
                anse = arr[e];
                ansm = arr[m];
            }

            if(sum > 0)
                e--;
            else
                m++;
        }
    }
    

    cout << ansf << ' ' << ansm << ' ' << anse;

    return 0;
}


//해결법 : 기준하나잡고 나머지 두용액