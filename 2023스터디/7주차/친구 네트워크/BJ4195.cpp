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

unordered_map<string,s> um; //<자기이름(키워드), 부모(값)> 값은 다음 키워드로 연결!

string getRoot(string myname)  //루트를 찾아주기 위한 재귀함수
{
    auto iter = um.find(myname);
    if(iter->second.parentName == myname)  //자신이 자신의 부모라면 속하는 그래프의 루트라는 뜻
        return iter->first;
    return iter->second.parentName = getRoot(iter->second.parentName);  //빠져나오면서 루트정보 최신화
}

void unionRoot(string a, string b)    //루트를 합치면 그것이 union 왜냐하면 트리구조니까
{
    auto iterA = um.find(a);
    auto iterB = um.find(b);
    a = getRoot(iterA->first);
    b = getRoot(iterB->first);

    //작은애를 루트로
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
            if(um.find(name) == um.end()) //첫등장이라면
            {
                um[name] = {name, 1};
            }

            string name2;
            cin >> name2;
            if(um.find(name2) == um.end()) //첫등장이라면
            {
                um[name2] = {name2, 1};
            }

            unionRoot(name, name2);
        }
        um.clear();
    }

    return 0;
}