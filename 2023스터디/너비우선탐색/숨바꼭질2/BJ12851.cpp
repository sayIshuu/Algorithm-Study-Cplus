#include <iostream>
#include <queue>
using namespace std;

int arr[100001];

typedef struct
{
    int curPos;
    int time;
}node;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;

    if(n==k) { cout << 0 << '\n' << 1; return 0; }

    int cnt = 0;
    for (int i = 0; i < 100001; i++)
        arr[i] = 1000000;

    queue<node> q;
    q.push({n,0});
    arr[n] = 0;
    while (!q.empty())
    {
        int x = q.front().curPos;
        int time = q.front().time;
        q.pop();

        if(x == k && arr[x] >= time)
        {
            cnt++;
            arr[x] = time;
            continue;
        }

        if(x+1 <= 100000)
        {
            if(arr[x+1] > time)
            {
                arr[x+1] = time+1;
                q.push({x+1, time+1});
            }
        }
        if(x-1 >= 0)
        {
            if(arr[x-1] > time)
            {
                arr[x-1] = time+1;
                q.push({x-1, time+1});
            }
        }
        if(x*2 <= 100000)
        {
            if(arr[x*2] > time)
            {
                arr[x*2] = time+1;
                q.push({x*2, time+1});
            }
        }
    }

    cout << arr[k] << '\n';
    cout << cnt;

    return 0;
}