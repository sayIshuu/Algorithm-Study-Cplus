#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

//antic 5개는 확정. 이거보다 k작으면 답 0

//비교할 요소는 문자열마다 추출한 set antic 제외
//antic제외하고 k개로 set 백트래킹으로 만들어봄
//포함되는지 비교는 includes로 부분집합 비교하면 될듯

int n, k;
int ans;
set<char> antic = {'a', 'n', 't', 'i', 'c'};
vector<set<char>> v;

set<char> temp;
void back(int idx, int cnt)
{
    if(cnt == k){
        int c = 0;
        for (int i = 0; i < n; i++)
            if(includes(temp.begin(), temp.end(), v[i].begin(), v[i].end()))
                c++;
        ans = max(ans, c);
    }

    for (int i = idx; i < 26; i++)
    {
        if(antic.count(i+'a'))
            continue;
        temp.insert(i+'a');
        back(i+1, cnt+1);
        temp.erase(i+'a');
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    if(k < 5){
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        set<char> s;
        for (int j = 4; j < str.length()-4; j++){
            if(antic.count(str[j]))
                continue;
            s.insert(str[j]);
        }
        v.push_back(s);
    }

    back(0, 5);
    cout << ans;

    return 0;
}