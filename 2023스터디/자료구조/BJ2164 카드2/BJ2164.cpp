#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int main(void)
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        q.push(i+1);
    }

    while(q.size() != 1)
    {
        q.pop();
        if(q.size() ==1)
            break;
        int a = q.front();
        q.pop();
        q.push(a);
    }
    
    cout << q.front();
    return 0;
}