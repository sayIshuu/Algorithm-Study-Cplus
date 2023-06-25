#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 문제의의 :
// 문자열 입력초기화와 입력
// vector요소로 구조체들어갔을 때 함수 지정해서 정렬하기!!

typedef struct
{
    int number;
    int age;
    string name;
}node;

bool compare(node a, node b) {
	if (a.age == b.age) {
		return a.number < b.number;
	}
	else {
		return a.age < b.age;
	}
}


int main(void)
{
    int n; cin >> n;

    vector<node> v;

    for (int i = 0; i < n; i++)
    {
        int age; cin >> age;
        string name;
        cin.ignore();
        getline(cin,name);

        v.push_back({i,age,name});
    }
    
    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << v[i].age << ' ' << v[i].name << '\n';
    }
    
    
    return 0;
}