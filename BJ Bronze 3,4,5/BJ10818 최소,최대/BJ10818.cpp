//BJ10818 최소,최대 브3
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n;
    cin >> n;

    vector<int> v;

    while(n--)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    
    int min = v.front();
    int max = v.front();

    for (int i = 0; i < v.size(); i++)
    {
        if(v[i] > max)
        {
            max = v[i];
        }
        else if(v[i] < min)
        {
            min = v[i];
        }
    }
    
    cout << min << ' ' << max << endl;
    
    return 0;
}