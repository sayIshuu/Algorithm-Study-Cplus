#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int start, fin;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    vector<pair<int, int>> from[n+1]; //간선 정보들 <to, value>
    int minVal[n+1] = {};
    for (int i = 1; i <= n; i++) minVal[i] = 1000000000;
    
    while (m--)
    {
        int _from, _to, _value;
        cin >> _from >> _to >> _value;

        from[_from].push_back({_to, _value});
    }
    
    cin >> start >> fin;

    minVal[start] = 0;
    priority_queue<pair<int,int>> pq; // 다음갈곳까지의비용, 다음갈곳
    pq.push({0, start});

    while (!pq.empty())
    {
        int value = -pq.top().first;   //들어갈때 -로 들어가니
        int cur = pq.top().second;
        pq.pop();

        if(minVal[cur] < value) continue;

        for (int i = 0; i < from[cur].size(); i++)
        {
            //지금 top에있는 노드의 인접노드들 탐색
            int next = from[cur][i].first;
            int nextVal = value + from[cur][i].second;

            if(minVal[next] > nextVal)
            {
                minVal[next] = nextVal;
                pq.push({-nextVal, next}); //오름차순 우선순위 큐
            }
        }
    }

    cout << minVal[fin];

    return 0;
}



//통해서 가는 최종 거리값 기준으로 우선순위 큐 돌린다 돌리면서 답 초기화
//cnt[20000]을 설정할때 무한으로 초기값 설정해놓는다.. 개념만 가져와
//배열은 메모리초과 뜨니까.