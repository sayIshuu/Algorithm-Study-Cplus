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
    
    vector<pair<int, int>> from[n+1]; //���� ������ <to, value>
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
    priority_queue<pair<int,int>> pq; // �������������Ǻ��, ��������
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

    cout << minVal[fin];

    return 0;
}



//���ؼ� ���� ���� �Ÿ��� �������� �켱���� ť ������ �����鼭 �� �ʱ�ȭ
//cnt[20000]�� �����Ҷ� �������� �ʱⰪ �����س��´�.. ���丸 ������
//�迭�� �޸��ʰ� �ߴϱ�.