#include <iostream>
#include <stack>
using namespace std;

typedef struct
{
    int index;
    int value;
}NODE;

NODE arr[1000001];
stack<NODE> s;
int ans[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    for (int i = 0; i < n; i++)
    {
        arr[i].index = i;
        cin >> arr[i].value;
    }

    for (int i = 0; i < n; i++)
    {
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }

        if(arr[i].value > s.top().value)
        {
            ans[s.top().index] = arr[i].value;
            s.pop();
            i--;
            continue;
        }
        else
            s.push(arr[i]);
    }
    int a = s.size();
    for (int i = 0; i < a; i++)
    {
        ans[s.top().index] = -1;
        s.pop();
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    

    return 0;
}