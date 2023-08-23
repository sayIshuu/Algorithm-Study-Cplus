#include <iostream>
#define N 1000001
using namespace std;

long long tree[N*4];
long long a[N];

int n,m,k;

long long init(int start, int end, int node)
{
    if(start == end) return tree[node] = a[start];

    int mid = (start+end) / 2;

    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}


void change(int start, int end, int node, int index, long long val)
{
    if(start > index || end < index)
        return;

    if(start == index && end == index)
    {
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    change(start, mid, node*2, index, val);
    change(mid+1, end, node*2+1, index, val);
    tree[node] = tree[node*2] + tree[node*2+1];
}

long long sum(int start, int end, int node, int left, int right)
{
    if(start > right || end < left) return 0;

    if(start >= left && end <= right)
        return tree[node];

    int mid = (start + end) / 2;
    return sum(start , mid, node*2, left, right) + sum(mid+1, end, node*2+1, left, right);
}

void input()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    init(1,n+1,1);

    m+=k;

    while (m--)
    {
        int a,b;
        long long c;
        cin >> a >> b >> c;
        if(a==1)
            change(1,n+1,1, b,c);
        else if(a==2)
            cout << sum(1,n+1,1,b,c) << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    input();

    return 0;
}