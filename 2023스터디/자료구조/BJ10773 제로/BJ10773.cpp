/*
#include <iostream>
#include <stack>
using namespace std;

int main(void)
{
    int n; cin >> n;
    stack<int> v;
    while (n--)
    {
        int a; cin >> a;
        if(a==0){
            v.pop();
            continue;
        }
        
        v.push(a);
    }
    
    int sum = 0;
    if(v.size() == 0){
        cout << sum;
        return 0;
    }
    int t = v.size();
    for (int i = 0; i <= t; i++)
    {
        sum += v.top();
        v.pop();
    }
    
    cout << sum;
    return 0;
}
*/


#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n; cin >> n;
    vector<int> v;
    while (n--)
    {
        int a; cin >> a;
        if(a==0){
            v.pop_back();
            continue;
        }
        
        v.push_back(a);
    }
    
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    
    cout << sum;
    return 0;
}