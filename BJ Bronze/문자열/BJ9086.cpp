#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int t; cin >> t;
    while (t--)
    {
        string str = "";
        cin >> str;
        
        cout << str[0] << str[str.size()-1] << endl;
    }
    return 0;
}