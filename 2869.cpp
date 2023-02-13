#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double a, b, v;

    cin >> a >> b >> v;

    double t = (v - a) / (a - b);

    int k = ceil(t + 1);

    cout << k;
}