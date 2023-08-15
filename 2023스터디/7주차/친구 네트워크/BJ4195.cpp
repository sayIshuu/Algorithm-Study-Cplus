#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int t,n;
typedef struct
{
    string parentName;
    int netNum;
}s;

unordered_map<string,s> um; //<�ڱ��̸�(Ű����), �θ�(��)> ���� ���� Ű����� ����!

string getRoot(string myname)  //��Ʈ�� ã���ֱ� ���� ����Լ�
{
    auto iter = um.find(myname);
    if(iter->second.parentName == myname)  //�ڽ��� �ڽ��� �θ��� ���ϴ� �׷����� ��Ʈ��� ��
        return iter->first;
    return iter->second.parentName = getRoot(iter->second.parentName);  //���������鼭 ��Ʈ���� �ֽ�ȭ
}

void unionRoot(string a, string b)    //��Ʈ�� ��ġ�� �װ��� union �ֳ��ϸ� Ʈ�������ϱ�
{
    auto iterA = um.find(a);
    auto iterB = um.find(b);
    a = getRoot(iterA->first);
    b = getRoot(iterB->first);

    //�����ָ� ��Ʈ��
    if(a<b)
    {
        um[b].parentName = a;
        um[a].netNum += um[b].netNum;
        cout << um[a].netNum << '\n';
    }
    else if (b<a) {
        um[a].parentName = b;
        um[b].netNum += um[a].netNum;
        cout << um[b].netNum << '\n';
    }
    else {
        um[a].parentName = b;
        cout << um[b].netNum << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    while (t--)
    {
        cin >> n;
        while (n--)
        {
            string name;
            cin >> name;
            if(um.find(name) == um.end()) //ù�����̶��
            {
                um[name] = {name, 1};
            }

            string name2;
            cin >> name2;
            if(um.find(name2) == um.end()) //ù�����̶��
            {
                um[name2] = {name2, 1};
            }

            unionRoot(name, name2);
        }
        um.clear();
    }

    return 0;
}