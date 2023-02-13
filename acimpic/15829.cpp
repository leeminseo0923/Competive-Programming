#include <iostream>
using namespace std;

int main()
{
    int l;
    cin >> l;
    string s;
    cin >> s;
    long long sum = 0;
    long long M = 1234567891;
    long long r = 31;
    for (int i = 0; i < l; i++)
    {
        long long d = s[i] - 'a' + 1;
        for (int j = 0; j < i; j++)
        {
            d *= r;
            d %= M;
        }
        sum += d;
        sum %= M;
    }
    cout << sum << endl;
    return 0;
}