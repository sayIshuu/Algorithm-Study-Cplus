#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int memory[100];
int cost[100];
int total;

vector<int> sumCosts;

void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> memory[i];
        total += memory[i];
    }
    
    for (int i = 0; i < n; i++)
        cin >> cost[i];
}


void knapsack(int index, int sumCost, int sumMemory, int total)
{
    //promising
    if(sumMemory >= m)
    {
        sumCosts.push_back(sumCost);
        return;
    }
    if(sumMemory + total < m)
        return;

    if(index == n)
    {
        if(sumMemory < m)
            return;
        
        sumCosts.push_back(sumCost);
        return;
    }

    knapsack(index+1, sumCost, sumMemory, total);
    knapsack(index+1, sumCost+cost[index], sumMemory+memory[index], total-memory[index]);
}

void solve()
{
    knapsack(0,0,0,total);

    cout << *min_element(sumCosts.begin(), sumCosts.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    solve();

    return 0;
}

//백트래킹 시간초과~~~~~