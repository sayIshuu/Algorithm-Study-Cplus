//BJ12869 뮤탈리스크 골4 언타멘토링4주차 너비우선탐색
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*흠...
시간제한 2초.. 좀 넉넉하게 생각해볼까
단순하게 scv 3개 체력 오름차순 정렬 매 공격마다.
큰순으로 9 3 1 박아넣어
언제 다 죽는지.


매 공격을 큰 반복문으로.
살아남은 scv 수 계산 = temp
    아래에 조건문(temp == 3)
                {
                    젤큰놈 -9
                    temp--;
                }
내림차순 정렬하고
박아넣기.
셋다 죽으면 끝.
*/

vector<int> scv(3);

int attack[3] = {9,3,1};


int main(void)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> scv[i];
    }

    int time = 0;
    while(!scv.empty())
    {
        sort(scv.rbegin(), scv.rend());
        for (int i = 0; i < scv.size(); i++)
        {
            scv[i] -= attack[i];
            if(scv[i] <= 0)
            {
                scv.erase(scv.begin() + i);
            }
        }
        time++;
    }

    cout << time;
    
    return 0;
}

//당장 첫번째 예제 부터 틀림..이게 어떻게 너비우선탐색이지.
