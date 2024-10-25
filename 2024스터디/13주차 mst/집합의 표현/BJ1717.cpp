#include <iostream>
using namespace std;

int n, m;
int arr[1000001];

int getRoot(int x){
     if(arr[x] == x)
          return x;
     return arr[x] = getRoot(arr[x]);
}

void unionRoot(int a, int b){
     a = getRoot(arr[a]);
     b = getRoot(arr[b]);

     if(a<b) arr[b] = a;
     else arr[a] = b;
}

string findUnion(int a, int b){
     a = getRoot(arr[a]);
     b = getRoot(arr[b]);

     if(a==b) return "YES";
     else return "NO";
}

int main(void)
{
     ios::sync_with_stdio(false);
     cin.tie(NULL);

     cin >> n >> m;
     for (int i = 0; i <= n; i++)
          arr[i] = i;
     while (m--)
     {
          int select; cin >> select;
          int a,b; cin >> a >> b;
          if(select == 1)
               cout << findUnion(a,b) << '\n';
          else
               unionRoot(a,b);
     }
     
     return 0;
}