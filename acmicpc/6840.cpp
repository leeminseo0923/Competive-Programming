#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int bowl[3];
    for (int i = 0; i < 3; i++)
        cin >> bowl[i];

    sort(bowl, bowl + 3);

    cout << bowl[1];
    return 0;
}