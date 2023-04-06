//BJ11057 ������ �� ��1 ��Ÿ�˰���丵6���� ���̳��� ���α׷���
#include <iostream>
using namespace std;

// dpǪ�¹� ��üȭ �ȵ�. �賶ó�� ���ǵ� �̾Ƴ��� ǥ ����� ��. ���� ���� ���������� ����

int graph[10][1001];    // ���� ���� ����. ���� �ڸ���. ù���� �������� ������ ���� 0�ڸ����� ����

int main(void)
{
    int n; cin >> n;


    for (int i = 0; i <= n; i++)
    {
        graph[0][i] = 1;
    }
    for (int i = 1; i < 10; i++)
    {
        graph[i][1] = i+1;
        for (int j = 2; j <= n; j++)
        {
            graph[i][j] = graph[i-1][j]%10007 + graph[i][j-1]%10007;
            graph[i][j]%=10007;
        }    
    }

    cout << graph[9][n] << endl;

    return 0;
}