#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// �������� :
// ���ڿ� �Է��ʱ�ȭ�� �Է�
// vector��ҷ� ����ü���� �� �Լ� �����ؼ� �����ϱ�!!

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