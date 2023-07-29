#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int arr[100001];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr,arr+n);

    int f = 0;  int e = n-1;
    int min = 2000000000;
    int ansf = 0;   int anse = 0;

    //탐색의 포인트는 브루트포스가 아니라, 포인터를 옮기는 정답이 정해져 잇다는점
    //합이 음수냐, 양수냐에 따라 f,e포인터중 뭘 옮겨야되는지가 다르다

    while(f<e)
    {
        int sum = arr[f]+arr[e];
        if(abs(sum) < min)
        {
            min = abs(sum);
            ansf = arr[f];
            anse = arr[e];
        }

        if(sum > 0)
            e--;
        else
            f++;
    }

    cout << ansf << ' ' << anse;
    
    return 0;
}