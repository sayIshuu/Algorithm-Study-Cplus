#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
    int n, k; cin >> n >> k;

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i+1);
    }

    //큐면 큐답게 front에만 신경쓰자.
    cout << '<';
    while (n--)
    {  
        for (int i = 0; i < k; i++)
        {
            if(i == k-1){
                cout << q.front();
                q.pop();
            }
            else{
                q.push(q.front());
                q.pop();
            }
        }
        if(n!=0)
            cout << ", ";
    }
    cout << '>';
    


    return 0;
}