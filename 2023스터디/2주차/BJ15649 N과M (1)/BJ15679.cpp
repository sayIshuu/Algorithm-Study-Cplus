#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> answer; //하나씩 저장해서 출력하고 클리어

//백트래킹은 dfs기반, 재귀함수를 활용해서 각단계를 나누자
void back()
{
    if(answer.size() == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return; //끝에서만 탈출
    }

    for (int i = 0; i < n; i++)
    {
        bool t = false;
        for (int k = 0; k < answer.size(); k++)
        {
            if(answer[k]==(i+1))
            {
                t = true;
                break;
            }
        }
        if(t) continue;
        answer.push_back(i+1);
        back();
        answer.pop_back();
    }
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    back();
    return 0;    
}