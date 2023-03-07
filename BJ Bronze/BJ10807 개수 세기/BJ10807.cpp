//BJ10807 개수 세기 브5
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> Pcount(101);
    vector<int> Mcount(101);
    //vector<int> v(n+1); 이거 왜 안돼
    vector<int> v(101);

    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        if(v[i]>=0)
        {
            Pcount[v[i]]++;
        }
        else if(v[i]<0)
        {
            Mcount[v[i]*(-1)]++;
        }
    }

    int s;
    cin >> s;

    if(s>=0)
        cout << Pcount[s];
    else if(s<0)
        cout << Mcount[s*(-1)];

    return 0;
}