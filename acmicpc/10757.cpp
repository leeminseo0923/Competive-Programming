#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int result[101010];

int main()
{
    int ctn = 0;
    string str1, str2;
    cin >> str1 >> str2;
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int len = min(str1.length(), str2.length());

    int adder = 0;

    for (int i = 0; i < len; i++)
    {
        int sum = str1.at(i) - '0' + str2.at(i) - '0' + adder;
        result[i] = sum % 10;
        adder = sum / 10;
        ctn++;
    }
    for (int i = len; i < str1.length(); i++)
    {
        int sum = str1.at(i) - '0' + adder;
        result[i] = sum % 10;
        adder = sum / 10;
        ctn++;
    }
    for (int i = len; i < str2.length(); i++)
    {
        int sum = str2.at(i) - '0' + adder;
        result[i] = sum % 10;
        adder = sum / 10;
        ctn++;
    }
    if (adder)
    {
        result[ctn] = adder;
        ctn++;
    }

    for (int i = ctn - 1; i >= 0; i--)
    {
        cout << result[i];
    }
    return 0;
}