//BJ2178 �̷�Ž�� ��1 �˰�����丵 3���� �ʺ�켱Ž��
#include <iostream>
#include <string>
#include <queue>
using namespace std;

/* �������̵��
�ִܰ�λ��� ���̷��� ������ ����.. �̷δ� 2�����迭�� �����ϰ���.
���ο� ��� push�ɶ����� answer++;
pop�ϱ����� ������ �͵� Ǫ�����ݾ�? Ǫ���ϴ°� ���ٸ� ���� ������. �׷��� answer--;
ť�� empty�Ǹ� �� �� ������ �񿡼��� ���� ������ ó���ǹǷ� answer -1 ���
*/

//ť�� ��Ұ� �� ����ü
typedef struct node
{
    int N;
    int M;
}Node;


int main(void)
{
    //============2�����迭�� �̷� ����===============
    int n,m;
    cin >> n >> m;
    int miro[n][m]; //�ε������� -1 ����

    for (int i = 0; i < n; i++)
    {
        //�ڸ������� ��,������ ���ϱ⺸�� ���ڿ��� �ް� �ѱ��ھ� ����ȯ
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++)
        {
            miro[i][j] = temp[j]-'0';
        }
    }


    //ť�� �̷��� ��ġ������ ������ �־����...����ü ����ʹ�..�̰Ծ�Ƴ�
    //(1,1)�� �������� ���� �־���
    //�ݺ��� while(!q.empty)
    //  ť.front() (n,m)������ ������ �����¿�ĭ �� ���� 1�� ĭ �ִ���?
    //  ������ answer--;
    //  ������ push�ϰ� answer++;
    //  q.front()�� �ش��ϴ� �̷� ĭ = 0    ..�湮üũ
    //  q.pop();
    //���� answer+2; ù��� �ȵ��� ������ ��忡�� -1 ��.
    
    int answer = 0;

    queue<Node> q;
    q.push({1,1});
    
    while (!q.empty())
    {
        Node front = q.front();
        //�Ʒ� ���ǹ��� ���� count�� 0�� �����Ǹ� ���ٸ���. ���� answer--;����
        int count = 0; 
        if(q.back().M == m && q.back().n == n)
            cout << answer+2;
        //��
        if(front.N+1 >= 0 && front.N+1 <= n)
        {
            if(miro[front.N+1][front.M] == 1)
            {
                q.push({front.N+1,front.M});
                answer++;
                count++;
                continue;
            }
        }
        //��
        if(front.M+1 >= 0 && front.M+1 <= m)
        {
            if(miro[front.N][front.M+1] == 1)
            {
                q.push({front.N,front.M+1});
                answer++;
                count++;
                continue;
            }
        }
        //��
        if(front.N-1 >= 0 && front.N-1 <= n)
        {
            if(miro[front.N-1][front.M] == 1)
            {
                q.push({front.N-1,front.M});
                answer++;
                count++;
                continue;
            }
        }
        //��
        if(front.M-1 >= 0 && front.M-1 <= m)
        {
            if(miro[front.N][front.M-1] == 1)
            {
                q.push({front.N,front.M-1});
                answer++;
                count++;
                continue;
            }
        }
        if(count == 0)
            answer--;

        //�Ǿճ�� �湮üũ�ϰ� ��
        miro[front.N][front.M] = 0;
        q.pop(); 
    }
    

    cout << answer+2;
}


//����. ���̿켱Ž���� ������� ������ ������.