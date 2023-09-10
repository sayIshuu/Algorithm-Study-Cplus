#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s = "";

    cin >> s;
    int count = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ',')
            count++;
    }
    
    cout << count;

    return 0;
}