#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int cnt = 0;

    while (!s.empty())
    {
        char cur = s.back();
        s.pop_back();
        switch (cur)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cnt++;
            break;
        default:
            break;
        }
    }
    cout << cnt;
    return 0;
}