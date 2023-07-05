#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
    string name;
    int korean;
    int english;
    int math;
}node;

bool compare(node n1, node n2)
{
    if(n1.korean == n2.korean)
    {
        if(n1.english == n2.english)
        {
            if(n1.math == n2.math)
                return n1.name < n2.name;
            else
                return n1.math > n2.math;
        }
        else
            return n1.english < n2.english;
    }
    else
        return n1.korean > n2.korean;
}

int main(void)
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    vector<node> v;
    int n; cin >> n;

    while (n--)
    {
        string s;
        int k,e,m;
        cin >> s >> k >> e >> m;
        v.push_back({s,k,e,m});
    }
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].name << '\n';
    }
    

    return 0;
}