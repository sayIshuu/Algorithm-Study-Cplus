#include <iostream>
#include <vector>
#include <queue>
//#define INF 1000000000;
using namespace std;

int v, e;
int start;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> v >> e >> start;
    
    vector<pair<int, int>> from[v+1]; //���� ������ <to, value>
    int minVal[v+1] = {};
    for (int i = 1; i <= v; i++) minVal[i] = 1000000000;
    
    while (e--)
    {
        int _from, _to, _value;
        cin >> _from >> _to >> _value;

        from[_from].push_back({_to, _value});
    }
    
    minVal[start] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int value = -pq.top().first;   //���� -�� ����
        int cur = pq.top().second;
        pq.pop();

        if(minVal[cur] < value) continue;

        for (int i = 0; i < from[cur].size(); i++)
        {
            //���� top���ִ� ����� �������� Ž��
            int next = from[cur][i].first;
            int nextVal = value + from[cur][i].second;

            if(minVal[next] > nextVal)
            {
                minVal[next] = nextVal;
                pq.push({-nextVal, next}); //�������� �켱���� ť
            }
        }
    }

    for (int i = 1; i <= v; i++)
    {
        if(minVal[i] == 1000000000 )
            cout << "INF" << '\n';
        else
            cout << minVal[i] << '\n';
    }

    return 0;
}



//���ؼ� ���� ���� �Ÿ��� �������� �켱���� ť ������ �����鼭 �� �ʱ�ȭ
//cnt[20000]�� �����Ҷ� �������� �ʱⰪ �����س��´�.. ���丸 ������
//�迭�� �޸��ʰ� �ߴϱ�.