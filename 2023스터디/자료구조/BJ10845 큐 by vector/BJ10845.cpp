//BJ10845 큐 실4 queue사용해서 구현
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> q;

void push(){
    int n; cin>>n;
    q.push_back(n);
}

int pop(){
    if(q.empty())
        return -1;
    else{
        int a = q.front();
        q.erase(q.begin());
        return a;
    }
}

int size(){
    return q.size();
}

int empty(){
    if(q.empty())
        return 1;
    else
        return 0;
}

int front(){
    if(q.empty())
        return -1;
    else
        return q.front();
}

int back(){
    if(q.empty())
        return -1;
    else
        return q.back();
}


int main(void)
{
    //queue<int> q;
    int n; cin >> n;

    while (n--)
    {
        string str = ""; cin >> str;
        if(str == "push")
            push();
        else if(str == "front")
            cout << front() << '\n';
        else if(str == "back")
            cout <<back() << '\n';
        else if(str == "empty")
            cout << empty()<< '\n';
        else if(str == "pop")
            cout << pop() << '\n';
        else if(str == "size")
            cout << size() << '\n';
    }
    return 0;
}