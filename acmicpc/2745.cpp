#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string str;
    int base;
    cin >> str >> base;

    int result = 0;
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        char cur = str.at(i);

        if (cur >= '0' && cur <= '9')
            result += (cur - '0') * pow(base, len - i - 1);
        else
            result += (cur - 'A' + 10) * pow(base, len - i - 1);
    }

    cout << result;

    return 0;
}