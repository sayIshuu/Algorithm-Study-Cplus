#include <iostream>
#include <deque>
using namespace std;

int n, m;
deque<int> answer; //�ϳ��� �����ؼ� ����ϰ� Ŭ����

//��Ʈ��ŷ�� dfs���, ����Լ��� Ȱ���ؼ� ���ܰ踦 ������
void back()
{
    if(answer.size() == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << answer[i] << ' ';
        }
        cout << '\n';
        return; //�������� Ż��
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