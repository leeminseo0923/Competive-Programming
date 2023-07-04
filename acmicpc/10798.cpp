#include <iostream>
#include <string>

using namespace std;

char arr[15][5];

int main()
{
    for (int i = 0; i < 5; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++)
            arr[j][i] = str.at(j);
    }

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (arr[i][j] != 0)
                cout << arr[i][j];
        }
    }
    return 0;
}