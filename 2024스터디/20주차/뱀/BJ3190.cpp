#include <iostream>
#include <queue>
#include <vector>
using namespace std;
//���� ���������� �ᱹ push, pop����. ���� �湮üũ�� �ʵ忡�� ���� ���ָ� �ȴ�.

int n,k,l;
int answer;
queue<pair<int,int>> warm;

//�ð���� �����̹Ƿ� D�� +1%4 L�̸� +3%4
pair<int,int> dir[4] = {{0,1},{1,0},{0,-1},{-1,0}};
int d = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    // O�� �����, X�� ������, A�� ���
    vector<vector<char>> field(n, vector<char>(n,'O'));
    field[0][0] = 'X';
    warm.push({0,0});

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin >> a >> b;
        field[a-1][b-1] = 'A';
    }
    
    cin >> l;
    int time;
    int preTime = 0;
    for (int i = 0; i < l; i++)
    {
        cin >> time;
        int temp = time;
        time -= preTime;
        preTime = temp;
        if(i==l-1)
          time = 10000;
        //ť�� front�� �������� ������ �ش��ؼ� �� �򰥸���
        while (time--)
        {
            answer++;

            int nx,ny;
            nx = warm.back().first + dir[d].first;
            ny = warm.back().second + dir[d].second;

            if(nx < 0 || ny < 0 || nx >= n || ny >= n || field[nx][ny] == 'X'){
                cout << answer;
                return 0;
            }
            else if(field[nx][ny] == 'A'){
                warm.push({nx,ny});
                field[nx][ny] = 'X';
            }
            else{
                warm.push({nx,ny});
                field[nx][ny] = 'X';
                field[warm.front().first][warm.front().second] = 'O';
                warm.pop();
            }
        }
        char turn; cin >> turn;
        if(turn == 'L')
            d = (d+3)%4;
        else
            d = (d+1)%4;
    }
    return 0;
}