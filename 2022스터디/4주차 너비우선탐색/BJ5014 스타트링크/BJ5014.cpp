//BJ5014 ��ŸƮ��ũ ��1 ��Ÿ���丵4���� �ʺ�켱Ž��
#include <iostream>
#include <queue>
using namespace std;

//�ε����� ��, �� 0�� �湮��, 1�� �湮
int arr[1000000] = {0,};

typedef struct node
{
    int curPos;
    int time;
}Node;

int main(void)
{
    //�����, ����ġ, ������, up, down
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;

    if(s==g) {cout << 0; return 0;}

    queue<Node> q;
    q.push({s,0});
    arr[s] = 1;
    while (!q.empty())
    {
        int x = q.front().curPos;
        int time = q.front().time;
        q.pop();       

        if(x+u == g || x-d == g) { cout << time+1; return 0; }

        //�����ȳѾ�� Ȯ���ϸ鼭 push.. �׷��� ��ǥ��kã���� break;
        //x+1
        if(x+u <= f)
        {
            if(arr[x+u] == 0)
            {
                //�湮üũ
                arr[x+u] = 1;
                q.push({x+u, time+1});
            }
        }
        //x-1
        if(x-d >= 1)
        {
            if(arr[x-d] == 0)
            {
                //�湮üũ
                arr[x-d] = 1;
                q.push({x-d, time+1});   
            }             
        }
    }
    cout << "use the stairs" << endl;

    return 0;
}