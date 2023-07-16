#include <iostream>
#include <queue>
using namespace std;

//너비우선탐색처럼 풀자
int arr[1000001];
queue<int> q;
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    if(n==1)
    {
        cout << 0;
        return 0;
    }
    q.push(1);
    //arr[1] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();

        if(x+1 == n || x*2 == n || x*3 == n)
        {
            cout << arr[x]+1;
            return 0;
        }

        if(x+1 <= n && arr[x+1] == 0){
            arr[x+1] = arr[x]+1;
            q.push(x+1);
        }
        if(x*2 <= n && arr[x*2] == 0){
            arr[x*2] = arr[x]+1;
            q.push(x*2);
        }
        if(x*3 <= n && arr[x*3] == 0){
            arr[x*3] = arr[x]+1;
            q.push(x*3);    
        }
    }
    return 0;
}