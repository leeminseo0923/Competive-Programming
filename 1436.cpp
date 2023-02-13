#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int count = 1;
    long long curNum = 666;

    while (N > count)
    {
        while (true)
        {
            curNum++;
            string temp = to_string(curNum);
            if (string::npos != temp.find("666"))
            {
                break;
            }
        }
        count++;
    }
    cout << curNum;
    return 0;
}