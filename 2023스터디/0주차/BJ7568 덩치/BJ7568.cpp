#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct
{
    int w;
    int h;
}s;

int main(void)
{
    int n; cin >> n;

    vector<s> v;
    for (int i = 0; i < n; i++)
    {
        int w,h;    cin >> w >> h;
        v.push_back({w,h});
    }

    for (int i = 0; i < n; i++)
    {
        int rank = 1;
        for (int j = 0; j < n; j++)
        {
            if(v[i].w >= v[j].w || v[i].h >= v[j].h)
                continue;
            
            rank++;
        }
        cout << rank << ' ';
    }
    
    return 0;
}