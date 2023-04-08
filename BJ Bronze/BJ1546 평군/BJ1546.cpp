//브1 단계별로 풀어보기 1차원배열
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<double> scores(1001);
int main(void)
{
    int n; cin >> n;
    double M = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
        if(scores[i] > M)
            M = scores[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        scores[i] = scores[i]/M*(100.0);
    }
    
    cout << accumulate(scores.begin(), scores.end(),0.0)/n;
}