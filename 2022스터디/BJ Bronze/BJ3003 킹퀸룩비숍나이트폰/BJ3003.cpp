//BJ3003 킹,퀸,룩,비숍,나이트,폰 브5
#include <iostream>
#include <vector>
using namespace std;

//vector 익숙해지기 진행중
int main(void)
{
    //정답배열
    vector<int> v = {1,1,2,2,2,8};

    //지금 있는 기물 개수
    vector<int> p(6);

    cin >> p[0] >> p[1] >> p[2] >> p[3] >> p[4] >> p[5];

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] - p[i] << ' ';
    }
    

    return 0;
}