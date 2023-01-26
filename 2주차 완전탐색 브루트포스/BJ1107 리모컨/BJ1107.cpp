//BJ1107 리모컨 골5 완전탐색 브루트포스 알고리즘 언타멘토링 2주차 마지막문제
#include <iostream>
#include <vector>
using namespace std;

/**/


int main(void)
{
    vector<int> a;
    vector<int> b;

    a.push_back(1);

    cout << a[3] << endl;

    b.push_back(2);
    b.push_back(3);

    a.push_back(b);

    cout << a[3] << endl;

    return 0;
}