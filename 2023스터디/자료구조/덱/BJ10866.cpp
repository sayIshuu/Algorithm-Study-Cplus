#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> d;

void solution(string q)
{
    // switch (q) c++에선 switch(문자열)을 제공하지 않는다.
    
    if(q == "push_back")
    {
        int a; cin >> a;
        d.push_back(a);
    }
    else if(q == "push_front")
    {
        int a; cin >> a;
        d.push_front(a);
    }
    else if(q == "pop_front")
    {
        if(d.empty())
            cout << -1 << '\n';
        else{  
            cout << d.front() << '\n';
            d.pop_front();
        }
    }
    else if(q == "pop_back")
    {
        if(d.empty())
            cout << -1 << '\n';
        else{  
            cout << d.back() << '\n';
            d.pop_back();
        }
    }
    else if(q == "size")
    {
        cout << d.size() << '\n';
    }
    else if(q == "empty")
    {
        if(d.empty())
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    else if(q == "front")
    {
        if(d.empty())
            cout << -1 << '\n';
        else
            cout << d.front() << '\n';
    }
    else if(q == "back")
    {
        if(d.empty())
            cout << -1 << '\n';
        else
            cout << d.back() << '\n';
    }
}

void input()
{
    int n; cin >> n;
    while (n--)
    {
        string str; cin >> str;
        solution(str);
    } 
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    return 0;
}